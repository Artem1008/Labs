/* ������ୠ� ࠡ�� �8
 * �� ⥬�: ��᫥������� � �++ ��������筮��, �訡��, �⫠��� ������ ���� � IDE Qt Creator?
 * ���� ࠡ���:
 * 1. ���९��� �� �ࠪ⨪� �।�⠢����� � �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢.
 * 2. �������� ᮧ������ �ணࠬ�� � �ᯮ�짮������ ���������� �㭪権 STL � ��ॣ�㦠�� ������� ��� ᮡ�⢥���� ��ꥪ⮢ �++.
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
