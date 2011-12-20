! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_avtp

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_avtp.c

HEADERS += $$TOPDIR/include/*.hpp

