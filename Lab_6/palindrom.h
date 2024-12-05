#ifndef PALINDROM_H
#define PALINDROM_H
#include <QString>

class Palindrom
{
private:
    QString Str;

public:
    Palindrom();
    bool CheckPalindrom();
    QString getStr(){return Str;}
    void setStr(QString _Str);
};

#endif // PALINDROM_H
