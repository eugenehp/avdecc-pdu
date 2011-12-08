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
#include "avdecc-pdu_adp_print.h"


bool avdecc_pdu_print_adp_message_type (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_message_type_t v
)
{
    bool r;
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_adp_message_type_entity_available:
            s= "Available";
            break;
            
        case avdecc_adp_message_type_entity_departing:
            s= "Departing";
            break;
            
        case avdecc_adp_message_type_entity_discover:
            s= "Discover";
            break;
    }
    
    r = avdecc_pdu_print ( buf,offset,len,"%s", s );
    
    return r;
}

bool avdecc_pdu_print_adp_valid_time (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_valid_time_t v
)
{
    return avdecc_pdu_print ( buf, offset, len, "%d seconds", v*2 );
}

bool avdecc_pdu_print_adp_control_data_length (
    char *buf,
    size_t *offset,
    size_t len,
    uint8_t control_data_length
)
{
    return avdecc_pdu_print ( buf, offset, len, "%d", control_data_length );
}


bool avdecc_pdu_print_adp_talker_capabilities (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_talker_capabilities_t *talker_capabilities
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len, " [ " );
    
    if ( talker_capabilities->implemented )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "IMPLEMENTED " );
    }
    
    if ( talker_capabilities->other_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "OTHER_SOURCE " );
    }
    
    if ( talker_capabilities->control_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "CONTROL_SOURCE " );
    }
    
    if ( talker_capabilities->media_clock_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MEDIA_CLOCK_SOURCE " );
    }
    
    if ( talker_capabilities->smpte_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "SMPTE_SOURCE " );
    }
    
    if ( talker_capabilities->midi_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MIDI_SOURCE " );
    }
    
    if ( talker_capabilities->audio_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_SOURCE " );
    }
    
    if ( talker_capabilities->video_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_SOURCE " );
    }
    
    r&=avdecc_pdu_print ( buf,offset,len, "]" );
    return r;
    
}

bool avdecc_pdu_print_adp_listener_capabilities (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_listener_capabilities_t *listener_capabilities
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len, " [ " );
    
    if ( listener_capabilities->implemented )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "IMPLEMENTED " );
    }
    
    if ( listener_capabilities->other_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "OTHER_SINK " );
    }
    
    if ( listener_capabilities->control_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "CONTROL_SINK " );
    }
    
    if ( listener_capabilities->media_clock_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MEDIA_CLOCK_SINK " );
    }
    
    if ( listener_capabilities->smpte_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "SMPTE_SINK " );
    }
    
    if ( listener_capabilities->midi_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MIDI_SINK " );
    }
    
    if ( listener_capabilities->audio_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_SINK " );
    }
    
    if ( listener_capabilities->video_sink )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_SINK " );
    }
    
    r&=avdecc_pdu_print ( buf,offset,len, "]" );
    return r;
    
}

bool avdecc_pdu_print_adp_controller_capabilities (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_controller_capabilities_t *controller_capabilities
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len, " [ " );
    
    if ( controller_capabilities->implemented )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "IMPLEMENTED " );
    }
    
    if ( controller_capabilities->layer3_proxy )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "LAYER3_PROXY " );
    }
    
    r&=avdecc_pdu_print ( buf,offset,len, "]" );
    return r;
}

bool avdecc_pdu_print_adp_entity_capabilities (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_entity_capabilities_t *entity_capabilities
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len, " [ " );
    
    if ( entity_capabilities->avdecc_ip )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AVDECC_IP " );
    }
    
    if ( entity_capabilities->zero_conf )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "ZERO_CONF " );
    }
    
    if ( entity_capabilities->gateway_entity )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "GATEWAY_ENTITY " );
    }
    
    if ( entity_capabilities->avdecc_control )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AVDECC_CONTROL " );
    }
    
    if ( entity_capabilities->legacy_avc )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "LEGACY_AVC " );
    }
    
    if ( entity_capabilities->association_id_supported )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "ASSOCIATION_ID_SUPPORTED " );
    }
    
    if ( entity_capabilities->association_id_valid )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "ASSOCIATION_ID_VALID " );
    }
    
    r&=avdecc_pdu_print ( buf,offset,len, "]" );
    return r;
}



bool avdecc_pdu_print_adp_entity_type (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_entity_type_t *entity_type
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len, "[ " );
    
    if ( entity_type->other )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "OTHER " );
    }
    
    if ( entity_type->multifunction )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MULTIFUNCTION " );
    }
    
    if ( entity_type->loudspeaker )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "LOUDSPEAKER " );
    }
    
    if ( entity_type->microphone )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MICROPHONE " );
    }
    
    if ( entity_type->audio_amplifier )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_AMPLIFIER " );
    }
    
    if ( entity_type->audio_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_SOURCE " );
    }
    
    if ( entity_type->audio_processor )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_PROCESSOR " );
    }
    
    if ( entity_type->audio_mixer )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "AUDIO_MIXER " );
    }
    
    if ( entity_type->headset )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "HEADSET " );
    }
    
    if ( entity_type->computer )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "COMPUTER " );
    }
    
    if ( entity_type->musical_instrument )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MUSICAL_INSTRUMENT " );
    }
    
    if ( entity_type->midi_device )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MIDI_DEVICE " );
    }
    
    if ( entity_type->media_server )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MEDIA_SERVER " );
    }
    
    if ( entity_type->media_recorder )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "MEDIA_RECORDER " );
    }
    
    if ( entity_type->video_source )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_SOURCE " );
    }
    
    if ( entity_type->video_display )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_DISPLAY " );
    }
    
    if ( entity_type->video_processor )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_PROCESSOR " );
    }
    
    if ( entity_type->video_mixer )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "VIDEO_MIXER " );
    }
    
    if ( entity_type->timing_device )
    {
        r&=avdecc_pdu_print ( buf,offset,len, "TIMING DEVICE " );
    }
    
    r&=avdecc_pdu_print ( buf,offset,len, "]" );
    return r;
    
}


bool avdecc_pdu_print_adp (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_t *adp
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len,"ADP:\n" );    
    r&=avdecc_pdu_print ( buf,offset,len,"%-28s", "Message Type:" );
    r&=avdecc_pdu_print_adp_message_type ( buf,offset,len, adp->message_type );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Valid Time:" );
    r&=avdecc_pdu_print_adp_valid_time ( buf,offset,len,adp->valid_time );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity GUID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->entity_guid );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Vendor Model GUID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->vendor_model_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity Capabilities:" );
    r&=avdecc_pdu_print_adp_entity_capabilities ( buf,offset,len, &adp->entity_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%04x", "Talker Stream Sources:", adp->talker_stream_sources );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Talker Capabilities:" );
    r&=avdecc_pdu_print_adp_talker_capabilities ( buf,offset,len, &adp->talker_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%04x", "Listener Stream Sinks:", adp->listener_stream_sinks );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Listener Capabilities:" );
    r&=avdecc_pdu_print_adp_listener_capabilities ( buf,offset,len, &adp->listener_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Controller Capabilities:" );
    r&=avdecc_pdu_print_adp_controller_capabilities ( buf,offset,len,&adp->controller_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%08x", "Available Index:", adp->available_index );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "AS Grandmaster ID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->as_grandmaster_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Association ID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->association_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity Type:" );
    r&=avdecc_pdu_print_adp_entity_type ( buf,offset,len, &adp->entity_type );
    r&=avdecc_pdu_print ( buf,offset,len,"\n" );
    return r;
}


