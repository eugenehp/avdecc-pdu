#ifndef AVDECC_PDU_APP_H_
#define AVDECC_PDU_APP_H_

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

#include "avdecc-pdu_mac.h"
#include "avdecc-pdu_bits.h"
#include "avdecc-pdu_ip.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \addtogroup app
    */
/* @{ */

enum avdecc_app_status_e
{
    avdecc_app_status_success=0,
    avdecc_app_status_invalid_header=1,
    avdecc_app_status_unsupported_version=2,
    avdecc_app_status_not_implemented=3,
    avdecc_app_status_invalid_status=4,
    avdecc_app_status_invalid_message_type=5,
    avdecc_app_status_invalid_network_port=6,
    avdecc_app_status_invalid_destination=7,
    avdecc_app_status_invalid_source=8,
    avdecc_app_status_invalid_extension=9,
    avdecc_app_status_invalid_payload_length=0xa,
    avdecc_app_status_invalid_payload=0xb,
    avdecc_app_status_authentication_required=0xc,
    avdecc_app_status_authentication_failed=0xd,
    avdecc_app_status_tls_required=0xe,
    avdecc_app_status_reserved=0xf
};

typedef enum avdecc_app_status_e avdecc_app_status_t;

enum avdecc_app_message_type_e
{
    avdecc_app_message_nop=0,
    avdecc_app_message_hello=1,
    avdecc_app_message_upgrade=2,
    avdecc_app_message_start_tls=3,
    avdecc_app_message_authenticate=4,
    avdecc_app_message_port_status=5,
    avdecc_app_message_avdecc=6,
    avdecc_app_message_join_group=7,
    avdecc_app_message_leave_group=8,
    avdecc_app_message_reserved=9,
    avdecc_app_message_vendor=0x3fff
};

typedef enum avdecc_app_message_type_e avdecc_app_message_type_t;
#define AVDECC_APP_VERSION (0)
#define AVDECC_APP_PDU_MIN_PDU_SIZE (28)
#define AVDECC_APP_PDU_MAX_PAYLOAD (AVDECC_PDU_MAX_PAYLOAD_SIZE)

struct avdecc_app_s
{
    uint8_t version;
    avdecc_app_status_t status;
    uint16_t sequence_id;
    unsigned unsolicited:1;
    avdecc_app_message_type_t message_type;
    unsigned rc:1;
    uint16_t payload_length;
    avdecc_mac_t network_port;
    avdecc_mac_t destination;
    avdecc_mac_t source;
    uint16_t extension;
    uint8_t payload[AVDECC_APP_PDU_MAX_PAYLOAD];
};

typedef struct avdecc_app_s avdecc_app_t;

AVDECC_BITS_MAP_OCTET(avdecc_app, version, uint8_t, 0)
AVDECC_BITS_MAP_OCTET(avdecc_app, status, avdecc_app_status_t, 1 )
AVDECC_BITS_MAP_DOUBLET(avdecc_app, sequence_id, uint16_t, 2 )
AVDECC_BITS_MAP_DOUBLET_BITFIELD(avdecc_app, u, bool, 4, 0, 0 )
AVDECC_BITS_MAP_DOUBLET_BITFIELD(avdecc_app, message_type, avdecc_app_message_type_t, 4, 1, 14 )
AVDECC_BITS_MAP_DOUBLET_BITFIELD(avdecc_app, rc, bool, 4, 15, 15 )
AVDECC_BITS_MAP_DOUBLET(avdecc_app, payload_length, uint16_t, 6 )
AVDECC_BITS_MAP_SEXLET(avdecc_app, network_port, avdecc_mac_t, 8)
AVDECC_BITS_MAP_SEXLET(avdecc_app, destination, avdecc_mac_t, 14)
AVDECC_BITS_MAP_SEXLET(avdecc_app, source, avdecc_mac_t, 20)
AVDECC_BITS_MAP_DOUBLET(avdecc_app, extension, uint16_t, 26 )

#define AVDECC_APP_HELLO_TLS_SUPPORTED_BIT              (15)
#define AVDECC_APP_HELLO_TLS_SUPPORTED                  (0x0001L)
#define AVDECC_APP_HELLO_TLS_REQUIRED_BIT               (14)
#define AVDECC_APP_HELLO_TLS_REQUIRED                   (0x0002L)
#define AVDECC_APP_HELLO_AUTHENTICATION_SUPPORTED_BIT   (13)
#define AVDECC_APP_HELLO_AUTHENTICATION_SUPPORTED       (0x0004L)
#define AVDECC_APP_HELLO_AUTHENTICATION_REQUIRED_BIT    (12)
#define AVDECC_APP_HELLO_AUTHENTICATION_REQUIRED        (0x0008L)
#define AVDECC_APP_HELLO_UPGRADE_SUPPORTED_BIT          (11)
#define AVDECC_APP_HELLO_UPGRADE_SUPPORTED              (0x0010L)
#define AVDECC_APP_HELLO_GROUP_SUPPORTED_BIT            (10)
#define AVDECC_APP_HELLO_GROUP_SUPPORTED                (0x0020L)

struct avdecc_app_hello_capabilities_s
{
    unsigned tls_supported:1;
    unsigned tls_required:1;
    unsigned authentication_supported:1;
    unsigned authentication_required:1;
    unsigned upgrade_supported:1;
    unsigned group_supported:1;
};

typedef struct avdecc_app_hello_capabilities_s avdecc_app_hello_capabilities_t;

void avdecc_app_hello_capabilities_read(
        avdecc_app_hello_capabilities_t *cap,
        uint16_t extension
        );

uint16_t avdecc_app_hello_capabilities_write(
        const avdecc_app_hello_capabilities_t *cap
        );


/**
*/

void avdecc_app_init ( avdecc_app_t *self );

/**
  */
static inline uint16_t avdecc_app_pdu_size( avdecc_app_t const *self )
{
    return self->payload_length + AVDECC_APP_PDU_MIN_PDU_SIZE;
}

/**
  */
bool avdecc_app_status_is_valid( avdecc_app_status_t v, uint8_t version );

/**
  */
bool avdecc_app_message_type_is_valid( avdecc_app_message_type_t v, uint8_t version );

/**
  */
bool avdecc_app_payload_length_is_valid( uint16_t payload_length, uint8_t version );

/**
  */

bool avdecc_app_get_frame_size(
        uint8_t *buf,
        size_t offset,
        size_t buf_size,
        size_t *frame_size
        );

/** 
*/

bool avdecc_app_read (
    avdecc_app_t *self,
    const void *pdu,
    size_t len,
    avdecc_app_status_t *status_code
    );

/**
*/
bool avdecc_app_write (
    const avdecc_app_t *self,
    void *dest_pdu,
    size_t *len
    );


/* @} */

#ifdef __cplusplus
}
#endif

#endif
