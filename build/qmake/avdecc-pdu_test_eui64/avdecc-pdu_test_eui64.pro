! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_eui64

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_eui64.c

HEADERS += $$TOPDIR/include/*.hpp

