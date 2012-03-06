#ifndef AVDECC_PDU_ACMP_H_
#define AVDECC_PDU_ACMP_H_


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

#include "avdecc-pdu_world.h"
#include "avdecc-pdu_mac.h"
#include "avdecc-pdu_eui64.h"
#include "avdecc-pdu_bits.h"
#include "avdecc-pdu_avtp.h"
#include "avdecc-pdu_adp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \addtogroup acmp
    */
/* @{ */

#define AVDECC_ACMP_CONTROL_DATA_LENGTH (44) /* See IEEE 1722.1 Clause 8.2.1.7 */

/** \addtogroup timeouts Timeouts,
     See IEEE 1722.1 Clause 8.2.2
     */

#define AVDECC_ACMP_TIMEOUT_CONNECT_TX (2000)
#define AVDECC_ACMP_TIMEOUT_DISCONNECT_TX (200)
#define AVDECC_ACMP_TIMEOUT_GET_TX_STATE (200)
#define AVDECC_ACMP_TIMEOUT_CONNECT_RX (4500)
#define AVDECC_ACMP_TIMEOUT_DISCONNECT_RX (500)
#define AVDECC_ACMP_TIMEOUT_GET_RX_STATE (200)
#define AVDECC_ACMP_TIMEOUT_GET_TX_CONNECTION (200)

/*@}*/


/** See IEEE 1722.1 Clause 8.2.1.6 */
enum avdecc_acmp_status_e
{
    avdecc_acmp_status_success = 0,
    avdecc_acmp_status_listener_unknown_id =1,
    avdecc_acmp_status_talker_unknown_id =2,
    avdecc_acmp_status_talker_dest_mac_fail =3,
    avdecc_acmp_status_talker_no_stream_index =4,
    avdecc_acmp_status_talker_no_bandwidth =5,
    avdecc_acmp_status_talker_exclusive =6,
    avdecc_acmp_status_listener_talker_timeout=7,
    avdecc_acmp_status_listener_exclusive=8,
    avdecc_acmp_status_state_unavailable=9,
    avdecc_acmp_status_not_connected=10,
    avdecc_acmp_status_no_such_connection=11,
    avdecc_acmp_status_could_not_send_message=12,
    avdecc_acmp_status_listener_default_format_invalid=13,
    avdecc_acmp_status_talker_default_format_invalid=14,
    avdecc_acmp_status_default_set_different=15,
    avdecc_acmp_status_controller_not_authorized=16,
    avdecc_acmp_status_incompatible_request=17,
    avdecc_acmp_status_reserved
};

typedef enum avdecc_acmp_status_e avdecc_acmp_status_t;


/** See IEEE 1722.1 Clause 8.2.1.17 */
#define AVDECC_ACMP_FLAG_CLASS_B_BIT (15)
#define AVDECC_ACMP_FLAG_CLASS_B (AVDECC_BITS_DOUBLET_BIT(AVDECC_ACMP_FLAG_CLASS_B_BIT))
#define AVDECC_ACMP_FLAG_FAST_CONNECT_BIT (14)
#define AVDECC_ACMP_FLAG_FAST_CONNECT (AVDECC_BITS_DOUBLET_BIT(AVDECC_ACMP_FLAG_FAST_CONNECT_BIT))
#define AVDECC_ACMP_FLAG_SAVED_STATE_BIT (13)
#define AVDECC_ACMP_FLAG_SAVED_STATE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ACMP_FLAG_SAVED_STATE_BIT))
#define AVDECC_ACMP_FLAG_STREAMING_WAIT_BIT (12)
#define AVDECC_ACMP_FLAG_STREAMING_WAIT (AVDECC_BITS_DOUBLET_BIT(AVDECC_ACMP_FLAG_STREAMING_WAIT_BIT))

typedef struct avdecc_acmp_flags_s
{
    uint8_t class_b:1;
    uint8_t fast_connect:1;
    uint8_t saved_state:1;
    uint8_t streaming_wait:1;
} avdecc_acmp_flags_t;


static inline void avdecc_acmp_flags_read (
    avdecc_acmp_flags_t *self,
    const uint16_t v
    )
{
    self->class_b = AVDECC_BITS_GET_DOUBLET_BIT ( v, AVDECC_ACMP_FLAG_CLASS_B_BIT );
    self->fast_connect = AVDECC_BITS_GET_DOUBLET_BIT ( v, AVDECC_ACMP_FLAG_FAST_CONNECT_BIT );
    self->saved_state = AVDECC_BITS_GET_DOUBLET_BIT ( v, AVDECC_ACMP_FLAG_SAVED_STATE_BIT );
    self->streaming_wait = AVDECC_BITS_GET_DOUBLET_BIT ( v, AVDECC_ACMP_FLAG_STREAMING_WAIT_BIT );
}

