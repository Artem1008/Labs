#ifndef MAINWINDOW_H
#define MAINWINDOW_H>
#include <QMainWindow>
#include <algorithm>
#include "mathexprintepreter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void InitForm();
   void Solve();
    ~MainWindow();

signals:
    void ClearForm();

private slots:
    void UpdateFormula();
    void UpdateText(QString);
private:
    QString QSformula="";
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
