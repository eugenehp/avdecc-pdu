#ifndef AVDECC_PDU_ADP_HPP_
#define AVDECC_PDU_ADP_HPP_


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
#include "avdecc-pdu_eui64.hpp"
#include "avdecc-pdu_avtp.hpp"


/**
    \addtogroup adp
    */
/* @{ */

typedef uint8_t avdecc_adp_valid_time_t;

/** \addtogroup ADP Message types */
/* @{ */
typedef enum
{
    avdecc_adp_message_type_entity_available=0,
    avdecc_adp_message_type_entity_departing=1,
    avdecc_adp_message_type_entity_discover=2
} avdecc_adp_message_type_t;
/* @} */

#define AVDECC_ADP_TALKER_CAP_IMPLEMENTED_BIT (15)
#define AVDECC_ADP_TALKER_CAP_IMPLEMENTED (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_IMPLEMENTED_BIT))
#define AVDECC_ADP_TALKER_CAP_OTHER_SOURCE_BIT (6)
#define AVDECC_ADP_TALKER_CAP_OTHER_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_OTHER_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_CONTROL_SOURCE_BIT (5)
#define AVDECC_ADP_TALKER_CAP_CONTROL_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_CONTROL_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_MEDIA_CLOCK_SOURCE_BIT (4)
#define AVDECC_ADP_TALKER_CAP_MEDIA_CLOCK_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_MEDIA_CLOCK_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_SMPTE_SOURCE_BIT (3)
#define AVDECC_ADP_TALKER_CAP_SMPTE_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_SMPTE_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_MIDI_SOURCE_BIT (2)
#define AVDECC_ADP_TALKER_CAP_MIDI_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_MIDI_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_AUDIO_SOURCE_BIT (1)
#define AVDECC_ADP_TALKER_CAP_AUDIO_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_AUDIO_SOURCE_BIT))
#define AVDECC_ADP_TALKER_CAP_VIDEO_SOURCE_BIT (0)
#define AVDECC_ADP_TALKER_CAP_VIDEO_SOURCE (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_TALKER_CAP_VIDEO_SOURCE_BIT))

typedef struct avdecc_adp_talker_capabilities_s
{
    unsigned implemented:1;
    unsigned other_source:1;
    unsigned control_source:1;
    unsigned media_clock_source:1;
    unsigned smpte_source:1;
    unsigned midi_source:1;
    unsigned audio_source:1;
    unsigned video_source:1;
} avdecc_adp_talker_capabilities_t;

static inline void avdecc_adp_talker_capabilities_init ( avdecc_adp_talker_capabilities_t *self )
{
    memset ( self, 0, sizeof ( *self ) );
}

static inline void avdecc_adp_talker_capabilities_read ( avdecc_adp_talker_capabilities_t *self, uint16_t v )
{
    self->implemented = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_IMPLEMENTED_BIT );
    self->other_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_OTHER_SOURCE_BIT );
    self->control_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_CONTROL_SOURCE_BIT );
    self->media_clock_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_MEDIA_CLOCK_SOURCE_BIT );
    self->smpte_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_SMPTE_SOURCE_BIT );
    self->midi_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_MIDI_SOURCE_BIT );
    self->audio_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_AUDIO_SOURCE_BIT );
    self->video_source = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_TALKER_CAP_VIDEO_SOURCE_BIT );
}

static inline uint16_t avdecc_adp_talker_capabilities_write ( const avdecc_adp_talker_capabilities_t *self )
{
    uint16_t v=0;

    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_IMPLEMENTED_BIT, self->implemented );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_OTHER_SOURCE_BIT, self->other_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_CONTROL_SOURCE_BIT, self->control_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_MEDIA_CLOCK_SOURCE_BIT, self->media_clock_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_SMPTE_SOURCE_BIT, self->smpte_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_MIDI_SOURCE_BIT, self->midi_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_AUDIO_SOURCE_BIT, self->audio_source );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_TALKER_CAP_VIDEO_SOURCE_BIT, self->video_source );
    return v;
}



