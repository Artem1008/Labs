/* Лабораторная работа №6
 * на тему: “Исследование С++ классов в IDE Qt Creator”
 * Цель работы:
 * 1. Закрепить на практике представление о классах.
 * 2. Научиться инкапсулировать данные в классах языка С++.
 * Developer Zvorygin Artem
*/
#include "mainwindow.h"
#include <QApplication>

extern std::string pass;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;   
    w.show();
    return a.exec();
}
