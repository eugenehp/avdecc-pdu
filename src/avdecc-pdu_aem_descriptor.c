
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_aem_descriptor.h"


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



void avdecc_audio_pull_init ( avdecc_aem_audio_pull_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_audio_pull_t ) );
}


bool avdecc_audio_pull_read (
    avdecc_aem_audio_pull_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_audio_pull_write (
    const avdecc_aem_audio_pull_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_audio_sample_rate_init ( avdecc_aem_audio_sample_rate_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_audio_sample_rate_t ) );
}


bool avdecc_audio_sample_rate_read (
    avdecc_aem_audio_sample_rate_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_audio_sample_rate_write (
    const avdecc_aem_audio_sample_rate_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_init ( avdecc_aem_descriptor_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_t ) );
}


bool avdecc_descriptor_read (
    avdecc_aem_descriptor_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_write (
    const avdecc_aem_descriptor_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_entity_init ( avdecc_aem_descriptor_entity_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_entity_t ) );
}


bool avdecc_descriptor_entity_read (
    avdecc_aem_descriptor_entity_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_entity_write (
    const avdecc_aem_descriptor_entity_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_configuration_counts_init ( avdecc_aem_descriptor_configuration_counts_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_configuration_counts_t ) );
}


bool avdecc_descriptor_configuration_counts_read (
    avdecc_aem_descriptor_configuration_counts_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_configuration_counts_write (
    const avdecc_aem_descriptor_configuration_counts_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_configuration_init ( avdecc_aem_descriptor_configuration_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_configuration_t ) );
}


bool avdecc_descriptor_configuration_read (
    avdecc_aem_descriptor_configuration_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_configuration_write (
    const avdecc_aem_descriptor_configuration_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_audio_unit_init ( avdecc_aem_descriptor_audio_unit_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_audio_unit_t ) );
}


bool avdecc_descriptor_audio_unit_read (
    avdecc_aem_descriptor_audio_unit_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_audio_unit_write (
    const avdecc_aem_descriptor_audio_unit_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_video_unit_init ( avdecc_aem_descriptor_video_unit_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_video_unit_t ) );
}


bool avdecc_descriptor_video_unit_read (
    avdecc_aem_descriptor_video_unit_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_video_unit_write (
    const avdecc_aem_descriptor_video_unit_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_sensor_unit_init ( avdecc_aem_descriptor_sensor_unit_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_sensor_unit_t ) );
}


bool avdecc_descriptor_sensor_unit_read (
    avdecc_aem_descriptor_sensor_unit_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_sensor_unit_write (
    const avdecc_aem_descriptor_sensor_unit_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_stream_format_init ( avdecc_aem_stream_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_stream_format_t ) );
}


bool avdecc_stream_format_read (
    avdecc_aem_stream_format_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_stream_format_write (
    const avdecc_aem_stream_format_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_stream_init ( avdecc_aem_descriptor_stream_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_stream_t ) );
}


bool avdecc_descriptor_stream_read (
    avdecc_aem_descriptor_stream_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_stream_write (
    const avdecc_aem_descriptor_stream_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_jack_flags_init ( avdecc_aem_jack_flags_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_jack_flags_t ) );
}


bool avdecc_jack_flags_read (
    avdecc_aem_jack_flags_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_jack_flags_write (
    const avdecc_aem_jack_flags_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_jack_type_init ( avdecc_aem_jack_type_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_jack_type_t ) );
}


bool avdecc_jack_type_read (
    avdecc_aem_jack_type_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_jack_type_write (
    const avdecc_aem_jack_type_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_jack_init ( avdecc_aem_descriptor_jack_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_jack_t ) );
}


bool avdecc_descriptor_jack_read (
    avdecc_aem_descriptor_jack_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_jack_write (
    const avdecc_aem_descriptor_jack_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_port_flags_init ( avdecc_aem_port_flags_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_port_flags_t ) );
}


bool avdecc_port_flags_read (
    avdecc_aem_port_flags_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_port_flags_write (
    const avdecc_aem_port_flags_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_audio_port_init ( avdecc_aem_descriptor_audio_port_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_audio_port_t ) );
}


bool avdecc_descriptor_audio_port_read (
    avdecc_aem_descriptor_audio_port_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_audio_port_write (
    const avdecc_aem_descriptor_audio_port_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_media_format_init ( avdecc_aem_media_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_media_format_t ) );
}


bool avdecc_media_format_read (
    avdecc_aem_media_format_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_media_format_write (
    const avdecc_aem_media_format_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_video_port_init ( avdecc_aem_descriptor_video_port_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_video_port_t ) );
}


