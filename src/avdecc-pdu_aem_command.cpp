
#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_aem_command.hpp"
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

void avdecc_command_init ( avdecc_aem_command_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_t ) );
    self->message_type = avdecc_aecp_message_type_aem_command;
    self->status = avdecc_aem_status_success;
}

bool avdecc_command_read (
    avdecc_aem_command_t *self,
    const void *pdu
    )
{
    bool r=false;
    const uint8_t *base = ( uint8_t * ) pdu;
    
    if ( avdecc_aecp_get_cd ( base ) == avdecc_avtp_cd_control  &&
         avdecc_aecp_get_subtype ( base ) == avdecc_avtp_subtype_aecp  &&
         avdecc_aecp_get_sv ( base ) ==avdecc_avtp_sv_not_valid  &&
         avdecc_aecp_get_version ( base ) ==0 &&
         avdecc_aecp_get_message_type ( base ) ==avdecc_aecp_message_type_aem_command &&
         avdecc_aecp_get_status ( base ) ==avdecc_aecp_status_success
         )
    {
        self->message_type = avdecc_aecp_get_message_type ( base );
        self->status = avdecc_aecp_aem_get_status ( base );
        self->control_data_length = avdecc_aecp_get_control_data_length ( base );
        self->target_guid = avdecc_aecp_get_target_guid ( base );
        self->controller_guid = avdecc_aecp_get_controller_guid ( base );
        self->sequence_id = avdecc_aecp_get_sequence_id ( base );
        self->unsolicited = avdecc_aecp_aem_get_u ( base );
        self->command_type = (avdecc_aem_command_type_t)avdecc_aecp_aem_get_command_type ( base );
        r=true;
    }
    
    return r;
}


bool avdecc_command_write (
    const avdecc_aem_command_t *self,
    void *pdu
    )
{
    uint8_t *base = ( uint8_t * ) pdu;
    
    avdecc_aecp_set_cd ( base, avdecc_avtp_cd_control );
    avdecc_aecp_set_subtype ( base, avdecc_avtp_subtype_aecp );
    avdecc_aecp_set_sv ( base, avdecc_avtp_sv_not_valid );
    avdecc_aecp_set_version ( base, 0 );
    avdecc_aecp_set_message_type ( base, self->message_type );
    avdecc_aecp_aem_set_status ( base, self->status );
    avdecc_aecp_set_control_data_length ( base, self->control_data_length );
    avdecc_aecp_set_target_guid ( base, self->target_guid );
    avdecc_aecp_set_controller_guid ( base, self->controller_guid );
    avdecc_aecp_set_sequence_id ( base, self->sequence_id );
    avdecc_aecp_aem_set_u ( base, self->unsolicited );
    avdecc_aecp_aem_set_command_type ( base, self->command_type );
    
    return true;
}

void avdecc_response_init ( avdecc_aem_response_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_t ) );
    self->message_type = avdecc_aecp_message_type_aem_response;
    self->status = avdecc_aem_status_not_implemented;
}

bool avdecc_response_read (
    avdecc_aem_response_t *self,
    const void *pdu
    )
{
    bool r=false;
    const uint8_t *base = ( uint8_t * ) pdu;
    
    if ( avdecc_aecp_get_cd ( base ) == avdecc_avtp_cd_control  &&
         avdecc_aecp_get_subtype ( base ) == avdecc_avtp_subtype_aecp  &&
         avdecc_aecp_get_sv ( base ) ==avdecc_avtp_sv_not_valid  &&
         avdecc_aecp_get_version ( base ) ==0 &&
         avdecc_aecp_get_message_type ( base ) ==avdecc_aecp_message_type_aem_response
         )
    {
        self->message_type = avdecc_aecp_get_message_type ( base );
        self->status = avdecc_aecp_aem_get_status ( base );
        self->control_data_length = avdecc_aecp_get_control_data_length ( base );
        self->target_guid = avdecc_aecp_get_target_guid ( base );
        self->controller_guid = avdecc_aecp_get_controller_guid ( base );
        self->sequence_id = avdecc_aecp_get_sequence_id ( base );
        self->unsolicited = avdecc_aecp_aem_get_u ( base );
        self->command_type = (avdecc_aem_command_type_t)avdecc_aecp_aem_get_command_type ( base );
        r=true;
    }
    
    return r;
}

