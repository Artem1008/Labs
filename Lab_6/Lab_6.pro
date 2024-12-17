QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brick.cpp \
    bruteforce.cpp \
    car.cpp \
    comboboxdelegat.cpp \
    dispmodel.cpp \
    driver.cpp \
    drivermodel.cpp \
    flight.cpp \
    main.cpp \
    mainwindow.cpp \
    palindrom.cpp \
    projection.cpp

HEADERS += \
    brick.h \
    bruteforce.h \
    car.h \
    comboboxdelegat.h \
    complex.h \
    dispmodel.h \
    driver.h \
    drivermodel.h \
    flight.h \
    mainwindow.h \
    palindrom.h \
    projection.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
