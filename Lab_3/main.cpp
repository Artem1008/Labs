#include "main.h"

//TASK опредёлен в pro иначе жалуется "macro name missing"
static int var{12};

int main()
{
#if (TASK==1)
    cout << "Задание 1" <<"\n";
    task1();
#endif
#if (TASK==2)
    cout << "Задание 2" <<"\n";
    printChar();
    printChar('q');
    printChar('q','w');
    printChar('q','w','e');
    printChar('q','w','e','r');
#endif
#if (TASK==3)
    cout << "Задание 3"<<"\n";
    cout<<Initialization()<<'\n';
    int var=33;
    cout<<"Глобальная - "<<::var<<"; Локальная - "<<var;
#endif
#if (TASK==4)
    std::cout << "Задание 4" <<"\n";
    Animal zoo=goat;
    getAnimalName(zoo);
    printNumberOfLegs(zoo);
#endif
#if (TASK==5)
    std::cout << "Задание 5" <<"\n";
    std::cout <<"Введите 3 числа:\n";
    int v[3];
    ChekValue(v,3);
    std::cout << "Максимум : "<<SeekMax(v[0],v[1],v[2])<<'\n';
    std::cout << "Минимум : "<<SeekMin(v[0],v[1],v[2])<<'\n';
#endif
#if (TASK==6)
    std::cout << "Задание 6" <<"\n";
    task6();
#endif
#if (TASK==7)
    std::cout << "Задание 7" <<"\n";
    task7();
#endif
}
template<typename T>
int ChekValue(T &Value,int L)
{
    for(int i=0;i<L;i++)
    {
        cin>>Value[i];
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<" Некорректное значение\n";
            i=-1;
        }
    }
    return 1;
}
