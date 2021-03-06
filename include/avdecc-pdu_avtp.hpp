#ifndef AVDECC_PDU_AVTP_HPP_
#define AVDECC_PDU_AVTP_HPP_


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
#include "avdecc-pdu_bits.hpp"
#include "avdecc-pdu_stream.hpp"
#include "avdecc-pdu_stream_print.hpp"


/**
    \addtogroup avtp
    */
/* @{ */


/** full 64 bit presentation time value type */
typedef uint64_t avdecc_avtp_presentation_time_t;

/** full 64 bit presentation time offset value type */
typedef int64_t avdecc_avtp_presentation_time_offset_t;

/* @} */

typedef enum
{
    avdecc_avtp_cd_data=0,
    avdecc_avtp_cd_control=1
} avdecc_avtp_cd_t;

typedef enum
{
    avdecc_avtp_subtype_61883_IICD = 0x00,
    avdecc_avtp_subtype_mma = 0x01,
    avdecc_avtp_subtype_aaf = 0x02,
    avdecc_avtp_subtype_avf = 0x03,
    avdecc_avtp_subtype_cs = 0x04,
    avdecc_avtp_subtype_adp = 0x7a,
    avdecc_avtp_subtype_aecp = 0x7b,
    avdecc_avtp_subtype_acmp = 0x7c,
    avdecc_avtp_subtype_mcn = 0x7d,
    avdecc_avtp_subtype_maap = 0x7e,
    avdecc_avtp_subtype_experimental = 0x7f
} avdecc_avtp_subtype_t;


typedef enum
{
    avdecc_avtp_sv_not_valid = 0,
    avdecc_avtp_sv_valid = 1
} avdecc_avtp_sv_t;

typedef uint8_t avdecc_avtp_version_t;

typedef uint32_t avdecc_avtp_type_specific_data_t;

typedef uint8_t avdecc_avtp_control_data_t;

typedef uint8_t avdecc_avtp_control_status_t;

typedef uint16_t avdecc_avtp_control_data_length_t;

typedef bool avdecc_avtp_stream_mr_t;

typedef bool avdecc_avtp_stream_r_t;

typedef bool avdecc_avtp_stream_gv_t;

typedef bool avdecc_avtp_stream_tv_t;

typedef uint8_t avdecc_avtp_stream_sequence_num_t;

typedef uint8_t avdecc_avtp_stream_reserved_t;

typedef bool avdecc_avtp_stream_tu_t;

typedef uint32_t avdecc_avtp_stream_timestamp_t;

typedef uint32_t avdecc_avtp_stream_gateway_info_t;

typedef uint16_t avdecc_avtp_stream_data_length_t;

typedef uint16_t avdecc_avtp_stream_protocol_specific_header_t;

AVDECC_BITS_MAP_OCTET_BIT ( avdecc_avtp, cd, avdecc_avtp_cd_t, 0, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_avtp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_avtp, sv, avdecc_avtp_sv_t, 1, 0, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_avtp, version, avdecc_avtp_version_t, 1, 1, 3 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, type_specific_data, avdecc_avtp_type_specific_data_t, 0, 12, 31 )
AVDECC_BITS_MAP_OCTLET ( avdecc_avtp, stream_id, avdecc_stream_id_t, 4 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, control_data, avdecc_avtp_control_data_t, 0, 12, 15 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, control_status, avdecc_avtp_control_status_t, 0, 16, 20 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, control_data_length, avdecc_avtp_control_data_length_t, 0, 21, 31 )
AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_avtp, stream_mr, avdecc_avtp_stream_mr_t, 0, 12 )
AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_avtp, stream_r, avdecc_avtp_stream_r_t, 0, 13 )
AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_avtp, stream_gv, avdecc_avtp_stream_gv_t, 0, 14 )
AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_avtp, stream_tv, avdecc_avtp_stream_tv_t, 0, 15 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, sequence_num, avdecc_avtp_stream_sequence_num_t, 0, 16, 23 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_avtp, stream_reserved, avdecc_avtp_stream_reserved_t, 0, 24, 30 )
AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_avtp, stream_tu, avdecc_avtp_stream_tu_t, 0, 31 )
AVDECC_BITS_MAP_QUADLET ( avdecc_avtp, stream_avtp_timestamp, avdecc_avtp_stream_timestamp_t, 12 )
AVDECC_BITS_MAP_QUADLET ( avdecc_avtp, stream_gateway_info, avdecc_avtp_stream_gateway_info_t, 16 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_avtp, stream_data_length, avdecc_avtp_stream_data_length_t, 20 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_avtp, stream_protocol_specific_header, avdecc_avtp_stream_protocol_specific_header_t, 22 )



