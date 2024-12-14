#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<thread>
#include "bruteforce.h"
#include "palindrom.h"
#include "complex.h"
#include "depomodel.h"
#include "comboboxdelegat.h"


enum ComplexType
{
    Arefmic=1,
    Trigonometric,
    Exp,
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void InitDepo();
    ~MainWindow();
     QVector<Flight> myFlights;

private slots:

    void on_SymbolsBox_clicked(bool checked);

    void on_numberBox_clicked(bool checked);

    void on_CapitalBox_clicked(bool checked);

    void on_UserPass_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void SimFlights();
private:
    Bruteforce myFind;
    ComplexType VeiwType=Arefmic;
    Complex<int> *myComplex1;
    Complex<int> *myComplex2;
    Complex<int> *rezult;
    QChar operation;
    Palindrom myPalindrom;
    Ui::MainWindow *ui;
    Dispatcher* myDisp =new Dispatcher("Умывальников начальник");
    QVector<Driver> myDrivers
    {
        {"Водитель 1"},
        {"Водитель 2"},
        {"Водитель 3"}
    };
    QVector<Car> myCar
    {
        {333,"Камаз"},
        {4444,"Газель"},
        {555,"Каблук"}
    };
};
#endif // MAINWINDOW_H
