#include "webclient.h"

WebClient::WebClient(char* _address ,int _port):port(_port),address(_address),wsa()
{
    if (InitClient() != 1)
    {
        throw std::runtime_error("Failed to initialize client");
    }
}
int WebClient::InitClient()
{
    my_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (my_sock == INVALID_SOCKET) {
        return -2;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    if (inet_addr(address) != INADDR_NONE)
        dest_addr.sin_addr.s_addr = inet_addr(address);
    else
    {
        hst = gethostbyname(address);
        if (hst!=nullptr){
            memcpy(&dest_addr.sin_addr, hst->h_addr_list[0], hst->h_length);
        }
        else
        {
            closesocket(my_sock);
            return -3;
        }
    }
    if (connect(my_sock, (sockaddr *)&dest_addr, sizeof(dest_addr)))
    {
        closesocket(my_sock);
        return -4;
    }
    return 1;
}

void WebClient::SendBitmap()
{
    BITMAP bmp;
    HBITMAP tempBitmap=screen.getScreenshot();
    GetObject(tempBitmap, sizeof(BITMAP), &bmp);

    DWORD dwSize = bmp.bmWidthBytes * bmp.bmHeight;
    BYTE* pBits = new BYTE[dwSize];
    GetBitmapBits(tempBitmap, dwSize, pBits);

    // Отправляем через сокет
    send(socket, (char*)&dwSize, sizeof(DWORD), 0);
    send(socket, (char*)pBits, dwSize, 0);

    // Освобождаем память
    delete[] pBits;
}
