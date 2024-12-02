#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SymbolsBox_clicked(bool checked)
{
myFind.setFlagSymbols(checked);
}

void MainWindow::on_numberBox_clicked(bool checked)
{
    myFind.setFlagNumber(checked);
}

void MainWindow::on_CapitalBox_clicked(bool checked)
{
    myFind.setFlagCapital(checked);
    qDebug()<<pass.c_str();
}

void MainWindow::on_UserPass_textEdited(const QString &arg1)
{
    pass=arg1.toStdString();
}

void MainWindow::on_pushButton_clicked()
{
    ((QPushButton*)sender())->setEnabled(false);
    ui->GeneralPass->setText(QString::fromStdString(myFind.RunFind()));
    ((QPushButton*)sender())->setEnabled(true);
}
