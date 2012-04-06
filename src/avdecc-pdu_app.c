#include "avdecc-pdu_world.h"
#include "avdecc-pdu_app.h"

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


void avdecc_app_init ( avdecc_app_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_app_t ) );
}

bool avdecc_app_read (
    avdecc_app_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=false;

    avdecc_app_init( self );
    if( len>=AVDECC_APP_PDU_MIN_PDU_SIZE )
    {
        self->app_version = avdecc_app_get_version(pdu);

        if( self->app_version == 0 )
        {
            self->app_msg_type = avdecc_app_get_msg_type(pdu);
            self->payload_length = avdecc_app_get_payload_length(pdu);
            self->source = avdecc_app_get_source(pdu);
            self->destination = avdecc_app_get_destination(pdu);
            if( self->app_msg_type == avdecc_app_message_type_vendor ||
                    self->app_msg_type < avdecc_app_message_type_reserved )
            {
                if( self->payload_length==0 )
                {
                    r=true;
                }
                else
                {
                    if( self->payload_length <= AVDECC_APP_PDU_MAX_PAYLOAD
                            && len >= (self->payload_length + AVDECC_APP_PDU_MIN_PDU_SIZE) )
                    {
                        memcpy( self->payload, ((uint8_t *)pdu)+ AVDECC_APP_PDU_MIN_PDU_SIZE, self->payload_length );
                        r=true;
                    }
                }
            }
        }

    }
    return r;
}

bool avdecc_app_write (
    const avdecc_app_t *self,
    void *dest_pdu,
    size_t *len
    )
{
    bool r=false;

    if( *len >= avdecc_app_pdu_size(self) )
    {
        avdecc_app_set_version(dest_pdu,self->app_version);
        avdecc_app_set_msg_type(dest_pdu,self->app_msg_type );
        avdecc_app_set_payload_length(dest_pdu,self->payload_length);
        if( self->payload_length==0 )
        {
            r=true;
            *len=AVDECC_APP_PDU_MIN_PDU_SIZE;
        }
        else
        {
            if( self->payload_length <= AVDECC_APP_PDU_MAX_PAYLOAD )
            {
                memcpy( ((uint8_t *)dest_pdu)+ AVDECC_APP_PDU_MIN_PDU_SIZE, self->payload, self->payload_length );
                r=true;
            }
        }
    }

    return r;
}


