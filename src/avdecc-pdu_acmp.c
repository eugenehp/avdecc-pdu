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
#include "avdecc-pdu_acmp.h"



void avdecc_acmp_init ( avdecc_acmp_t *self )
{
    memset ( self, 0, sizeof ( *self ) );
}

bool avdecc_acmp_read_pdu ( avdecc_acmp_t *self, const void *pdu )
{
    avdecc_acmp_init ( self );
    
    if ( avdecc_acmp_get_cd ( pdu ) !=avdecc_avtp_cd_control )
        return false;
    
    if ( avdecc_acmp_get_subtype ( pdu ) !=avdecc_avtp_subtype_acmp )
        return false;

    if ( avdecc_acmp_get_sv ( pdu ) !=avdecc_avtp_sv_not_valid )
        return false;
    
    if ( avdecc_acmp_get_version ( pdu ) !=0 )
        return false;

    self->control_data_length = avdecc_acmp_get_control_data_length ( pdu );
    
    if ( self->control_data_length < AVDECC_ACMP_CONTROL_DATA_LENGTH )
    {
        avdecc_pdu_log_error (
                              "acmp control data length (%d) < %d",
                              self->control_data_length,
                              AVDECC_ACMP_CONTROL_DATA_LENGTH
                              );
        return false;
    }
    
    self->message_type = avdecc_acmp_get_message_type ( pdu );    
    self->status = avdecc_acmp_get_status(pdu);
    self->controller_guid = avdecc_acmp_get_controller_guid(pdu);
    self->talker_guid = avdecc_acmp_get_talker_guid(pdu);
    self->listener_guid = avdecc_acmp_get_listener_guid(pdu);
    self->talker_unique_id = avdecc_acmp_get_talker_unique_id(pdu);
    self->listener_unique_id = avdecc_acmp_get_listener_unique_id(pdu);
    self->dest_mac = avdecc_acmp_get_dest_mac(pdu);
    self->connection_count = avdecc_acmp_get_connection_count(pdu);
    self->sequence_id = avdecc_acmp_get_sequence_id(pdu);
    avdecc_acmp_flags_read(&self->flags, avdecc_acmp_get_flags(pdu));
    
    return true;
}

size_t avdecc_acmp_write_pdu ( const avdecc_acmp_t *self, void *pdu )
{
    memset ( pdu, 0, AVDECC_ACMP_CONTROL_DATA_LENGTH + AVDECC_PDU_HEADER_SIZE );
    avdecc_acmp_set_cd ( pdu,avdecc_avtp_cd_control );
    avdecc_acmp_set_subtype ( pdu,avdecc_avtp_subtype_adp );
    avdecc_acmp_set_sv ( pdu,avdecc_avtp_sv_not_valid );
    avdecc_acmp_set_version ( pdu,0 );
    avdecc_acmp_set_control_data_length ( pdu, AVDECC_ACMP_CONTROL_DATA_LENGTH );
    avdecc_acmp_set_message_type ( pdu, self->message_type );
    avdecc_acmp_set_status ( pdu, self->status );
    avdecc_acmp_set_controller_guid ( pdu, self->controller_guid );
    avdecc_acmp_set_talker_guid ( pdu, self->talker_guid );
    avdecc_acmp_set_listener_guid ( pdu, self->listener_guid );
    avdecc_acmp_set_talker_unique_id(pdu, self->talker_unique_id);
    avdecc_acmp_set_listener_unique_id(pdu, self->listener_unique_id);
    avdecc_acmp_set_dest_mac(pdu, self->dest_mac);
    avdecc_acmp_set_connection_count(pdu, self->connection_count);
    avdecc_acmp_set_sequence_id(pdu, self->sequence_id);
    avdecc_acmp_set_flags(pdu, avdecc_acmp_flags_write(&self->flags) );
    
    return AVDECC_ACMP_CONTROL_DATA_LENGTH + AVDECC_PDU_HEADER_SIZE;    
}

