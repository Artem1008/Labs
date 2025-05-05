#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <server.h>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void UpdateData(BitmapData);
private:
    int err;
    Server* _server ;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
