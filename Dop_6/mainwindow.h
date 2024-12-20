#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <thread>
#include "modelexo.h"
#include "client.h"
#include "server.h"
#include "errors.h"


#define SERVERADDR

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void InitForm();
    void InitServer();
    void Restart();

    void HandleError(const char*,int);
    ~MainWindow();
public slots:
    void UpdateData();

private slots:
    void on_Conect_1_clicked();

    void on_Conect_2_clicked();

    void on_setmsg_1_clicked();

    void on_setmsg_2_clicked();

private:
    Ui::MainWindow *ui;
    ModeleXO model;
     int err;
     Client*_client;
     Client*_client2;
     Server* _server ;
};
#endif // MAINWINDOW_H
