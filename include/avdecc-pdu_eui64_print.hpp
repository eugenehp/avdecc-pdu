#ifndef AVDECC_PDU_EUI64_PRINT_HPP_
#define AVDECC_PDU_EUI64_PRINT_HPP_


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


#include "avdecc-pdu_eui64.hpp"


/**
    \addtogroup eui64
    */
/* @{ */

bool avdecc_eui64_to_text ( const avdecc_eui64_t *eui64, char *buf, int buf_len );
bool avdecc_eui64_from_text ( avdecc_eui64_t *eui64, const char *buf );


bool avdecc_eui64_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_eui64_t *self
    );


/* @} */


/**
 * \addtogroup entity_guid
 */

/* @{ */

static inline bool avdecc_entity_guid_to_text ( const avdecc_entity_guid_t *self, char *buf, int buf_len )
{
    return avdecc_eui64_to_text( &self->value, buf, buf_len );
}

static inline bool avdecc_entity_guid_from_text ( avdecc_entity_guid_t *self, const char *buf )
{
    return avdecc_eui64_from_text( &self->value, buf );
}


static inline bool avdecc_entity_guid_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_entity_guid_t *self
    )
{
    return avdecc_eui64_print( buf, pos, len, &self->value );
}


/* @} */


/**
 * \addtogroup vendor_model_guid
 */

/* @{ */

static inline bool avdecc_vendor_model_guid_to_text ( const avdecc_vendor_model_guid_t *self, char *buf, int buf_len )
{
    return avdecc_eui64_to_text( &self->value, buf, buf_len );
}

static inline bool avdecc_vendor_model_guid_from_text ( avdecc_vendor_model_guid_t *self, const char *buf )
{
    return avdecc_eui64_from_text( &self->value, buf );
}


static inline bool avdecc_vendor_model_guid_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_vendor_model_guid_t *self
    )
{
    return avdecc_eui64_print( buf, pos, len, &self->value );
}


/* @} */



#endif
