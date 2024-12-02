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
