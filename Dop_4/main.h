#ifndef MAIN_H
#define MAIN_H
# define MAXVALUE 100
# define MINVALUE 0
#include <iostream>

/**
* @brief Функция запроса типа
*/
void InputType(int &type);
/**
* @brief Функция запроса метода сортировки
*/
void InputSort(int &type);
/**
* @brief Функция запроса размера
*/
void InputSize(int & size);
/**
* @brief Функция проверки ввода
*/
template<typename T>
int ChekValue(T &Value);
/**
* @brief Функция Создания массива
*/
template<typename T>
void CreateArray(T* &pArr,int size);
/**
* @brief Функция быстрой сортировки
*/
template<typename T>
void QuickSort(T* pArr,int begin, int end);
/**
* @brief Функция разбиения массива для быстрой сортировки
*/
template<typename T>
int Partition(T* pArr,int begin, int end);
/**
* @brief Функция Пирамидальной сортировки
*/
template<typename T>
void PyramidSort(T* pArr,int begin, int end);
/**
* @brief Функция сортировки методом перебора
*/
template<typename T>
void EnumerationSort(T* pArr,int begin, int end);
/**
* @brief Функция сортировки методом пузырька
*/
template<typename T>
void BubbleSort(T* pArr,int begin, int end);
/**
* @brief Функция сортировки методом пузырька
*/
template<typename T>
void HaorSort(T* pArr,int begin, int end);
/**
* @brief Функция выбора указателя на функцию
*/
template<typename T>
void(*select(int))(T* ,int,int);
#endif // MAIN_H
