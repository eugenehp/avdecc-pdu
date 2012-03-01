
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_eui64.h"


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



void avdecc_eui64_init ( avdecc_eui64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_eui64_t ) );
}


bool avdecc_eui64_read (
    avdecc_eui64_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    avdecc_eui64_t m;
    const uint8_t *d=(const uint8_t *)pdu;
    d+=offset;

    m=AVDECC_BITS_MAKE_OCTLET( d[0],d[1], d[2], d[3], d[4], d[5], d[6], d[7] );
    *self = m;
    return r;
}


bool avdecc_eui64_write (
    const avdecc_eui64_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    avdecc_eui64_t m=*self;

    uint8_t *d=(uint8_t *)pdu;
    d+=offset;

    d[0] = AVDECC_BITS_GET_OCTET_7 ( m );
    d[1] = AVDECC_BITS_GET_OCTET_6 ( m );
    d[2] = AVDECC_BITS_GET_OCTET_5 ( m );
    d[3] = AVDECC_BITS_GET_OCTET_4 ( m );
    d[4] = AVDECC_BITS_GET_OCTET_3 ( m );
    d[5] = AVDECC_BITS_GET_OCTET_2 ( m );
    d[6] = AVDECC_BITS_GET_OCTET_1 ( m );
    d[7] = AVDECC_BITS_GET_OCTET_0 ( m );

    return r;
}



