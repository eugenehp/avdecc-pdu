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
#include "avdecc-pdu_adp.h"

void avdecc_adp_init ( avdecc_adp_t *self )
{
    memset ( self, 0, sizeof ( *self ) );
}

bool avdecc_adp_read_pdu ( avdecc_adp_t *self, const void *pdu )
{
    avdecc_adp_init ( self );
    
    if ( avdecc_pdu_avtp_get_cd ( pdu ) !=avdecc_avtp_cd_control )
        return false;
        
    if ( avdecc_pdu_avtp_get_subtype ( pdu ) !=avdecc_avtp_subtype_adp )
        return false;
        
    if ( avdecc_pdu_avtp_get_sv ( pdu ) !=avdecc_avtp_sv_not_valid )
        return false;
        
    if ( avdecc_pdu_avtp_get_version ( pdu ) !=0 )
        return false;
        
    if ( avdecc_pdu_avtp_get_control_data_length ( pdu ) < AVDECC_ADP_CONTROL_DATA_LENGTH )
    {
        avdecc_pdu_log_error (
            "adp control data length (%d) < %d",
            avdecc_pdu_avtp_get_control_data_length ( pdu ),
            AVDECC_ADP_CONTROL_DATA_LENGTH
        );
        return false;
    }
    
    self->message_type = avdecc_adp_get_message_type ( pdu );
    self->valid_time = avdecc_adp_get_valid_time ( pdu );
    self->entity_guid = avdecc_adp_get_entity_guid ( pdu );
    self->vendor_model_id = avdecc_adp_get_vendor_model_id ( pdu );
    
    avdecc_adp_entity_capabilities_read ( &self->entity_capabilities, avdecc_adp_get_entity_capabilities ( pdu ) );
    
    self->talker_stream_sources = avdecc_bits_get_doublet ( pdu, 24 );
    avdecc_adp_talker_capabilities_read ( &self->talker_capabilities, avdecc_bits_get_doublet ( pdu,26 ) );
    self->listener_stream_sinks = avdecc_bits_get_doublet ( pdu,28 );
    avdecc_adp_listener_capabilities_read ( &self->listener_capabilities, avdecc_bits_get_doublet ( pdu, 30 ) );
    
    avdecc_adp_controller_capabilities_read ( &self->controller_capabilities, avdecc_bits_get_quadlet ( pdu, 32 ) );
    self->available_index = avdecc_bits_get_quadlet ( pdu,36 );
    
    self->as_grandmaster_id = avdecc_adp_get_as_grandmaster_id ( pdu );
    
    self->reserved1 = avdecc_adp_get_reserved1(pdu);
    self->reserved2 = avdecc_adp_get_reserved2(pdu);    
    self->association_id = avdecc_adp_get_association_id ( pdu );
    avdecc_adp_entity_type_read ( &self->entity_type, avdecc_bits_get_quadlet ( pdu, 64 ) );
    
    return true;
}

size_t avdecc_adp_write_pdu ( const avdecc_adp_t *self, void *pdu )
{
    memset ( pdu, 0, AVDECC_ADP_CONTROL_DATA_LENGTH + AVDECC_PDU_HEADER_SIZE );
    avdecc_adp_set_cd ( pdu,avdecc_avtp_cd_control );
    avdecc_adp_set_subtype ( pdu,avdecc_avtp_subtype_adp );
    avdecc_adp_set_sv ( pdu,avdecc_avtp_sv_not_valid );
    avdecc_adp_set_version ( pdu,0 );
    avdecc_adp_set_control_data_length ( pdu, AVDECC_ADP_CONTROL_DATA_LENGTH );
    avdecc_adp_set_message_type ( pdu, self->message_type );
    avdecc_adp_set_valid_time ( pdu, self->valid_time );
    avdecc_adp_set_entity_guid ( pdu, self->entity_guid );
    avdecc_adp_set_vendor_model_id ( pdu, self->vendor_model_id );
    avdecc_bits_set_quadlet ( pdu, 20, avdecc_adp_entity_capabilities_write ( &self->entity_capabilities ) );
    avdecc_bits_set_doublet ( pdu, 24, self->talker_stream_sources );
    avdecc_bits_set_doublet ( pdu, 26, avdecc_adp_talker_capabilities_write ( &self->talker_capabilities ) );
    
    avdecc_bits_set_doublet ( pdu, 28, self->listener_stream_sinks );
    avdecc_bits_set_doublet ( pdu, 30, avdecc_adp_listener_capabilities_write ( &self->listener_capabilities ) );
    avdecc_bits_set_quadlet ( pdu, 32, avdecc_adp_controller_capabilities_write ( &self->controller_capabilities ) );
    avdecc_bits_set_quadlet ( pdu, 36, self->available_index );
    
    avdecc_adp_set_as_grandmaster_id ( pdu, self->as_grandmaster_id );
    avdecc_adp_set_reserved1(pdu, self->reserved1);
    avdecc_adp_set_reserved2(pdu, self->reserved2);
    avdecc_adp_set_association_id ( pdu, self->association_id );
    avdecc_bits_set_quadlet ( pdu, 64, avdecc_adp_entity_type_write ( &self->entity_type ) );
    
    return AVDECC_ADP_CONTROL_DATA_LENGTH + AVDECC_PDU_HEADER_SIZE;
}