bool avdecc_descriptor_video_port_read (
    avdecc_aem_descriptor_video_port_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_video_port_write (
    const avdecc_aem_descriptor_video_port_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_external_port_init ( avdecc_aem_descriptor_external_port_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_external_port_t ) );
}


bool avdecc_descriptor_external_port_read (
    avdecc_aem_descriptor_external_port_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_external_port_write (
    const avdecc_aem_descriptor_external_port_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_sensor_port_init ( avdecc_aem_descriptor_sensor_port_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_sensor_port_t ) );
}


bool avdecc_descriptor_sensor_port_read (
    avdecc_aem_descriptor_sensor_port_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_sensor_port_write (
    const avdecc_aem_descriptor_sensor_port_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_internal_port_init ( avdecc_aem_descriptor_internal_port_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_internal_port_t ) );
}


bool avdecc_descriptor_internal_port_read (
    avdecc_aem_descriptor_internal_port_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_internal_port_write (
    const avdecc_aem_descriptor_internal_port_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_msrp_mappings_init ( avdecc_aem_msrp_mappings_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_msrp_mappings_t ) );
}


bool avdecc_msrp_mappings_read (
    avdecc_aem_msrp_mappings_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_msrp_mappings_write (
    const avdecc_aem_msrp_mappings_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_avb_interface_init ( avdecc_aem_descriptor_avb_interface_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_avb_interface_t ) );
}


bool avdecc_descriptor_avb_interface_read (
    avdecc_aem_descriptor_avb_interface_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_avb_interface_write (
    const avdecc_aem_descriptor_avb_interface_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_clock_source_flags_init ( avdecc_aem_clock_source_flags_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_clock_source_flags_t ) );
}


bool avdecc_clock_source_flags_read (
    avdecc_aem_clock_source_flags_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_clock_source_flags_write (
    const avdecc_aem_clock_source_flags_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_clock_source_type_init ( avdecc_aem_clock_source_type_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_clock_source_type_t ) );
}


bool avdecc_clock_source_type_read (
    avdecc_aem_clock_source_type_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_clock_source_type_write (
    const avdecc_aem_clock_source_type_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_clock_source_init ( avdecc_aem_descriptor_clock_source_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_clock_source_t ) );
}


bool avdecc_descriptor_clock_source_read (
    avdecc_aem_descriptor_clock_source_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_clock_source_write (
    const avdecc_aem_descriptor_clock_source_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_audio_mapping_init ( avdecc_aem_audio_mapping_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_audio_mapping_t ) );
}


bool avdecc_audio_mapping_read (
    avdecc_aem_audio_mapping_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_audio_mapping_write (
    const avdecc_aem_audio_mapping_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_audio_map_init ( avdecc_aem_descriptor_audio_map_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_audio_map_t ) );
}


bool avdecc_descriptor_audio_map_read (
    avdecc_aem_descriptor_audio_map_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_audio_map_write (
    const avdecc_aem_descriptor_audio_map_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_audio_cluster_init ( avdecc_aem_descriptor_audio_cluster_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_audio_cluster_t ) );
}


bool avdecc_descriptor_audio_cluster_read (
    avdecc_aem_descriptor_audio_cluster_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_audio_cluster_write (
    const avdecc_aem_descriptor_audio_cluster_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_type_init ( avdecc_aem_control_type_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_type_t ) );
}


bool avdecc_control_type_read (
    avdecc_aem_control_type_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_type_write (
    const avdecc_aem_control_type_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_units_init ( avdecc_aem_units_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_units_t ) );
}


bool avdecc_units_read (
    avdecc_aem_units_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_units_write (
    const avdecc_aem_units_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_init ( avdecc_aem_control_value_type_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_t ) );
}


bool avdecc_control_value_type_read (
    avdecc_aem_control_value_type_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_write (
    const avdecc_aem_control_value_type_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_int8_init ( avdecc_aem_control_value_type_linear_format_int8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_int8_t ) );
}


bool avdecc_control_value_type_linear_format_int8_read (
    avdecc_aem_control_value_type_linear_format_int8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_int8_write (
    const avdecc_aem_control_value_type_linear_format_int8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_uint8_init ( avdecc_aem_control_value_type_linear_format_uint8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_uint8_t ) );
}


bool avdecc_control_value_type_linear_format_uint8_read (
    avdecc_aem_control_value_type_linear_format_uint8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_uint8_write (
    const avdecc_aem_control_value_type_linear_format_uint8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_int16_init ( avdecc_aem_control_value_type_linear_format_int16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_int16_t ) );
}


