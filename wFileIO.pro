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

HEADERS += \
    rdi_utf8_file_dir.h \
    rdi_utf8_util.h \
    rdi_wfileio.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
