#include "webclient.h"

WebClient::WebClient(char* _address ,int _port):port(_port),address(_address),wsa()
{
    if (InitClient() != 1)
    {
        std::cout<<"Failed to initialize client\n";
        throw std::runtime_error("Failed to initialize client");
    }
}
int WebClient::InitClient()
{
    my_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (my_sock == INVALID_SOCKET) {
         std::cout<<"Failed -2\n";
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
            std::cout<<"Failed -3\n";
            closesocket(my_sock);
            return -3;
        }
    }
    if (connect(my_sock, (sockaddr *)&dest_addr, sizeof(dest_addr)))
    {
        std::cout<<"Failed -4\n";
        closesocket(my_sock);
        return -4;
    }
    std::cout<<"OK\n";
    return 1;
}

void WebClient::SendBitmap(int sec)
{
    std::cout<<"SendBitmap\n";
    BITMAP bmp;
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(sec));
        HBITMAP tempBitmap=screen.getScreenshot();
        GetObject(tempBitmap, sizeof(BITMAP), &bmp);
        int dwSize = bmp.bmWidthBytes * bmp.bmHeight;
        // Работа с памятью
        std::unique_ptr<BYTE[]> pBits(new BYTE[dwSize]);
        GetBitmapBits(tempBitmap, dwSize, pBits.get());
        int header[3] = {bmp.bmWidth, bmp.bmHeight, dwSize};
       // Отправка размера структуры
        send(my_sock, (char*)header, sizeof(header), 0);
        std::cout<<"peredal razmer\n";
       // Отправка данных
        send(my_sock, (char*)pBits.get(), dwSize, 0);
        std::cout<<"peredal scrin\n";
        // Очистка ресурсов
        DeleteObject(tempBitmap);
    }
}

void WebClient::StartClient()
{
    std::thread([this]() {SendBitmap(10);}).join();
}
void WebClient::StopClient()
{
        running = false;
}
