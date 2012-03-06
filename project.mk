PROJECT=avdecc-pdu
PROJECT_NAME=avdecc-pdu
PROJECT_VERSION=$(BRANCH)20120304
PROJECT_EMAIL=jeff.koftinoff@ieee.org
PROJECT_LICENSE=ISC
PROJECT_MAINTAINER=Jeff Koftinoff <jeff.koftinoff@ieee.org>
PROJECT_COPYRIGHT=Copyright 2012
PROJECT_DESCRIPTION=avdecc-pdu
PROJECT_WEBSITE=http://avdecc-pdu.statusbar.com/
PROJECT_IDENTIFIER=com.statusbar.avdecc-pdu
TOP_LIB_DIRS+=.
CONFIG_TOOLS+=
PKGCONFIG_PACKAGES+=
ENABLE_PRECOMPILED_HEADERS?=1
PRECOMPILED_HEADER=$(TOP)/include/avdecc-pdu_world.h

COMPILE_FLAGS+=-Wall -Wunused -Wno-variadic-macros
CFLAGS+=-std=c99


