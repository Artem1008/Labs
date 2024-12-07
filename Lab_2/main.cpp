/* Лабораторная работа №2
 * на тему: “Исследование типов данных, лексем в IDE (интегрированной среде разработки) QtCreator”
 * Цель работы:
 * 1. Продолжаем знакомство с IDE Qt Creator. Научится создавать консольное и Qt Widget приложения.
 * 2. Познакомиться и реализовать ввод-вывод типов данных с помощью стандартной библиотеки С++
 * 3. Исследование основными типами данных, преобразование типов данных.
 * Developer Zvorygin Artem
*/
    
#include "main.h"
#define TASK 1

using namespace std;

int main()
{
    //Задание 1
#if(TASK==1)
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
#if(TASK==2)
    cout<<"char: "<<sizeof(char)<<" bytes\n";
    cout<<"int: "<<sizeof(int)<<" bytes\n";
    cout<<"float: "<<sizeof(float)<<" bytes\n";
    cout<<"bool: "<<sizeof(bool)<<" bytes\n";
    cout<<"unsigned char: "<<sizeof(unsigned char)<<" bytes\n";
    cout<<"short: "<<sizeof(short)<<" bytes\n";
    cout<<"signed short int: "<<sizeof(signed short int)<<" bytes\n";
    cout<<"unsigned short int: "<<sizeof(unsigned short int)<<" bytes\n";
    cout<<"long: "<<sizeof(long)<<" bytes\n";
    cout<<"unsigned long: "<<sizeof(unsigned long)<<" bytes\n";
    cout<<"unsigned int: "<<sizeof(unsigned int)<<" bytes\n";
    cout<<"double: "<<sizeof(double)<<" bytes\n";
    cout<<"long double: "<<sizeof(long double)<<" bytes\n";
    cout<<"long long: "<<sizeof(long long)<<" bytes\n";

    cout<<"Числовой диапазон int: от "<<hex<<INT_MAX<<" "<<dec<<INT_MAX<<" "<<bitset<sizeof(INT_MAX)*8>(INT_MAX)<<" до "<<hex<<INT_MIN<<" "<<dec<<INT_MIN<<" "<<bitset<sizeof(INT_MIN)*8>(INT_MIN)<<"\n";
    cout<<"Числовой диапазон char: от "<<hex<<SCHAR_MAX<<" "<<dec<<SCHAR_MAX<<" "<<bitset<sizeof(SCHAR_MAX)*8>(SCHAR_MAX)<<" до "<<hex<<SCHAR_MIN<<" "<<dec<<SCHAR_MIN<<" "<<bitset<sizeof(SCHAR_MIN)*8>(SCHAR_MIN)<<"\n";
    cout<<"Числовой диапазон short: от "<<hex<<SHRT_MAX<<" "<<dec<<SHRT_MAX<<" "<<bitset<sizeof(SHRT_MAX)*8>(SHRT_MAX)<<" до "<<hex<<SHRT_MIN<<" "<<dec<<SHRT_MIN<<" "<<bitset<sizeof(SHRT_MIN)*8>(SHRT_MIN)<<"\n";
    cout<<"Числовой диапазон long: от "<<hex<<LONG_MAX<<" "<<dec<<LONG_MAX<<" "<<bitset<sizeof(LONG_MAX)*8>(LONG_MAX)<<" до "<<hex<<LONG_MIN<<" "<<dec<<LONG_MIN<<" "<<bitset<sizeof(LONG_MIN)*8>(LONG_MIN)<<"\n";
    cout<<"Числовой диапазон long long: от "<<hex<<LONG_LONG_MAX<<" "<<dec<<LONG_LONG_MAX<<" "<<bitset<sizeof(LONG_LONG_MAX)*8>(LONG_LONG_MAX)<<" до "<< hex <<LONG_LONG_MIN <<" "<<dec<<LONG_LONG_MIN<<" "<<bitset<sizeof(LONG_LONG_MIN)*8>(LONG_LONG_MIN)<<"\n";
#endif
    //Задание 3
#if(TASK==3)
    const int count=10;
    float Numbers;
    double Sum;
    cout<<"Введите 10 чисел с плавающей точкой: "<<"\n";
    for(int i=0;i<count;i++)
    {
        if(ChekValue(Numbers)==-1) return -1;
        Sum=Sum+Numbers;
    }
    cout<<"Среднее арифметическое: "<<Sum/count;
#endif
    //Задание 4
#if (TASK==4)
    vector<string> Numbers{"34.50","0.004000","123.005","146000"};
    for(auto i:Numbers)
    {
        cout<<scientific<<stof(i)<<"; Значащих цифр: "<<SeekSignificantNumbers(i)<<"\n";
    }
#endif
    //Задание 5
#if(TASK==5)
    cout<<"1)\n";
    cout<<"(true && true) || false Ответ: "<<boolalpha<<((true && true)||false)<<"\n";
    cout<<"(false && true) || true Ответ: "<<boolalpha<<((false && true)||true)<<"\n";
    cout<<"(false && true) || false || true Ответ: "<<boolalpha<<((false && true)||false||true)<<"\n";
    cout<<"(5 > 6 || 4 > 3) && (7 > 8) Ответ: "<<boolalpha<<((5>6||4>3)&&(7>8))<<"\n";
    cout<<"!(7 > 6 || 3 > 4) Ответ:"<<boolalpha<<!(7>6||3>4)<<"\n";
    cout<<"2)\n";
    const bool b1=true,b2=false,b3=false,b4=true;
    constexpr bool b5(b1&b3), b6(b3|b4);
    enum iEnum
    {
        ONE=1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX
    };
    cout<<"( b1 && b2 ) || ( !b5) && ( b3 || b4 ) Ответ: "<<boolalpha<<((b1&&b2)||(!b5)&&(b3||b4))<<"\n";
    cout<<"( b3 && b5 ) || ( b6 && b2 ) || ( !b1) Ответ: "<<boolalpha<<((b3&&b5 )||(b6&&b2)||(!b1))<<"\n";
    cout<<"(b6 || b5) && (b4 || b3) && (b2 || b1) Ответ:"<<boolalpha<<((b6||b5)&&(b4||b3)&&(b2||b1))<<"\n";
    cout<<"((SIX >FOUR) && (TWO<ONE) && (FIVE!=THREE)) Ответ: "<<boolalpha<<((SIX>FOUR)&&(TWO<ONE)&&(FIVE!=THREE))<<"\n";
    cout<<"3)\n";
    bool a=true,b=false;
    cout<<"не (true и false) = (не true) или (не false) Ответ: "<<!(a&&b)<<"="<<((!a)||(!b))<<"\n";
    cout<<"не (true или false) = (не true) и (не false) Ответ: "<<!(a||b)<<"="<<((!a)&&(!b))<<"\n";
    cout<<"4)\n";
    vector<int> xyzv;
    bool LogicValue;
    RequestData(xyzv);
    cout<<"x = 3 + 4 + 5 Ответ: "<<(xyzv[1]= (3+4+5))<<"\n";
    cout<<"x = y = z Ответ: "<<(xyzv[1]= xyzv[2]=xyzv[3])<<"\n";
    cout<<"z *= ++y + 5 Ответ: "<<(xyzv[3]*=++xyzv[2]+5)<<"\n";
    cout<<"x = "<<xyzv[1]<<"; y = "<<xyzv[2]<<"; z = "<<xyzv[3]<<"; v = "<<xyzv[4]<<"\n";
    cout<<"logicValue = x || y && z || v Ответ: "<<(LogicValue=(xyzv[1]||xyzv[2]&&xyzv[3]||xyzv[4]))<<"\n";
    cout<<"5)\n";
    unsigned short Number;
    unsigned short Shift;
    cout<<"Если вы ещё не заколебались вводить данные, то введите число от 0 до 2^4"<<"\n";
    ChekValue(Number);
    cout<<"На сколько бит сдвинуть данное чило в лево?: "<<"\n";
     ChekValue(Shift);
     if(Number>16)
     {
        cout<<"Ну больше и болше, в ТЗ не сказано что делать если больше"<<"\n";
     }
     else if(Shift>8)
     {
         cout<<"Слишкои далеко двигаем: "<<"\n";
     }
     else
     {
         Number=Number<<Shift;
          cout<<"Результат:"<<" "<<dec<<Number<<" "<<bitset<sizeof(Number)*8>(Number)<<" "<<hex<<Number<<" "<<oct<<Number<<"\n";
     }
     cout<<"6)\n";
     int res;
     int a1=10,a2=20;
     cout<<"res = a + b * 1 – 128/5 Ответ:"<<(res=a1+a2*1-128/5)<<"\n";
     cout<<"res = a | b >> 1 Ответ:"<<(res=a1|a2>>1)<<"\n";
     cout<<"res=a/b*k Ответ:"<<(res=a1|a2>>1)<<"\n";

#endif
}

