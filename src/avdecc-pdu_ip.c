#include "avdecc-pdu_world.h"
#include "avdecc-pdu_ip.h"

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


void avdecc_ip_init ( avdecc_ip_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_ip_t ) );
}

bool avdecc_ip_read (
    avdecc_ip_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=false;

    if( len>=AVDECC_IP_MIN_DATAGRAM_SIZE )
    {
        self->udp_msg_type = avdecc_ip_get_msg_type( pdu );
        self->reserved = avdecc_ip_get_reserved( pdu );
        self->udp_msg_eui64 = avdecc_ip_get_msg_eui64(pdu);
        self->payload = avdecc_ip_get_msg_payload_read( pdu );
        self->payload_length = len - AVDECC_IP_MIN_DATAGRAM_SIZE;
        r=true;
    }

    return r;
}

bool avdecc_ip_write (
    const avdecc_ip_t *self,
    void *pdu,
    size_t *len
    )
{
    bool r=false;

    size_t total_size = self->payload_length + AVDECC_IP_MIN_DATAGRAM_SIZE;
    if( total_size<=1024 && *len >= total_size )
    {
        avdecc_ip_set_msg_type(pdu,self->udp_msg_type);
        avdecc_ip_set_reserved(pdu,self->reserved);
        avdecc_ip_set_msg_eui64(pdu,self->udp_msg_eui64);
        memcpy( avdecc_ip_get_msg_payload_write(pdu), self->payload, self->payload_length );
        r=true;
    }

    return r;
}


