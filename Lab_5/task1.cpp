#include "main.h"

void task1(int i)
{
 printf("адрес функции task1 0x%08x\n",reinterpret_cast<void*>(task1));
 printf("адрес переменной созданной в стэке 0x%08x\n",&i);
}
