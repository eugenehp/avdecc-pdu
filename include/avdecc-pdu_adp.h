#ifndef AVDECC_PDU_ADP_H_
#define AVDECC_PDU_ADP_H_

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
#include "avdecc-pdu_mac.h"
#include "avdecc-pdu_eui64.h"
#include "avdecc-pdu_stream.h"
#include "avdecc-pdu_avtp.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup adp adp */
    /*@{*/
    
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
#define AVDECC_ADP_ENTITY_CAP_AVDECC_IP_BIT (31)
#define AVDECC_ADP_ENTITY_CAP_AVDECC_IP (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_AVDECC_IP_BIT))
#define AVDECC_ADP_ENTITY_CAP_ZERO_CONF_BIT (30)
#define AVDECC_ADP_ENTITY_CAP_ZERO_CONF (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ZERO_CONF_BIT))
#define AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT (29)
#define AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT))
#define AVDECC_ADP_ENTITY_CAP_AVDECC_CONTROL_BIT (28)
#define AVDECC_ADP_ENTITY_CAP_AVDECC_CONTROL (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_AVDECC_CONTROL_BIT))
#define AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT (27)
#define AVDECC_ADP_ENTITY_CAP_LEGACY_AVC (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT))
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT (26)
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT))
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT (25)
#define AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT))
    
    typedef struct avdecc_adp_entity_capabilities_s
    {
        unsigned avdecc_ip:1;
        unsigned zero_conf:1;
        unsigned gateway_entity:1;
        unsigned avdecc_control:1;
        unsigned legacy_avc:1;
        unsigned association_id_supported:1;
        unsigned association_id_valid:1;
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
        self->avdecc_ip= AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_AVDECC_IP_BIT );
        self->zero_conf = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_ZERO_CONF_BIT );
        self->gateway_entity = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT );
        self->avdecc_control = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_AVDECC_CONTROL_BIT );
        self->legacy_avc = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT );
        self->association_id_supported = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT );
        self->association_id_valid = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT );
    }
    
    static inline uint32_t avdecc_adp_entity_capabilities_write (
        const avdecc_adp_entity_capabilities_t *self
    )
    {
        uint32_t v=0;
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_AVDECC_IP_BIT, self->avdecc_ip );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ZERO_CONF_BIT, self->zero_conf );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_GATEWAY_ENTITY_BIT, self->gateway_entity );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_AVDECC_CONTROL_BIT, self->avdecc_control );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_LEGACY_AVC_BIT, self->legacy_avc );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_SUPPORTED_BIT, self->association_id_supported );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_CAP_ASSOCIATION_ID_VALID_BIT, self->association_id_valid );
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
    
    
    
    
    
    /** \addtogroup  EntityDefaultAudio Default audio format sample rates */
    /* @{ */
