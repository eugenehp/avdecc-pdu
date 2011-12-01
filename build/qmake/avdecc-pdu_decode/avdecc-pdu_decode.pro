! include( ../common.pri ) {
  error( need common.pri file )
}


TARGET=avdecc-pdu_decode

SOURCES += $$TOPDIR/tools-dev/avdecc-pdu_decode.cpp

HEADERS += $$TOPDIR/include/*.hpp