#define AVDECC_ADP_LISTENER_CAP_IMPLEMENTED_BIT (15)
#define AVDECC_ADP_LISTENER_CAP_IMPLEMENTED (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_IMPLEMENTED_BIT))
#define AVDECC_ADP_LISTENER_CAP_OTHER_SINK_BIT (6)
#define AVDECC_ADP_LISTENER_CAP_OTHER_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_OTHER_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_CONTROL_SINK_BIT (5)
#define AVDECC_ADP_LISTENER_CAP_CONTROL_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_CONTROL_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_MEDIA_CLOCK_SINK_BIT (4)
#define AVDECC_ADP_LISTENER_CAP_MEDIA_CLOCK_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_MEDIA_CLOCK_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_SMPTE_SINK_BIT (3)
#define AVDECC_ADP_LISTENER_CAP_SMPTE_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_SMPTE_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_MIDI_SINK_BIT (2)
#define AVDECC_ADP_LISTENER_CAP_MIDI_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_MIDI_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_AUDIO_SINK_BIT (1)
#define AVDECC_ADP_LISTENER_CAP_AUDIO_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_AUDIO_SINK_BIT))
#define AVDECC_ADP_LISTENER_CAP_VIDEO_SINK_BIT (0)
#define AVDECC_ADP_LISTENER_CAP_VIDEO_SINK (AVDECC_BITS_DOUBLET_BIT(AVDECC_ADP_LISTENER_CAP_VIDEO_SINK_BIT))

typedef struct avdecc_adp_listener_capabilities_s
{
    unsigned implemented:1;
    unsigned other_sink:1;
    unsigned control_sink:1;
    unsigned media_clock_sink:1;
    unsigned smpte_sink:1;
    unsigned midi_sink:1;
    unsigned audio_sink:1;
    unsigned video_sink:1;
} avdecc_adp_listener_capabilities_t;

static inline void avdecc_adp_listener_capabilities_init ( avdecc_adp_listener_capabilities_t *self )
{
    memset ( self, 0, sizeof ( *self ) );
}

static inline void avdecc_adp_listener_capabilities_read ( avdecc_adp_listener_capabilities_t *self, uint16_t v )
{
    self->implemented = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_IMPLEMENTED_BIT );
    self->other_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_OTHER_SINK_BIT );
    self->control_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_CONTROL_SINK_BIT );
    self->media_clock_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_MEDIA_CLOCK_SINK_BIT );
    self->smpte_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_SMPTE_SINK_BIT );
    self->midi_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_MIDI_SINK_BIT );
    self->audio_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_AUDIO_SINK_BIT );
    self->video_sink = AVDECC_BITS_IS_DOUBLET_BIT_SET ( v,AVDECC_ADP_LISTENER_CAP_VIDEO_SINK_BIT );
}

static inline uint16_t avdecc_adp_listener_capabilities_write ( const avdecc_adp_listener_capabilities_t *self )
{
    uint16_t v=0;

    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_IMPLEMENTED_BIT, self->implemented );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_OTHER_SINK_BIT, self->other_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_CONTROL_SINK_BIT, self->control_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_MEDIA_CLOCK_SINK_BIT, self->media_clock_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_SMPTE_SINK_BIT, self->smpte_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_MIDI_SINK_BIT, self->midi_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_AUDIO_SINK_BIT, self->audio_sink );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF ( v,AVDECC_ADP_LISTENER_CAP_VIDEO_SINK_BIT, self->video_sink );
    return v;
}


/** \addtogroup EntityCapabilities Entity Capabilities */
/* @{ */
#define AVDECC_ADP_ENTITY_CAP_DFU_MODE_BIT (31)
#define AVDECC_ADP_ENTITY_CAP_DFU_MODE_IP (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_DFU_MODE_BIT))
#define AVDECC_ADP_ENTITY_CAP_ADDRESS_ACCESS_SUPPORTED_BIT (30)
#define AVDECC_ADP_ENTITY_CAP_ADDRESS_ACCESS_SUPPORTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ADDRESS_ACCESS_SUPPORTED_BIT))
#define AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT (29)
#define AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT))
#define AVDECC_ADP_ENTITY_CAP_AEM_SUPPORTED_BIT (28)
#define AVDECC_ADP_ENTITY_CAP_AEM_SUPPORTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_AEM_SUPPORTED_BIT))
#define AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT (27)
#define AVDECC_ADP_ENTITY_CAP_LEGACY_AVC (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT))
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT (26)
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT))
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT (25)
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT))
#define AVDECC_ADP_ENTITY_CAP_VENDOR_UNIQUE_SUPPORTED_BIT (25)
#define AVDECC_ADP_ENTITY_CAP_VENDOR_UNIQUE_SUPPORTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_VENDOR_UNIQUE_SUPPORTED_BIT))