bool avdecc_response_write (
    const avdecc_aem_response_t *self,
    void *pdu
    )
{
    uint8_t *base = ( uint8_t * ) pdu;
    
    avdecc_aecp_set_cd ( base, avdecc_avtp_cd_control );
    avdecc_aecp_set_subtype ( base, avdecc_avtp_subtype_aecp );
    avdecc_aecp_set_sv ( base, avdecc_avtp_sv_not_valid );
    avdecc_aecp_set_version ( base, 0 );
    avdecc_aecp_set_message_type ( base, self->message_type );
    avdecc_aecp_aem_set_status ( base, self->status );
    avdecc_aecp_set_control_data_length ( base, self->control_data_length );
    avdecc_aecp_set_target_guid ( base, self->target_guid );
    avdecc_aecp_set_controller_guid ( base, self->controller_guid );
    avdecc_aecp_set_sequence_id ( base, self->sequence_id );
    avdecc_aecp_aem_set_u ( base, self->unsolicited );
    avdecc_aecp_aem_set_command_type ( base, self->command_type );
    
    return true;
}

void avdecc_command_lock_entity_init ( avdecc_aem_command_lock_entity_t *self )
{
    avdecc_command_init ( &self->base );
    self->base.command_type = avdecc_aem_command_lock_entity;
    self->flags = 0;
    self->locked_guid = 0;
}


bool avdecc_command_lock_entity_read (
    avdecc_aem_command_lock_entity_t *self,
    const void *pdu
    )
{
    bool r=true;
    
    if ( avdecc_command_read ( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_lock_entity )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->flags = avdecc_bits_get_quadlet ( base,24 );
            self->locked_guid = avdecc_bits_get_octlet ( base,28 );
        }
        else
        {
            r=false;
        }
    }
    
    return r;
}


bool avdecc_command_lock_entity_write (
    const avdecc_aem_command_lock_entity_t *self,
    void *pdu
    )
{
    bool r=avdecc_command_write ( &self->base, pdu );
    
    if ( r )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_quadlet ( base,24,self->flags );
        avdecc_bits_set_octlet ( base,28,self->locked_guid );
    }
    
    return r;
}


void avdecc_response_lock_entity_init ( avdecc_aem_response_lock_entity_t *self )
{
    avdecc_response_init ( &self->base );
    self->base.command_type = avdecc_aem_command_lock_entity;
    self->flags = 0;
    self->locked_guid = 0;
}

bool avdecc_response_lock_entity_read (
    avdecc_aem_response_lock_entity_t *self,
    const void *pdu
    )
{
    bool r=true;
    
    if ( avdecc_response_read ( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_lock_entity )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->flags = avdecc_bits_get_quadlet ( base,24 );
            self->locked_guid = avdecc_bits_get_octlet ( base,28 );
        }
        else
        {
            r=false;
        }
    }
    
    return r;
}

bool avdecc_response_lock_entity_write (
    const avdecc_aem_response_lock_entity_t *self,
    void *pdu
    )
{
    bool r=avdecc_response_write ( &self->base, pdu );
    
    if ( r )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_quadlet ( base,24,self->flags );
        avdecc_bits_set_octlet ( base,28,self->locked_guid );
    }
    
    return r;
}


void avdecc_command_read_descriptor_init ( avdecc_aem_command_read_descriptor_t *self )
{
    avdecc_command_init ( &self->base );
    self->base.command_type = avdecc_aem_command_read_descriptor;
    self->configuration = 0;
    self->m_descriptor_index = 0;
    self->m_descriptor_type = avdecc_aem_descriptor_entity;
}


bool avdecc_command_read_descriptor_read (
    avdecc_aem_command_read_descriptor_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;

    if ( avdecc_command_read ( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_read_descriptor )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->configuration = avdecc_bits_get_doublet( base, 24 );
            self->m_descriptor_type = (avdecc_aem_descriptor_type_t)avdecc_bits_get_doublet( base, 28 );
            self->m_descriptor_index = avdecc_bits_get_doublet( base, 30 );
        }
        else
        {
            r=false;
        }
    }

    return r;
}


bool avdecc_command_read_descriptor_write (
    const avdecc_aem_command_read_descriptor_t *self,
    void *pdu
    )
{
    bool r=avdecc_command_write ( &self->base, pdu );

    if ( r )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_doublet( base, 24, self->configuration );
        avdecc_bits_set_doublet( base, 26, 0 );
        avdecc_bits_set_doublet ( base,28,(uint16_t)self->m_descriptor_type );
        avdecc_bits_set_doublet ( base,30,self->m_descriptor_index );
    }

    return r;
}


void avdecc_response_read_descriptor_init ( avdecc_aem_response_read_descriptor_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_read_descriptor_t ) );
}


