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


bool avdecc_adp_print_message_type (
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

bool avdecc_adp_print_valid_time (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_valid_time_t v
)
{
    /* @TODO: */
}

bool avdecc_adp_print_control_data_length (
    char *buf,
    size_t *offset,
    size_t len,
    uint8_t control_data_length
)
{
    /* @TODO: */
}





bool avdecc_adp_print_adp (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_t *adp
)
{
    bool r=true;
    r&=avdecc_pdu_print ( buf,offset,len,"%-28s", "Message Type:" );
    r&=avdecc_adp_print_message_type ( buf,offset,len, adp->message_type );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Valid Time:" );
    r&=avdecc_adp_print_valid_time ( buf,offset,len,adp->valid_time );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity GUID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->entity_guid );
    r&=avdecc_print ( buf,offset,len,"\n%-28s", "Vendor Model GUID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->vendor_model_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity Capabilities:" );
    r&=avdecc_pdu_print_entity_capabilities ( buf,offset,len, &adp->entity_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%04x", "Talker Stream Sources:", adp->talker_stream_sources );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Talker Capabilities:" );
    r&=avdecc_pdu_print_talker_capabilities ( buf,offset,len, &adp->talker_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%04x", "Listener Stream Sinks:", adp->listener_stream_sinks );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Listener Capabilities:" );
    r&=avdecc_pdu_print_listener_capabilities ( buf,offset,len, &adp->listener_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Controller Capabilities:" );
    r&=avdecc_pdu_print_controller_capabilities ( buf,offset,len,&adp->controller_capabilities );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s0x%08x", "Available Index:", adp->available_index );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "AS Grandmaster ID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->as_grandmaster_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Default Audio Format:" );
    r&=avdecc_pdu_print_default_audio_format ( buf,offset,len, &adp->default_audio_format );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Default Video Format:" );
    r&=avdecc_pdu_print_default_video_format ( buf,offset,len, &adp->default_video_format );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Association ID:" );
    r&=avdecc_pdu_print_eui64 ( buf,offset,len, &adp->association_id );
    r&=avdecc_pdu_print ( buf,offset,len,"\n%-28s", "Entity Type:" );
    r&=avdecc_pdu_print_entity_type ( buf,offset,len, &adp->entity_type );
    r&=avdecc_pdu_print ( buf,offset,len,"\n" );
    return r;
}


