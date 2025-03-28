#include "client.h"

Client::Client(char* _address ,int _port):port(_port),address(_address)
{    
}

int Client::InitClient()
{
    if (WSAStartup(0x202, (WSADATA *)&buff[0]))
    {
        return -1;
    }
    my_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (my_sock < 0)
    {
        return -2;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    if (inet_addr(address) != INADDR_NONE)
        dest_addr.sin_addr.s_addr = inet_addr(address);
    else
    {
        if (hst = gethostbyname(address))
            ((unsigned long *)&dest_addr.sin_addr)[0] =((unsigned long **)hst->h_addr_list)[0][0];
        else
        {
            closesocket(my_sock);
            WSACleanup();
            return -3;
        }
    }
    if (connect(my_sock, (sockaddr *)&dest_addr, sizeof(dest_addr)))
    {
        return -4;
    }
}

void Client::StartClient(QTextBrowser* obj)
{
    int nsize;
    while ((nsize = recv(my_sock, &buff[0], sizeof(buff) - 1, 0)) != SOCKET_ERROR)
        {
            buff[nsize] = 0;
            obj->append(buff);
            if (!strcmp(&buff[0], "quit\n"))
            {
                closesocket(my_sock);
                WSACleanup();
            }
        }
}

void Client::SetMessag(std::string str)
{
    qDebug()<<"SetMessag"<<str.c_str();
    if (!strcmp(str.c_str(), "quit\n"))
    {
        // Корректный выход
        printf("Exit...");
        closesocket(my_sock);
        WSACleanup();
    }
    // передаем строку клиента серверу
    send(my_sock, str.c_str(), strlen(str.c_str()), 0);
}

Client::~Client()
{
    closesocket(my_sock);
    WSACleanup();
}
