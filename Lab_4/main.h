#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <random>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <functional>

#define MAX  SeekMax
#define MIN  SeekMin

/**
* @brief Функция проверки ввода
*/
template<typename T>
int ChekValue(T &Value);
/**
* @brief Функция операций над массивами
*/
template<typename T>
T operation(T(*)(T[], int), T[], int);
/**
* @brief Функция определения минимума
*/
template<typename T>
T SeekMin(T mass[] ,int size);
/**
* @brief Функция определения максиммума
*/
template<typename T>
T SeekMax(T mass[] ,int size);
/**
* @brief Функция для рекурсивного вычисления факториала
*/
int CalcFactorialRecursion(int number);
/**
* @brief Функция для итерационного вычисления факториала
*/
int CalcFactorialIteration(int number);
/**
* @brief Функция выводит пирамиду
*/
void CalcPiramida(int sum,int CountString,int number=1);
/**
* @brief Функция подсчета количества строк
*/
int CalcString(int sum);
/**
* @brief Функция для вычисления последовательности Фибоначчи
*/
void CalcFibonachi(int number);
/**
* @brief Функция для первого задания
*/
void task1();
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
int task4();
/**
* @brief Функция для пятого задания
*/
int task5();
/**
* @brief Функция для шестого задания
*/
int task6();
/**
* @brief Функция для седьмого задания
*/
int task7();
/**
* @brief Функция для восьмого задания
*/
int task8();
/**
* @brief Функция для девятого задания
*/
int task9();
/**
* @brief Функция запроса типа
*/
void InputType(int &type);
/**
* @brief Функция запроса размера
*/
void InputSize(int & size);
/**
* @brief Функция запроса размера
*/
template<typename T>
void CreateArray(T* &pArr,int size);
/**
* @brief Функция быстрой сортировки
*/
template<typename T>
void Quicksort(T* pArr,int begin, int end);
/**
* @brief Функция разбиения массива для быстрой сортировки
*/
template<typename T>
int Partition(T* pArr,int begin, int end);
/**
* @brief Функция подсчета числа комбинаций
*/
int CalcCombination(int,int);
/**
* @brief Функция операций с переменными
*/
int LogicOperation(std::function<int(int, int)> pfcn,int a1,int a2);
/**
* @brief Шаблон функции И
*/
int AND(int a1 ,int a2);
/**
* @brief Шаблон функции ИЛИ
*/
int OR(int a1 ,int a2);
/**
* @brief Шаблон функции  XOR
*/
int XOR(int a1 ,int a2);
/**
* @brief Шаблон Замены четного на нечетное значение
*/
void FuncSwap(char* &pArr,int size);
#endif // MAIN_H
