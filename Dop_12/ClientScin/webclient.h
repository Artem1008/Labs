#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include <winsock2.h>
#include <screen.h>
#include <iostream>
#include <string>

class WebClient
{
private:
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
    SOCKET my_sock;
    sockaddr_in dest_addr;
    HOSTENT *hst;
    // Метод инициализации
    int InitClient();
    WSAInitializer wsa;
public:
    WebClient(char* _address ,int _port);
    void SendBitmap();
    void StartClient();
    ~WebClient();
};

#endif // WEBCLIENT_H