static inline uint16_t avdecc_acmp_flags_write (
    const avdecc_acmp_flags_t *self
    )
{
    uint16_t v=0;
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v, AVDECC_ACMP_FLAG_CLASS_B_BIT, self->class_b );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v, AVDECC_ACMP_FLAG_FAST_CONNECT_BIT, self->fast_connect );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v, AVDECC_ACMP_FLAG_SAVED_STATE_BIT, self->saved_state );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v, AVDECC_ACMP_FLAG_STREAMING_WAIT_BIT, self->streaming_wait );
    return v;
}


/** See IEEE 1722.1 Clause 8.2.1.5 */
enum avdecc_acmp_message_type_e
{
    avdecc_acmp_message_connect_tx_command = 0,
    avdecc_acmp_message_connect_tx_response = 1,
    avdecc_acmp_message_disconnect_tx_command = 2,
    avdecc_acmp_message_disconnect_tx_response = 3,
    avdecc_acmp_message_get_tx_state_command = 4,
    avdecc_acmp_message_get_tx_state_response = 5,
    avdecc_acmp_message_connect_rx_command = 6,
    avdecc_acmp_message_connect_rx_response = 7,
    avdecc_acmp_message_disconnect_rx_command = 8,
    avdecc_acmp_message_disconnect_rx_response = 9,
    avdecc_acmp_message_get_rx_state_command = 10,
    avdecc_acmp_message_get_rx_state_response = 11,
    avdecc_acmp_message_get_tx_connection_command = 12,
    avdecc_acmp_message_get_tx_connection_response = 13,
    avdecc_acmp_message_reserved
};

typedef enum avdecc_acmp_message_type_e avdecc_acmp_message_type_t;

/* See IEEE 1722.1 Clause 8.2.1 */

AVDECC_BITS_MAP_OCTET_BIT ( avdecc_acmp, cd, avdecc_avtp_cd_t, 0, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_acmp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 )
AVDECC_BITS_MAP_OCTET_BIT ( avdecc_acmp, sv, avdecc_avtp_sv_t, 1, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_acmp, version, avdecc_avtp_version_t, 1, 1, 3 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_acmp, message_type, avdecc_acmp_message_type_t, 0, 12, 15 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_acmp, status, avdecc_acmp_status_t, 0, 16, 20 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_acmp, control_data_length, avdecc_avtp_control_data_length_t, 0, 21, 31 )
AVDECC_BITS_MAP_OCTLET ( avdecc_acmp, stream_id, avdecc_stream_id_t, 4 )
AVDECC_BITS_MAP_OCTLET ( avdecc_acmp, controller_guid, avdecc_eui64_t, 12 )
AVDECC_BITS_MAP_OCTLET ( avdecc_acmp, talker_guid, avdecc_eui64_t, 20 )
AVDECC_BITS_MAP_OCTLET ( avdecc_acmp, listener_guid, avdecc_eui64_t, 28 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_acmp, talker_unique_id, uint16_t, 36 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_acmp, listener_unique_id, uint16_t, 38 )
AVDECC_BITS_MAP_SEXLET ( avdecc_acmp, dest_mac, avdecc_mac_t, 40 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_acmp, connection_count, uint16_t, 46 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_acmp, sequence_id, uint16_t, 48 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_acmp, flags, uint16_t, 50 )
AVDECC_BITS_MAP_QUADLET ( avdecc_acmp, reserved1, uint32_t, 52 )


/** avdecc_acmp_t
    */

/** See IEEE 1722.1 Clause 8.2.1 */

typedef struct avdecc_acmp_s
{
    avdecc_acmp_message_type_t message_type;
    avdecc_acmp_status_t status;
    avdecc_avtp_control_data_length_t control_data_length;
    avdecc_stream_id_t stream_id;
    avdecc_eui64_t controller_guid;
    avdecc_eui64_t talker_guid;
    avdecc_eui64_t listener_guid;
    uint16_t talker_unique_id;
    uint16_t listener_unique_id;
    avdecc_mac_t dest_mac;
    uint16_t connection_count;
    uint16_t sequence_id;
    avdecc_acmp_flags_t flags;
    uint32_t reserved1;
} avdecc_acmp_t;



/** avdecc_acmp_init
     *
     *  Initialize a avdecc_acmp_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_acmp_init ( avdecc_acmp_t *self );


/** avdecc_acmp_read
     *
     *  Read a avdecc_acmp_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     *  @param len length of packet
     *  @returns bool true on success
     */

bool avdecc_acmp_read (
    avdecc_acmp_t *self,
    const void *pdu,
    size_t len
    );


/** avdecc_acmp_write
     *
     *  write a avdecc_acmp_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to, must be MTU size
     *  @param offset offset from base of pdu in octets to start writing to
     *  @param len size_t gets filled in with length of pdu generated
     *  @returns bool true on success
     */

bool avdecc_acmp_write (
    const avdecc_acmp_t *self,
    void *pdu,
    size_t *len
    );



/* @} */

#ifdef __cplusplus
}
#endif

#endif
