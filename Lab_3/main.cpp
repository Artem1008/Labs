#include "main.h"

//TASK ��।񫥭 � pro ���� ������� "macro name missing"
static int var{12};

int main()
{
#if (TASK==1)
    cout << "������� 1" <<"\n";
    task1();
#endif
#if (TASK==2)
    cout << "������� 2" <<"\n";
    printChar();
    printChar('q');
    printChar('q','w');
    printChar('q','w','e');
    printChar('q','w','e','r');
#endif
#if (TASK==3)
    cout << "������� 3"<<"\n";
    cout<<Initialization()<<'\n';
    int var=33;
    cout<<"������쭠� - "<<::var<<"; �����쭠� - "<<var;
#endif
#if (TASK==4)
    std::cout << "������� 4" <<"\n";
    Animal zoo=goat;
    getAnimalName(zoo);
    printNumberOfLegs(zoo);
#endif
#if (TASK==5)
    std::cout << "������� 5" <<"\n";
    std::cout <<"������ 3 �᫠:\n";
    int v[3];
    ChekValue(v,3);
    std::cout << "���ᨬ� : "<<SeekMax(v[0],v[1],v[2])<<'\n';
    std::cout << "������ : "<<SeekMin(v[0],v[1],v[2])<<'\n';
#endif
#if (TASK==6)
    std::cout << "������� 6" <<"\n";
    task6();
#endif
#if (TASK==7)
    std::cout << "������� 7" <<"\n";
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
            cout<<" �����४⭮� ���祭��\n";
            i=-1;
        }
    }
    return 1;
}
