#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMap>
#include <thread>
#include "bruteforce.h"
#include "palindrom.h"
#include "complex.h"
#include "dispmodel.h"
#include "comboboxdelegat.h"
#include "drivermodel.h"


enum ComplexType
{
    Arefmic=1,
    Trigonometric,
    Exp,
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//int Flight::Index=1;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void InitDispatcher();
    void InitDriver();
    ~MainWindow();
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

    void UpdateSlot(QStandardItem*);
private:
    Bruteforce myFind;
    ComplexType VeiwType=Arefmic;
    Complex<int> *myComplex1;
    Complex<int> *myComplex2;
    Complex<int> *rezult;
    QChar operation;
    Palindrom myPalindrom;
    Ui::MainWindow *ui;
    ModelDisp  *modelDisp;
    ModelDriver  *modelDriver;
    //имитация запроса из базы данных
    QMap<QString,Driver> myDrivers
    {
        {"Водитель 1",{"Вася"}},
        {"Водитель 2",{"Петя"}},
        {"Водитель 3",{"Коля"}}
    };
    QVector<Car> myCar
    {
        {333,"Камаз"},
        {4444,"Газель"},
        {555,"Каблук"}
    };
    QVector<Flight> myFlights
    {
        {1,"Томск","Новосибирск"},
        {2,"Топки","Иваново"},
        {3,"Кемерово","Мариинск"},
    };
};
#endif // MAINWINDOW_H
