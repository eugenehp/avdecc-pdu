#ifndef AVDECC_PDU_AECP_H_
#define AVDECC_PDU_AECP_H_

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
#include "avdecc-pdu_avtp.h"
#include "avdecc-pdu_adp.h"


#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup aecp aecp */
    /*@{*/
    
    /** \addtogroup AECP Message types */
    /* @{ */
    
    
    /** See IEEE 1722.1 Section 9.2.1.1.5 */
    typedef enum
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
    }
            avdecc_aecp_message_type_t;
            
    /* @} */
    
    /** \addtogroup AECP Status type */
    /* @{ */
    
    /** See IEEE 1722.1 Section 9.2.1.1.6 */
    typedef enum
    {
        avdecc_aecp_status_success = 0,
        avdecc_aecp_status_not_implemented = 1
    } avdecc_aecp_status_t;
    
    /* @} */
    
    /** See IEEE 1722.1 Section 9.2.1.1.7 */
    typedef avdecc_avtp_control_data_length_t avdecc_aecp_control_data_length_t;
    
#define AVDECC_AECP_MAX_CONTROL_DATA_LENGTH ((avdecc_aecp_control_data_length_t)(524)) /** See IEEE 1722.1 Section 9.2.1.1.7 */
    
#define AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA (AVDECC_AECP_MAX_CONTROL_DATA_LENGTH-10) /** See IEEE 1722.1 Section 9.2.1.1.7 */
    
    /** See IEEE 1722.1 Section 9.2.1.1.8 */
    typedef uint16_t avdecc_aecp_sequence_id_t;
    
    /* See IEEE 1722.1 Section 9.2.1 */
    
    AVDECC_BITS_MAP_OCTET_BIT ( avdecc_aecp, cd, avdecc_avtp_cd_t, 0, 0 );
    AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_aecp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 );
    AVDECC_BITS_MAP_OCTET_BIT ( avdecc_aecp, sv, avdecc_avtp_sv_t, 1, 0 );
    AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_aecp, version, avdecc_avtp_version_t, 1, 1, 3 );
    AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, message_type, avdecc_aecp_message_type_t, 0, 12, 15 );
    AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, status, avdecc_aecp_status_t, 0, 16, 20 );
    AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_aecp, control_data_length, avdecc_aecp_control_data_length_t, 0, 21, 31 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_aecp, target_guid, avdecc_eui64_t, 4 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_aecp, controller_guid, avdecc_eui64_t, 12 );
    AVDECC_BITS_MAP_DOUBLET ( avdecc_aecp, sequence_id, uint16_t, 20 );
    
    typedef struct avdecc_aecp_s
    {
        avdecc_aecp_message_type_t message_type;
        avdecc_aecp_status_t status;
        avdecc_eui64_t controller_guid;
        avdecc_aecp_control_data_length_t control_data_length;
        avdecc_aecp_sequence_id_t sequence_id;
        uint8_t payload_specific_data[AVDECC_AECP_MAX_PAYLOAD_SPECIFIC_DATA];
    } avdecc_aecp_t;
    
    void avdecc_aecp_init ( avdecc_aecp_t *self );
    bool avdecc_aecp_read_pdu ( avdecc_aecp_t *self, const void *pdu );
    size_t avdecc_aecp_write_pdu ( const avdecc_aecp_t *self, void *pdu );
    
    /*@}*/
    
#ifdef __cplusplus
}
#endif



#endif
