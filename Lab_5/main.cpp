#include "main.h"
static int sa2;
static int sa3=1;
static int array2[] {1,2,3,4};
int main()
{
#if(TASK==1)
    int a1=10;
    int array[] {1,2,3,4};
    std::cout<< "������� 1:"<<'\n';
    printf("���� �㭪樨 main 0x%08x\n",reinterpret_cast<void*>(main));
    task1(a1);
    printf("���� ��६����� ᮧ������ � ��� 0x%08x\n",&a1);
    for(int i=0;i<=sizeof (array)/sizeof (*array);i++)
    {
        printf("a�pec� � ���祭�� ����⮢ ���ᨢ� ᮧ������� � ��� 0x%08x\n",(array+i));
    }
    printf("���� ��६����� � ����᪮� ����� � ᥪ樨 .bss 0x%08x\n",&sa2);
    printf("���� ��६����� � ����᪮� ����� � ᥪ樨 .data 0x%08x\n",&sa3);
    for(int i=0;i<=sizeof (array2)/sizeof (*array2);i++)
    {
     printf("��pec� � ���祭�� ����⮢ ���ᨢ� ᮧ������� � ����᪮� ����� 0x%08x\n",(array2+i));
    }
    int* a4=new int;
    printf("���� ��६����� ᮧ������ � ��� 0x%08x\n",a4);
    int* array3=new  int[4]{1,2,3,4};
    for(int i=0;i<=3;i++)
    {
    printf("a�pec� � ���祭�� ����⮢ ���ᨢ� ᮧ������� � ��� 0x%08x\n",(array3+i));
    }
#endif
#if(TASK==2)
    std::cout<< "������� 2:"<<'\n';
    task2();
#endif
#if(TASK==3)
    std::cout<< "������� 3:"<<'\n';
    task3();
#endif
#if(TASK==31)
    std::cout<< "������� 3:"<<'\n';
    task3_1();
#endif
#if(TASK==4)
    std::cout<< "������� 4:"<<'\n';
    task4();
#endif
#if(TASK==5)
    std::cout<< "������� 5:"<<'\n';
    task5();
#endif
#if(TASK==6)
    std::cout<< "������� 6:"<<'\n';
    task6();
#endif
}
