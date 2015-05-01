#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T16:33:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZBarCodeReader
TEMPLATE = app

#LIBS+=../Pix4DOutput/tinyxml/tinyxml2.lib
#LIBS+=tinyxml/tinyxml2.lib
#ZBar\lib\libzbar-0.lib  \


SOURCES += main.cpp\
        barcodereader.cpp \
    reportgenerator.cpp \
    model.cpp \
    feature.cpp \
    pointtoimageparser.cpp \
    volumefileparser.cpp \
    xmlsurfaceparser.cpp \
    xmlverticesparser.cpp \
    tinyxml/tinyxml2.cpp

HEADERS  += barcodereader.h \
    reportgenerator.h \
    model.h \
    feature.h \
    pointtoimageparser.h \
    volumefileparser.h \
    xmlsurfaceparser.h \
    xmlverticesparser.h \
    tinyxml/tinyxml2.h

FORMS    += barcodereader.ui \
    reportgenerator.ui

