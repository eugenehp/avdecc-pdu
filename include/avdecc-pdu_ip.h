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

#define AVDECC_IP_DNSSD_PROXY_UDP_SERVICE "_avdecc-proxy._udp."
#define AVDECC_IP_DNSSD_AVDECC_UDP_SERVICE "_avdecc._udp."

#define AVDECC_IP_MULTICAST_IPV4 "224.0.0.251"
#define AVDECC_IP_MULTICAST_IPV6 "ff02::fb"

#define AVDECC_IP_MULTICAST_PORT "17221"
#define AVDECC_IP_MULTICAST_PORT_NUM (17221)

#define AVDECC_IP_MIN_DATAGRAM_SIZE (12)

enum avdecc_ip_message_type_e
{
    avdecc_ip_message_type_active=0,
    avdecc_ip_message_type_inactive=1,
    avdecc_ip_message_type_port_state_up=2,
    avdecc_ip_message_type_port_state_down=3,
    avdecc_ip_message_type_avdecc=4,
    avdecc_ip_message_type_avdecc_proxy_rx=5,
    avdecc_ip_message_type_avdecc_proxy_tx=6
};

typedef enum avdecc_ip_message_type_e avdecc_ip_message_type_t;

struct avdecc_ip_s
{
    avdecc_ip_message_type_t udp_msg_type;
    uint16_t reserved;
    avdecc_eui64_t udp_msg_eui64;
    const void *payload;
    uint16_t payload_length;
};

typedef struct avdecc_ip_s avdecc_ip_t;


AVDECC_BITS_MAP_DOUBLET ( avdecc_ip, msg_type, uint16_t, 0 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_ip, reserved, uint16_t, 2 )
AVDECC_BITS_MAP_OCTLET ( avdecc_ip, msg_eui64, avdecc_eui64_t, 4 )

static inline const void *avdecc_ip_get_msg_payload_read( const void *pdu )
{
    const uint8_t *base = (uint8_t *)pdu;
    return (const void *)(base+12);
}

static inline void *avdecc_ip_get_msg_payload_write( void *pdu )
{
    uint8_t *base = (uint8_t *)pdu;
    return base+12;
}

/** avdecc_avtp_control_init
     *
     *  Initialize a avdecc_ip_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_ip_init ( avdecc_ip_t *self );


/** avdecc_ip_read
     *
     *  Read a avdecc_ip_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     */

bool avdecc_ip_read (
    avdecc_ip_t *self,
    const void *pdu,
    size_t len,
    uint8_t **inner_payload,
    size_t *inner_payload_len
    );


/** avdecc_avtp_control_write
     *
     *  write a avdecc_avtp_control_t into a pdu
     *
     */

bool avdecc_ip_write (
    const avdecc_ip_t *self,
    void *dest_pdu,
    size_t *len,
    const void *inner_payload,
    size_t inner_payload_len
    );


/* @} */

#ifdef __cplusplus
}
#endif

#endif
