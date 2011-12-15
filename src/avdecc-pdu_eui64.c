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
#include "avdecc-pdu_eui64.h"


void avdecc_eui64_convert_mac ( avdecc_eui64_t *eui64, const avdecc_mac_t *mac, bool is_eui48 )
{
    uint8_t bytes[8];
    uint64_t mac_v = *mac;
    /* copy OUI */
    bytes[0] = AVDECC_BITS_GET_OCTET_7 ( mac_v );
    bytes[1] = AVDECC_BITS_GET_OCTET_6 ( mac_v );
    bytes[2] = AVDECC_BITS_GET_OCTET_5 ( mac_v );
    
    /* append 0xff 0xfe is is_eui8, 0xff 0xff if not */
    
    bytes[3] = 0xff;
    
    if ( is_eui48 )
    {
        bytes[4] = 0xfe;
    }
    else
    {
        bytes[4] = 0xff;
    }
    
    /* copy nic specific */
    bytes[5] = AVDECC_BITS_GET_OCTET_4 ( mac_v );
    bytes[6] = AVDECC_BITS_GET_OCTET_3 ( mac_v );
    bytes[7] = AVDECC_BITS_GET_OCTET_2 ( mac_v );
    
    *eui64 = AVDECC_BITS_MAKE_OCTLET ( bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7] );
}


