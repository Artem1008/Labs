#include "main.h"
static int sa2;
static int sa3=1;
static int array2[] {1,2,3,4};
int main()
{
#if(TASK==1)
    int a1=10;
    int array[] {1,2,3,4};
    std::cout<< "Задание 1:"<<'\n';
    printf("адрес функции main 0x%08x\n",reinterpret_cast<void*>(main));
    task1(a1);
    printf("адрес переменной созданной в стэке 0x%08x\n",&a1);
    for(int i=0;i<=sizeof (array)/sizeof (*array);i++)
    {
        printf("aдpecа и значения элементов массива созданного в стэке 0x%08x\n",(array+i));
    }
    printf("адрес переменной в статической памяти в секции .bss 0x%08x\n",&sa2);
    printf("адрес переменной в статической памяти в секции .data 0x%08x\n",&sa3);
    for(int i=0;i<=sizeof (array2)/sizeof (*array2);i++)
    {
     printf("адpecа и значения элементов массива созданного в статической памяти 0x%08x\n",(array2+i));
    }
    int* a4=new int;
    printf("адрес переменной созданной в куче 0x%08x\n",a4);
    int* array3=new  int[4]{1,2,3,4};
    for(int i=0;i<=3;i++)
    {
    printf("aдpecа и значения элементов массива созданного в куче 0x%08x\n",(array3+i));
    }
#endif
#if(TASK==2)
    std::cout<< "Задание 2:"<<'\n';
    task2();
#endif
#if(TASK==3)
    std::cout<< "Задание 3:"<<'\n';
    task3();
#endif
#if(TASK==4)
    std::cout<< "Задание 4:"<<'\n';
    task4();
#endif
#if(TASK==5)
    std::cout<< "Задание 5:"<<'\n';
    task5();
#endif
#if(TASK==6)
    std::cout<< "Задание 6:"<<'\n';
    task6();
#endif
#if(TASK==7)
    std::cout<< "Задание 7:"<<'\n';
    task7();
#endif
#if(TASK==8)
    std::cout<< "Задание 8:"<<'\n';
    task8();
#endif
}
