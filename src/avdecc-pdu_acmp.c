
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_acmp.h"
#include "avdecc-pdu_avtp.h"


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



void avdecc_acmp_init ( avdecc_acmp_t *self )
{
    memset( (void *)self, 0, sizeof( avdecc_acmp_t ));
}


bool avdecc_acmp_read (
        avdecc_acmp_t *self,
        const void *pdu,
        size_t len
        )
{
    bool r=false;
    if( len>=56 )
    {
        if( avdecc_avtp_get_cd(pdu)==avdecc_avtp_cd_control &&
                avdecc_avtp_get_subtype(pdu)==avdecc_avtp_subtype_acmp &&
                avdecc_avtp_get_sv(pdu)==avdecc_avtp_sv_not_valid &&
                avdecc_avtp_get_version(pdu)==0 )
        {
            self->message_type = avdecc_acmp_get_message_type(pdu);
            self->status = avdecc_acmp_get_status(pdu);
            self->control_data_length = avdecc_acmp_get_control_data_length(pdu);
            if( self->control_data_length >= 44 )
            {
                self->stream_id = avdecc_acmp_get_stream_id(pdu);
                self->controller_guid = avdecc_acmp_get_controller_guid(pdu);
                self->talker_guid = avdecc_acmp_get_talker_guid(pdu);
                self->listener_guid = avdecc_acmp_get_listener_guid(pdu);
                self->talker_unique_id = avdecc_acmp_get_talker_unique_id(pdu);
                self->listener_unique_id = avdecc_acmp_get_listener_unique_id(pdu);
                self->dest_mac = avdecc_acmp_get_dest_mac(pdu);
                self->connection_count = avdecc_acmp_get_connection_count(pdu);
                self->sequence_id = avdecc_acmp_get_sequence_id(pdu);
                avdecc_acmp_flags_read( &self->flags, avdecc_acmp_get_flags(pdu) );
                r=true;
            }
        }
    }
    return r;
}


bool avdecc_acmp_write (
        const avdecc_acmp_t *self,
        void *pdu,
        size_t *len
        )
{
    avdecc_avtp_set_cd(pdu,avdecc_avtp_cd_control);
    avdecc_avtp_set_subtype(pdu,avdecc_avtp_subtype_acmp);
    avdecc_avtp_set_sv(pdu,avdecc_avtp_sv_not_valid);
    avdecc_avtp_set_version(pdu,0);
    avdecc_acmp_set_message_type(pdu,self->message_type);
    avdecc_acmp_set_status(pdu,self->status);
    avdecc_acmp_set_control_data_length(pdu,44);
    avdecc_acmp_set_stream_id(pdu,self->stream_id);
    avdecc_acmp_set_controller_guid(pdu,self->controller_guid);
    avdecc_acmp_set_talker_guid(pdu,self->talker_guid);
    avdecc_acmp_set_listener_guid(pdu,self->listener_guid);
    avdecc_acmp_set_talker_unique_id(pdu,self->talker_unique_id);
    avdecc_acmp_set_listener_unique_id(pdu,self->listener_unique_id);
    avdecc_acmp_set_dest_mac(pdu,self->dest_mac);
    avdecc_acmp_set_connection_count(pdu,self->connection_count);
    avdecc_acmp_set_sequence_id(pdu,self->sequence_id);
    avdecc_acmp_set_flags( pdu, avdecc_acmp_flags_write( &self->flags) );
    *len = 56;
    return true;
}




