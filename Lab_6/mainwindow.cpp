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
}

void MainWindow::on_UserPass_textEdited(const QString &arg1)
{
    pass=arg1.toStdString();
}

void MainWindow::on_pushButton_clicked()
{
    ((QPushButton*)sender())->setEnabled(false);
    std::string temp=myFind.RunFind();
    if (temp=="") temp="Password not found";
    ui->GeneralPass->setText(QString::fromStdString(temp));
    ((QPushButton*)sender())->setEnabled(true);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    myFind.setLengthPass(arg1.toUInt());
}
