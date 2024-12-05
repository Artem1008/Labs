#include "palindrom.h"

Palindrom::Palindrom()
{

}
void Palindrom::setStr(QString _Str)
{
    Str=_Str.remove(' ').remove(',').toLower();
}
bool Palindrom::CheckPalindrom()
{
    int length=Str.length();
    if (length==0) return false;
    for(int i=0;i<length;i++)
    {
        if (Str[i]!=Str[length-1-i]) return false;
    }
    return true;
}