bool avdecc_control_value_type_linear_format_int16_read (
    avdecc_aem_control_value_type_linear_format_int16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_int16_write (
    const avdecc_aem_control_value_type_linear_format_int16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_uint16_init ( avdecc_aem_control_value_type_linear_format_uint16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_uint16_t ) );
}


bool avdecc_control_value_type_linear_format_uint16_read (
    avdecc_aem_control_value_type_linear_format_uint16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_uint16_write (
    const avdecc_aem_control_value_type_linear_format_uint16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_int32_init ( avdecc_aem_control_value_type_linear_format_int32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_int32_t ) );
}


bool avdecc_control_value_type_linear_format_int32_read (
    avdecc_aem_control_value_type_linear_format_int32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_int32_write (
    const avdecc_aem_control_value_type_linear_format_int32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_uint32_init ( avdecc_aem_control_value_type_linear_format_uint32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_uint32_t ) );
}


bool avdecc_control_value_type_linear_format_uint32_read (
    avdecc_aem_control_value_type_linear_format_uint32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_uint32_write (
    const avdecc_aem_control_value_type_linear_format_uint32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_int64_init ( avdecc_aem_control_value_type_linear_format_int64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_int64_t ) );
}


bool avdecc_control_value_type_linear_format_int64_read (
    avdecc_aem_control_value_type_linear_format_int64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_int64_write (
    const avdecc_aem_control_value_type_linear_format_int64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_uint64_init ( avdecc_aem_control_value_type_linear_format_uint64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_uint64_t ) );
}


bool avdecc_control_value_type_linear_format_uint64_read (
    avdecc_aem_control_value_type_linear_format_uint64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_uint64_write (
    const avdecc_aem_control_value_type_linear_format_uint64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_float_init ( avdecc_aem_control_value_type_linear_format_float_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_float_t ) );
}


bool avdecc_control_value_type_linear_format_float_read (
    avdecc_aem_control_value_type_linear_format_float_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_float_write (
    const avdecc_aem_control_value_type_linear_format_float_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_linear_format_double_init ( avdecc_aem_control_value_type_linear_format_double_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_linear_format_double_t ) );
}


bool avdecc_control_value_type_linear_format_double_read (
    avdecc_aem_control_value_type_linear_format_double_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_linear_format_double_write (
    const avdecc_aem_control_value_type_linear_format_double_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_int8_init ( avdecc_aem_control_value_type_selector_format_int8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_int8_t ) );
}


bool avdecc_control_value_type_selector_format_int8_read (
    avdecc_aem_control_value_type_selector_format_int8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_int8_write (
    const avdecc_aem_control_value_type_selector_format_int8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_uint8_init ( avdecc_aem_control_value_type_selector_format_uint8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_uint8_t ) );
}


bool avdecc_control_value_type_selector_format_uint8_read (
    avdecc_aem_control_value_type_selector_format_uint8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_uint8_write (
    const avdecc_aem_control_value_type_selector_format_uint8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_int16_init ( avdecc_aem_control_value_type_selector_format_int16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_int16_t ) );
}


bool avdecc_control_value_type_selector_format_int16_read (
    avdecc_aem_control_value_type_selector_format_int16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_int16_write (
    const avdecc_aem_control_value_type_selector_format_int16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_uint16_init ( avdecc_aem_control_value_type_selector_format_uint16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_uint16_t ) );
}


bool avdecc_control_value_type_selector_format_uint16_read (
    avdecc_aem_control_value_type_selector_format_uint16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_uint16_write (
    const avdecc_aem_control_value_type_selector_format_uint16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_int32_init ( avdecc_aem_control_value_type_selector_format_int32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_int32_t ) );
}


bool avdecc_control_value_type_selector_format_int32_read (
    avdecc_aem_control_value_type_selector_format_int32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_int32_write (
    const avdecc_aem_control_value_type_selector_format_int32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_uint32_init ( avdecc_aem_control_value_type_selector_format_uint32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_uint32_t ) );
}


bool avdecc_control_value_type_selector_format_uint32_read (
    avdecc_aem_control_value_type_selector_format_uint32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_uint32_write (
    const avdecc_aem_control_value_type_selector_format_uint32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_int64_init ( avdecc_aem_control_value_type_selector_format_int64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_int64_t ) );
}


bool avdecc_control_value_type_selector_format_int64_read (
    avdecc_aem_control_value_type_selector_format_int64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_int64_write (
    const avdecc_aem_control_value_type_selector_format_int64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_uint64_init ( avdecc_aem_control_value_type_selector_format_uint64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_uint64_t ) );
}