/** avdecc_avtp_common_t
    */

typedef struct avdecc_avtp_common_s
{
    avdecc_avtp_cd_t cd;
    avdecc_avtp_subtype_t subtype;
    avdecc_avtp_sv_t sv;
    avdecc_avtp_version_t version;
    avdecc_avtp_type_specific_data_t type_specific_data;
    avdecc_stream_id_t stream_id;
} avdecc_avtp_common_t;



/** avdecc_avtp_common_init
     *
     *  Initialize a avdecc_avtp_common_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_avtp_common_init ( avdecc_avtp_common_t *self );


/** avdecc_avtp_common_read
     *
     *  Read a avdecc_avtp_common_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_avtp_common_read (
    avdecc_avtp_common_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_avtp_common_write
     *
     *  write a avdecc_avtp_common_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_avtp_common_write (
    const avdecc_avtp_common_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_avtp_stream_t
    */

typedef struct avdecc_avtp_stream_s
{
    avdecc_avtp_cd_t cd;
    avdecc_avtp_subtype_t subtype;
    avdecc_avtp_sv_t sv;
    avdecc_avtp_version_t version;
    avdecc_avtp_stream_mr_t mr;
    avdecc_avtp_stream_r_t r;
    avdecc_avtp_stream_gv_t gv;
    avdecc_avtp_stream_tv_t tv;
    avdecc_avtp_stream_sequence_num_t sequence_num;
    avdecc_avtp_stream_reserved_t reserved;
    avdecc_avtp_stream_tu_t tu;
    avdecc_stream_id_t stream_id;
    avdecc_avtp_stream_timestamp_t avtp_timestamp;
    avdecc_avtp_stream_gateway_info_t gateway_info;
    avdecc_avtp_stream_data_length_t stream_data_length;
    avdecc_avtp_stream_protocol_specific_header_t protocol_specific_header;
} avdecc_avtp_stream_t;


/** avdecc_avtp_stream_init
     *
     *  Initialize a avdecc_avtp_stream_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_avtp_stream_init ( avdecc_avtp_stream_t *self );


/** avdecc_avtp_stream_read
     *
     *  Read a avdecc_avtp_stream_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_avtp_stream_read (
    avdecc_avtp_stream_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_avtp_stream_write
     *
     *  write a avdecc_avtp_stream_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_avtp_stream_write (
    const avdecc_avtp_stream_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_avtp_control_t
    */

typedef struct avdecc_avtp_control_s
{
    avdecc_avtp_cd_t cd;
    avdecc_avtp_subtype_t subtype;
    avdecc_avtp_sv_t sv;
    avdecc_avtp_version_t version;
    avdecc_avtp_control_data_t control_data;
    avdecc_avtp_control_status_t control_status;
    avdecc_avtp_control_data_length_t control_data_length;
    avdecc_stream_id_t stream_id;
} avdecc_avtp_control_t;


/** avdecc_avtp_control_init
     *
     *  Initialize a avdecc_avtp_control_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_avtp_control_init ( avdecc_avtp_control_t *self );


/** avdecc_avtp_control_read
     *
     *  Read a avdecc_avtp_control_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     */

bool avdecc_avtp_control_read (
    avdecc_avtp_control_t *self,
    const void *pdu,
    size_t len
    );


/** avdecc_avtp_control_write
     *
     *  write a avdecc_avtp_control_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     */

bool avdecc_avtp_control_write (
    const avdecc_avtp_control_t *self,
    void *pdu,
    size_t *len
    );



/* @} */


#endif
