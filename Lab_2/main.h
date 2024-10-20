#ifndef MAIN_H
#define MAIN_H
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <limits>
#include <bitset>

/**
* @brief Функция Запроса данных
*/
int RequestData(std::map<std::string, int> &data);
int RequestData(std::vector<int> &data);
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

/**
* @brief Функция определения количества значащих цифр
* @param число
*/
int SeekSignificantNumbers(std::string Value);

#endif // MAIN_H
