#include "server.h"

int Server::nclients=0;
DWORD Server::SexToClient(LPVOID client_socket)
{
     qDebug()<<"Start SexToClient"<<client_socket;
    SOCKET my_sock;
    my_sock = ((SOCKET *)client_socket)[0];
    char buff[20 * 1024];
    int bytes_recv;
    while ((bytes_recv = recv(my_sock, &buff[0], sizeof(buff), 0)) &&bytes_recv != SOCKET_ERROR)
    {
        qDebug()<<"получил данные: "<<buff;
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
    qDebug()<<"StartServer";
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
        qDebug()<<"Start accept"<<client_socket;
        nclients++;
        HOSTENT *hst;
        hst = gethostbyaddr((char *)&client_addr. sin_addr.s_addr, 4, AF_INET);
        printf("+%s [%s] new connect!\n",
               (hst) ? hst->h_name : "", inet_ntoa(client_addr.sin_addr));
        if (nclients) printf("%d user on-line\n", nclients);
        else printf("No User on line\n");
        DWORD thID;
        CreateThread(NULL, NULL, SexToClient, &client_socket, NULL, &thID);
        //SexToClient(&client_socket);
    }
}
