#ifndef MAIN_H
#define MAIN_H
#include <iostream>

/**
* @brief �㭪�� ��� ��ࢮ�� �������
*/
void task1(int i);
/**
* @brief �㭪�� ��� ��ண� �������
*/
void task2();
/**
* @brief �㭪�� ��� ���쥣� �������
*/
void task3();
/**
* @brief �㭪�� ��� ���쥣� �������
*/
void task3_1();
/**
* @brief �㭪�� ��� �⢥�⮣� �������
*/
void task4();
/**
* @brief �㭪�� ��� ��⮣� �������
*/
void task5();
/**
* @brief �㭪�� ��� ��⮣� �������
*/
void task6();
/**
* @brief �㭪�� ���஢�� ���ᨢ� ��ப
*/
int SortSting(char ch[] ,int line);
/**
* @brief �㭪�� �뢮�� ���ᨢ� ��ப
*/
void PrintfSting(const char ch[] ,int line);
/**
* @brief �㭪�� �஢�ન �����
*/
template<typename T>
int ChekValue(T &Value);
/**
* @brief �㭪�� ���஢�� �� ������
*/
void SortLength(char ch[] ,int line);
/**
* @brief �㭪�� ���஢�� �� ��䠢���
*/
void SortABC(char ch[] ,int line);
/**
* @brief �㭪�� ���᪠ �������襣� �����
*/
int LookLittleLength(char ch[],int start, int size);
/**
* @brief �㭪�� ���᪠ �������襣� �����
*/
int LookLittleABC(char ch[],int start, int size);
/**
* @brief �㭪�� ������ ���⠬�
*/
void CharSwap(char* ch1,int begin,int end);
#endif // MAIN_H
