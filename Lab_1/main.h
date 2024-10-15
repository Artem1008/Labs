#ifndef MAIN_H
#define MAIN_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
/**
* @brief Функция вывода титульного листа(Задание 2)
* @param sStudentName Имя студента.
* @param sGroupName Номер группы.
*/
void OutputStr(const std::string sStudentName , const std::string sGroupName );
/**
* @brief Функция вычисления скорости прямолинейного движения(Задание 3)
*/
void CalcSpeed();
/**
* @brief Функция вычисления ускорения(Задание 3)
*/
void CalcBoost();
/**
* @brief Функция вычисления радиуса круга(Задание 3)
*/
void CalcRadius();
/**
* @brief Функция проверки ввода(Задание 3)
*/
template<typename T>
int ChekValue(T &Interval);
/**
* @brief Функция вывода заголовка(Задание 3)
*/
void OutputHeading();
#endif // MAIN_H
