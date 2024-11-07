/*
Номер группы 317, факультет Доп. Образование
Разработчики программы 1. Артём
Номер Лабораторной работы №1
*/

#include "main.h"
#define SPACING 30

using namespace std;

int main()
{
    string sStudentName="Артём";
    string sGroupName="317";
    int index;
    OutputStr(sStudentName,sGroupName);
    OutputHeading();
    while(true)
    {
        ChekValue(index);
        switch (index)
        {
        case 1:
            CalcSpeed();
            OutputHeading();
            break;
        case 2:
            CalcBoost();
            OutputHeading();
            break;
        case 3:
            CalcRadius();
            OutputHeading();
            break;
        case 9:
            cout<<"До свидания\n";
            return 0;
        default:
            cout<<"Вычисление под данным номером не существует\n";
        }
    }
}
void OutputStr(const string sStudentName, const string sGroupName)
{
    stringstream ss;
    //формируем заголовок
    ss<<"*****"<<setw(SPACING)<<"ТУСУР"<<setw(SPACING)<<"*****"<<endl;
    //вычисляем его длину
    int LengthFirstStr=ss.str().length();
    ss.setf(ios_base::right);
    ss<<setw(LengthFirstStr)<<"Факультет: Доп. Образование\n"<<setw(LengthFirstStr)<<"Группа: "+sGroupName+"\n"<<setw(LengthFirstStr)<<"Студент: "+sStudentName+"\n";
    //TODO сделать что то более красивое
    string FinishStr="Томск 2024";
    ss<<setw((LengthFirstStr-FinishStr.length())/2+FinishStr.length())<<FinishStr<<endl<<endl;
    cout<<ss.str();
}
void OutputHeading()
{
    cout<<"Введите номер требуемого вычисление:\n";
    cout<<"1. Вычисление скорости прямолинейного движения\n";
    cout<<"2. Вычислить ускорение\n";
    cout<<"3. Вычислить радиус круга\n";
    cout<<"9. Выход\n";
}
void CalcSpeed()
{
    float Interval,Time;
    cout<<"Введите значение расстояния:\n";
    if(ChekValue(Interval)==-1) return;
    cout<<"Введите значение времени:\n";
    if(ChekValue(Time)==-1) return;
    cout<<"Скорость прямолинейного движения: "<<Interval*Time<<endl;
}
void CalcBoost()
{
    float BeginSpeed,EndSpeed,Time;
    cout<<"Введите значение начальной скорсти:\n";
    if(ChekValue(BeginSpeed)==-1) return;
    cout<<"Введите значение конечной:\n";
    if(ChekValue(EndSpeed)==-1) return;
    cout<<"Введите время:\n";
    if(ChekValue(Time)==-1) return;
    cout<<"Ускорение: "<<(EndSpeed-BeginSpeed)/Time<<endl;
}
void CalcRadius()
{
    float Circumference;
    cout<<"Введите Длину окружности:\n";
    if(ChekValue(Circumference)==-1) return;
    cout<<"Радиус круга: "<<Circumference/(2*M_PI)<<endl;
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
        else   return 1;
    }
    cout<<"Привышено число попыток ввода данных\n";
    return -1;
}
