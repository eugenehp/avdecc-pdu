! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_test_aem_commands

SOURCES += $$TOPDIR/tests/avdecc-pdu_test_aem_commands.c

HEADERS += $$TOPDIR/include/*.hpp

