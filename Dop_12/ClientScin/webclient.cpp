#include "webclient.h"

WebClient::WebClient(char* _address ,int _port):port(_port),address(_address), wsa(),my_sock(new SOCKET(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)), SocketDeleter{})
{

    if (InitClient() != 1)
    {
        throw std::runtime_error("Failed to initialize client");
    }
}
int WebClient::InitClient()
{
    my_sock=createSocket();
    if (my_sock == nullptr || *my_sock == INVALID_SOCKET) {
        return -2;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);

    if (inet_addr(address) != INADDR_NONE) {
        dest_addr.sin_addr.s_addr = inet_addr(address);
    } else {
        hst = gethostbyname(address);
        if (hst == nullptr) {
            return -3;
        }
        memcpy(&dest_addr.sin_addr, hst->h_addr_list[0], hst->h_length);
    }

    if (connect(*my_sock, (sockaddr*)&dest_addr, sizeof(dest_addr)) == SOCKET_ERROR)
    {
        return -4;
    }
    return 1;
}

void WebClient::SendBitmap()
{
    BITMAP bmp;
    HBITMAP tempBitmap=screen.getScreenshot();

    GetObject(tempBitmap, sizeof(BITMAP), &bmp);
    // создать поток для отправки
    //std::ofstream file(filename, std::ios::binary);

    /* if (file.is_open()) {
        BITMAPFILEHEADER bf;
        bf.bfType = 0x4D42; // 'BM'
        bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bmp.bmWidth * bmp.bmHeight * 4;
        bf.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        BITMAPINFOHEADER bi;
        bi.biSize = sizeof(BITMAPINFOHEADER);
        bi.biWidth = bmp.bmWidth;
        bi.biHeight = bmp.bmHeight;
        bi.biPlanes = 1;
        bi.biBitCount = 32;
        bi.biCompression = BI_RGB;

        file.write(reinterpret_cast<char*>(&bf), sizeof(BITMAPFILEHEADER));
        file.write(reinterpret_cast<char*>(&bi), sizeof(BITMAPINFOHEADER));

        // Копирование данных
        BYTE* buffer = new BYTE[bmp.bmWidth * bmp.bmHeight * 4];
        GetDIBits(CreateCompatibleDC(NULL), hBitmap, 0, bmp.bmHeight, buffer,
                  reinterpret_cast<BITMAPINFO*>(&bi), DIB_RGB_COLORS);
        file.write(reinterpret_cast<char*>(buffer), bmp.bmWidth * bmp.bmHeight * 4);

        delete[] buffer;
        file.close();
    }*/
}