bool avdecc_response_read_descriptor_read (
    avdecc_aem_response_read_descriptor_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_read_descriptor_write (
    const avdecc_aem_response_read_descriptor_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_write_descriptor_init ( avdecc_aem_command_write_descriptor_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_write_descriptor_t ) );
}


bool avdecc_command_write_descriptor_read (
    avdecc_aem_command_write_descriptor_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_write_descriptor_write (
    const avdecc_aem_command_write_descriptor_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}




void avdecc_command_acquire_entity_init ( avdecc_aem_command_acquire_entity_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_acquire_entity_t ) );
}


bool avdecc_command_acquire_entity_read (
    avdecc_aem_command_acquire_entity_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_acquire_entity_write (
    const avdecc_aem_command_acquire_entity_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



void avdecc_command_controller_available_init ( avdecc_aem_command_controller_available_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_controller_available_t ) );
}


bool avdecc_command_controller_available_read (
    avdecc_aem_command_controller_available_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_controller_available_write (
    const avdecc_aem_command_controller_available_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_controller_available_init ( avdecc_aem_response_controller_available_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_controller_available_t ) );
}


bool avdecc_response_controller_available_read (
    avdecc_aem_response_controller_available_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_controller_available_write (
    const avdecc_aem_response_controller_available_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_clock_source_init ( avdecc_aem_command_set_clock_source_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_clock_source_t ) );
}


bool avdecc_command_set_clock_source_read (
    avdecc_aem_command_set_clock_source_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_clock_source_write (
    const avdecc_aem_command_set_clock_source_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_clock_source_init ( avdecc_aem_response_set_clock_source_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_clock_source_t ) );
}


bool avdecc_response_set_clock_source_read (
    avdecc_aem_response_set_clock_source_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_clock_source_write (
    const avdecc_aem_response_set_clock_source_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_clock_source_init ( avdecc_aem_command_get_clock_source_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_clock_source_t ) );
}


bool avdecc_command_get_clock_source_read (
    avdecc_aem_command_get_clock_source_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_clock_source_write (
    const avdecc_aem_command_get_clock_source_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_clock_source_init ( avdecc_aem_response_get_clock_source_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_clock_source_t ) );
}


bool avdecc_response_get_clock_source_read (
    avdecc_aem_response_get_clock_source_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_clock_source_write (
    const avdecc_aem_response_get_clock_source_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_stream_format_init ( avdecc_aem_command_set_stream_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_stream_format_t ) );
}


bool avdecc_command_set_stream_format_read (
    avdecc_aem_command_set_stream_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_stream_format_write (
    const avdecc_aem_command_set_stream_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_stream_format_init ( avdecc_aem_response_set_stream_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_stream_format_t ) );
}


bool avdecc_response_set_stream_format_read (
    avdecc_aem_response_set_stream_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_stream_format_write (
    const avdecc_aem_response_set_stream_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_stream_format_init ( avdecc_aem_command_get_stream_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_stream_format_t ) );
}


bool avdecc_command_get_stream_format_read (
    avdecc_aem_command_get_stream_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_stream_format_write (
    const avdecc_aem_command_get_stream_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_stream_format_init ( avdecc_aem_response_get_stream_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_stream_format_t ) );
}


bool avdecc_response_get_stream_format_read (
    avdecc_aem_response_get_stream_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_stream_format_write (
    const avdecc_aem_response_get_stream_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_configuration_init ( avdecc_aem_command_set_configuration_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_configuration_t ) );
}


bool avdecc_command_set_configuration_read (
    avdecc_aem_command_set_configuration_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_configuration_write (
    const avdecc_aem_command_set_configuration_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_configuration_init ( avdecc_aem_response_set_configuration_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_configuration_t ) );
}


bool avdecc_response_set_configuration_read (
    avdecc_aem_response_set_configuration_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_configuration_write (
    const avdecc_aem_response_set_configuration_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_configuration_init ( avdecc_aem_command_get_configuration_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_configuration_t ) );
}


bool avdecc_command_get_configuration_read (
    avdecc_aem_command_get_configuration_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_configuration_write (
    const avdecc_aem_command_get_configuration_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_configuration_init ( avdecc_aem_response_get_configuration_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_configuration_t ) );
}


bool avdecc_response_get_configuration_read (
    avdecc_aem_response_get_configuration_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_configuration_write (
    const avdecc_aem_response_get_configuration_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_control_value_init ( avdecc_aem_command_set_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_control_value_t ) );
    avdecc_command_init(&self->base);
    self->m_descriptor_type = avdecc_aem_descriptor_control;
    self->base.command_type = avdecc_aem_command_set_control_value;
}


