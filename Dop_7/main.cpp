#include <iostream>
#include <stdio.h>
#include <string>
#include  "main.h"

struct ipadr
{
    int a1;
    int a2;
    int a3;
    int a4;
}IpStart,IpStop;

int main()
{
#if(TASK==1)
    std::string str;
    printf("%s","Введите диапозон адресов (172.16.40.1-172.16.40.254):");
    std::getline(std::cin,str);
    sscanf(str.c_str(), "%d.%d.%d.%d-%d.%d.%d.%d", &IpStart.a1, &IpStart.a2, &IpStart.a3,&IpStart.a4,&IpStop.a1, &IpStop.a2, &IpStop.a3,&IpStop.a4);
    int size=IpStop.a4-IpStart.a4;
    //std::thread thread_array[size];
    for(int i=0;i<=size;i++)
    {
       str=std::to_string(IpStart.a1)+'.'+std::to_string(IpStart.a2)+'.'+std::to_string(IpStart.a3)+'.'+std::to_string(IpStart.a4+i);
      // thread_array[i] = std::thread(ping, str.c_str());
       //if (thread_array[i].joinable()) thread_array[i].detach();
       ping(str.c_str());
    }
#endif
    return 0;
 }

