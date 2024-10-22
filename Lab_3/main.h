#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;
enum Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog
};
enum Levels
{
    garage,
    hol,
    casino,
    restaurant,
    pool,
    bar,
    cafe
};
/**
* @brief �㭪�� ��� ��ࢮ�� �������
*/
void task1();
/**
* @brief �㭪�� ��� ��⮣� �������
*/
void task6();
/**
* @brief �㭪�� ��� ᥤ쬮�� �������
*/
void task7();
/**
* @brief �㭪�� ��� ��ண� �������
*/
void printChar(int a='a', char b='b',char c='c', char d='d');
/**
* @brief �㭪�� ���樠����樨
*/
auto Initialization()->int;
/**
* @brief �㭪�� �뢮�� �������� ����⭮��
*/
void getAnimalName(Animal &data);
/**
* @brief �㭪�� �뢮�� ������⢠ ���
*/
void printNumberOfLegs(Animal &data);
/**
* @brief �㭪�� �஢�ન �����
*/
template<typename T>
int ChekValue(T &Value,int L);
int ChekValue();
/**
* @brief �㭪�� ��宦����� ���ᨬ㬠
*/
int SeekMin(int var1,int var2);
int SeekMin(unsigned short var1,unsigned short var2);
int SeekMin(int var1,int var2,int var3);
/**
* @brief �㭪�� ��宦����� �����㬠
*/
int SeekMax(int var1,int var2);
int SeekMax(unsigned short var1,unsigned short var2);
int SeekMax(int var1,int var2,int var3);
#endif // MAIN_H
