#ifndef AVDECC_PDU_AECP_HPP_
#define AVDECC_PDU_AECP_HPP_


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

#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_mac.hpp"
#include "avdecc-pdu_eui64.hpp"
#include "avdecc-pdu_avtp.hpp"


/**
    \addtogroup aecp
    */
/* @{ */

/** \addtogroup AECP Message types */
/* @{ */


/** See IEEE 1722.1 Clause 9.2.1.1.5 */
enum avdecc_aecp_message_type_e
{
    avdecc_aecp_message_type_aem_command=0,
    avdecc_aecp_message_type_aem_response=1,
    avdecc_aecp_message_type_address_access_command=2,
    avdecc_aecp_message_type_address_access_response=3,
    avdecc_aecp_message_type_avc_command=4,
    avdecc_aecp_message_type_avc_response=5,
    avdecc_aecp_message_type_vendor_unique_command=6,
    avdecc_aecp_message_type_vendor_unique_respone=7,
    avdecc_aecp_message_type_extended_command=14,
    avdecc_aecp_message_type_extended_response=15
};

typedef enum avdecc_aecp_message_type_e avdecc_aecp_message_type_t;

/** \addtogroup AECP Status type */
/* @{ */

/** See IEEE 1722.1 Clause 9.2.1.1.6 */
enum avdecc_aecp_status_e
{
    avdecc_aecp_status_success = 0,
    avdecc_aecp_status_not_implemented = 1
};

typedef enum avdecc_aecp_status_e avdecc_aecp_status_t;

/* @} */

/** See IEEE 1722.1 Clause 9.2.1.1.7 */
typedef avdecc_avtp_control_data_length_t avdecc_aecp_control_data_length_t;

#define AVDECC_AECP_MAX_CONTROL_DATA_LENGTH ((avdecc_aecp_control_data_length_t)(524)) /** See IEEE 1722.1 Clause 9.2.1.1.7 */

#define AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_CONTROL_DATA_LENGTH-10) /** See IEEE 1722.1 Clause 9.2.1.1.7 */

/** See IEEE 1722.1 Clause 9.2.1.1.8 */
typedef uint16_t avdecc_aecp_sequence_id_t;

/* See IEEE 1722.1 Clause 9.2.1 */

AVDECC_BITS_MAP_OCTET_BIT ( avdecc_aecp, cd, avdecc_avtp_cd_t, 0, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_aecp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 )
AVDECC_BITS_MAP_OCTET_BIT ( avdecc_aecp, sv, avdecc_avtp_sv_t, 1, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_aecp, version, avdecc_avtp_version_t, 1, 1, 3 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, message_type, avdecc_aecp_message_type_t, 0, 12, 15 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, status, avdecc_aecp_status_t, 0, 16, 20 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, control_data_length, avdecc_aecp_control_data_length_t, 0, 21, 31 )
AVDECC_BITS_MAP_OCTLET ( avdecc_aecp, target_guid, avdecc_eui64_t, 4 )
AVDECC_BITS_MAP_OCTLET ( avdecc_aecp, controller_guid, avdecc_eui64_t, 12 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_aecp, sequence_id, uint16_t, 20 )

/** avdecc_aecp_t
    */

typedef struct avdecc_aecp_s
{
    avdecc_aecp_message_type_t message_type;
    avdecc_aecp_status_t status;
    avdecc_aecp_control_data_length_t control_data_length;
    avdecc_eui64_t target_guid;
    avdecc_eui64_t controller_guid;
    avdecc_aecp_sequence_id_t sequence_id;
    uint8_t payload_specific_data[AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA];
} avdecc_aecp_t;



/** avdecc_aecp_init
     *
     *  Initialize a avdecc_aecp_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_aecp_init ( avdecc_aecp_t *self );


/** avdecc_aecp_read
     *
     *  Read a avdecc_aecp_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_aecp_read (
    avdecc_aecp_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_aecp_write
     *
     *  write a avdecc_aecp_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_aecp_write (
    const avdecc_aecp_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/**
     \addtogroup aecp_aem
     */
/* @{ */


#define AVDECC_AECP_AEM_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA-2)

/** \addtogroup AECP Status type */
/* @{ */

/** See IEEE 1722.1 Clause 7.4 */
enum avdecc_aecp_aem_status_e
{
    avdecc_aem_status_success = 0,
    avdecc_aem_status_not_implemented = 1,
    avdecc_aem_status_no_such_descriptor = 2,
    avdecc_aem_status_entity_locked = 3,
    avdecc_aem_status_entity_acquired = 4,
    avdecc_aem_status_not_authorized = 5,
    avdecc_aem_status_insufficient_privileges = 6,
    avdecc_aem_status_bad_arguments = 7,
    avdecc_aem_status_no_resources = 8,
    avdecc_aem_status_in_progress = 9
};

typedef enum avdecc_aecp_aem_status_e avdecc_aecp_aem_status_t;


/* @} */

/** See IEEE 1722.1 Clause 9.2.1.2 */

AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_aecp_aem, u, bool, 20, 16 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp_aem, command_type, uint16_t, 20, 17, 31 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp_aem, status, avdecc_aecp_aem_status_t, 0, 16, 20 )

/** avdecc_aecp_aem_t
    */

