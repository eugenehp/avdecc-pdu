! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_adp

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_adp.c

HEADERS += $$TOPDIR/include/*.hpp

