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
* @brief Функция для первого задания
*/
void task1();
/**
* @brief Функция для шестого задания
*/
void task6();
/**
* @brief Функция для седьмого задания
*/
void task7();
/**
* @brief Функция для второго задания
*/
void printChar(int a='a', char b='b',char c='c', char d='d');
/**
* @brief Функция инициализации
*/
auto Initialization()->int;
/**
* @brief Функция вывода названия животного
*/
void getAnimalName(Animal &data);
/**
* @brief Функция вывода количества лап
*/
void printNumberOfLegs(Animal &data);
/**
* @brief Функция проверки ввода
*/
template<typename T>
int ChekValue(T &Value,int L);
int ChekValue();
/**
* @brief Функция нахождения максимума
*/
int SeekMin(int var1,int var2);
int SeekMin(unsigned short var1,unsigned short var2);
int SeekMin(int var1,int var2,int var3);
/**
* @brief Функция нахождения минимума
*/
int SeekMax(int var1,int var2);
int SeekMax(unsigned short var1,unsigned short var2);
int SeekMax(int var1,int var2,int var3);
#endif // MAIN_H