bool avdecc_command_set_control_value_read (
    avdecc_aem_command_set_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=false;
    if (avdecc_command_read( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_set_control_value )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->m_descriptor_type = (avdecc_aem_descriptor_type_t)avdecc_bits_get_doublet( base, 24 );
            self->m_descriptor_index = avdecc_bits_get_doublet( base, 26 );
            if( self->base.control_data_length > 16 )
              memcpy( &self->values, base + 28, self->base.control_data_length - 16 );
            r = true;
        }
    }
    return r;
}


bool avdecc_command_set_control_value_write (
    const avdecc_aem_command_set_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=false;
    if ( avdecc_command_write ( &self->base, pdu ) )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_doublet ( base,24,(uint16_t)self->m_descriptor_type );
        avdecc_bits_set_doublet ( base,26,self->m_descriptor_index );
        memcpy( base + 28, &self->values, offset );
        r = true;
    }
    return r;
}


void avdecc_response_set_control_value_init ( avdecc_aem_response_set_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_control_value_t ) );
}


bool avdecc_response_set_control_value_read (
    avdecc_aem_response_set_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=false;
    if (avdecc_response_read( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_set_control_value )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->m_descriptor_type = (avdecc_aem_descriptor_type_t)avdecc_bits_get_doublet( base, 24 );
            self->m_descriptor_index = avdecc_bits_get_doublet( base, 26 );
            if( self->base.control_data_length > 16 )
              memcpy( &self->values, base + 28, self->base.control_data_length - 16 );
            r = true;
        }
    }
    return r;
}


bool avdecc_response_set_control_value_write (
    const avdecc_aem_response_set_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=false;
    if ( avdecc_command_write ( &self->base, pdu ) )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_doublet ( base,24,(uint16_t)self->m_descriptor_type );
        avdecc_bits_set_doublet ( base,26,self->m_descriptor_index );
        memcpy( base + 28, &self->values, offset );
        r = true;
    }
    return r;
}


void avdecc_command_get_control_value_init ( avdecc_aem_command_get_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_control_value_t ) );
    avdecc_command_init(&self->base);
    self->m_descriptor_type = avdecc_aem_descriptor_control;
    self->base.command_type = avdecc_aem_command_get_control_value;
}


bool avdecc_command_get_control_value_read (
    avdecc_aem_command_get_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=false;
    if (avdecc_command_read( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_get_control_value )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->m_descriptor_type = (avdecc_aem_descriptor_type_t)avdecc_bits_get_doublet( base, 24 );
            self->m_descriptor_index = avdecc_bits_get_doublet( base, 26 );
            if( self->base.control_data_length > 16 )
              memcpy( &self->values, base + 28, self->base.control_data_length - 16 );
            r = true;
        }
    }
    return r;
}


bool avdecc_command_get_control_value_write (
    const avdecc_aem_command_get_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=false;
    if ( avdecc_command_write ( &self->base, pdu ) )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_doublet ( base,24,(uint16_t)self->m_descriptor_type );
        avdecc_bits_set_doublet ( base,26,self->m_descriptor_index );
        memcpy( base + 28, &self->values, offset );
        r = true;
    }
    return r;
}


void avdecc_response_get_control_value_init ( avdecc_aem_response_get_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_control_value_t ) );
}


bool avdecc_response_get_control_value_read (
    avdecc_aem_response_get_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=false;
    if (avdecc_response_read( &self->base, pdu ) )
    {
        if ( self->base.command_type == avdecc_aem_command_get_control_value )
        {
            const uint8_t *base = ( const uint8_t * ) pdu;
            self->m_descriptor_type = (avdecc_aem_descriptor_type_t)avdecc_bits_get_doublet( base, 24 );
            self->m_descriptor_index = avdecc_bits_get_doublet( base, 26 );
            if( self->base.control_data_length > 16 )
              memcpy( &self->values, base + 28, self->base.control_data_length - 16 );
            r = true;
        }
    }
    return r;
}


bool avdecc_response_get_control_value_write (
    const avdecc_aem_response_get_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=false;
    if ( avdecc_command_write ( &self->base, pdu ) )
    {
        uint8_t *base = ( uint8_t * ) pdu;
        avdecc_bits_set_doublet ( base,24,(uint16_t)self->m_descriptor_type );
        avdecc_bits_set_doublet ( base,26,self->m_descriptor_index );
        memcpy( base + 28, &self->values, offset );
        r = true;
    }
    return r;
}


