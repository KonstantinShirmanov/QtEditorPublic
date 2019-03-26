
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TexRed
TEMPLATE = app


SOURCES += main.cpp\
        mainclass.cpp

HEADERS  += mainclass.h

RESOURCES += Resources.qrc

OTHER_FILES += \
    output.odf