#define AVDECC_ADP_DEFAULT_AUDIO_SR_44K1_BIT (5)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_48K (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_48K_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_SR_48K_BIT (4)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_48K (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_48K_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_SR_88K2_BIT (3)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_88K2 (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_88K2_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_SR_96K_BIT (2)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_96K (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_96K_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_SR_176K4_BIT (1)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_176K4 (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_176K4_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_SR_192K_BIT (0)
#define AVDECC_ADP_DEFAULT_AUDIO_SR_192K (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_SR_192K_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_AAF_BIT (14)
#define AVDECC_ADP_DEFAULT_AUDIO_AAF (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_AAF_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_FLOAT_BIT (15)
#define AVDECC_ADP_DEFAULT_AUDIO_FLOAT (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_FLOAT_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_24_CH_BIT (16)
#define AVDECC_ADP_DEFAULT_AUDIO_24_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_24_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_22_CH_BIT (17)
#define AVDECC_ADP_DEFAULT_AUDIO_22_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_22_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_20_CH_BIT (18)
#define AVDECC_ADP_DEFAULT_AUDIO_20_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_20_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_18_CH_BIT (19)
#define AVDECC_ADP_DEFAULT_AUDIO_18_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_18_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_16_CH_BIT (20)
#define AVDECC_ADP_DEFAULT_AUDIO_16_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_16_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_14_CH_BIT (21)
#define AVDECC_ADP_DEFAULT_AUDIO_14_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_14_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_12_CH_BIT (22)
#define AVDECC_ADP_DEFAULT_AUDIO_12_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_12_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_10_CH_BIT (23)
#define AVDECC_ADP_DEFAULT_AUDIO_10_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_10_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_8_CH_BIT (24)
#define AVDECC_ADP_DEFAULT_AUDIO_8_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_8_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_7_CH_BIT (25)
#define AVDECC_ADP_DEFAULT_AUDIO_7_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_7_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_6_CH_BIT (26)
#define AVDECC_ADP_DEFAULT_AUDIO_6_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_6_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_5_CH_BIT (27)
#define AVDECC_ADP_DEFAULT_AUDIO_5_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_5_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_4_CH_BIT (28)
#define AVDECC_ADP_DEFAULT_AUDIO_4_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_4_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_3_CH_BIT (29)
#define AVDECC_ADP_DEFAULT_AUDIO_3_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_3_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_2_CH_BIT (30)
#define AVDECC_ADP_DEFAULT_AUDIO_2_CH (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_2_CH_BIT))
#define AVDECC_ADP_DEFAULT_AUDIO_MONO_BIT (31)
#define AVDECC_ADP_DEFAULT_AUDIO_MONO (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_AUDIO_MONO_BIT))
    
    typedef struct avdecc_adp_default_audio_format_s
    {
        unsigned audio_sr_44k1:1;
        unsigned audio_sr_48k:1;
        unsigned audio_sr_88k2:1;
        unsigned audio_sr_96k:1;
        unsigned audio_sr_176k4:1;
        unsigned audio_sr_192k:1;
        unsigned audio_aaf:1;
        unsigned audio_float:1;
        unsigned audio_24_ch:1;
        unsigned audio_22_ch:1;
        unsigned audio_20_ch:1;
        unsigned audio_18_ch:1;
        unsigned audio_16_ch:1;
        unsigned audio_14_ch:1;
        unsigned audio_12_ch:1;
        unsigned audio_10_ch:1;
        unsigned audio_8_ch:1;
        unsigned audio_7_ch:1;
        unsigned audio_6_ch:1;
        unsigned audio_5_ch:1;
        unsigned audio_4_ch:1;
        unsigned audio_3_ch:1;
        unsigned audio_2_ch:1;
        unsigned audio_mono:1;
        int max_channels;
    } avdecc_adp_default_audio_format_t;
    
    static inline void avdecc_adp_default_audio_format_init ( avdecc_adp_default_audio_format_t *self )
    {
        memset ( self,0,sizeof ( *self ) );
    }
    
    static inline void avdecc_adp_default_audio_format_read (
        avdecc_adp_default_audio_format_t *self,
        const uint32_t v
    )
    {
        self->audio_sr_44k1 = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_44K1_BIT );
        self->audio_sr_48k = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_48K_BIT );
        self->audio_sr_88k2 = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_88K2_BIT );
        self->audio_sr_96k = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_96K_BIT );
        self->audio_sr_176k4 = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_176K4_BIT );
        self->audio_sr_192k = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_192K_BIT );
        self->audio_aaf = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_AAF_BIT );
        self->audio_float = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_FLOAT_BIT );
        self->audio_24_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_24_CH_BIT );
        self->audio_22_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_22_CH_BIT );
        self->audio_20_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_20_CH_BIT );
        self->audio_18_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_18_CH_BIT );
        self->audio_16_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_16_CH_BIT );
        self->audio_14_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_14_CH_BIT );
        self->audio_12_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_12_CH_BIT );
        self->audio_10_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_10_CH_BIT );
        self->audio_8_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_8_CH_BIT );
        self->audio_7_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_7_CH_BIT );
        self->audio_6_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_6_CH_BIT );
        self->audio_5_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_5_CH_BIT );
        self->audio_4_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_4_CH_BIT );
        self->audio_3_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_3_CH_BIT );
        self->audio_2_ch = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_2_CH_BIT );
        self->audio_mono = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_DEFAULT_AUDIO_MONO_BIT );
        self->max_channels = AVDECC_BITS_GET_QUADLET_BITFIELD ( v, 6, 13 );
    }
    
    static inline uint32_t avdecc_adp_default_audio_format_write (
        const avdecc_adp_default_audio_format_t *self
    )
    {
        uint32_t v=0;
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_44K1_BIT, self->audio_sr_44k1 );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_48K_BIT, self->audio_sr_48k );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_88K2_BIT, self->audio_sr_88k2 );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_96K_BIT, self->audio_sr_96k );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_176K4_BIT, self->audio_sr_176k4 );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_SR_192K_BIT, self->audio_sr_192k );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_AAF_BIT, self->audio_aaf );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_FLOAT_BIT, self->audio_float );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_24_CH_BIT, self->audio_24_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_22_CH_BIT, self->audio_22_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_20_CH_BIT, self->audio_20_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_18_CH_BIT, self->audio_18_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_16_CH_BIT, self->audio_16_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_14_CH_BIT, self->audio_14_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_12_CH_BIT, self->audio_12_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_10_CH_BIT, self->audio_10_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_8_CH_BIT, self->audio_8_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_7_CH_BIT, self->audio_7_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_6_CH_BIT, self->audio_6_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_5_CH_BIT, self->audio_5_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_4_CH_BIT, self->audio_4_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_3_CH_BIT, self->audio_3_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_2_CH_BIT, self->audio_2_ch );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_AUDIO_MONO_BIT, self->audio_mono );
        v = AVDECC_BITS_SET_QUADLET_BITFIELD ( v, 6, 13, self->max_channels );
        return v;
    }
    
    static inline void avdecc_adp_default_audio_format_merge (
        avdecc_adp_default_audio_format_t *self,
        const avdecc_adp_default_audio_format_t *a,
        const avdecc_adp_default_audio_format_t *b
    )
    {
        uint32_t av = avdecc_adp_default_audio_format_write ( a );
        uint32_t bv = avdecc_adp_default_audio_format_write ( b );
        uint32_t mergev = av & bv;
        int merged_max_channels =  a->max_channels > b->max_channels ? a->max_channels : b->max_channels;
        avdecc_adp_default_audio_format_read ( self, mergev );
        self->max_channels = merged_max_channels;
    }
    
    
    /* @} */
    
    
    /** \addtogroup EntityDefaultVideo Default video format bits */
    /* @{ */
