/* ������ୠ� ࠡ�� �11
 * �� ⥬�:��᫥������� � �++ �६���, r-value ��뫮�, smart-㪠��⥫��,�᭮���� ����� � IDE Qt Creator
 * ���� ࠡ���:
 * 1. ���९��� �� �ࠪ⨪� ࠡ��� � �६����, r-value ��뫪���.
 * 2. �������� ᮧ������ �ணࠬ�� � �++ � �ᯮ�짮������ smart-㪠��⥫��.
 * Developer Zvorygin Artem
*/
#include  "main.h"
enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5};
const ProgrEnum progrEnum = ProgrEnum::Task_2;

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
        task4();
    }
    else if constexpr (progrEnum == ProgrEnum::Task_5) {
        task5();
    }
    else {
        // doError();
    }
}
