#include "main.h"
#include<thread>
#include<chrono>
#include<bitset>

struct ProtData
{
    struct{
        char OldByte;
        int AdressClient;
        int AdressServer;
        unsigned char Flags:4;
    }Header;
    struct {
        unsigned char Status:3;
        int CommandBasis;
        int CommandConfirm;
        long long Reserve;
    }Command;
    union {
        struct {
            unsigned char Status:2;
            uint8_t  Data[2048];
            uint8_t  Reserve[12];
        }ReadData;
        struct
        {
            unsigned char Status:1;
            unsigned char Condition;
            uint8_t Data[2048];
            uint8_t  Reserve[32];
        }WriteData;
        struct {
            uint8_t  Data[24];
        }Reserv;
    }RWData;

    struct {
        int CRC32;
        unsigned char Reserv;
    }Checksum;
unsigned char StopByte;
}MyData;

    void Server()
    {
        while(1)
        {
            std::cout<<"Server\n";
            std::cout<<MyData.Header.AdressClient<<'\n';
            std::cout<<MyData.Header.AdressServer<<'\n';
            std::cout<<MyData.Header.Flags<<'\n';
            std::cout<<MyData.Header.OldByte<<'\n';

            std::cout<<MyData.Command.CommandBasis<<'\n';
            std::cout<<MyData.Command.CommandConfirm<<'\n';
            std::cout<<MyData.Command.Status<<'\n';

            std::cout<<MyData.RWData.ReadData.Data<<'\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    void Client()
    {
        while(1)
        {
            std::cout<<"Client\n";
            MyData.Header.AdressClient=11111;
            MyData.Header.AdressServer=2222;
            MyData.Header.Flags=1;
           MyData.Header.OldByte=200;

            MyData.Command.CommandBasis=3333;
            MyData.Command.CommandConfirm=4444;
            MyData.Command.Status=1;

            MyData.RWData.ReadData.Data;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    };
    void task2()
    {
        std::thread serverthread(Server);
        std::thread clientthread(Client);
        serverthread.join();
        clientthread.join();
    }