#define AVDECC_ADP_DEFAULT_VIDEO_AVF_BIT (0)
#define AVDECC_ADP_DEFAULT_VIDEO_AVF (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_VIDEO_AVF_BIT))
#define AVDECC_ADP_DEFAULT_VIDEO_61883_4_BIT (1)
#define AVDECC_ADP_DEFAULT_VIDEO_61883_4 (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_VIDEO_61883_4_BIT))
#define AVDECC_ADP_DEFAULT_VIDEO_61883_8_BIT (2)
#define AVDECC_ADP_DEFAULT_VIDEO_61883_8 (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_VIDEO_61883_8_BIT))
#define AVDECC_ADP_DEFAULT_VIDEO_IIDC_BIT (3)
#define AVDECC_ADP_DEFAULT_VIDEO_IIDC (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_DEFAULT_VIDEO_IIDC_BIT))
    
    typedef struct avdecc_adp_default_video_format_s
    {
        unsigned video_avf:1;
        unsigned video_61883_4:1;
        unsigned video_61883_8:1;
        unsigned video_iidc:1;
    } avdecc_adp_default_video_format_t;
    
    static inline void avdecc_adp_default_video_format_init ( avdecc_adp_default_video_format_t *self )
    {
        memset ( self,0,sizeof ( *self ) );
    }
    
    static inline void avdecc_adp_default_video_format_read (
        avdecc_adp_default_video_format_t *self,
        const uint32_t v
    )
    {
        self->video_avf = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_VIDEO_AVF_BIT );
        self->video_61883_4 = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_VIDEO_61883_4_BIT );
        self->video_61883_8 = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_VIDEO_61883_8_BIT );
        self->video_iidc = AVDECC_BITS_GET_QUADLET_BIT ( v, AVDECC_ADP_DEFAULT_VIDEO_IIDC_BIT );
    }
    
    static inline uint32_t avdecc_adp_default_video_format_write (
        const avdecc_adp_default_video_format_t *self
    )
    {
        uint32_t v=0;
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_VIDEO_AVF_BIT, self->video_avf );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_VIDEO_61883_4_BIT, self->video_61883_4 );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_VIDEO_61883_8_BIT, self->video_61883_8 );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_DEFAULT_VIDEO_IIDC_BIT, self->video_iidc );
        return v;
    }
    
    static inline void avdecc_adp_default_video_format_merge (
        avdecc_adp_default_video_format_t *self,
        const avdecc_adp_default_video_format_t *a,
        const avdecc_adp_default_video_format_t *b
    )
    {
        uint32_t av = avdecc_adp_default_video_format_write ( a );
        uint32_t bv = avdecc_adp_default_video_format_write ( b );
        uint32_t mergev = av & bv;
        avdecc_adp_default_video_format_read ( self, mergev );
    }
    
    /* @} */
    
    
    /** \addtogroup ADP Entity type bit field values */
    /* @{ */
    
