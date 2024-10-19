#include "main.h"
//укажите номер задания
#define TASK 3
using namespace std;

int main()
{
    //Задание 1
#if  (TASK==1)
    map<std::string, int> UserData;
    string rezult;
    RequestData(UserData);
    cout<<"Подсчет идеального веса\n";
    CalcWeightFunctionBrok(UserData["height"],UserData["sex"],rezult);
    cout<<"a - по формуле Брока: "<<rezult<<"кг\n";
    CalcWeightForIndex(UserData["height"],rezult);
    cout<<"b - по индексу массы тела: "<<rezult<<"кг\n";
    CalcWeightForIndexAndAge(UserData["height"],UserData["age"],UserData["sex"],rezult);
    cout<<"с - по индексу массы тела с учетом возраста: "<<rezult<<"кг\n";
#endif
    //Задание 2
#if (TASK==2)
    cout<<"char: "<< sizeof(char) <<" bytes\n";
    cout<<"int: "<< sizeof(int) <<" bytes\n";
    cout<<"float: "<< sizeof(float) <<" bytes\n";
    cout<<"bool: "<< sizeof(bool) <<" bytes\n";
    cout<<"unsigned char: "<< sizeof(unsigned char) <<" bytes\n";
    cout<<"short: "<< sizeof(short) <<" bytes\n";
    cout<<"signed short int: "<< sizeof(signed short int) <<" bytes\n";
    cout<<"unsigned short int: "<< sizeof(unsigned short int) <<" bytes\n";
    cout<<"long: "<< sizeof(long) <<" bytes\n";
    cout<<"unsigned long: "<< sizeof(unsigned long) <<" bytes\n";
    cout<<"unsigned int: "<< sizeof(unsigned int) <<" bytes\n";
    cout<<"double: "<< sizeof(double) <<" bytes\n";
    cout<<"long double: "<< sizeof(long double) <<" bytes\n";
    cout<<"long long: "<< sizeof(long long) <<" bytes\n";

    cout<<"Числовой диапазон int: от "<< hex <<INT_MAX <<" "<<dec<<INT_MAX<<" "<<bitset<sizeof(INT_MAX) * 8>(INT_MAX)<<" до "<< hex <<INT_MIN <<" "<<dec<<INT_MIN<<" "<<bitset<sizeof(INT_MIN) * 8>(INT_MIN)<<"\n";
    cout<<"Числовой диапазон char: от "<< hex <<SCHAR_MAX <<" "<<dec<<SCHAR_MAX<<" "<<bitset<sizeof(SCHAR_MAX) * 8>(SCHAR_MAX)<<" до "<< hex <<SCHAR_MIN <<" "<<dec<<SCHAR_MIN<<" "<<bitset<sizeof(SCHAR_MIN) * 8>(SCHAR_MIN)<<"\n";
    cout<<"Числовой диапазон short: от "<< hex <<SHRT_MAX <<" "<<dec<<SHRT_MAX<<" "<<bitset<sizeof(SHRT_MAX) * 8>(SHRT_MAX)<<" до "<< hex <<SHRT_MIN <<" "<<dec<<SHRT_MIN<<" "<<bitset<sizeof(SHRT_MIN) * 8>(SHRT_MIN)<<"\n";
    cout<<"Числовой диапазон long: от "<< hex <<LONG_MAX <<" "<<dec<<LONG_MAX<<" "<<bitset<sizeof(LONG_MAX) * 8>(LONG_MAX)<<" до "<< hex <<LONG_MIN <<" "<<dec<<LONG_MIN<<" "<<bitset<sizeof(LONG_MIN) * 8>(LONG_MIN)<<"\n";
    cout<<"Числовой диапазон long long: от "<< hex <<LONG_LONG_MAX <<" "<<dec<<LONG_LONG_MAX<<" "<<bitset<sizeof(LONG_LONG_MAX) * 8>(LONG_LONG_MAX)<<" до "<< hex <<LONG_LONG_MIN <<" "<<dec<<LONG_LONG_MIN<<" "<<bitset<sizeof(LONG_LONG_MIN) * 8>(LONG_LONG_MIN)<<"\n";
#endif
    //Задание 3
#if (TASK==3)
    const int count=10;
    float Numbers;
    double Sum;
   cout<<"Введите 10 чисел с плавающей точкой: "<<"\n";
   for  (int i=0;i<count;i++)
   {
        if(ChekValue(Numbers)==-1) return -1;
        Sum=Sum+Numbers;
   }
    cout<<"Среднее арифметическое: "<<Sum/count;
#endif
}
int RequestData(map<std::string, int> &data)
{
    int iValue;
    bool bValue;
    cout<<"Введите возраст:";
    if(ChekValue(iValue)==-1) return -1;
    data["age"]=iValue;
    cout<<"Введите вес:";
    if(ChekValue(iValue)==-1) return -1;
    data["weight"]=iValue;
    cout<<"Введите рост:";
    if(ChekValue(iValue)==-1) return -1;
    data["height"]=iValue;
    cout<<"Если мужчина введите 1, женщина 0:";
    if(ChekValue(bValue)==-1) return -1;
    data["sex"]=bValue;;
}

template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        cin>>Value;
        cin.ignore(32767,'\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<"Вы ввели некоректное значение\n";
        }
        else return 1;
    }
    cout<<"Привышено число попыток ввода данных\n";
    return -1;
}

void CalcWeightFunctionBrok(int height,int sex,string &rezult)
{
    stringstream ss;
    ss.precision(4);
    if (sex)  ss<< (height-100)*0.9;
    else ss<<(height-100)*0.85;
    rezult=ss.str();
}
void CalcWeightForIndex(int heigh,string &rezult)
{
    stringstream ss;
    ss.precision(4);
    float index1=18.5;
    float index2=25;
    ss<<(pow((float)heigh/100,2)*index1)<<" "<<pow((float)heigh/100,2)*index2;
    rezult=ss.str();
}
void CalcWeightForIndexAndAge(int heigh,int age,int sex,string &rezult)
{
    stringstream ss;
    ss.precision(4);
    if(sex)
    {
        if (age>=19&&age<=24)  ss<<(pow((float)heigh/100,2)*21.4);
        else if (age>=25&&age<=34)  ss<<(pow((float)heigh/100,2)*21.6);
        else if (age>=35&&age<=44)  ss<<(pow((float)heigh/100,2)*22.9);
        else if (age>=45&&age<=54)  ss<<(pow((float)heigh/100,2)*25.8);
        else if (age>55)  ss<<(pow((float)heigh/100,2) *26.6);
        else  ss<<"Иди учи уроки";
    }
    else
    {
        if (age>=19&&age<=24)  ss<<(pow((float)heigh/100,2)*19.5);
        else if (age>=25&&age<=34)  ss<<(pow((float)heigh/100,2)*23.2);
        else if (age>=35&&age<=44)  ss<<(pow((float)heigh/100,2)*23.4);
        else if (age>=45&&age<=54)  ss<<(pow((float)heigh/100,2)*25.2);
        else if (age>55)  ss<<(pow((float)heigh/100,2) *27.3);
        else  ss<<"Иди учи уроки";
    }
    rezult=ss.str();
}

