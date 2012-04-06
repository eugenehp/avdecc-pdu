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

enum avdecc_app_msg_type_e
{
    avdecc_ip_message_type_active=0,
    avdecc_ip_message_type_inactive=1,
    avdecc_ip_message_type_port_state_up=2,
    avdecc_ip_message_type_port_state_down=3,
    avdecc_ip_message_type_avdecc=4
};

typedef enum avdecc_app_msg_type_e avdecc_app_msg_type_t;

#define AVDECC_APP_PDU_MAX_PAYLOAD (1008)

struct avdecc_app_pdu_s
{
    uint8_t app_version;
    uint8_t app_msg_type;
    uint16_t payload_length;
    uint64_t destination;
    uint64_t source;
    uint8_t payload[AVDECC_APP_PDU_MAX_PAYLOAD];
};

typedef struct avdecc_app_pdu_s avdecc_app_pdu_t;

AVDECC_BITS_MAP_OCTET(avdecc_app, version, uint8_t, 0)
AVDECC_BITS_MAP_OCTET ( avdecc_app, msg_type, uint8_t, 1 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_ip, payload_length, uint16_t, 2 )
AVDECC_BITS_MAP_SEXLET(avdecc_app, destination, uint64_t, 4)
AVDECC_BITS_MAP_SEXLET(avdecc_app, source, uint64_t, 10)

/**
*/

void avdecc_app_init ( avdecc_app_pdu_t *self );


/** 
*/

bool avdecc_app_read (
    avdecc_app_pdu_t *self,
    const void *pdu,
    size_t len
    );


/**
*/
bool avdecc_app_write (
    const avdecc_app_pdu_t *self,
    void *dest_pdu,
    size_t *len
    );


/* @} */

#ifdef __cplusplus
}
#endif

#endif