void avdecc_command_set_signal_selector_init ( avdecc_aem_command_set_signal_selector_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_signal_selector_t ) );
}


bool avdecc_command_set_signal_selector_read (
    avdecc_aem_command_set_signal_selector_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_signal_selector_write (
    const avdecc_aem_command_set_signal_selector_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_signal_selector_init ( avdecc_aem_response_set_signal_selector_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_signal_selector_t ) );
}


bool avdecc_response_set_signal_selector_read (
    avdecc_aem_response_set_signal_selector_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_signal_selector_write (
    const avdecc_aem_response_set_signal_selector_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_signal_selector_init ( avdecc_aem_command_get_signal_selector_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_signal_selector_t ) );
}


bool avdecc_command_get_signal_selector_read (
    avdecc_aem_command_get_signal_selector_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_signal_selector_write (
    const avdecc_aem_command_get_signal_selector_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_signal_selector_init ( avdecc_aem_response_get_signal_selector_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_signal_selector_t ) );
}


bool avdecc_response_get_signal_selector_read (
    avdecc_aem_response_get_signal_selector_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_signal_selector_write (
    const avdecc_aem_response_get_signal_selector_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_mixer_init ( avdecc_aem_command_set_mixer_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_mixer_t ) );
}


bool avdecc_command_set_mixer_read (
    avdecc_aem_command_set_mixer_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_mixer_write (
    const avdecc_aem_command_set_mixer_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_mixer_init ( avdecc_aem_response_set_mixer_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_mixer_t ) );
}


bool avdecc_response_set_mixer_read (
    avdecc_aem_response_set_mixer_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_mixer_write (
    const avdecc_aem_response_set_mixer_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_mixer_init ( avdecc_aem_command_get_mixer_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_mixer_t ) );
}


bool avdecc_command_get_mixer_read (
    avdecc_aem_command_get_mixer_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_mixer_write (
    const avdecc_aem_command_get_mixer_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_mixer_init ( avdecc_aem_response_get_mixer_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_mixer_t ) );
}


bool avdecc_response_get_mixer_read (
    avdecc_aem_response_get_mixer_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_mixer_write (
    const avdecc_aem_response_get_mixer_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_matrix_init ( avdecc_aem_command_set_matrix_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_matrix_t ) );
}


bool avdecc_command_set_matrix_read (
    avdecc_aem_command_set_matrix_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_matrix_write (
    const avdecc_aem_command_set_matrix_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_matrix_init ( avdecc_aem_response_set_matrix_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_matrix_t ) );
}


bool avdecc_response_set_matrix_read (
    avdecc_aem_response_set_matrix_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_matrix_write (
    const avdecc_aem_response_set_matrix_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_matrix_init ( avdecc_aem_command_get_matrix_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_matrix_t ) );
}


bool avdecc_command_get_matrix_read (
    avdecc_aem_command_get_matrix_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_matrix_write (
    const avdecc_aem_command_get_matrix_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_matrix_init ( avdecc_aem_response_get_matrix_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_matrix_t ) );
}


bool avdecc_response_get_matrix_read (
    avdecc_aem_response_get_matrix_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_matrix_write (
    const avdecc_aem_response_get_matrix_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_start_streaming_init ( avdecc_aem_command_start_streaming_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_start_streaming_t ) );
}


bool avdecc_command_start_streaming_read (
    avdecc_aem_command_start_streaming_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_start_streaming_write (
    const avdecc_aem_command_start_streaming_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_start_streaming_init ( avdecc_aem_response_start_streaming_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_start_streaming_t ) );
}


bool avdecc_response_start_streaming_read (
    avdecc_aem_response_start_streaming_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_start_streaming_write (
    const avdecc_aem_response_start_streaming_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_stop_streaming_init ( avdecc_aem_command_stop_streaming_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_stop_streaming_t ) );
}


bool avdecc_command_stop_streaming_read (
    avdecc_aem_command_stop_streaming_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_stop_streaming_write (
    const avdecc_aem_command_stop_streaming_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_stop_streaming_init ( avdecc_aem_response_stop_streaming_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_stop_streaming_t ) );
}


bool avdecc_response_stop_streaming_read (
    avdecc_aem_response_stop_streaming_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_stop_streaming_write (
    const avdecc_aem_response_stop_streaming_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_stream_info_init ( avdecc_aem_command_set_stream_info_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_stream_info_t ) );
}


bool avdecc_command_set_stream_info_read (
    avdecc_aem_command_set_stream_info_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_stream_info_write (
    const avdecc_aem_command_set_stream_info_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_stream_info_init ( avdecc_aem_response_set_stream_info_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_stream_info_t ) );
}


