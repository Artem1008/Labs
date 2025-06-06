QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        matrix.cpp \
        myfuct.cpp \
        task1.cpp \
        task2.cpp \
        task3.cpp \
        task4.cpp \
        task5.cpp \
        vector.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    main.h \
    matrix.h \
    matrix.inl \
    myfuct.h \
    vector.h \
    vector.inl
