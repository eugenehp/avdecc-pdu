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

#include "avdecc-pdu_world.h"
#include "avdecc-pdu_mac_print.h"

bool avdecc_pdu_mac_to_text ( const avdecc_pdu_mac_t *mac, char *buf, int buf_len )
{
    bool r=false;
    uint64_t v= *mac;
    
    if ( buf_len>17 )
    {
        uint8_t bytes[6];
        bytes[0] = AVDECC_BITS_GET_OCTET_7 ( v );
        bytes[1] = AVDECC_BITS_GET_OCTET_6 ( v );
        bytes[2] = AVDECC_BITS_GET_OCTET_5 ( v );
        bytes[3] = AVDECC_BITS_GET_OCTET_4 ( v );
        bytes[4] = AVDECC_BITS_GET_OCTET_3 ( v );
        bytes[5] = AVDECC_BITS_GET_OCTET_2 ( v );
        
        snprintf (
            buf, buf_len,
            "%02X:%02X:%02X:%02X:%02X:%02X",
            bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5]
        );
        
        r=true;
    }
    
    if ( !r )
    {
        *buf='\0';
    }
    
    return r;
}

bool avdecc_pdu_mac_from_text ( avdecc_pdu_mac_t *mac, const char *buf )
{
    bool r=false;
    int cnt;
    unsigned int bytes[6];
    
    cnt=sscanf (
            buf,
            "%02X:%02X:%02X:%02X:%02X:%02X",
            &bytes[0],
            &bytes[1],
            &bytes[2],
            &bytes[3],
            &bytes[4],
            &bytes[5]
        );
        
    if ( cnt==6 )
    {
        *mac = AVDECC_BITS_MAKE_OCTLET (
                   bytes[0], bytes[1], bytes[2], bytes[3],
                   bytes[4], bytes[5], 0, 0
               );
        r=true;
    }
    
    return r;
}



bool avdecc_pdu_print_mac (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_pdu_mac_t *mac
)
{
    /* @TODO: */
}
