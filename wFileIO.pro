#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T12:46:18
#
#-------------------------------------------------

QT       -= core gui

TARGET = wFileIO
TEMPLATE = lib
CONFIG += staticlib c++11

QMAKE_CXXFLAGS += -fPIC

DEFINES += WFILEIO_LIBRARY

SOURCES += wfileio.cpp \
    utf8_util.cpp \
    utf8_file_dir.cpp

HEADERS += wfileio.h \
    utf8_util.h \
    utf8_file_dir.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
