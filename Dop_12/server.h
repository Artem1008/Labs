#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <QDebug>
#include <QTextBrowser>

class Server
{
private:
    const int port=666;
    const char* address;
    char buff[1024];
    SOCKET server_sock;
    SOCKET client_socket;
    sockaddr_in local_addr;
    sockaddr_in client_addr;  
    static DWORD WINAPI ConncectToClient(LPVOID client_socke);
public:    
    Server();
    int StartServer();
    int InitServer();
};

#endif // SERVER_H
