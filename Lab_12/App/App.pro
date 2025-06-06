QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = App
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../Crc/include\
                            ../Hash/include

SOURCES += src/main.cpp
LIBS += -L../Crc/release -lCrc
LIBS += -L../Hash/release -lHash

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
