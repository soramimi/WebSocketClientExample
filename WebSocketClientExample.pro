QT       += core gui widgets websockets

TARGET = WebSocketClientExample
TEMPLATE = app
CONFIG += c++11

DESTDIR = $$PWD/_bin

LIBS += -L/usr/local/lib -lssl -lcrypto

SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui
