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
* @brief Функция выделения памяти
*/
template<typename T>
void AccumMem(T* &pArr,int size);
/**
* @brief Функция очистки памяти
*/
template<typename T>
void FreeMem(T* &pArr);
/**
* @brief Функция Пирамидальной сортировки
*/
template<typename T>
void PyramidSort(T*,int);
/**
* @brief Функция сборки убывающей кучи
*/
template<typename T>
void heapify(T* , int, int);
/**
* @brief Функция проверки элементов
*/
template<typename T>
void ChekPyramidSort(T*,int,int);
/**
* @brief Функция сортировки методом перебора
*/
template<typename T>
void EnumerationSort(T*,int);
/**
* @brief Функция поиска наименьшего элемента
*/
template<typename T>
int LookLittle(T* pArr,int start, int size);
/**
* @brief Функция сортировки методом пузырька
*/
template<typename T>
void BubbleSort(T*,int);
/**
* @brief Функция запуска юыстрой сортировки
*/
template<typename T>
void FirsStart(T* pArr,int size);
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
* @brief Функция генерации случаных чисел
*/
template<typename T>
void GeneralValue(T* &pArr,int size);
/**
* @brief Функция печати массива
*/
template<typename T>
void PrintArray(T* pArr,int size);
#endif // MAIN_H
