QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        belarusianhen.cpp \
        hen.cpp \
        henfactory.cpp \
        main.cpp \
        moldovanhen.cpp \
        russianhen.cpp \
        task1.cpp \
        task2.cpp \
        task3.cpp \
        task4.cpp \
        task5.cpp \
        task6.cpp \
        ukrainianhen.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    belarusianhen.h \
    hen.h \
    henfactory.h \
    main.h \
    moldovanhen.h \
    russianhen.h \
    ukrainianhen.h
