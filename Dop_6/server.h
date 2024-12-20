#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <QDebug>

DWORD WINAPI SexToClient(LPVOID client_socket);
static int nclients;
class Server
{
     Q_OBJECT
private:
    const int port=666;
    const char* address;
    char buff[1024];
    SOCKET server_sock;
    sockaddr_in local_addr;
    SOCKET client_socket; // сокет для клиента
    sockaddr_in client_addr;  
    static DWORD WINAPI SexToClient(LPVOID client_socke);
public:    
    Server();
    int StartServer();
    int InitServer();
};

#endif // SERVER_H