#define AVDECC_ADP_ENTITY_TYPE_OTHER_BIT (31)
#define AVDECC_ADP_ENTITY_TYPE_OTHER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_OTHER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MULTIFUNCTION_BIT (30)
#define AVDECC_ADP_ENTITY_TYPE_MULTIFUNCTION (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MULTIFUNCTION_BIT))
#define AVDECC_ADP_ENTITY_TYPE_LOUDSPEAKER_BIT (29)
#define AVDECC_ADP_ENTITY_TYPE_LOUDSPEAKER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_LOUDSPEAKER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MICROPHONE_BIT (28)
#define AVDECC_ADP_ENTITY_TYPE_MICROPHONE (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MICROPHONE_BIT))
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_AMPLIFIER_BIT (27)
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_AMPLIFIER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_AUDIO_AMPLIFIER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_SOURCE_BIT (26)
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_SOURCE (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_AUDIO_SOURCE_BIT))
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_PROCESSOR_BIT (25)
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_PROCESSOR (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_AUDIO_PROCESSOR_BIT))
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_MIXER_BIT (24)
#define AVDECC_ADP_ENTITY_TYPE_AUDIO_MIXER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_AUDIO_MIXER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_HEADSET_BIT (23)
#define AVDECC_ADP_ENTITY_TYPE_HEADSET (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_HEADSET_BIT))
#define AVDECC_ADP_ENTITY_TYPE_COMPUTER_BIT (22)
#define AVDECC_ADP_ENTITY_TYPE_COMPUTER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_COMPUTER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MUSICAL_INSTRUMENT_BIT (21)
#define AVDECC_ADP_ENTITY_TYPE_MUSICAL_INSTRUMENT (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MUSICAL_INSTRUMENT_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MIDI_DEVICE_BIT (20)
#define AVDECC_ADP_ENTITY_TYPE_MIDI_DEVICE (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MIDI_DEVICE_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MEDIA_SERVER_BIT (19)
#define AVDECC_ADP_ENTITY_TYPE_MEDIA_SERVER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MEDIA_SERVER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_MEDIA_RECORDER_BIT (18)
#define AVDECC_ADP_ENTITY_TYPE_MEDIA_RECORDER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_MEDIA_RECORDER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_SOURCE_BIT (17)
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_SOURCE (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_VIDEO_SOURCE_BIT))
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_DISPLAY_BIT (16)
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_DISPLAY (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_VIDEO_DISPLAY_BIT))
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_PROCESSOR_BIT (15)
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_PROCESSOR (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_VIDEO_PROCESSOR_BIT))
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_MIXER_BIT (14)
#define AVDECC_ADP_ENTITY_TYPE_VIDEO_MIXER (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_VIDEO_MIXER_BIT))
#define AVDECC_ADP_ENTITY_TYPE_TIMING_DEVICE_BIT (13)
#define AVDECC_ADP_ENTITY_TYPE_TIMING_DEVICE (AVDECC_BITS_QUADLET_BIT(AVDECC_ADP_ENTITY_TYPE_TIMING_DEVICE_BIT))
    
    typedef struct avdecc_adp_entity_type_s
    {
        unsigned other:1;
        unsigned multifunction:1;
        unsigned loudspeaker:1;
        unsigned microphone:1;
        unsigned audio_amplifier:1;
        unsigned audio_source:1;
        unsigned audio_processor:1;
        unsigned audio_mixer:1;
        unsigned headset:1;
        unsigned computer:1;
        unsigned musical_instrument:1;
        unsigned midi_device:1;
        unsigned media_server:1;
        unsigned media_recorder:1;
        unsigned video_source:1;
        unsigned video_display:1;
        unsigned video_processor:1;
        unsigned video_mixer:1;
        unsigned timing_device:1;
    } avdecc_adp_entity_type_t;
    
    static inline void avdecc_adp_entity_type_init ( avdecc_adp_entity_type_t *self )
    {
        memset ( self,0,sizeof ( *self ) );
    }
    
    static inline void avdecc_adp_entity_type_read (
        avdecc_adp_entity_type_t *self,
        const uint32_t v
    )
    {
        self->other = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_OTHER_BIT );
        self->multifunction = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MULTIFUNCTION_BIT );
        self->loudspeaker = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_LOUDSPEAKER_BIT );
        self->microphone = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MICROPHONE_BIT );
        self->audio_amplifier = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_AUDIO_AMPLIFIER_BIT );
        self->audio_source = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_AUDIO_SOURCE_BIT );
        self->audio_processor = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_AUDIO_PROCESSOR_BIT );
        self->audio_mixer = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_AUDIO_MIXER_BIT );
        self->headset = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_HEADSET_BIT );
        self->computer = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_COMPUTER_BIT );
        self->musical_instrument = AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MUSICAL_INSTRUMENT_BIT );
        self->midi_device= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MIDI_DEVICE_BIT );
        self->media_server= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MEDIA_SERVER_BIT );
        self->media_recorder= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_MEDIA_RECORDER_BIT );
        self->video_source= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_VIDEO_SOURCE_BIT );
        self->video_display= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_VIDEO_DISPLAY_BIT );
        self->video_processor= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_VIDEO_PROCESSOR_BIT );
        self->video_mixer= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_VIDEO_MIXER_BIT );
        self->timing_device= AVDECC_BITS_GET_QUADLET_BIT ( v,AVDECC_ADP_ENTITY_TYPE_TIMING_DEVICE_BIT );
    }
    
    static inline uint32_t avdecc_adp_entity_type_write (
        const avdecc_adp_entity_type_t *self
    )
    {
        uint32_t v=0;
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_OTHER_BIT, self->other );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MULTIFUNCTION_BIT, self->multifunction );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_LOUDSPEAKER_BIT, self->loudspeaker );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MICROPHONE_BIT, self->microphone );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_AUDIO_AMPLIFIER_BIT, self->audio_amplifier );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_AUDIO_SOURCE_BIT, self->audio_source );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_AUDIO_PROCESSOR_BIT, self->audio_processor );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_AUDIO_MIXER_BIT, self->audio_mixer );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_HEADSET_BIT, self->headset );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_COMPUTER_BIT, self->computer );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MUSICAL_INSTRUMENT_BIT, self->musical_instrument );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MIDI_DEVICE_BIT, self->midi_device );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MEDIA_SERVER_BIT, self->media_server );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_MEDIA_RECORDER_BIT, self->media_recorder );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_VIDEO_SOURCE_BIT, self->video_source );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_VIDEO_DISPLAY_BIT, self->video_display );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_VIDEO_PROCESSOR_BIT, self->video_processor );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_VIDEO_MIXER_BIT, self->video_mixer );
        v = AVDECC_BITS_SET_QUADLET_BIT_IF ( v, AVDECC_ADP_ENTITY_TYPE_TIMING_DEVICE_BIT, self->timing_device );
        return v;
    }
    
    
    /* @} */
    
    
