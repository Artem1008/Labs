#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <QDebug>
#include <QTextBrowser>

class Client
{
private:
    char buff[1024];
    const int port;
    const char* address;
    SOCKET my_sock;
    sockaddr_in dest_addr;
    HOSTENT *hst;

public:
    Client(char* _address ,int _port);
    int InitClient();
    void StartClient(QTextBrowser*);
    void SetMessag(std::string);
    ~Client();
};

#endif // CLIENT_H