int SeekSignificantNumbers(string Value)
{
    int countNumbers=0;
    bool FirstZero=true;
    for(auto var:Value)
    {
        if(var!='0'||FirstZero==false)
        {
            if (var!='.')
            {
                FirstZero=false;
                countNumbers++;
            }
        }
    }
    return countNumbers;
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
    data["sex"]=bValue;
    return 1;
}
int RequestData(vector<int> &data)
{
    int iValue;
    cout<<"Введите число x:";
    if(ChekValue(iValue)==-1) return -1;
    data.push_back(iValue);
    cout<<"Введите число y:";
    if(ChekValue(iValue)==-1) return -1;
    data.push_back(iValue);
    cout<<"Введите число z:";
    if(ChekValue(iValue)==-1) return -1;
    data.push_back(iValue);
    cout<<"Введите число v:";
    if(ChekValue(iValue)==-1) return -1;
    data.push_back(iValue);
    return 1;
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        cin>>Value;
        cin.ignore(32767,'\n');
        if(cin.fail())
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
    if(sex) ss<<(height-100)*0.9;
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
        if(age>=19&&age<=24) ss<<(pow((float)heigh/100,2)*21.4);
        else if(age>=25&&age<=34) ss<<(pow((float)heigh/100,2)*21.6);
        else if(age>=35&&age<=44) ss<<(pow((float)heigh/100,2)*22.9);
        else if(age>=45&&age<=54) ss<<(pow((float)heigh/100,2)*25.8);
        else if(age>55) ss<<(pow((float)heigh/100,2)*26.6);
        else  ss<<"Иди учи уроки";
    }
    else
    {
        if(age>=19&&age<=24) ss<<(pow((float)heigh/100,2)*19.5);
        else if(age>=25&&age<=34) ss<<(pow((float)heigh/100,2)*23.2);
        else if(age>=35&&age<=44) ss<<(pow((float)heigh/100,2)*23.4);
        else if(age>=45&&age<=54) ss<<(pow((float)heigh/100,2)*25.2);
        else if(age>55) ss<<(pow((float)heigh/100,2)*27.3);
        else ss<<"Иди учи уроки";
    }
    rezult=ss.str();
}
