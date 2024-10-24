#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitForm();
}
void MainWindow::UpdateText(QString str)
{
    if (QSformula!=str)QSformula=str;
}
void MainWindow::UpdateFormula()
{
    QString name=((QPushButton*)sender())->text();
    if(name=="CE")QSformula="";
    else if(name=="=")  Solve();
    else QSformula=QSformula+name;
    ui->FormulaTXT->setText(QSformula);
}
void MainWindow::Solve()
{
    string sformula=QSformula.toStdString();
    string::iterator end_pos = remove(sformula.begin(), sformula.end(), ' ');
    sformula.erase(end_pos, sformula.end());
    double result= MathExprIntepreter::Execute(sformula);
    QSformula=QString::number(result);
}
void MainWindow::InitForm()
{
    QList<QPushButton*> LinePushButton = ui->centralwidget->findChildren<QPushButton*>();
    QList<QPushButton*>::iterator it = LinePushButton.begin();

    while(it!=LinePushButton.end())
    {

     connect((*it),SIGNAL(clicked()),this,SLOT(UpdateFormula()));
     it++;
    }
    connect((ui->FormulaTXT),SIGNAL(textChanged(QString)),this,SLOT(UpdateText(QString)));
}
MainWindow::~MainWindow()
{
    delete ui;
}
