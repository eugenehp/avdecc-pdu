! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_mac

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_mac.cpp

HEADERS += $$TOPDIR/include/*.hpp

