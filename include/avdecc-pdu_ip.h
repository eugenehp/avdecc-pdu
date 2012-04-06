#ifndef AVDECC_PDU_IP_H_
#define AVDECC_PDU_IP_H_

/*
Copyright (c) 2012, Jeff Koftinoff <jeff.koftinoff@ieee.org>
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

#include "avdecc-pdu_eui64.h"
#include "avdecc-pdu_bits.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \addtogroup ip
    */
/* @{ */

#define AVDECC_IP_DNSSD_PROXY_TCP_SERVICE "_avdecc-proxy._tcp."
#define AVDECC_IP_DNSSD_AVDECC_UDP_SERVICE "_avdecc._udp."

#define AVDECC_IP_MULTICAST_IPV4 "224.0.0.251"
#define AVDECC_IP_MULTICAST_IPV6 "ff02::fb"

#define AVDECC_IP_MULTICAST_PORT "17221"
#define AVDECC_IP_MULTICAST_PORT_NUM (17221)

/* @} */

#ifdef __cplusplus
}
#endif

#endif
