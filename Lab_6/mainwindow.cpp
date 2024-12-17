#include <QValidator>
#include <QStringListModel>
#include <QTableView>
#include <QItemSelectionModel>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //инициализация интерфуйса диспетчера
    InitDispatcher();
    InitDriver();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitDispatcher()
{
    modelDisp = new ModelDisp(myFlights,this);
    ui->listFlight->setModel(modelDisp);
    ui->tableFlight->setModel(modelDisp);
    connect(ui->listFlight, SIGNAL(clicked(const QModelIndex&)),ui->tableFlight, SLOT(setRootIndex(const QModelIndex&)));
    emit ui->listFlight->clicked(modelDisp->index(0, 0, QModelIndex()));
    ComboBoxDelegat* delegate= new ComboBoxDelegat (myDrivers,this);
    ui->tableFlight->setItemDelegateForRow(3,delegate);
    connect(modelDisp, SIGNAL(itemChanged(QStandardItem*)),this, SLOT(UpdateSlot(QStandardItem*)));
}

void MainWindow::InitDriver()
{
    modelDriver = new ModelDriver(myDrivers,myFlights,this);
    ui->listFlight_2->setModel(modelDriver);
    ui->tableFlight_2->setModel(modelDriver);
    connect(ui->listFlight_2, SIGNAL(clicked(const QModelIndex&)),ui->tableFlight_2, SLOT(setRootIndex(const QModelIndex&)));
    emit ui->listFlight_2->clicked(modelDriver->index(0, 0, QModelIndex()));
}
void MainWindow::UpdateSlot(QStandardItem *item)
{
    if (!item) return;
    int indexVect=item->parent()->child(0)->text().toInt()-1;
    //имитация записи в базу данных
    myFlights[indexVect].Setdriver(item->text());
    myDrivers.find(item->text()).value().SetRequest("Заявка"+QString::number(myFlights.at(indexVect).GetNumber()));
    modelDriver->initialize();
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

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("[А-Яа-яёЁ,' ',',',0-9A-Za-z]{50}")));
    myPalindrom.setStr(arg1);
}

void MainWindow::on_pushButton_2_clicked()
{
    QPalette palettered;
    palettered.setColor(QPalette::Base,Qt::red);
    QPalette palettegreen;
    palettegreen.setColor(QPalette::Base,Qt::green);
    bool rezult;
    rezult=myPalindrom.CheckPalindrom();
    if (rezult) ui->lineEdit_2->setPalette(palettegreen);
    else ui->lineEdit_2->setPalette(palettered);
}
void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}[+','\\-']{1}[0-9]{1,5}[i]{1}")));
    int a1;
    int a2;
    QChar op1;
    QString string = arg1;
    QTextStream stream(&string);
    stream>>a1>>op1>>a2;
    if (op1=='-') a2*=(-1);
    myComplex1=new Complex<int>(a1,a2);
}
void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}[+','\\-']{1}[0-9]{1,5}[i]{1}")));
    int a1;
    int a2;
    QChar op1;
    QString string = arg1;
    QTextStream stream(&string);
    stream>>a1>>op1>>a2;
    if (op1=='-') a2*=(-1);
    myComplex2=new Complex<int>(a1,a2);
}
void MainWindow::on_lineEdit_5_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("['+','-','*','/','^']{1}")));
    operation=arg1[0];
}

void MainWindow::on_pushButton_3_clicked()
{

    switch(operation.unicode())
    {
    case u'+':
        rezult = new Complex<int>(*myComplex1+*myComplex2);
        break;
    case u'-':
        rezult=new Complex<int>(*myComplex1-*myComplex2);
        break;
    case u'*':
        rezult=new Complex<int>((*myComplex1)*(*myComplex2));
        break;
    case u'/':
        rezult=new Complex<int>((*myComplex1)/(*myComplex2));
        break;
    }
    ui->lineEdit_6->setText(rezult->GetArefmicForm());
}
void MainWindow::on_pushButton_4_clicked()
{
    if (VeiwType==Arefmic)
    {
        if (rezult!=nullptr) ui->lineEdit_6->setText(rezult->GetTrigonometricForm());
        VeiwType=Trigonometric;
    }
    else if (VeiwType==Trigonometric)
    {
        if (rezult!=nullptr) ui->lineEdit_6->setText(rezult->GetExpForm());
        VeiwType=Exp;
    }
    else if (VeiwType==Exp)
    {
        if (rezult!=nullptr) ui->lineEdit_6->setText(rezult->GetArefmicForm());
        VeiwType=Arefmic;
    }
}
int CheckGeometry(Projection &projection,  Brick &brick)
{
    QMap<int,QPair<int,int>>::const_iterator it = brick.sizes.begin();
    for(;it != brick.sizes.end(); ++it)
    {
          if(((projection.x>=it.value().second)&&(projection.y>=it.value().first))||((projection.y>=it.value().second)&&(projection.x>=it.value().first))) return it.key();
    }
    return -1;
}
void MainWindow::on_lineEdit_10_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    myProjection.SetX(arg1.toInt());
    ui->myProject->SetX(arg1.toInt());
    ui->myBrickView->Setindex(CheckGeometry(myProjection,myBrick));
    ui->myBrickView->repaint();
    ui->myProject->repaint();
}

void MainWindow::on_lineEdit_9_textEdited(const QString &arg1)
{
    ((QLineEdit*)sender())->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    myProjection.SetY(arg1.toInt());
    ui->myProject->SetY(arg1.toInt());
    ui->myBrickView->Setindex(CheckGeometry(myProjection,myBrick));
    ui->myBrickView->repaint();
    ui->myProject->repaint();
}
