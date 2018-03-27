#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T12:46:18
#
#-------------------------------------------------

QT       -= core gui

TARGET = wfile
TEMPLATE = lib
CONFIG += staticlib c++11

QMAKE_CXXFLAGS += -fPIC

SOURCES += \
    utf8_util.cpp \
    utf8_file_dir.cpp \
    wfile.cpp

HEADERS += \
    utf8_file_dir.h \
    utf8_util.h \
    rdi_wfile.h \
    windows_dirent.h
