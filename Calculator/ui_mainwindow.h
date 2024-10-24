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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *CalcLayout;
    QPushButton *Button1;
    QPushButton *Button5;
    QPushButton *brackOn;
    QPushButton *Add;
    QPushButton *Button2;
    QPushButton *Mult;
    QPushButton *Sub;
    QPushButton *Button4;
    QPushButton *brackOff;
    QPushButton *Button9;
    QPushButton *Button1_13;
    QPushButton *Button8;
    QPushButton *Button3;
    QPushButton *Ravno;
    QPushButton *Button6;
    QPushButton *point;
    QPushButton *Dev;
    QPushButton *Button0;
    QPushButton *Button7;
    QLineEdit *FormulaTXT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(390, 340);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(390, 340));
        MainWindow->setMaximumSize(QSize(390, 340));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 311));
        CalcLayout = new QGridLayout(gridLayoutWidget);
        CalcLayout->setObjectName(QString::fromUtf8("CalcLayout"));
        CalcLayout->setContentsMargins(0, 0, 0, 0);
        Button1 = new QPushButton(gridLayoutWidget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        Button1->setFont(font);
        Button1->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button1->setAutoFillBackground(false);
        Button1->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button1, 4, 0, 1, 1);

        Button5 = new QPushButton(gridLayoutWidget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setFont(font);
        Button5->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button5->setAutoFillBackground(false);
        Button5->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button5, 3, 1, 1, 1);

        brackOn = new QPushButton(gridLayoutWidget);
        brackOn->setObjectName(QString::fromUtf8("brackOn"));
        brackOn->setFont(font);
        brackOn->setContextMenuPolicy(Qt::DefaultContextMenu);
        brackOn->setAutoFillBackground(false);
        brackOn->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(brackOn, 1, 1, 1, 1);

        Add = new QPushButton(gridLayoutWidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setFont(font);
        Add->setContextMenuPolicy(Qt::DefaultContextMenu);
        Add->setAutoFillBackground(false);
        Add->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Add, 5, 3, 1, 1);

        Button2 = new QPushButton(gridLayoutWidget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setFont(font);
        Button2->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button2->setAutoFillBackground(false);
        Button2->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button2, 4, 1, 1, 1);

        Mult = new QPushButton(gridLayoutWidget);
        Mult->setObjectName(QString::fromUtf8("Mult"));
        Mult->setFont(font);
        Mult->setContextMenuPolicy(Qt::DefaultContextMenu);
        Mult->setAutoFillBackground(false);
        Mult->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Mult, 3, 3, 1, 1);

        Sub = new QPushButton(gridLayoutWidget);
        Sub->setObjectName(QString::fromUtf8("Sub"));
        Sub->setFont(font);
        Sub->setContextMenuPolicy(Qt::DefaultContextMenu);
        Sub->setAutoFillBackground(false);
        Sub->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Sub, 4, 3, 1, 1);

        Button4 = new QPushButton(gridLayoutWidget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setFont(font);
        Button4->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button4->setAutoFillBackground(false);
        Button4->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button4, 3, 0, 1, 1);

        brackOff = new QPushButton(gridLayoutWidget);
        brackOff->setObjectName(QString::fromUtf8("brackOff"));
        brackOff->setFont(font);
        brackOff->setContextMenuPolicy(Qt::DefaultContextMenu);
        brackOff->setAutoFillBackground(false);
        brackOff->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(brackOff, 1, 2, 1, 1);

        Button9 = new QPushButton(gridLayoutWidget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setFont(font);
        Button9->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button9->setAutoFillBackground(false);
        Button9->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button9, 2, 2, 1, 1);

        Button1_13 = new QPushButton(gridLayoutWidget);
        Button1_13->setObjectName(QString::fromUtf8("Button1_13"));
        Button1_13->setFont(font);
        Button1_13->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button1_13->setAutoFillBackground(false);
        Button1_13->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button1_13, 1, 3, 1, 1);

        Button8 = new QPushButton(gridLayoutWidget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setFont(font);
        Button8->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button8->setAutoFillBackground(false);
        Button8->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button8, 2, 1, 1, 1);

        Button3 = new QPushButton(gridLayoutWidget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setFont(font);
        Button3->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button3->setAutoFillBackground(false);
        Button3->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button3, 4, 2, 1, 1);

        Ravno = new QPushButton(gridLayoutWidget);
        Ravno->setObjectName(QString::fromUtf8("Ravno"));
        Ravno->setFont(font);
        Ravno->setContextMenuPolicy(Qt::DefaultContextMenu);
        Ravno->setAutoFillBackground(false);
        Ravno->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Ravno, 5, 2, 1, 1);

        Button6 = new QPushButton(gridLayoutWidget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setFont(font);
        Button6->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button6->setAutoFillBackground(false);
        Button6->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button6, 3, 2, 1, 1);

        point = new QPushButton(gridLayoutWidget);
        point->setObjectName(QString::fromUtf8("point"));
        point->setFont(font);
        point->setContextMenuPolicy(Qt::DefaultContextMenu);
        point->setAutoFillBackground(false);
        point->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(point, 5, 1, 1, 1);

        Dev = new QPushButton(gridLayoutWidget);
        Dev->setObjectName(QString::fromUtf8("Dev"));
        Dev->setFont(font);
        Dev->setContextMenuPolicy(Qt::DefaultContextMenu);
        Dev->setAutoFillBackground(false);
        Dev->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Dev, 2, 3, 1, 1);

        Button0 = new QPushButton(gridLayoutWidget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        Button0->setFont(font);
        Button0->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button0->setAutoFillBackground(false);
        Button0->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button0, 5, 0, 1, 1);

        Button7 = new QPushButton(gridLayoutWidget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setFont(font);
        Button7->setContextMenuPolicy(Qt::DefaultContextMenu);
        Button7->setAutoFillBackground(false);
        Button7->setIconSize(QSize(60, 60));

        CalcLayout->addWidget(Button7, 2, 0, 1, 1);

        FormulaTXT = new QLineEdit(gridLayoutWidget);
        FormulaTXT->setObjectName(QString::fromUtf8("FormulaTXT"));
        FormulaTXT->setFrame(true);
        FormulaTXT->setClearButtonEnabled(false);

        CalcLayout->addWidget(FormulaTXT, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 390, 21));
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
        Button1->setText(QApplication::translate("MainWindow", "1", nullptr));
        Button5->setText(QApplication::translate("MainWindow", "5", nullptr));
        brackOn->setText(QApplication::translate("MainWindow", "(", nullptr));
        Add->setText(QApplication::translate("MainWindow", "+", nullptr));
        Button2->setText(QApplication::translate("MainWindow", "2", nullptr));
        Mult->setText(QApplication::translate("MainWindow", "*", nullptr));
        Sub->setText(QApplication::translate("MainWindow", "-", nullptr));
        Button4->setText(QApplication::translate("MainWindow", "4", nullptr));
        brackOff->setText(QApplication::translate("MainWindow", ")", nullptr));
        Button9->setText(QApplication::translate("MainWindow", "9", nullptr));
        Button1_13->setText(QApplication::translate("MainWindow", "CE", nullptr));
        Button8->setText(QApplication::translate("MainWindow", "8", nullptr));
        Button3->setText(QApplication::translate("MainWindow", "3", nullptr));
        Ravno->setText(QApplication::translate("MainWindow", "=", nullptr));
        Button6->setText(QApplication::translate("MainWindow", "6", nullptr));
        point->setText(QApplication::translate("MainWindow", ".", nullptr));
        Dev->setText(QApplication::translate("MainWindow", "/", nullptr));
        Button0->setText(QApplication::translate("MainWindow", "0", nullptr));
        Button7->setText(QApplication::translate("MainWindow", "7", nullptr));
        FormulaTXT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
