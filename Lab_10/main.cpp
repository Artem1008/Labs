/* ������ୠ� ࠡ�� �10
 * �� ⥬�: ��᫥������� � �++ ��������筮��, �訡��, �⫠��� ������ ���� � IDE Qt Creator?
 * ���� ࠡ���:
 * 1. ���९��� �� �ࠪ⨪� �।�⠢����� � �ﬡ�� ��ࠦ�����, ��᫥������� � ����㠫��� �㭪���.
 * 2. �������� ᮧ������ �ணࠬ�� � �++ � �ᯮ�짮������ ��� ��ࠤ���.
 * Developer Zvorygin Artem
*/
#include  "main.h"
enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5, Task_6};
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
    else if constexpr (progrEnum == ProgrEnum::Task_6) {
        task6();
    }
    else {
        // doError();
    }
}
