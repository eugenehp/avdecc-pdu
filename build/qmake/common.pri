TOPDIR= ../../..

QT -= core gui
CONFIG += link_prl
macx:CONFIG-=app_bundle
win32:QT += core
win32:CONFIG+=console

TEMPLATE = app


INCLUDEPATH += $$TOPDIR/include 

DEPENDPATH += $$INCLUDEPATH

!win32:LIBS += -L../avdecc-pdu -lavdecc-pdu
win32 {
  CONFIG(release):LIBS += -L../avdecc-pdu/release -lavdecc-pdu
  CONFIG(debug):LIBS += -L../avdecc-pdu/debug -lavdecc-pdu
}

win32:LIBS+=ws2_32.lib



