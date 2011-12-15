#ifndef AVDECC_MAC_H_
#define AVDECC_MAC_H_

/*
Copyright (c) 2010, Jeff Koftinoff <jeff.koftinoff@ieee.org>
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
#include "avdecc-pdu_bits.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup Mac Mac Address
      * @{
      */
    
    /**
     Structure to hold a MAC address
     */
    typedef uint64_t avdecc_mac_t;
    
    /**
     Set the OUI from the lower 24 bits from a 32 bit word
     */
    static inline void avdecc_mac_set_oui24_lsb ( avdecc_mac_t *self, uint32_t oui )
    {
        uint64_t v = *self & 0xFFFFFFL;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_2 ( oui ) ) << 40;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_1 ( oui ) ) << 32;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_0 ( oui ) ) << 24;
    }
    
    static inline void avdecc_mac_set_oui24_msb ( avdecc_mac_t *self, uint32_t oui )
    {
        uint64_t v = *self & 0xFFFFFFL;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_3 ( oui ) ) << 40;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_2 ( oui ) ) << 32;
        v |= ( ( uint64_t ) AVDECC_BITS_GET_OCTET_1 ( oui ) ) << 24;
    }
    
    /**
     Check if MAC address is locally administered
     */
    static inline bool avdecc_mac_is_localadmin ( const avdecc_mac_t *self )
    {
        /* IEEE BIT 6 of MAC address means locally administrated */
        return ( bool ) AVDECC_BITS_IS_SEXLET_BIT_SET ( *self, 6 );
    }
    
    
    /**
     Set localadmin flag
     */
    
    static inline void avdecc_mac_set_localadmin ( avdecc_mac_t *self, bool localadmin )
    {
        *self = AVDECC_BITS_SET_SEXLET_BIT_IF ( *self, 6, localadmin );
    }
    
    /**
     Check if MAC address is multicast
     */
    
    static inline bool avdecc_mac_is_multicast ( const avdecc_mac_t *self )
    {
        /* IEEE BIT 7 of MAC address means multicast */
        return ( bool ) AVDECC_BITS_IS_SEXLET_BIT_SET ( *self, 7 );
    }
    
    /**
     Set multicast flag
     */
    
    static inline void avdecc_mac_set_multicast ( avdecc_mac_t *self, bool multicast )
    {
        *self = AVDECC_BITS_SET_SEXLET_BIT_IF ( *self, 6, multicast );
    }
    /* @} */
    
    
#ifdef __cplusplus
}
#endif

#endif

