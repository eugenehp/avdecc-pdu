#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_app.hpp"

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

void avdecc_app_hello_capabilities_read(
        avdecc_app_hello_capabilities_t *cap,
        uint16_t extension
        )
{
    cap->upgrade_supported = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_UPGRADE_SUPPORTED);
    cap->authentication_supported = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_AUTHENTICATION_SUPPORTED);
    cap->authentication_required = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_AUTHENTICATION_REQUIRED);
    cap->tls_supported = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_TLS_SUPPORTED);
    cap->tls_required = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_TLS_REQUIRED);
    cap->group_supported = AVDECC_BITS_IS_BITVALUE_SET(extension,AVDECC_APP_HELLO_GROUP_SUPPORTED);
}

uint16_t avdecc_app_hello_capabilities_write(
        const avdecc_app_hello_capabilities_t *cap
        )
{
    uint16_t v=0;

    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_UPGRADE_SUPPORTED_BIT, cap->upgrade_supported );
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_AUTHENTICATION_SUPPORTED_BIT, cap->authentication_supported);
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_AUTHENTICATION_REQUIRED_BIT, cap->authentication_required);
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_TLS_SUPPORTED_BIT, cap->tls_supported);
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_TLS_REQUIRED_BIT, cap->tls_required);
    v = AVDECC_BITS_SET_DOUBLET_BIT_IF(v,AVDECC_APP_HELLO_GROUP_SUPPORTED_BIT, cap->group_supported);
    return v;
}

bool avdecc_app_get_frame_size(
        uint8_t *buf,
        size_t offset,
        size_t buf_size,
        size_t *frame_size
        )
{
    bool r=false;
    if( (buf_size-offset)>=AVDECC_APP_PDU_MIN_PDU_SIZE)
    {
        uint8_t *pdu = buf+offset;
        uint8_t version = avdecc_app_get_version(pdu);

        if( version==AVDECC_APP_VERSION )
        {
            if( avdecc_app_status_is_valid(
                        avdecc_app_get_status(pdu), version ) )
            {
                if( avdecc_app_message_type_is_valid(
                            avdecc_app_get_message_type(pdu),
                            version ) )
                {
                    uint16_t payload_length = avdecc_app_get_payload_length(pdu);

                    if( avdecc_app_payload_length_is_valid(
                                payload_length,
                                version ) )
                    {
                        r=true;
                        *frame_size = payload_length+AVDECC_APP_PDU_MIN_PDU_SIZE;
                    }
                }
            }
        }
    }
    return r;
}

bool avdecc_app_status_is_valid( avdecc_app_status_t v, uint8_t version )
{
    bool r=false;
    if( version==AVDECC_APP_VERSION )
    {
        if( (v>=avdecc_app_status_success && v<avdecc_app_status_reserved) )
        {
            r=true;
        }
    }
    return r;
}

bool avdecc_app_payload_length_is_valid( uint16_t payload_length, uint8_t version )
{
    bool r=false;
    if( version==AVDECC_APP_VERSION )
    {
        if( payload_length <= AVDECC_APP_PDU_MAX_PAYLOAD )
        {
            r=true;
        }
    }
    return r;
}


bool avdecc_app_message_type_is_valid( avdecc_app_message_type_t v, uint8_t version )
{
    bool r=false;
    if( version==AVDECC_APP_VERSION )
    {
        if( (v>=avdecc_app_message_nop && v<avdecc_app_message_reserved)
                || (v==avdecc_app_message_vendor ))
        {
            r=true;
        }
    }
    return r;
}

void avdecc_app_init ( avdecc_app_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_app_t ) );
}

bool avdecc_app_read (
    avdecc_app_t *self,
    const void *pdu,
    size_t len,
    avdecc_app_status_t *status_code
    )
{
    bool r=false;

    avdecc_app_init( self );
    if( len>=AVDECC_APP_PDU_MIN_PDU_SIZE )
    {
        self->version = avdecc_app_get_version(pdu);

        if( self->version == AVDECC_APP_VERSION )
        {
            self->status = avdecc_app_get_status(pdu);
            if( avdecc_app_status_is_valid(self->status,self->version) )
            {
                self->sequence_id = avdecc_app_get_sequence_id(pdu);
                self->unsolicited = avdecc_app_get_u(pdu);
                self->message_type = avdecc_app_get_message_type(pdu);
                self->rc = avdecc_app_get_rc(pdu);

                if( avdecc_app_message_type_is_valid(self->message_type,self->version))
                {
                    self->payload_length = avdecc_app_get_payload_length(pdu);
                    self->network_port = avdecc_app_get_network_port(pdu);
                    self->destination = avdecc_app_get_destination(pdu);
                    self->source = avdecc_app_get_source(pdu);
                    self->extension = avdecc_app_get_extension(pdu);

                    if( avdecc_app_payload_length_is_valid(self->payload_length,self->version) )
                    {
                        if( len == (self->payload_length + AVDECC_APP_PDU_MIN_PDU_SIZE) )
                        {
                            if( self->payload_length==0 )
                            {
                                r=true;
                            }
                            else
                            {

                                memcpy( self->payload,
                                        ((uint8_t *)pdu)+ AVDECC_APP_PDU_MIN_PDU_SIZE,
                                        self->payload_length
                                        );
                                r=true;
                            }
                        }
                    }
                    else
                    {
                        *status_code = avdecc_app_status_invalid_payload_length;
                    }
                }
                else
                {
                    *status_code = avdecc_app_status_invalid_message_type;
                }
            }
            else
            {
                *status_code = avdecc_app_status_invalid_status;
            }
        }
        else
        {
            *status_code = avdecc_app_status_unsupported_version;
        }
    }
    else
    {
        *status_code = avdecc_app_status_invalid_header;
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
        avdecc_app_set_version(dest_pdu,self->version);
        avdecc_app_set_status(dest_pdu,self->status);
        avdecc_app_set_sequence_id(dest_pdu,self->sequence_id);
        avdecc_app_set_u( dest_pdu, self->unsolicited );
        avdecc_app_set_message_type(dest_pdu,self->message_type );
        avdecc_app_set_rc( dest_pdu, self->rc );
        avdecc_app_set_payload_length(dest_pdu,self->payload_length);
        avdecc_app_set_network_port( dest_pdu, self->network_port);
        avdecc_app_set_destination( dest_pdu, self->destination );
        avdecc_app_set_source( dest_pdu, self->source );
        avdecc_app_set_extension( dest_pdu, self->extension );
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
                *len=AVDECC_APP_PDU_MIN_PDU_SIZE + self->payload_length;
                r=true;
            }
        }
    }

    return r;
}