bool avdecc_control_value_type_selector_format_uint64_read (
    avdecc_aem_control_value_type_selector_format_uint64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_uint64_write (
    const avdecc_aem_control_value_type_selector_format_uint64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_float_init ( avdecc_aem_control_value_type_selector_format_float_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_float_t ) );
}


bool avdecc_control_value_type_selector_format_float_read (
    avdecc_aem_control_value_type_selector_format_float_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_float_write (
    const avdecc_aem_control_value_type_selector_format_float_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_double_init ( avdecc_aem_control_value_type_selector_format_double_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_double_t ) );
}


bool avdecc_control_value_type_selector_format_double_read (
    avdecc_aem_control_value_type_selector_format_double_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_double_write (
    const avdecc_aem_control_value_type_selector_format_double_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_utf8_format_init ( avdecc_aem_control_value_type_utf8_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_utf8_format_t ) );
}


bool avdecc_control_value_type_utf8_format_read (
    avdecc_aem_control_value_type_utf8_format_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_utf8_format_write (
    const avdecc_aem_control_value_type_utf8_format_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_bode_plot_limits_init ( avdecc_aem_control_value_type_bode_plot_limits_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_bode_plot_limits_t ) );
}


bool avdecc_control_value_type_bode_plot_limits_read (
    avdecc_aem_control_value_type_bode_plot_limits_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_bode_plot_limits_write (
    const avdecc_aem_control_value_type_bode_plot_limits_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_bode_plot_entry_init ( avdecc_aem_control_value_type_bode_plot_entry_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_bode_plot_entry_t ) );
}


bool avdecc_control_value_type_bode_plot_entry_read (
    avdecc_aem_control_value_type_bode_plot_entry_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_bode_plot_entry_write (
    const avdecc_aem_control_value_type_bode_plot_entry_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_bode_plot_format_init ( avdecc_aem_control_value_type_bode_plot_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_bode_plot_format_t ) );
}


bool avdecc_control_value_type_bode_plot_format_read (
    avdecc_aem_control_value_type_bode_plot_format_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_bode_plot_format_write (
    const avdecc_aem_control_value_type_bode_plot_format_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_int8_init ( avdecc_aem_control_value_type_array_format_int8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_int8_t ) );
}


bool avdecc_control_value_type_array_format_int8_read (
    avdecc_aem_control_value_type_array_format_int8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_int8_write (
    const avdecc_aem_control_value_type_array_format_int8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_uint8_init ( avdecc_aem_control_value_type_array_format_uint8_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_uint8_t ) );
}


bool avdecc_control_value_type_array_format_uint8_read (
    avdecc_aem_control_value_type_array_format_uint8_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_uint8_write (
    const avdecc_aem_control_value_type_array_format_uint8_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_int16_init ( avdecc_aem_control_value_type_array_format_int16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_int16_t ) );
}


bool avdecc_control_value_type_array_format_int16_read (
    avdecc_aem_control_value_type_array_format_int16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_int16_write (
    const avdecc_aem_control_value_type_array_format_int16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_uint16_init ( avdecc_aem_control_value_type_array_format_uint16_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_uint16_t ) );
}


bool avdecc_control_value_type_array_format_uint16_read (
    avdecc_aem_control_value_type_array_format_uint16_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_uint16_write (
    const avdecc_aem_control_value_type_array_format_uint16_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_int32_init ( avdecc_aem_control_value_type_array_format_int32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_int32_t ) );
}


bool avdecc_control_value_type_array_format_int32_read (
    avdecc_aem_control_value_type_array_format_int32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_int32_write (
    const avdecc_aem_control_value_type_array_format_int32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_uint32_init ( avdecc_aem_control_value_type_array_format_uint32_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_uint32_t ) );
}


bool avdecc_control_value_type_array_format_uint32_read (
    avdecc_aem_control_value_type_array_format_uint32_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_uint32_write (
    const avdecc_aem_control_value_type_array_format_uint32_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_int64_init ( avdecc_aem_control_value_type_array_format_int64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_int64_t ) );
}


bool avdecc_control_value_type_array_format_int64_read (
    avdecc_aem_control_value_type_array_format_int64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_int64_write (
    const avdecc_aem_control_value_type_array_format_int64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_uint64_init ( avdecc_aem_control_value_type_array_format_uint64_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_uint64_t ) );
}


bool avdecc_control_value_type_array_format_uint64_read (
    avdecc_aem_control_value_type_array_format_uint64_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_uint64_write (
    const avdecc_aem_control_value_type_array_format_uint64_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_float_init ( avdecc_aem_control_value_type_array_format_float_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_float_t ) );
}