#define AVDECC_ADP_CONTROL_DATA_LENGTH (52)
    
    /* See IEEE 1722.1 Section 6.2.1 */
    
    AVDECC_BITS_MAP_OCTET_BIT ( avdecc_adp, cd, avdecc_avtp_cd_t, 0, 0 );
    AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_adp, subtype, avdecc_avtp_subtype_t, 0, 1, 7 );
    AVDECC_BITS_MAP_OCTET_BIT ( avdecc_adp, sv, avdecc_avtp_sv_t, 1, 0 );
    AVDECC_BITS_MAP_OCTET_BITFIELD ( avdecc_adp, version, avdecc_avtp_version_t, 1, 1, 3 );
    AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_adp, message_type, avdecc_adp_message_type_t, 0, 12, 15 );
    AVDECC_BITS_MAP_QUADLET_BITFIELD ( avdecc_adp, valid_time, avdecc_adp_valid_time_t, 0, 16, 20 );
    AVDECC_BITS_MAP_QUADLET_BIT ( avdecc_adp, control_data_length, avdecc_adp_valid_time_t, 0, 31 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_adp, entity_guid, avdecc_pdu_eui64_t, 4 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_adp, vendor_model_id, avdecc_pdu_eui64_t, 12 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, entity_capabilities, uint32_t, 20 );
    AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, talker_streasources, uint16_t, 24 );
    AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, talker_capabilities, uint16_t, 26 );
    AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, listener_streasources, uint16_t, 28 );
    AVDECC_BITS_MAP_DOUBLET ( avdecc_adp, listener_capabilities, uint16_t, 30 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, controller_capabilities, uint32_t, 32 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, available_index, uint32_t, 36 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_adp, as_grandmaster_id, avdecc_pdu_eui64_t, 40 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, default_audio_format, uint32_t, 48 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, default_video_format, uint32_t, 52 );
    AVDECC_BITS_MAP_OCTLET ( avdecc_adp, association_id, avdecc_pdu_eui64_t, 56 );
    AVDECC_BITS_MAP_QUADLET ( avdecc_adp, entity_type, uint32_t, 52 );
    
    typedef struct avdecc_adp_s
    {
        avdecc_adp_message_type_t message_type;
        avdecc_adp_valid_time_t valid_time;
        avdecc_pdu_eui64_t entity_guid;
        avdecc_pdu_eui64_t vendor_model_id;
        avdecc_adp_entity_capabilities_t entity_capabilities;
        uint16_t talker_stream_sources;
        avdecc_adp_talker_capabilities_t talker_capabilities;
        uint16_t listener_stream_sinks;
        avdecc_adp_listener_capabilities_t listener_capabilities;
        avdecc_adp_controller_capabilities_t controller_capabilities;
        uint32_t available_index;
        avdecc_pdu_eui64_t as_grandmaster_id;
        avdecc_adp_default_audio_format_t default_audio_format;
        avdecc_adp_default_video_format_t default_video_format;
        avdecc_pdu_eui64_t association_id;
        avdecc_adp_entity_type_t entity_type;
    } avdecc_adp_t;
    
    void avdecc_adp_init ( avdecc_adp_t *self );
    bool avdecc_adp_read_pdu ( avdecc_adp_t *self, const void *pdu );
    size_t avdecc_adp_write_pdu ( const avdecc_adp_t *self, void *pdu );
    
#ifdef __cplusplus
}
#endif

/*@}*/

#endif