typedef struct avdecc_aecp_aem_s
{
    avdecc_aecp_message_type_t message_type;
    avdecc_aecp_aem_status_t status;
    avdecc_aecp_control_data_length_t control_data_length;
    avdecc_eui64_t target_guid;
    avdecc_eui64_t controller_guid;
    avdecc_aecp_sequence_id_t sequence_id;
    bool unsolicited;
    unsigned command_type:15;
    uint8_t payload_specific_data[AVDECC_AECP_AEM_MAX_PAYLOAD_SPECIFIC_DATA];
} avdecc_aecp_aem_t;



/** avdecc_aecp_aem_init
     *
     *  Initialize a avdecc_aecp_aem_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_aecp_aem_init ( avdecc_aecp_aem_t *self );


/** avdecc_aecp_aem_read
     *
     *  Read a avdecc_aecp_aem_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_aecp_aem_read (
    avdecc_aecp_aem_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_aecp_aem_write
     *
     *  write a avdecc_aecp_aem_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_aecp_aem_write (
    const avdecc_aecp_aem_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/**
     \addtogroup aecp_aa
     */
/* @{ */

#define AVDECC_AECP_AA_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA-2)
#define AVDECC_AECP_AA_MAX_TLV_COUNT (16) /* <<NOTE:CAPTURE>> */

/** avdecc_aecp_aa_tlv_t
     */
typedef struct avdecc_aecp_aa_tlv_s
{
    uint8_t mode;
    uint16_t length;
    uint64_t address;
    uint8_t *data;
} avdecc_aecp_aa_tlv_t;

/** avdecc_aecp_aa_t
    */

typedef struct avdecc_aecp_aa_s
{
    avdecc_aecp_message_type_t message_type;
    avdecc_aecp_status_t status;
    avdecc_aecp_control_data_length_t control_data_length;
    avdecc_eui64_t target_guid;
    avdecc_eui64_t controller_guid;
    avdecc_aecp_sequence_id_t sequence_id;
    uint16_t tlv_count;
    avdecc_aecp_aa_tlv_t tlv[AVDECC_AECP_AA_MAX_TLV_COUNT];
    uint8_t payload_specific_data[AVDECC_AECP_AA_MAX_PAYLOAD_SPECIFIC_DATA];
} avdecc_aecp_aa_t;

/** avdecc_aecp_aa_init
     *
     *  Initialize a avdecc_aecp_aa_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_aecp_aa_init ( avdecc_aecp_aa_t *self );


/** avdecc_aecp_aa_read
     *
     *  Read a avdecc_aecp_aa_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_aecp_aa_read (
    avdecc_aecp_aa_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_aecp_aa_write
     *
     *  write a avdecc_aecp_aa_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_aecp_aa_write (
    const avdecc_aecp_aa_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/**
     \addtogroup aecp_avc
     */
/* @{ */

#define AVDECC_AECP_AVC_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA-2)

/** avdecc_aecp_avc_t
    */

typedef struct avdecc_aecp_avc_s
{
    avdecc_aecp_message_type_t message_type;
    avdecc_aecp_status_t status;
    avdecc_aecp_control_data_length_t control_data_length;
    avdecc_eui64_t target_guid;
    avdecc_eui64_t controller_guid;
    avdecc_aecp_sequence_id_t sequence_id;
    uint16_t avc_length;
    uint8_t payload_specific_data[AVDECC_AECP_AVC_MAX_PAYLOAD_SPECIFIC_DATA];
} avdecc_aecp_avc_t;



/** avdecc_aecp_avc_init
     *
     *  Initialize a avdecc_aecp_avc_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_aecp_avc_init ( avdecc_aecp_avc_t *self );


/** avdecc_aecp_avc_read
     *
     *  Read a avdecc_aecp_avc_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_aecp_avc_read (
    avdecc_aecp_avc_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_aecp_avc_write
     *
     *  write a avdecc_aecp_avc_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_aecp_avc_write (
    const avdecc_aecp_avc_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/**
     \addtogroup aecp_vu
     */
/* @{ */

#define AVDECC_AECP_VU_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA-6)


/** avdecc_aecp_vu_t
    */

typedef struct avdecc_aecp_vu_s
{
    avdecc_aecp_message_type_t message_type;
    avdecc_aecp_status_t status;
    avdecc_aecp_control_data_length_t control_data_length;
    avdecc_eui64_t target_guid;
    avdecc_eui64_t controller_guid;
    avdecc_aecp_sequence_id_t sequence_id;
    uint16_t avc_length;
    avdecc_mac_t protocol_id;
    uint8_t payload_specific_data[AVDECC_AECP_VU_MAX_PAYLOAD_SPECIFIC_DATA];
} avdecc_aecp_vu_t;


/** avdecc_aecp_vu_init
     *
     *  Initialize a avdecc_aecp_vu_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_aecp_vu_init ( avdecc_aecp_vu_t *self );


/** avdecc_aecp_vu_read
     *
     *  Read a avdecc_aecp_vu_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_aecp_vu_read (
    avdecc_aecp_vu_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_aecp_vu_write
     *
     *  write a avdecc_aecp_vu_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_aecp_vu_write (
    const avdecc_aecp_vu_t *self,
    void *pdu,
    size_t offset
    );


/* @} */
/* @} */


#endif
