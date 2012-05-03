
#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_adp.hpp"


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



void avdecc_adp_init ( avdecc_adp_t *self )
{
    memset( (void *)self, 0, sizeof ( avdecc_adp_t ));
}


bool avdecc_adp_read (
    avdecc_adp_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=false;
    
    avdecc_adp_init ( self );

    if ( avdecc_avtp_get_cd ( pdu ) ==avdecc_avtp_cd_control &&
         avdecc_avtp_get_subtype ( pdu ) ==avdecc_avtp_subtype_adp &&
         avdecc_avtp_get_sv ( pdu ) ==avdecc_avtp_sv_not_valid &&
         avdecc_avtp_get_version ( pdu ) ==0
         )
    {
		if ( len>=(AVDECC_PDU_HEADER_SIZE + AVDECC_ADP_CONTROL_DATA_LENGTH)
			&& avdecc_avtp_get_control_data_length ( pdu ) >= AVDECC_ADP_CONTROL_DATA_LENGTH )
        {
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

            avdecc_adp_vlan_id_read( &self->class_a_vlan_tci, avdecc_bits_get_doublet( pdu,48));
            avdecc_adp_vlan_id_read( &self->class_b_vlan_tci, avdecc_bits_get_doublet( pdu,50));
            self->reserved1 = avdecc_adp_get_reserved1 ( pdu );
            self->association_id = avdecc_adp_get_association_id ( pdu );
            self->entity_type = avdecc_adp_get_entity_type( pdu );
            r=true;
        }
    }
    return r;
}

bool avdecc_adp_write (
    const avdecc_adp_t *self,
    void *pdu,
    size_t *len
    )
{
    bool r=false;
    size_t adp_packet_len = AVDECC_PDU_HEADER_SIZE + AVDECC_ADP_CONTROL_DATA_LENGTH;
    if( *len >= adp_packet_len )
    {
        *len = adp_packet_len;
        memset ( pdu, 0, adp_packet_len );
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
        avdecc_bits_set_doublet( pdu, 48, avdecc_adp_vlan_id_write(&self->class_a_vlan_tci));
        avdecc_bits_set_doublet( pdu, 50, avdecc_adp_vlan_id_write(&self->class_b_vlan_tci));
        avdecc_adp_set_reserved1 ( pdu, self->reserved1 );
        avdecc_adp_set_association_id ( pdu, self->association_id );
        avdecc_adp_set_entity_type( pdu, self->entity_type );
        r=true;
    }
    return r;
}

