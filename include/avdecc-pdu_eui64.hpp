#ifndef AVDECC_PDU_EUI64_HPP_
#define AVDECC_PDU_EUI64_HPP_


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



/**
\addtogroup eui64
*/
/* @{ */


/** avdecc_eui64_t */

typedef uint64_t avdecc_eui64_t;



/** avdecc_eui64_init
 *
 *  Initialize a avdecc_eui64_t
 *
 *  @param self pointer to object to initialize
 *  @returns void
 */

void avdecc_eui64_init ( avdecc_eui64_t *self );


/** avdecc_eui64_read
 *
 *  Read a avdecc_eui64_t from a PDU
 *
 *  @param self pointer to object to fill
 *  @param pdu pointer to base of pdu to read
 *  @param offset offset from base of pdu in octets to start reading from
 *  @returns bool true on success
 */

bool avdecc_eui64_read (
        avdecc_eui64_t *self,
        const void *pdu,
        size_t offset
        );


/** avdecc_eui64_write
 *
 *  write a avdecc_eui64_t into a pdu
 *
 *  @param self pointer to object to store into pdu
 *  @param pdu pointer to base of pdu to write to
 *  @param offset offset from base of pdu in octets to start writing to
 *  @returns bool true on success
 */

bool avdecc_eui64_write (
        const avdecc_eui64_t *self,
        void *pdu,
        size_t offset
        );

/* @} */

/**
 * \addtogroup entity_guid
 */

/* @{ */

typedef struct avdecc_entity_guid_s
{
    avdecc_eui64_t value;
} avdecc_entity_guid_t;

static inline void avdecc_entity_guid_init ( avdecc_entity_guid_t *self )
{
    avdecc_eui64_init( &self->value );
}

static inline bool avdecc_entity_guid_read (
        avdecc_entity_guid_t *self,
        const void *pdu,
        size_t offset
        )
{
    return avdecc_eui64_read( &self->value, pdu, offset );
}

static inline bool avdecc_entity_guid_write (
        const avdecc_entity_guid_t *self,
        void *pdu,
        size_t offset
        )
{
    return avdecc_eui64_write( &self->value, pdu, offset );
}

/* @} */


/**
 * \addtogroup vendor_model_guid
 */

/* @{ */

typedef struct avdecc_vendor_model_guid_s
{
    avdecc_eui64_t value;
} avdecc_vendor_model_guid_t;

static inline void avdecc_vendor_model_guid_init ( avdecc_vendor_model_guid_t *self )
{
    avdecc_eui64_init( &self->value );
}

static inline bool avdecc_vendor_model_guid_read (
        avdecc_vendor_model_guid_t *self,
        const void *pdu,
        size_t offset
        )
{
    return avdecc_eui64_read( &self->value, pdu, offset );
}

static inline bool avdecc_vendor_model_guid_write (
        const avdecc_vendor_model_guid_t *self,
        void *pdu,
        size_t offset
        )
{
    return avdecc_eui64_write( &self->value, pdu, offset );
}

/* @} */



#endif