bool avdecc_response_set_stream_info_read (
    avdecc_aem_response_set_stream_info_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_stream_info_write (
    const avdecc_aem_response_set_stream_info_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_stream_info_init ( avdecc_aem_command_get_stream_info_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_stream_info_t ) );
}


bool avdecc_command_get_stream_info_read (
    avdecc_aem_command_get_stream_info_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_stream_info_write (
    const avdecc_aem_command_get_stream_info_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_stream_info_init ( avdecc_aem_response_get_stream_info_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_stream_info_t ) );
}


bool avdecc_response_get_stream_info_read (
    avdecc_aem_response_get_stream_info_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_stream_info_write (
    const avdecc_aem_response_get_stream_info_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_name_init ( avdecc_aem_command_set_name_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_name_t ) );
}


bool avdecc_command_set_name_read (
    avdecc_aem_command_set_name_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_name_write (
    const avdecc_aem_command_set_name_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_name_init ( avdecc_aem_response_set_name_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_name_t ) );
}


bool avdecc_response_set_name_read (
    avdecc_aem_response_set_name_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_name_write (
    const avdecc_aem_response_set_name_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_name_init ( avdecc_aem_command_get_name_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_name_t ) );
}


bool avdecc_command_get_name_read (
    avdecc_aem_command_get_name_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_name_write (
    const avdecc_aem_command_get_name_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_name_init ( avdecc_aem_response_get_name_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_name_t ) );
}


bool avdecc_response_get_name_read (
    avdecc_aem_response_get_name_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_name_write (
    const avdecc_aem_response_get_name_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_association_id_init ( avdecc_aem_command_set_association_id_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_association_id_t ) );
}


bool avdecc_command_set_association_id_read (
    avdecc_aem_command_set_association_id_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_association_id_write (
    const avdecc_aem_command_set_association_id_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_association_id_init ( avdecc_aem_response_set_association_id_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_association_id_t ) );
}


bool avdecc_response_set_association_id_read (
    avdecc_aem_response_set_association_id_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_association_id_write (
    const avdecc_aem_response_set_association_id_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_association_id_init ( avdecc_aem_command_get_association_id_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_association_id_t ) );
}


bool avdecc_command_get_association_id_read (
    avdecc_aem_command_get_association_id_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_association_id_write (
    const avdecc_aem_command_get_association_id_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_association_id_init ( avdecc_aem_response_get_association_id_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_association_id_t ) );
}


bool avdecc_response_get_association_id_read (
    avdecc_aem_response_get_association_id_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_association_id_write (
    const avdecc_aem_response_get_association_id_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_auth_add_key_init ( avdecc_aem_command_auth_add_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_auth_add_key_t ) );
}


bool avdecc_command_auth_add_key_read (
    avdecc_aem_command_auth_add_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_add_key_write (
    const avdecc_aem_command_auth_add_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_auth_add_key_init ( avdecc_aem_response_auth_add_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_auth_add_key_t ) );
}


bool avdecc_response_auth_add_key_read (
    avdecc_aem_response_auth_add_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_add_key_write (
    const avdecc_aem_response_auth_add_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_auth_get_key_init ( avdecc_aem_command_auth_get_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_auth_get_key_t ) );
}


bool avdecc_command_auth_get_key_read (
    avdecc_aem_command_auth_get_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_get_key_write (
    const avdecc_aem_command_auth_get_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_auth_get_key_init ( avdecc_aem_response_auth_get_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_auth_get_key_t ) );
}


bool avdecc_response_auth_get_key_read (
    avdecc_aem_response_auth_get_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_get_key_write (
    const avdecc_aem_response_auth_get_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_authenticate_init ( avdecc_aem_command_authenticate_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_authenticate_t ) );
}


bool avdecc_command_authenticate_read (
    avdecc_aem_command_authenticate_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_authenticate_write (
    const avdecc_aem_command_authenticate_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_authenticate_init ( avdecc_aem_response_authenticate_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_authenticate_t ) );
}


bool avdecc_response_authenticate_read (
    avdecc_aem_response_authenticate_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_authenticate_write (
    const avdecc_aem_response_authenticate_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_counters_init ( avdecc_aem_command_get_counters_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_counters_t ) );
}


bool avdecc_command_get_counters_read (
    avdecc_aem_command_get_counters_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_counters_write (
    const avdecc_aem_command_get_counters_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_counters_init ( avdecc_aem_response_get_counters_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_counters_t ) );
}


