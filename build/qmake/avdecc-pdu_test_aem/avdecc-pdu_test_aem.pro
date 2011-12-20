! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_aem

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_aem.c

HEADERS += $$TOPDIR/include/*.hpp

