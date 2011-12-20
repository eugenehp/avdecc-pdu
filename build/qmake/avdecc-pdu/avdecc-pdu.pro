QT -= core \
    gui
CONFIG += create_prl
TOPDIR = ../../../


INCLUDEPATH += $$TOPDIR/include 
DEPENDPATH += $$INCLUDEPATH
TARGET = avdecc-pdu
TEMPLATE = lib
CONFIG += staticlib


LIBS += 
SOURCES += $$TOPDIR/src/*.c 
HEADERS += $$TOPDIR/include/*.h 

mac {
  CONFIG -= app_bundle
}