bool avdecc_response_get_counters_read (
    avdecc_aem_response_get_counters_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_counters_write (
    const avdecc_aem_response_get_counters_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_reboot_init ( avdecc_aem_command_reboot_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_reboot_t ) );
}


bool avdecc_command_reboot_read (
    avdecc_aem_command_reboot_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_reboot_write (
    const avdecc_aem_command_reboot_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_reboot_init ( avdecc_aem_response_reboot_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_reboot_t ) );
}


bool avdecc_response_reboot_read (
    avdecc_aem_response_reboot_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_reboot_write (
    const avdecc_aem_response_reboot_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_set_media_format_init ( avdecc_aem_command_set_media_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_set_media_format_t ) );
}


bool avdecc_command_set_media_format_read (
    avdecc_aem_command_set_media_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_media_format_write (
    const avdecc_aem_command_set_media_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_set_media_format_init ( avdecc_aem_response_set_media_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_set_media_format_t ) );
}


bool avdecc_response_set_media_format_read (
    avdecc_aem_response_set_media_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_media_format_write (
    const avdecc_aem_response_set_media_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_media_format_init ( avdecc_aem_command_get_media_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_media_format_t ) );
}


bool avdecc_command_get_media_format_read (
    avdecc_aem_command_get_media_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_media_format_write (
    const avdecc_aem_command_get_media_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_media_format_init ( avdecc_aem_response_get_media_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_media_format_t ) );
}


bool avdecc_response_get_media_format_read (
    avdecc_aem_response_get_media_format_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_media_format_write (
    const avdecc_aem_response_get_media_format_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_register_state_notification_init ( avdecc_aem_command_register_state_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_register_state_notification_t ) );
}


bool avdecc_command_register_state_notification_read (
    avdecc_aem_command_register_state_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_register_state_notification_write (
    const avdecc_aem_command_register_state_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_register_state_notification_init ( avdecc_aem_response_register_state_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_register_state_notification_t ) );
}


bool avdecc_response_register_state_notification_read (
    avdecc_aem_response_register_state_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_register_state_notification_write (
    const avdecc_aem_response_register_state_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_deregister_state_notification_init ( avdecc_aem_command_deregister_state_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_deregister_state_notification_t ) );
}


bool avdecc_command_deregister_state_notification_read (
    avdecc_aem_command_deregister_state_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deregister_state_notification_write (
    const avdecc_aem_command_deregister_state_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_deregister_state_notification_init ( avdecc_aem_response_deregister_state_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_deregister_state_notification_t ) );
}


bool avdecc_response_deregister_state_notification_read (
    avdecc_aem_response_deregister_state_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deregister_state_notification_write (
    const avdecc_aem_response_deregister_state_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_register_query_notification_init ( avdecc_aem_command_register_query_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_register_query_notification_t ) );
}


bool avdecc_command_register_query_notification_read (
    avdecc_aem_command_register_query_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_register_query_notification_write (
    const avdecc_aem_command_register_query_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_register_query_notification_init ( avdecc_aem_response_register_query_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_register_query_notification_t ) );
}


bool avdecc_response_register_query_notification_read (
    avdecc_aem_response_register_query_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_register_query_notification_write (
    const avdecc_aem_response_register_query_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_deregister_query_notification_init ( avdecc_aem_command_deregister_query_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_deregister_query_notification_t ) );
}


bool avdecc_command_deregister_query_notification_read (
    avdecc_aem_command_deregister_query_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deregister_query_notification_write (
    const avdecc_aem_command_deregister_query_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_deregister_query_notification_init ( avdecc_aem_response_deregister_query_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_deregister_query_notification_t ) );
}


bool avdecc_response_deregister_query_notification_read (
    avdecc_aem_response_deregister_query_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deregister_query_notification_write (
    const avdecc_aem_response_deregister_query_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



void avdecc_response_identify_notification_init ( avdecc_aem_response_identify_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_identify_notification_t ) );
}


bool avdecc_response_identify_notification_read (
    avdecc_aem_response_identify_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_identify_notification_write (
    const avdecc_aem_response_identify_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}




void avdecc_response_state_change_notification_init ( avdecc_aem_response_state_change_notification_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_state_change_notification_t ) );
}


bool avdecc_response_state_change_notification_read (
    avdecc_aem_response_state_change_notification_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_state_change_notification_write (
    const avdecc_aem_response_state_change_notification_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_increment_control_value_init ( avdecc_aem_command_increment_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_increment_control_value_t ) );
}


bool avdecc_command_increment_control_value_read (
    avdecc_aem_command_increment_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_increment_control_value_write (
    const avdecc_aem_command_increment_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_increment_control_value_init ( avdecc_aem_response_increment_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_increment_control_value_t ) );
}


