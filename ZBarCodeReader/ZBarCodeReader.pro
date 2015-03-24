#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T16:33:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZBarCodeReader
TEMPLATE = app


SOURCES += main.cpp\
        barcodereader.cpp \
    reportgenerator.cpp

HEADERS  += barcodereader.h \
    reportgenerator.h

FORMS    += barcodereader.ui \
    reportgenerator.ui
