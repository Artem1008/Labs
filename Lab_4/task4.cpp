#include "main.h"

int task4()
{
    int number;
    printf("������ �᫮ ��� ���ண� ����室��� ���᫨�� 䠪�ਠ�:\n");
    if(ChekValue(number)==-1) return -1;
    printf("����ਠ� %d ��⮤�� ४��ᨨ = %d\n",number,CalcFactorialRecursion(number));
    printf("����ਠ� %d ��⮤�� ���樨 = %d\n",number,CalcFactorialIteration(number));
    printf("������ ����� ��᫥����⥫쭮�� ��������:\n");
    if(ChekValue(number)==-1) return -1;
    CalcFibonachi(number);
    int sum;
    printf("������ �㬬� �᭮����� ��ࠬ���:\n");
    if(ChekValue(sum)==-1) return -1;
    int CountString=CalcString(sum);
    CalcPiramida(sum,CountString);
}
int CalcFactorialRecursion(int number)
{
    if(number>1) return number*CalcFactorialRecursion(number-1);
    else return number;
}
int CalcFactorialIteration(int number)
{
    int rezult=1;
    for(;1<number;number--)
    {
        rezult*=number;
    }
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"�� ����� ����४⭮� ���祭��\n";
        }
        else return 1;
    }
    std::cout<<"�ਢ�襭� �᫮ ����⮪ ����� ������\n";
    return -1;
}
void CalcFibonachi(int number)
{
    if (number<1)
    {
        printf("0");
        return;
    }
    int temp;
    int num[2]={0,1};
    for(;0<number;number--)
    {
        temp=num[0];
        printf("%d ",temp);
        num[0]=num[1];
        num[1]=temp+num[1];
    }
}
void CalcPiramida(int sum,int CountString,int number)
{
    std::stringstream ss;
    int rezult=0;
    int temp=number;
    for(;temp>0;temp--)
    {
        ss<<temp<<" ";
        rezult+=temp;
    }
    if (rezult<=sum)
    {
        if (number>9&&CountString>=1) --CountString;
        if (CountString==0) std::cout<<ss.str()<<"  "<<rezult<<"\n";
        else  std::cout<<std::string(CountString, ' ')<<ss.str()<<"  "<<rezult<<"\n";
        CalcPiramida(sum,--CountString,++number);
    }
}
int CalcString(int sum)
{
    int temp=0;
    int CountString=0;
    while(temp<sum)
    {
        temp+=CountString+1;
        if(CountString>10)  CountString+=2;
        else CountString++;
    }
    return CountString;
}
