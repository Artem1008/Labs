#include "mainwindow.h"
#include "ui_mainwindow.h"

void serverfunct(Server* serv)
{
    qDebug()<<"serverfunct";
    serv->StartServer();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui=new Ui::MainWindow;
    ui->setupUi(this);
    _server=new Server();
    err= _server->InitServer();
    connect(_server,&Server::signalBITMAP,this,&MainWindow::UpdateData);
    if(err>=0)
    {
        std::thread serverthread(serverfunct,_server);
        serverthread.detach();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::UpdateData(BitmapData data)
{
    qDebug()<<"UpdateData"<<data.data<<" "<<data.size;

    // Создаем QImage напрямую из данных
    QImage qImage(reinterpret_cast<uchar*>(data.data),
                  data.width,
                  data.height,
                  data.width * 4,  // шаг строки (stride)
                  QImage::Format_RGB32);
    if (qImage.format() != QImage::Format_RGB32) {
        qImage = qImage.rgbSwapped();
    }

    ui->MyLabel->setPixmap(QPixmap::fromImage(qImage));
    ui->MyLabel->setScaledContents(true);
}

