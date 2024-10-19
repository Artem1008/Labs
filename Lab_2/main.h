#ifndef MAIN_H
#define MAIN_H
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
#include <stdio.h>
#include <limits>
#include <bitset>

/**
* @brief Функция Запроса данных
*/
int RequestData(std::map<std::string, int> &data);
/**
* @brief Функция проверки ввода
*/
template<typename T>
int ChekValue(T &Value);

/**
* @brief Функция расчёта веса по формуле Брока
* @param Рост
* @param Пол
*/
void CalcWeightFunctionBrok(int,int,std::string &);

/**
* @brief Функция расчёта веса по индексу массы тела
* @param Рост
*/
void CalcWeightForIndex(int,std::string &);

/**
* @brief Функция расчёта веса по индексу массы тела с учетом возраста
* @param Рост
* @param Возраст
* @param Пол
*/
void CalcWeightForIndexAndAge(int,int,int,std::string &);


#endif // MAIN_H
