#include "mainwindow.h"
#include "ui_mainwindow.h"

void serverfunct(Server* serv)
{
    serv->StartServer();
}
void clientrfunct(Client* client,QTextBrowser* obj)
{
    client->StartClient(obj);

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server=new Server();
    err= _server->InitServer();
    HandleError((char*)"server",err);
    InitForm();
    if(err>=0)
    {
    std::thread serverthread(serverfunct,_server);
    serverthread.detach();
    }
}

void MainWindow::InitForm()
{
    QRegularExpression exp("Btn");
    QList<QPushButton*> PushButton = ui->centralwidget->findChildren<QPushButton*>(exp);
    QList<QPushButton*>::iterator it = PushButton.begin();
    while(it!=PushButton.end())
    {
        connect((*it),SIGNAL(clicked()),this,SLOT(UpdateData()));
        it++;
    }
}

void MainWindow::Restart()
{
    model.Restart();
    QRegularExpression exp("Btn");
    QList<QPushButton*> PushButton = ui->centralwidget->findChildren<QPushButton*>(exp);
    for(auto var:PushButton)
    {
        var->setText("");
    }
}

void MainWindow::HandleError(const char* obj,int err)
{
    switch (err)
    {
    case ret::Ok:
        break;
    case ret::ErrWSA:
        printf("%s WSAStart error \n",obj);
        break;
    case ret::ErrSock:
        printf("%s Socket error \n",obj);
        break;
    case ret::ErrAddress:
        printf("%s Invalid address  \n",obj);
        break;
    case ret::ErrConnect:
        printf("%s Connect error \n",obj);
        break;
    case ret::ErrBind:
        printf("%s Error bind \n",obj);
        break;
    case ret::ErrListen:
        printf("%s Error listen \n",obj);
        break;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateData()
{
    QMessageBox msg;
    if(((QPushButton*)sender())->text()=='X'||((QPushButton*)sender())->text()=='O') return;
    model.UpdatePole((sender()->objectName()).mid(3,1).toInt());

    ((QPushButton*)sender())->setText((QString)model.GetSimvol());
    if(model.CheckWin())
    {
        msg.setIcon(QMessageBox::Question);
        msg.setText("Победил игрок\n"+(QString)model.GetSimvol()+"\nНачать новую игру?");
        msg.setWindowTitle("Победа!!");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg.setDefaultButton(QMessageBox::Yes);
        int ret = msg.exec();
        if (ret == QMessageBox::Yes)
        {
            Restart();
        }
    }
    else
    {
        model.UpdateSimvol();
    }
}
void MainWindow::on_Conect_1_clicked()
{
    _client=new Client((char*)"192.168.159.1",666);
    int err =_client->InitClient();
    std::thread clientthread(clientrfunct,_client,ui->centralwidget->findChild<QTextBrowser*>("textBrowser_1"));
    HandleError((char*)"client",err);
    clientthread.detach();
}

void MainWindow::on_Conect_2_clicked()
{
    _client2=new Client((char*)"192.168.159.1",666);
    int err =_client2->InitClient();
    std::thread clientthread(clientrfunct,_client2,ui->centralwidget->findChild<QTextBrowser*>("textBrowser_2"));
    HandleError((char*)"client",err);
     clientthread.detach();

}

void MainWindow::on_setmsg_1_clicked()
{
    _client->SetMessag(ui->centralwidget->findChild<QLineEdit*>("lineEdit_1")->text().toStdString());
}

void MainWindow::on_setmsg_2_clicked()
{
    _client2->SetMessag(ui->centralwidget->findChild<QLineEdit*>("lineEdit_2")->text().toStdString());
}
