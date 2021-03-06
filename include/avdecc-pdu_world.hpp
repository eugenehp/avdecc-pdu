#ifndef AVDECC_PDU_WORLD_HPP_
#define AVDECC_PDU_WORLD_HPP_

/*
Copyright (c) 2011, Jeff Koftinoff <jeff.koftinoff@ieee.org>
All rights reserved.

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


/* define AVDECC_PDU_FIRST_INCLUDE to be a include file name to insert here for platform specific configuration */
#ifdef AVDECC_PDU_FIRST_INCLUDE
# include AVDECC_PDU_FIRST_INCLUDE
#endif

#if defined(TARGET_PLATFORM_POSIX)
# define AVDECC_PDU_CONFIG_POSIX
#elif defined(TARGET_PLATFORM_LINUX)
# define AVDECC_PDU_CONFIG_POSIX
# define AVDECC_PDU_CONFIG_LINUX
#endif

#if defined(__APPLE__)
# undef AVDECC_PDU_CONFIG_MACOSX
# define AVDECC_PDU_CONFIG_MACOSX
# undef AVDECC_PDU_CONFIG_POSIX
# define AVDECC_PDU_CONFIG_POSIX
#elif defined(__linux__)
# undef AVDECC_PDU_CONFIG_LINUX
# define AVDECC_PDU_CONFIG_LINUX
# undef AVDECC_PDU_CONFIG_POSIX
# define AVDECC_PDU_CONFIG_POSIX
#elif defined(__CYGWIN__)
# undef AVDECC_PDU_CONFIG_POSIX
# define AVDECC_PDU_CONFIG_POSIX
#elif defined(WIN32) || defined(_WIN32) || defined( _MSC_VER )
# undef AVDECC_PDU_CONFIG_WIN32
# define AVDECC_PDU_CONFIG_WIN32
#ifndef _CRT_SECURE_NO_DEPRECATE
# define _CRT_SECURE_NO_DEPRECATE 1
#endif
#ifndef _WIN32_WINNT
# define _WIN32_WINNT 0x0600
# undef WINVER
# define WINVER _WIN32_WINNT
#endif
#ifndef _SCL_SECURE_NO_DEPRECATE
# define _SCL_SECURE_NO_DEPRECATE 1
#endif
#endif

#if defined( _MSC_VER )
# pragma warning( disable : 4267 )
# define snprintf _snprintf
#endif



#if defined(_WIN32)

# include <winsock2.h>
# include <ws2tcpip.h>
# include <mswsock.h>

#include <errno.h>
# ifndef EADDRINUSE
#  define EADDRINUSE 112  /* Address already in use */
# endif

# include <windows.h>
# include <io.h>
# include <fcntl.h>

# include <process.h>

typedef long ssize_t;

#if _MSC_VER >= 1600
#include <stdint.h>
#else
typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef char int8_t;
typedef unsigned char uint8_t;
#endif
#endif

#if defined(AVDECC_PDU_CONFIG_POSIX)
#ifndef _BSD_SOURCE
# define _BSD_SOURCE
#endif
#ifndef _POSIX_SOURCE
# define _POSIX_SOURCE 1
#endif
#ifndef _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 1
#endif
#ifndef _DARWIN_C_SOURCE
# define _DARWIN_C_SOURCE 1
#endif
# include <locale.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <unistd.h>
# include <pthread.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/tcp.h>
# include <arpa/inet.h>
# include <sys/poll.h>
# include <errno.h>
# include <strings.h>
# include <net/if.h>
# include <stdint.h>
#endif

#include <limits.h>
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#include "avdecc-pdu_bits.hpp"

#define AVDECC_PDU_COUNTOF(x) (sizeof(x)/sizeof(x[0]))

#ifdef AVDECC_PDU_UNUSED
#elif defined(__GNUC__)
# define AVDECC_PDU_UNUSED(x) AVDECC_PDU_UNUSED_ ## x __attribute__((unused))
#else
# define AVDECC_PDU_UNUSED(x) //AVDECC_PDU_UNUSED_ ## x
#endif

#define AVDECC_AVTP_ETHERTYPE ((uint16_t)0x22f0)
#define AVDECC_AVTP_OUI ((uint32_t)0x90e0f0L)
#define AVDECC_PDU_HEADER_SIZE (12) /* See IEEE 1722-2011 Section 5.2 */
#define AVDECC_PDU_MAX_PAYLOAD_SIZE (536) /* See IEEE 1722.1 Clause 9.2.1.1.7 */


bool avdecc_print (
    char *buf,
    size_t *offset,
    size_t len,
    const char *fmt,
    ...
    );

bool avdecc_print_block (
    char *buf,
    size_t *offset,
    size_t len,
    const void *packet,
    size_t packet_len
    );

bool avdecc_print_utf8 (
    char *buf,
    size_t *offset,
    size_t len,
    const uint8_t *s,
    size_t s_len
    );

typedef struct avdecc_string64_s
{
    char buf[65];
} avdecc_string64_t;

typedef struct avdecc_string32_s
{
    char buf[33];
} avdecc_string32_t;

#ifndef avdecc_log_info
#define avdecc_log_info(...)
#endif

#ifndef avdecc_log_error
#define avdecc_log_error(...)
#endif

#ifndef avdecc_log_warning
#define avdecc_log_warning(...)
#endif


#endif

