! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_aecp

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_aecp.cpp

HEADERS += $$TOPDIR/include/*.hpp