bool avdecc_response_increment_control_value_read (
    avdecc_aem_response_increment_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_increment_control_value_write (
    const avdecc_aem_response_increment_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_decrement_control_value_init ( avdecc_aem_command_decrement_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_decrement_control_value_t ) );
}


bool avdecc_command_decrement_control_value_read (
    avdecc_aem_command_decrement_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_decrement_control_value_write (
    const avdecc_aem_command_decrement_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_decrement_control_value_init ( avdecc_aem_response_decrement_control_value_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_decrement_control_value_t ) );
}


bool avdecc_response_decrement_control_value_read (
    avdecc_aem_response_decrement_control_value_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_decrement_control_value_write (
    const avdecc_aem_response_decrement_control_value_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_start_operation_init ( avdecc_aem_command_start_operation_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_start_operation_t ) );
}


bool avdecc_command_start_operation_read (
    avdecc_aem_command_start_operation_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_start_operation_write (
    const avdecc_aem_command_start_operation_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_start_operation_init ( avdecc_aem_response_start_operation_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_start_operation_t ) );
}


bool avdecc_response_start_operation_read (
    avdecc_aem_response_start_operation_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_start_operation_write (
    const avdecc_aem_response_start_operation_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_abort_operation_init ( avdecc_aem_command_abort_operation_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_abort_operation_t ) );
}


bool avdecc_command_abort_operation_read (
    avdecc_aem_command_abort_operation_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_abort_operation_write (
    const avdecc_aem_command_abort_operation_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_abort_operation_init ( avdecc_aem_response_abort_operation_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_abort_operation_t ) );
}


bool avdecc_response_abort_operation_read (
    avdecc_aem_response_abort_operation_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_abort_operation_write (
    const avdecc_aem_response_abort_operation_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



void avdecc_response_operation_status_init ( avdecc_aem_response_operation_status_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_operation_status_t ) );
}


bool avdecc_response_operation_status_read (
    avdecc_aem_response_operation_status_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_operation_status_write (
    const avdecc_aem_response_operation_status_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_auth_get_key_count_init ( avdecc_aem_command_auth_get_key_count_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_auth_get_key_count_t ) );
}


bool avdecc_command_auth_get_key_count_read (
    avdecc_aem_command_auth_get_key_count_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_get_key_count_write (
    const avdecc_aem_command_auth_get_key_count_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_auth_get_key_count_init ( avdecc_aem_response_auth_get_key_count_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_auth_get_key_count_t ) );
}


bool avdecc_response_auth_get_key_count_read (
    avdecc_aem_response_auth_get_key_count_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_get_key_count_write (
    const avdecc_aem_response_auth_get_key_count_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_get_as_path_init ( avdecc_aem_command_get_as_path_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_get_as_path_t ) );
}


bool avdecc_command_get_as_path_read (
    avdecc_aem_command_get_as_path_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_as_path_write (
    const avdecc_aem_command_get_as_path_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_get_as_path_init ( avdecc_aem_response_get_as_path_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_get_as_path_t ) );
}


bool avdecc_response_get_as_path_read (
    avdecc_aem_response_get_as_path_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_as_path_write (
    const avdecc_aem_response_get_as_path_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_deauthenticate_init ( avdecc_aem_command_deauthenticate_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_deauthenticate_t ) );
}


bool avdecc_command_deauthenticate_read (
    avdecc_aem_command_deauthenticate_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deauthenticate_write (
    const avdecc_aem_command_deauthenticate_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_deauthenticate_init ( avdecc_aem_response_deauthenticate_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_deauthenticate_t ) );
}


bool avdecc_response_deauthenticate_read (
    avdecc_aem_response_deauthenticate_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deauthenticate_write (
    const avdecc_aem_response_deauthenticate_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_command_auth_revoke_key_init ( avdecc_aem_command_auth_revoke_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_command_auth_revoke_key_t ) );
}


bool avdecc_command_auth_revoke_key_read (
    avdecc_aem_command_auth_revoke_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_revoke_key_write (
    const avdecc_aem_command_auth_revoke_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_response_auth_revoke_key_init ( avdecc_aem_response_auth_revoke_key_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_response_auth_revoke_key_t ) );
}


bool avdecc_response_auth_revoke_key_read (
    avdecc_aem_response_auth_revoke_key_t *self,
    const void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_revoke_key_write (
    const avdecc_aem_response_auth_revoke_key_t *self,
    void *pdu,
    size_t offset
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



