#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>

using std::cout;

typedef struct ip_hdr //заголовок IP
{
    unsigned char verhlen;
    unsigned char tos:6;
    unsigned char additional:2;
    unsigned short totallent;
    unsigned short id;
    unsigned short offset;
    unsigned char ttl;
    unsigned char proto;
    unsigned short checksum;
    unsigned int source;
    unsigned int destination;
}IpHeader;

typedef  struct icmp_hdr //заголовок ICMP
{
    unsigned char i_type;
    unsigned char i_code;
    unsigned short i_crc;
    unsigned short i_seq;
    unsigned short i_id;

}IcmpHeader;

USHORT crc2 (USHORT* addr, int count)
{
    long sum = 0;
    while( count > 1 )  {
        sum += * (unsigned short*) addr++;
        count -= 2;
    }
    if( count > 0 )
        sum += * (unsigned char *) addr;
    while (sum>>16)
        sum = (sum & 0xffff) + (sum >> 16);
    return (USHORT)(~sum);
}

unsigned int analize(char* data, sockaddr_in* adr)
{
    char* Ip = (char*)"";
    IpHeader *pHe = (IpHeader*)data;
    char Name[NI_MAXHOST]={0};
    char servInfo[NI_MAXSERV]={0};
    getnameinfo((struct sockaddr *) adr,sizeof (struct sockaddr),Name,  NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV);
    Ip = inet_ntoa(adr->sin_addr);
    int TTL = (int)pHe->ttl;
    data+=sizeof(IpHeader);
    IcmpHeader *ic = (IcmpHeader*)data;
    if(GetCurrentProcessId()==ic->i_id)
        cout<<"Reply from "<<Ip<<" OK!\n";
    else
         cout<<"Reply from "<<Ip<<" Failed!\n";
    return pHe->source;
}


int ping(const char* Ip)
{
 WSADATA wsaData;
//удаленный адрес
sockaddr_in list_adr;
list_adr.sin_addr.S_un.S_addr = inet_addr(Ip);
list_adr.sin_family = AF_INET;
list_adr.sin_port = htons(6666);

//локальный адрес
sockaddr_in bnd;
bnd.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
bnd.sin_family = AF_INET;
bnd.sin_port = htons(6666);

if (WSAStartup(0x0202, &wsaData))
{
    return -1;
}
SOCKET listn =socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
if (bind(listn,(sockaddr*)&bnd,sizeof(bnd)))
{
    closesocket(listn);
    WSACleanup();
    return -5;
}
IcmpHeader pac;
int timeout = 3000;
setsockopt(listn,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(timeout));
pac.i_type = 8;
pac.i_code = 0;
pac.i_seq = 0x2;
pac.i_crc =0;
pac.i_id = (USHORT)GetCurrentProcessId();
int size = sizeof(pac)+32;
char* Icmp = new char [size];
memcpy(Icmp,&pac,sizeof(pac));
memset(Icmp+sizeof(pac),'Z',32);

IcmpHeader *Packet = (IcmpHeader *)Icmp;
Packet->i_crc = crc2((USHORT*)Packet,size);
char bf [256] = {0};
int outlent = sizeof(sockaddr_in);
sockaddr_in out_;
out_.sin_family = AF_INET;

//ПИНГИ
cout<<"Pinging address > "<<Ip<<"       ";

    //Отправляет данные в определенный пункт назначения.
    sendto(listn,(char*)Packet,size,0,(sockaddr*)&list_adr,sizeof(list_adr));
    Sleep(1000);

    if(recvfrom(listn,bf,256,0,(sockaddr*)&out_,&outlent)==SOCKET_ERROR)
    {
        if(WSAGetLastError()==WSAETIMEDOUT)
        {
            cout<<"Request timeout\n";
        }
    }
    analize(bf,&out_);
    memset(bf,0,0);
delete [] Icmp;
closesocket(listn);
WSACleanup();
return 0;
}
