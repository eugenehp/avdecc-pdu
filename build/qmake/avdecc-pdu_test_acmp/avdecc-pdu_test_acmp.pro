! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_acmp

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_acmp.c

HEADERS += $$TOPDIR/include/*.hpp