bool avdecc_control_value_type_array_format_float_read (
    avdecc_aem_control_value_type_array_format_float_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_float_write (
    const avdecc_aem_control_value_type_array_format_float_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_array_format_double_init ( avdecc_aem_control_value_type_array_format_double_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_array_format_double_t ) );
}


bool avdecc_control_value_type_array_format_double_read (
    avdecc_aem_control_value_type_array_format_double_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_array_format_double_write (
    const avdecc_aem_control_value_type_array_format_double_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_selector_format_string_init ( avdecc_aem_control_value_type_selector_format_string_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_selector_format_string_t ) );
}


bool avdecc_control_value_type_selector_format_string_read (
    avdecc_aem_control_value_type_selector_format_string_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_selector_format_string_write (
    const avdecc_aem_control_value_type_selector_format_string_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_control_value_type_vendor_format_init ( avdecc_aem_control_value_type_vendor_format_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_control_value_type_vendor_format_t ) );
}


bool avdecc_control_value_type_vendor_format_read (
    avdecc_aem_control_value_type_vendor_format_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_control_value_type_vendor_format_write (
    const avdecc_aem_control_value_type_vendor_format_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_control_init ( avdecc_aem_descriptor_control_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_control_t ) );
}


bool avdecc_descriptor_control_read (
    avdecc_aem_descriptor_control_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_control_write (
    const avdecc_aem_descriptor_control_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_sources_init ( avdecc_aem_sources_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_sources_t ) );
}


bool avdecc_sources_read (
    avdecc_aem_sources_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_sources_write (
    const avdecc_aem_sources_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_signal_selector_init ( avdecc_aem_descriptor_signal_selector_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_signal_selector_t ) );
}


bool avdecc_descriptor_signal_selector_read (
    avdecc_aem_descriptor_signal_selector_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_signal_selector_write (
    const avdecc_aem_descriptor_signal_selector_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_mixer_init ( avdecc_aem_descriptor_mixer_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_mixer_t ) );
}


bool avdecc_descriptor_mixer_read (
    avdecc_aem_descriptor_mixer_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_mixer_write (
    const avdecc_aem_descriptor_mixer_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_matrix_init ( avdecc_aem_descriptor_matrix_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_matrix_t ) );
}


bool avdecc_descriptor_matrix_read (
    avdecc_aem_descriptor_matrix_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_matrix_write (
    const avdecc_aem_descriptor_matrix_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_locale_init ( avdecc_aem_descriptor_locale_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_locale_t ) );
}


bool avdecc_descriptor_locale_read (
    avdecc_aem_descriptor_locale_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_locale_write (
    const avdecc_aem_descriptor_locale_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_strings_init ( avdecc_aem_descriptor_strings_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_strings_t ) );
}


bool avdecc_descriptor_strings_read (
    avdecc_aem_descriptor_strings_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_strings_write (
    const avdecc_aem_descriptor_strings_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_matrix_signal_entry_init ( avdecc_aem_descriptor_matrix_signal_entry_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_matrix_signal_entry_t ) );
}


bool avdecc_descriptor_matrix_signal_entry_read (
    avdecc_aem_descriptor_matrix_signal_entry_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_matrix_signal_entry_write (
    const avdecc_aem_descriptor_matrix_signal_entry_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_matrix_signal_init ( avdecc_aem_descriptor_matrix_signal_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_matrix_signal_t ) );
}


bool avdecc_descriptor_matrix_signal_read (
    avdecc_aem_descriptor_matrix_signal_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_matrix_signal_write (
    const avdecc_aem_descriptor_matrix_signal_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_memory_object_type_init ( avdecc_aem_memory_object_type_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_memory_object_type_t ) );
}


bool avdecc_memory_object_type_read (
    avdecc_aem_memory_object_type_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_memory_object_type_write (
    const avdecc_aem_memory_object_type_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_memory_object_operation_init ( avdecc_aem_memory_object_operation_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_memory_object_operation_t ) );
}


bool avdecc_memory_object_operation_read (
    avdecc_aem_memory_object_operation_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_memory_object_operation_write (
    const avdecc_aem_memory_object_operation_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_descriptor_memory_object_init ( avdecc_aem_descriptor_memory_object_t *self )
{
    memset ( ( void * ) self, 0, sizeof ( avdecc_aem_descriptor_memory_object_t ) );
}


bool avdecc_descriptor_memory_object_read (
    avdecc_aem_descriptor_memory_object_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_descriptor_memory_object_write (
    const avdecc_aem_descriptor_memory_object_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



