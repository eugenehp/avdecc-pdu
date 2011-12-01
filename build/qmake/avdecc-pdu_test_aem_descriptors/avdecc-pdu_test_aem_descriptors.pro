! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_aem_descriptors

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_aem_descriptors.cpp

HEADERS += $$TOPDIR/include/*.hpp

