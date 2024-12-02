#include <iostream>
#include "bruteforce.h"
std::string pass="";

Bruteforce::Bruteforce()
{
    flagNumber=false;
    flagCapital=false;
    flagSymbols=false;
    Capital = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    Letters={"abcdefghijklmnopqrstuvwxyz"};
    Number={"0123456789"};
    Symbols={"!\"ü;%:?*()~.,/|\\"};
}
std::string Bruteforce::RunFind()
{
    std::string rezul;
    std::string str=Letters;
    std::cout<<Capital<<'n';

    //   if (flagNumber) str.append(Number);
    if (flagCapital) str.append(Capital);
    //   if (flagSymbols) str.append(Symbols);
    /*   while(1)
    {
        if (pass==rezul)return rezul;
    }*/
}
