#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include <screen.h>
#include <winsock2.h>
#include <memory>
#include <WS2tcpip.h>
#include <iostream>
#include <string>

class WebClient
{
private:
        struct SocketDeleter {
            void operator()(SOCKET sock) const {
                if (sock != INVALID_SOCKET) {
                    closesocket(sock);
                }
            }
        };
        struct WSAInitializer {
            WSAInitializer() {
                WSADATA wsaData;
                if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                    throw std::runtime_error("WSAStartup failed");
                }
            }
            ~WSAInitializer() {
                WSACleanup();
            }
        };
    Screen screen;
    char buff[1024];
    const int port;
    const char* address;
    std::unique_ptr<SOCKET, SocketDeleter> my_sock;
    sockaddr_in dest_addr;
    HOSTENT *hst;
    // Метод инициализации
    int InitClient();
    // Объект для автоматического вызова WSACleanup
    WSAInitializer wsa;
    std::unique_ptr<SOCKET, SocketDeleter> createSocket();
public:
    WebClient(char* _address ,int _port);
    void SendBitmap();
};

#endif // WEBCLIENT_H
