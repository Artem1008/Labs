#include "server.h"

static std::vector<SOCKET> arrsocket;
static int nclients=0;
DWORD Server::ConncectToClient(LPVOID client_socket)
{
    SOCKET my_sock;
    my_sock = ((SOCKET *)client_socket)[0];
    char buff[20 * 1024];
    int bytes_recv;
    while ((bytes_recv = recv(my_sock, &buff[0], sizeof(buff), 0)) &&bytes_recv != SOCKET_ERROR)
    {
        for (auto i : arrsocket)
        {
            send( i, &buff[0], bytes_recv, 0);
        }
    }
    nclients--;
    printf("-disconnect\n");
    if (nclients) printf("%d user on-line\n", nclients);
    else printf("No User on line\n");
    // закрываем сокет
    closesocket(my_sock);
    return 0;
}

Server::Server()
{

}

int Server::InitServer()
{
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

int Server::StartServer()
{  
    if (listen(server_sock, 0x100))
    {
        closesocket(server_sock);
        WSACleanup();
        return -6;
    }
    qDebug()<<"StartServer listen end"<<server_sock;
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
        CreateThread(NULL, NULL, ConncectToClient, &client_socket, NULL, &thID);
    }
    return 0;
}
