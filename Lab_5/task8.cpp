#include "main.h"
#include <string>
#include<bitset>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void Parse(const std::string& line, Address* const address)
{
    std::bitset <4> bitflags;
    std::string temp2;
    char temp;
    int Pos=0;
    for(int i=0;i<=(int)line.length();i++)
    {
        temp=line[i];
        if (line[i]==' '||line[i]=='\0')
        {
            switch (bitflags.to_ulong())
            {
            case 0:
                temp2=line.substr(Pos,i-Pos);
                address->Country=line.substr(Pos,i-Pos-1);
                Pos=i+1;
                bitflags[0]=1;
                break;
            case 1:
                temp2=line.substr(Pos,i-Pos);
                if(temp2!="г.")
                {
                    address->City=line.substr(Pos,i-Pos-1);
                    Pos=i+1;
                    bitflags[1]=1;
                }
                else
                {
                    Pos=i+1;
                }
                break;
            case 3:
                temp2=line.substr(Pos,i-Pos);
                if(temp2!="ул.")
                {
                    address->Street=line.substr(Pos,i-Pos-1);
                    Pos=i+1;
                    bitflags[2]=1;
                }
                else
                {
                    Pos=i+1;
                }
                break;
            case 7:
                temp2=line.substr(Pos,i-Pos);
                address->House=line.substr(Pos,i-Pos);
                Pos=i+1;
                bitflags[3]=1;
                break;
            }
        }
    }

}
std::string Format(const Address& address)
{
    return  address.Country+", город "+address.City+", улица "+address.Street+", дом "+address.House;
}

void task8()
{
    // Россия, г. Томск, ул. Кирова 43
    std::string line;
    Address* address=new Address;
    getline(std::cin, line);
    Parse(line, address);
    //Unify(address);
    std::cout << Format(*address) << "\n";
}
