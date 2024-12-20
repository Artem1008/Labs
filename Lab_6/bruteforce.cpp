#include <iostream>
#include <QDebug>
#include "bruteforce.h"
std::string pass="";

int recursFind(std::string str,std::string tempstr,int index,std::string &);
Bruteforce::Bruteforce()
{
    flagNumber=false;
    flagCapital=false;
    flagSymbols=false;
    lengthPass=1;

}
std::string Bruteforce::RunFind()
{
    std::string str=MLETTERS;
    if (flagNumber) str.append(MNUMBER);
    if (flagCapital) str.append(MCAPITAL);
    if (flagSymbols) str.append(MSYMBOL);
    std::string FindPass;
    recursFind("",str,lengthPass,FindPass);
    return FindPass;
}
int recursFind(std::string str,std::string tempstr,int index,std::string &temp)
{
    index--;
    for(int i=0;i<(int)tempstr.length();i++)
    {
        if(index==0)
        {
            if(pass==str+tempstr[i])
            {
                temp=str+tempstr[i];
                return 1 ;
            }
        }
        else
        {
            recursFind(str+tempstr[i],tempstr,index,temp);
            if((int)temp.length()>0)
            {
                return 1;
            }
        }
    }
}
