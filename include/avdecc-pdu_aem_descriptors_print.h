#ifndef AVDECC_PDU_AEM_DESCRIPTORS_PRINT_H_
#define AVDECC_PDU_AEM_DESCRIPTORS_PRINT_H_

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
#include "avdecc-pdu_aem_descriptors.h"
#include "avdecc-pdu_adp_print.h"
#include "avdecc-pdu_aecp_print.h"
#include "avdecc-pdu_aem_print.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup aem_descriptors aem_descriptors */
    /*@{*/
    
    /*
     avdecc_aem_descriptor_type_t
     avdecc_aem_audio_pull_t
     avdecc_aem_audio_sample_rate_t
     avdecc_aem_descriptor_t
     avdecc_aem_descriptor_entity_t
     avdecc_aem_descriptor_configuration_counts_t
     avdecc_aem_descriptor_configuration_t
     avdecc_aem_descriptor_audio_unit_t
     avdecc_aem_descriptor_video_unit_t
     avdecc_aem_descriptor_sensor_unit_t
     avdecc_aem_stream_format_t
     avdecc_aem_descriptor_stream_t
     avdecc_aem_jack_flags_t
     avdecc_aem_jack_type_t
     avdecc_aem_descriptor_jack_t
     avdecc_aem_port_flags_t
     avdecc_aem_descriptor_audio_port_t
     avdecc_aem_media_format_t
     avdecc_aem_descriptor_video_port_t
     avdecc_aem_descriptor_external_port_t
     avdecc_aem_descriptor_sensor_port_t
     avdecc_aem_descriptor_internal_port_t
     avdecc_aem_msrp_mappings_t
     avdecc_aem_descriptor_avb_interface_t
     avdecc_aem_clock_source_flags_t
     avdecc_aem_clock_source_type_t
     avdecc_aem_descriptor_clock_source_t
     avdecc_aem_audio_mapping_t
     avdecc_aem_descriptor_audio_map_t
     avdecc_aem_descriptor_audio_cluster_t
     avdecc_aem_control_type_t
     avdecc_aem_units_t
     avdecc_aem_control_value_type_t
     avdecc_aem_control_value_type_linear_format_int8_t
     avdecc_aem_control_value_type_linear_format_uint8_t
     avdecc_aem_control_value_type_linear_format_int16_t
     avdecc_aem_control_value_type_linear_format_uint16_t
     avdecc_aem_control_value_type_linear_format_int32_t
     avdecc_aem_control_value_type_linear_format_uint32_t
     avdecc_aem_control_value_type_linear_format_int64_t
     avdecc_aem_control_value_type_linear_format_uint64_t
     avdecc_aem_control_value_type_linear_format_float_t
     avdecc_aem_control_value_type_linear_format_double_t
     avdecc_aem_control_value_type_selector_format_int8_t
     avdecc_aem_control_value_type_selector_format_uint8_t
     avdecc_aem_control_value_type_selector_format_int16_t
     avdecc_aem_control_value_type_selector_format_uint16_t
     avdecc_aem_control_value_type_selector_format_int32_t
     avdecc_aem_control_value_type_selector_format_uint32_t
     avdecc_aem_control_value_type_selector_format_int64_t
     avdecc_aem_control_value_type_selector_format_uint64_t
     avdecc_aem_control_value_type_selector_format_float_t
     avdecc_aem_control_value_type_selector_format_double_t
     avdecc_aem_control_value_type_utf8_format_t
     avdecc_aem_control_value_type_bode_plot_limits_t
     avdecc_aem_control_value_type_bode_plot_entry_t
     avdecc_aem_control_value_type_bode_plot_format_t
     avdecc_aem_control_value_type_array_format_int8_t
     avdecc_aem_control_value_type_array_format_uint8_t
     avdecc_aem_control_value_type_array_format_int16_t
     avdecc_aem_control_value_type_array_format_uint16_t
     avdecc_aem_control_value_type_array_format_int32_t
     avdecc_aem_control_value_type_array_format_uint32_t
     avdecc_aem_control_value_type_array_format_int64_t
     avdecc_aem_control_value_type_array_format_uint64_t
     avdecc_aem_control_value_type_array_format_float_t
     avdecc_aem_control_value_type_array_format_double_t
     avdecc_aem_control_value_type_selector_format_string_t
     avdecc_aem_control_value_type_vendor_format_t
     avdecc_aem_descriptor_control_t
     avdecc_aem_sources_t
     avdecc_aem_descriptor_signal_selector_t
     avdecc_aem_descriptor_mixer_t
     avdecc_aem_descriptor_matrix_t
     avdecc_aem_descriptor_locale_t
     avdecc_aem_descriptor_strings_t
     avdecc_aem_descriptor_matrix_signal_entry_t
     avdecc_aem_descriptor_matrix_signal_t
     avdecc_aem_memory_object_type_t
     avdecc_aem_memory_object_operation_t
     avdecc_aem_descriptor_memory_object_t
     */
    
    bool avdecc_print_aem_descriptor_type (
        char *buf,
        size_t *pos,
        size_t len,
        avdecc_aem_descriptor_type_t v
    );
    
    bool avdecc_print_aem_audio_pull (
        char *buf,
        size_t *pos,
        size_t len,
        avdecc_aem_audio_pull_t v
    );
    
    bool avdecc_print_aem_audio_sample_rate (
        char *buf,
        size_t *pos,
        size_t len,
        avdecc_aem_audio_sample_rate_t v
    );
    
    bool avdecc_print_aem_descriptor (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_t *v
    );
    
    bool avdecc_print_aem_descriptor_entity (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_entity_t *v
    );
    
    bool avdecc_print_aem_descriptor_configuration_counts (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_configuration_counts_t *v
    );
    
    bool avdecc_print_aem_descriptor_configuration (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_configuration_t *v
    );
    
    bool avdecc_print_aem_descriptor_audio_unit (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_audio_unit_t *v
    );
    
    bool avdecc_print_aem_descriptor_video_unit (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_video_unit_t *v
    );
    
    bool avdecc_print_aem_descriptor_sensor_unit (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_sensor_unit_t *v
    );
    
    bool avdecc_print_aem_stream_format (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_stream_format_t *v
    );
    
    bool avdecc_print_aem_descriptor_stream (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_stream_t *v
    );
    
    bool avdecc_print_aem_jack_flags (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_jack_flags_t *v
    );
    
    bool avdecc_print_aem_jack_type (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_jack_type_t *v
    );
    
    bool avdecc_print_aem_descriptor_jack (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_jack_t *v
    );
    
    bool avdecc_print_aem_port_flags (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_port_flags_t *v
    );
    
    bool avdecc_print_aem_descriptor_audio_port (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_audio_port_t *v
    );
    
    bool avdecc_print_aem_media_format (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_media_format_t *v
    );
    
    bool avdecc_print_aem_descriptor_video_port (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_video_port_t *v
    );
    
    bool avdecc_print_aem_descriptor_external_port (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_external_port_t *v
    );
    
    bool avdecc_print_aem_descriptor_sensor_port (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_sensor_port_t *v
    );
    
    bool avdecc_print_aem_descriptor_internal_port (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_internal_port_t *v
    );
    
    bool avdecc_print_aem_msrp_mappings (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_msrp_mappings_t *v
    );
    
    bool avdecc_print_aem_descriptor_avb_interface (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_avb_interface_t *v
    );
    
    bool avdecc_print_aem_clock_source_flags (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_clock_source_flags_t *v
    );
    
    bool avdecc_print_aem_clock_source_type (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_clock_source_type_t *v
    );
    
    bool avdecc_print_aem_descriptor_clock_source (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_clock_source_t *v
    );
    
    bool avdecc_print_aem_audio_mapping (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_audio_mapping_t *v
    );
    
    bool avdecc_print_aem_descriptor_audio_map (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_audio_map_t *v
    );
    
    bool avdecc_print_aem_descriptor_audio_cluster (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_descriptor_audio_cluster_t *v
    );
    
    bool avdecc_print_aem_control_type (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_control_type_t *v
    );
    
    bool avdecc_print_aem_units (
        char *buf,
        size_t *pos,
        size_t len,
        const avdecc_aem_units_t *v
    );
    
    
    
    
    /*@}*/
    
#ifdef __cplusplus
}
#endif


#endif

