#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Регистрируем тип
        qRegisterMetaType<BitmapData>("BitmapData");
    MainWindow w;
    w.show();
    return a.exec();
}
