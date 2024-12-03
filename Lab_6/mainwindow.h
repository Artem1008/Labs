#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bruteforce.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_SymbolsBox_clicked(bool checked);

    void on_numberBox_clicked(bool checked);

    void on_CapitalBox_clicked(bool checked);

    void on_UserPass_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Bruteforce myFind;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
