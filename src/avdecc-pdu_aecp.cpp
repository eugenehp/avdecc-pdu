
#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_aecp.hpp"


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



void avdecc_aecp_init ( avdecc_aecp_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aecp_t ) );
}


bool avdecc_aecp_read (
    avdecc_aecp_t *self,
    const void *pdu
    )
{
    bool r=false;
    const uint8_t *base = ( uint8_t * ) pdu;

    if ( avdecc_aecp_get_cd ( base ) == avdecc_avtp_cd_control  &&
         avdecc_aecp_get_subtype ( base ) == avdecc_avtp_subtype_aecp  &&
         avdecc_aecp_get_sv ( base ) ==avdecc_avtp_sv_not_valid  &&
         avdecc_aecp_get_version ( base ) ==0 &&
		 avdecc_aecp_get_control_data_length( base ) >= AVDECC_AECP_HEADER_SIZE
         )
    {
        self->message_type = avdecc_aecp_get_message_type ( base );
        self->status = avdecc_aecp_get_status ( base );
        self->control_data_length = avdecc_aecp_get_control_data_length ( base );
        self->target_guid = avdecc_aecp_get_target_guid ( base );
        self->controller_guid = avdecc_aecp_get_controller_guid ( base );
        self->sequence_id = avdecc_aecp_get_sequence_id ( base );
		memcpy( self->payload_specific_data, &base[AVDECC_PDU_HEADER_SIZE + AVDECC_AECP_HEADER_SIZE], self->control_data_length-AVDECC_AECP_HEADER_SIZE );
        r=true;
    }

    return r;
}




bool avdecc_aecp_write (
    const avdecc_aecp_t *self,
    void *pdu,
    size_t len
    )
{
    bool r=true;
    
    if( len>=(size_t)(self->control_data_length + AVDECC_PDU_HEADER_SIZE + AVDECC_AECP_HEADER_SIZE) )
    {
        avdecc_avtp_set_cd(pdu,avdecc_avtp_cd_control);
        avdecc_avtp_set_subtype(pdu,avdecc_avtp_subtype_acmp);
        avdecc_avtp_set_sv(pdu,avdecc_avtp_sv_not_valid);
        avdecc_avtp_set_version(pdu,0);
        avdecc_aecp_set_message_type(pdu, self->message_type );
        avdecc_aecp_set_status(pdu,self->status);
        avdecc_aecp_set_control_data_length(pdu,self->control_data_length);
        avdecc_aecp_set_target_guid(pdu,self->target_guid );
        avdecc_aecp_set_controller_guid(pdu,self->controller_guid);
        avdecc_aecp_set_sequence_id(pdu,self->sequence_id);

        if( len>=self->control_data_length )
        {
            memcpy( ((uint8_t *)pdu)+(AVDECC_PDU_HEADER_SIZE + AVDECC_AECP_HEADER_SIZE), self->payload_specific_data, (self->control_data_length-AVDECC_AECP_HEADER_SIZE) );
        }
        r=true;
    }
    return r;
}


void avdecc_aecp_aem_init ( avdecc_aecp_aem_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aecp_aem_t ) );
}


bool avdecc_aecp_aem_read (
    avdecc_aecp_aem_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_aem_write (
    const avdecc_aecp_aem_t *self,
    void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_aa_init ( avdecc_aecp_aa_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aecp_aa_t ) );
}


bool avdecc_aecp_aa_read (
    avdecc_aecp_aa_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_aa_write (
    const avdecc_aecp_aa_t *self,
    void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_avc_init ( avdecc_aecp_avc_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aecp_avc_t ) );
}


bool avdecc_aecp_avc_read (
    avdecc_aecp_avc_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_avc_write (
    const avdecc_aecp_avc_t *self,
    void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_vu_init ( avdecc_aecp_vu_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aecp_vu_t ) );
}


bool avdecc_aecp_vu_read (
    avdecc_aecp_vu_t *self,
    const void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_vu_write (
    const avdecc_aecp_vu_t *self,
    void *pdu,
    size_t len
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



