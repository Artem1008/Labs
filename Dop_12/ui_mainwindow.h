/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Conect_1;
    QTextBrowser *textBrowser_1;
    QPushButton *Conect_2;
    QTextBrowser *textBrowser_2;
    QLineEdit *lineEdit_1;
    QPushButton *setmsg_1;
    QLineEdit *lineEdit_2;
    QPushButton *setmsg_2;
    QTextEdit *ServerLog;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 498);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(150, 150));
        MainWindow->setMaximumSize(QSize(9999, 9999));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Conect_1 = new QPushButton(centralwidget);
        Conect_1->setObjectName(QString::fromUtf8("Conect_1"));
        Conect_1->setGeometry(QRect(20, 20, 254, 23));
        textBrowser_1 = new QTextBrowser(centralwidget);
        textBrowser_1->setObjectName(QString::fromUtf8("textBrowser_1"));
        textBrowser_1->setGeometry(QRect(20, 50, 254, 192));
        Conect_2 = new QPushButton(centralwidget);
        Conect_2->setObjectName(QString::fromUtf8("Conect_2"));
        Conect_2->setGeometry(QRect(330, 20, 254, 23));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(330, 50, 254, 192));
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(20, 260, 173, 20));
        setmsg_1 = new QPushButton(centralwidget);
        setmsg_1->setObjectName(QString::fromUtf8("setmsg_1"));
        setmsg_1->setGeometry(QRect(200, 260, 75, 23));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 260, 173, 20));
        setmsg_2 = new QPushButton(centralwidget);
        setmsg_2->setObjectName(QString::fromUtf8("setmsg_2"));
        setmsg_2->setGeometry(QRect(520, 260, 75, 23));
        ServerLog = new QTextEdit(centralwidget);
        ServerLog->setObjectName(QString::fromUtf8("ServerLog"));
        ServerLog->setGeometry(QRect(20, 300, 571, 141));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Conect_1->setText(QApplication::translate("MainWindow", "connect", nullptr));
        Conect_2->setText(QApplication::translate("MainWindow", "connect", nullptr));
        setmsg_1->setText(QApplication::translate("MainWindow", "->", nullptr));
        setmsg_2->setText(QApplication::translate("MainWindow", "->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