typedef struct avdecc_adp_entity_capabilities_s
{
    unsigned dfu_mode:1;
    unsigned address_access_supported:1;
    unsigned gateway_entity:1;
    unsigned aem_supported:1;
    unsigned legacy_avc:1;
    unsigned association_id_supported:1;
    unsigned association_id_valid:1;
    unsigned vendor_unique_supported:1;
} avdecc_adp_entity_capabilities_t;

static inline void avdecc_adp_entity_capabilities_init ( avdecc_adp_entity_capabilities_t *self )
{
    memset ( self,0,sizeof ( *self ) );
}

static inline void avdecc_adp_entity_capabilities_read (
    avdecc_adp_entity_capabilities_t *self,
    const uint32_t v
    )
{
    self->dfu_mode= AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_DFU_MODE_BIT );
    self->address_access_supported= AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_ADDRESS_ACCESS_SUPPORTED_BIT );
    self->gateway_entity = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT );
    self->aem_supported = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_AEM_SUPPORTED_BIT );
    self->legacy_avc = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT );
    self->association_id_supported = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT );
    self->association_id_valid = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT );
    self->vendor_unique_supported = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_VENDOR_UNIQUE_SUPPORTED_BIT );
}

static inline uint32_t avdecc_adp_entity_capabilities_write (
    const avdecc_adp_entity_capabilities_t *self
    )
{
    uint32_t v=0;
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_DFU_MODE_BIT, self->dfu_mode );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ADDRESS_ACCESS_SUPPORTED_BIT, self->address_access_supported );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT, self->gateway_entity );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_AEM_SUPPORTED_BIT, self->aem_supported );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT, self->legacy_avc );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT, self->association_id_supported );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT, self->association_id_valid );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_VENDOR_UNIQUE_SUPPORTED_BIT, self->vendor_unique_supported );
    return v;
}

/* @} */




/** \addtogroup ControllerCapabilities Controller Capabilities */
/* @{ */
#define AVDECC_ADP_CONTROLLER_CAP_IMPLEMENTED_BIT (31)
#define AVDECC_ADP_CONTROLLER_CAP_IMPLEMENTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_CONTROLLER_CAP_IMPLEMENTED_BIT))
#define AVDECC_ADP_CONTROLLER_CAP_LAYER3_PROXY_BIT (30)
#define AVDECC_ADP_CONTROLLER_CAP_LAYER3_PROXY (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_CONTROLLER_CAP_LAYER3_PROXY_BIT))

typedef struct avdecc_adp_controller_capabilities_s
{
    unsigned implemented:1;
    unsigned layer3_proxy:1;
} avdecc_adp_controller_capabilities_t;

static inline void avdecc_adp_controller_capabilities_read ( avdecc_adp_controller_capabilities_t *self, uint32_t v )
{
    self->implemented = AVDECC_BITS_IS_QUADLET_BIT_SET ( v,AVDECC_ADP_CONTROLLER_CAP_IMPLEMENTED_BIT );
    self->layer3_proxy = AVDECC_BITS_IS_QUADLET_BIT_SET ( v, AVDECC_ADP_CONTROLLER_CAP_LAYER3_PROXY_BIT );
}

static inline uint32_t avdecc_adp_controller_capabilities_write ( const avdecc_adp_controller_capabilities_t *self )
{
    uint32_t v=0;
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_CONTROLLER_CAP_IMPLEMENTED_BIT, self->implemented );
    v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_CONTROLLER_CAP_LAYER3_PROXY_BIT, self->layer3_proxy );
    return v;
}

/* @} */

/** \addtogroup ADP class vlan_id fields */
/* @{ */
typedef struct avdecc_adp_vlan_id_s
{
    unsigned pcp:3;
    unsigned dei:1;
    unsigned vid:12;
} avdecc_adp_vlan_id_t;

static inline void avdecc_adp_vlan_id_read( avdecc_adp_vlan_id_t *self, uint16_t v )
{
    self->pcp = AVDECC_BITS_GET_DOUBLET_BITFIELD(v,0,2);
    self->dei = AVDECC_BITS_GET_DOUBLET_BITFIELD(v,3,3);
    self->vid = AVDECC_BITS_GET_DOUBLET_BITFIELD(v,4,15);
}

