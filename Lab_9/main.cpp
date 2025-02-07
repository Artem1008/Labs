/* Лабораторная работа №8
 * на тему: Исследование в С++ многопоточности, ошибок, отладки блоков кода в IDE Qt Creator?
 * Цели работы:
 * 1. Закрепить на практике представление о стандартной библиотеки шаблонов (STL), перегрузка операторов.
 * 2. Научиться создавать программу с использованием библиотечных функций STL и перегружать операторы для собственных объектов С++.
 * Developer Zvorygin Artem
*/
#include  "main.h"
enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5};
const ProgrEnum progrEnum = ProgrEnum::Task_1;

int main() {
    if constexpr (progrEnum== ProgrEnum::Task_1) {
         task1();
    }
    else if constexpr (progrEnum == ProgrEnum::Task_2) {
        task2();
    }
    else if constexpr (progrEnum == ProgrEnum::Task_3) {
        task3();
    }
    else if constexpr (progrEnum == ProgrEnum::Task_4) {
        task3();
    }
    else if constexpr (progrEnum == ProgrEnum::Task_5) {
        task3();
    }
    else {
        // doError();
    }
}
