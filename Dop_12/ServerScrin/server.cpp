#include "server.h"

static std::vector<SOCKET> arrsocket;
static int nclients=0;

Server::Server()
{

}
DWORD Server::ConnectToClient(LPVOID param)
{
    qDebug()<<"подключился";
    Server* server = static_cast<Server*>(param);
    SOCKET my_sock=server->client_socket;
    // Создаем буфер для приема данных
    int header[3];
    while (server->running)
    {
        // Ждем получения размера данных
        int bytesReceived = recv(my_sock, (char*)header, sizeof(header), 0);
        if (bytesReceived <= 0)
        {
            // Обработка ошибки или завершения соединения
            break;
        }
        // Создаем структуру для приема данных
        BitmapData receivedData;
        receivedData.width=header[0];
        receivedData.height=header[1];
        receivedData.size = header[2];
        receivedData.data = new BYTE[receivedData.size];
        // Получаем данные изображения
        int totalReceived = 0;
        while (totalReceived < receivedData.size)
        {
            int bytes = recv(my_sock,reinterpret_cast<char*>(receivedData.data) + totalReceived,receivedData.size - totalReceived, 0);
            if (bytes <= 0)
            {
                // Обработка ошибки
                break;
            }
            totalReceived += bytes;
        }
        emit server->signalBITMAP(receivedData);
    }
    nclients--;
    qDebug()<<"Закрыл сокет";
    printf("-disconnect\n");
    if (nclients) printf("%d user on-line\n", nclients);
    else printf("No User on line\n");
    // закрываем сокет
    closesocket(my_sock);
return 0;
}

int Server::StartServer()
{
    qDebug()<<"StartServer";
    if (listen(server_sock, 0x100))
    {
        closesocket(server_sock);
        WSACleanup();
        return -6;
    }
    int client_addr_size = sizeof(client_addr);
    while ((client_socket = accept(server_sock, (sockaddr *)&client_addr, &client_addr_size)))
    {
        nclients++;
        HOSTENT *hst;
        hst = gethostbyaddr((char *)&client_addr. sin_addr.s_addr, 4, AF_INET);
        printf("+%s [%s] new connect!\n",
               (hst) ? hst->h_name : "", inet_ntoa(client_addr.sin_addr));
        if (nclients) printf("%d user on-line\n", nclients);
        else printf("No User on line\n");
        DWORD thID;
        arrsocket.push_back(client_socket);
        CreateThread(NULL, NULL, ConnectToClient, this, NULL, &thID);
    }
    return 0;
}
int Server::InitServer()
{
    qDebug()<<"InitServer";
    if (WSAStartup(0x0202, (WSADATA *)&buff[0]))
    {
        return -1;
    }
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ((int)server_sock < 0)
    {
        return -2;
    }
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(port);
    local_addr.sin_addr.s_addr = 0;
    if (bind(server_sock, (sockaddr *)&local_addr, sizeof(local_addr)))
    {
        closesocket(server_sock); // закрываем сокет!
        WSACleanup();
        return -5;
    }
    return 1;
}
