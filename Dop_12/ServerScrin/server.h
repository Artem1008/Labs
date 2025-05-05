#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <memory>
#include <vector>
#include <qt_windows.h>
#include <QObject>
#include <QDebug>

struct BitmapData {
    int width;
    int height;
    int size;
    BYTE* data;
};

class Server:public QObject
{
    Q_OBJECT
private:
    bool running;
    const int port=666;
    const char* address;
    char buff[1024];
    SOCKET server_sock;
    SOCKET client_socket;
    sockaddr_in local_addr;
    sockaddr_in client_addr;
    static DWORD WINAPI ConnectToClient(LPVOID client_socke);
public:
    Server();
    int StartServer();
    int InitServer();
signals:
    void signalBITMAP(BitmapData);
};

#endif // SERVER_H
