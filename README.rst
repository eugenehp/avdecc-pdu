==========
AVDECC-PDU
==========


Reference implementation of the protocol data units used in IEEE P1722.1:

        http://grouper.ieee.org/groups/1722/1/

Authors:
        Jeff Koftinoff <jeff.koftinoff@ieee.org>

Please see the file COPYING for license information.

Quick Start
===========

On Unix-like systems
--------------------

to build on unix/linux/macosx::

    git clone ssh://git@github.com/jdkoftinoff/avdecc-pdu.git
    (cd avdecc-pdu && ./configure --debug=1 && make && make check )

* build results are in avdecc-pdu/tmp-target/build
* unit test results are in avdecc-pdu/tmp-target/build/tests/

also see::

    cd avdecc-pdu
    ./configure --help
    ./configure --prefix=/opt/local/avdecc-pdu
    make compile-info
    make install

On Mac OS X
-----------

    open build/xcode/avdecc-pdu/avdecc-pdu.xcodeproj

On Windows with VS2010:

    start build\\vs2010\\avdecc-pdu\\avdecci-pdu.sln


With qmake:

    cd build/qmake && qmake && make