static inline uint16_t avdecc_adp_vlan_id_write( const avdecc_adp_vlan_id_t *self )
{
    uint16_t v = 0;
    v = AVDECC_BITS_SET_DOUBLET_BITFIELD( v, 0, 3, self->pcp );
    v = AVDECC_BITS_SET_DOUBLET_BITFIELD( v, 3, 3, self->dei );
    v = AVDECC_BITS_SET_DOUBLET_BITFIELD( v, 4, 15, self->vid );
	return v;
}

/* @} */




typedef avdecc_avtp_control_data_length_t avdecc_adp_control_data_length_t;

#define AVDECC_ADP_CONTROL_DATA_LENGTH ((avdecc_adp_control_data_length_t)(56))     /* See IEEE 1722.1 Clause 6.2.1.7 */


/* See IEEE 1722.1 Clause 6.2.1 */

AVDECC_BITS_MAP_OCTET_BIT ( avdecc_adp, cd, avdecc_avtp_cd_t, 0, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_adp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 )
AVDECC_BITS_MAP_OCTET_BIT ( avdecc_adp, sv, avdecc_avtp_sv_t, 1, 0 )
AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_adp, version, avdecc_avtp_version_t, 1, 1, 3 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_adp, message_type, avdecc_adp_message_type_t, 0, 12, 15 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_adp, valid_time, avdecc_adp_valid_time_t, 0, 16, 20 )
AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_adp, control_data_length, avdecc_adp_control_data_length_t, 0, 21, 31 )
AVDECC_BITS_MAP_OCTLET ( avdecc_adp, entity_guid, avdecc_eui64_t, 4 )
AVDECC_BITS_MAP_OCTLET ( avdecc_adp, vendor_model_id, avdecc_eui64_t, 12 )
AVDECC_BITS_MAP_QUADLET ( avdecc_adp, entity_capabilities, uint32_t, 20 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, talker_stream_sources, uint16_t, 24 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, talker_capabilities, uint16_t, 26 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, listener_stream_sinks, uint16_t, 28 )
AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, listener_capabilities, uint16_t, 30 )
AVDECC_BITS_MAP_QUADLET ( avdecc_adp, controller_capabilities, uint32_t, 32 )
AVDECC_BITS_MAP_QUADLET ( avdecc_adp, available_index, uint32_t, 36 )
AVDECC_BITS_MAP_OCTLET ( avdecc_adp, as_grandmaster_id, avdecc_eui64_t, 40 )
AVDECC_BITS_MAP_QUADLET ( avdecc_adp, reserved1, uint32_t, 52 )
AVDECC_BITS_MAP_OCTLET ( avdecc_adp, association_id, avdecc_eui64_t, 56 )
AVDECC_BITS_MAP_QUADLET ( avdecc_adp, entity_type, uint32_t, 64 )

/** avdecc_adp_t
    */

typedef struct avdecc_adp_s
{
    avdecc_adp_message_type_t message_type;
    avdecc_adp_valid_time_t valid_time;
    avdecc_eui64_t entity_guid;
    avdecc_eui64_t vendor_model_id;
    avdecc_adp_entity_capabilities_t entity_capabilities;
    uint16_t talker_stream_sources;
    avdecc_adp_talker_capabilities_t talker_capabilities;
    uint16_t listener_stream_sinks;
    avdecc_adp_listener_capabilities_t listener_capabilities;
    avdecc_adp_controller_capabilities_t controller_capabilities;
    uint32_t available_index;
    avdecc_eui64_t as_grandmaster_id;
    avdecc_adp_vlan_id_t class_a_vlan_tci;
    avdecc_adp_vlan_id_t class_b_vlan_tci;
    uint32_t reserved1;
    avdecc_eui64_t association_id;
    uint32_t entity_type;
} avdecc_adp_t;



/** avdecc_adp_init
     *
     *  Initialize a avdecc_adp_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_adp_init ( avdecc_adp_t *self );


/** avdecc_adp_read
     *
     *  Read a avdecc_adp_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     */

bool avdecc_adp_read (
    avdecc_adp_t *self,
    const void *pdu,
    size_t len
    );


/** avdecc_adp_write
     *
     *  write a avdecc_adp_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     */

bool avdecc_adp_write (
    const avdecc_adp_t *self,
    void *pdu,
    size_t *len
    );



/* @} */


#endif
