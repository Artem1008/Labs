#ifndef MAIN_H
#define MAIN_H
#include <iostream>


/**
* @brief Функция для первого задания
*/
void task1(int i);
/**
* @brief Функция для второго задания
*/
void task2();
/**
* @brief Функция для третьего задания
*/
void task3();
/**
* @brief Функция для четвертого задания
*/
void task4();
/**
* @brief Функция для пятого задания
*/
void task5();
/**
* @brief Функция для шестого задания
*/
void task6();
/**
* @brief Функция для седьмого задания
*/
void task7();
/**
* @brief Функция для восьмого задания
*/
void task8();
/**
* @brief Функция сортировки массива строк
*/
int SortSting(char ch[] ,int line);
/**
* @brief Функция вывода массива строк
*/
void PrintfSting(const char ch[] ,int line);
/**
* @brief Функция проверки ввода
*/
template<typename T>
int ChekValue(T &Value);
/**
* @brief Функция сортировки по длинне
*/
void SortLength(char ch[] ,int line);
/**
* @brief Функция сортировки по алфавиту
*/
void SortABC(char ch[] ,int line);
/**
* @brief Функция поиска наименьшего элемента
*/
int LookLittleLength(char ch[],int start, int size);
/**
* @brief Функция поиска наименьшего элемента
*/
int LookLittleABC(char ch[],int start, int size);
/**
* @brief Функция обмена местами
*/
void CharSwap(char* ch1,int begin,int end);
/**
* @brief Функция перевода числа в строку
*/
std::string IntToString(int);
/**
* @brief Функция перевода строки в число
*/
int StringToInt(std::string );
#endif // MAIN_H
