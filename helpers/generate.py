
# Copyright (c) 2012, Jeff Koftinoff <jeff.koftinoff@ieee.org>
# All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


copyright = """
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
"""


eui64_types = [
    ("avdecc_eui64_t","eui64")
]

mac_types = [
    ("avdecc_mac_t","mac")
]

stream_types = [
    ("avdecc_stream_t","stream")
]


adp_types = [
    ( "avdecc_adp_t","adp" )
]

acmp_types = [
    ( "avdecc_acmp_t","acmp" )
]

aecp_types = [
    ( "avdecc_aecp_t","aecp" ),
    ( "avdecc_aecp_aem_t","aecp_aem" ),
    ( "avdecc_aecp_aa_t","aecp_aa" ),
    ( "avdecc_aecp_avc_t","aecp_avc" ),
    ( "avdecc_aecp_vu_t","aecp_vu" ),
]

avtp_types = [
    ( "avdecc_avtp_common_t","avtp_common" ),
    ( "avdecc_avtp_stream_t","avtp_stream" ),
    ( "avdecc_avtp_control_t","avtp_control" )
]

aem_descriptor_types = [
#     ( "avdecc_aem_descriptor_type_t", "descriptor_type" ),
     ( "avdecc_aem_audio_pull_t", "audio_pull" ),
     ( "avdecc_aem_audio_sample_rate_t", "audio_sample_rate" ),
     ( "avdecc_aem_descriptor_t", "descriptor" ),
     ( "avdecc_aem_descriptor_entity_t", "descriptor_entity" ),
     ( "avdecc_aem_descriptor_configuration_counts_t", "descriptor_configuration_counts" ),
     ( "avdecc_aem_descriptor_configuration_t", "descriptor_configuration" ),
     ( "avdecc_aem_descriptor_audio_unit_t", "descriptor_audio_unit" ),
     ( "avdecc_aem_descriptor_video_unit_t", "descriptor_video_unit" ),
     ( "avdecc_aem_descriptor_sensor_unit_t", "descriptor_sensor_unit" ),
     ( "avdecc_aem_stream_format_t", "stream_format" ),
     ( "avdecc_aem_descriptor_stream_t", "descriptor_stream" ),
     ( "avdecc_aem_jack_flags_t", "jack_flags" ),
     ( "avdecc_aem_jack_type_t", "jack_type" ),
     ( "avdecc_aem_descriptor_jack_t", "descriptor_jack" ),
     ( "avdecc_aem_port_flags_t", "port_flags" ),
     ( "avdecc_aem_descriptor_audio_port_t", "descriptor_audio_port" ),
     ( "avdecc_aem_media_format_t", "media_format" ),
     ( "avdecc_aem_descriptor_video_port_t", "descriptor_video_port" ),
     ( "avdecc_aem_descriptor_external_port_t", "descriptor_external_port" ),
     ( "avdecc_aem_descriptor_sensor_port_t", "descriptor_sensor_port" ),
     ( "avdecc_aem_descriptor_internal_port_t", "descriptor_internal_port" ),
     ( "avdecc_aem_msrp_mappings_t", "msrp_mappings" ),
     ( "avdecc_aem_descriptor_avb_interface_t", "descriptor_avb_interface" ),
     ( "avdecc_aem_clock_source_flags_t", "clock_source_flags" ),
     ( "avdecc_aem_clock_source_type_t", "clock_source_type" ),
     ( "avdecc_aem_descriptor_clock_source_t", "descriptor_clock_source" ),
     ( "avdecc_aem_audio_mapping_t", "audio_mapping" ),
     ( "avdecc_aem_descriptor_audio_map_t", "descriptor_audio_map" ),
     ( "avdecc_aem_descriptor_audio_cluster_t", "descriptor_audio_cluster" ),
     ( "avdecc_aem_control_type_t", "control_type" ),
     ( "avdecc_aem_units_t", "units" ),
     ( "avdecc_aem_control_value_type_t", "control_value_type" ),
     ( "avdecc_aem_control_value_type_linear_format_int8_t", "control_value_type_linear_format_int8" ),
     ( "avdecc_aem_control_value_type_linear_format_uint8_t", "control_value_type_linear_format_uint8" ),
     ( "avdecc_aem_control_value_type_linear_format_int16_t", "control_value_type_linear_format_int16" ),
     ( "avdecc_aem_control_value_type_linear_format_uint16_t", "control_value_type_linear_format_uint16" ),
     ( "avdecc_aem_control_value_type_linear_format_int32_t", "control_value_type_linear_format_int32" ),
     ( "avdecc_aem_control_value_type_linear_format_uint32_t", "control_value_type_linear_format_uint32" ),
     ( "avdecc_aem_control_value_type_linear_format_int64_t", "control_value_type_linear_format_int64" ),
     ( "avdecc_aem_control_value_type_linear_format_uint64_t", "control_value_type_linear_format_uint64" ),
     ( "avdecc_aem_control_value_type_linear_format_float_t", "control_value_type_linear_format_float" ),
     ( "avdecc_aem_control_value_type_linear_format_double_t", "control_value_type_linear_format_double" ),
     ( "avdecc_aem_control_value_type_selector_format_int8_t", "control_value_type_selector_format_int8" ),
     ( "avdecc_aem_control_value_type_selector_format_uint8_t", "control_value_type_selector_format_uint8" ),
     ( "avdecc_aem_control_value_type_selector_format_int16_t", "control_value_type_selector_format_int16" ),
     ( "avdecc_aem_control_value_type_selector_format_uint16_t", "control_value_type_selector_format_uint16" ),
     ( "avdecc_aem_control_value_type_selector_format_int32_t", "control_value_type_selector_format_int32" ),
     ( "avdecc_aem_control_value_type_selector_format_uint32_t", "control_value_type_selector_format_uint32" ),
     ( "avdecc_aem_control_value_type_selector_format_int64_t", "control_value_type_selector_format_int64" ),
     ( "avdecc_aem_control_value_type_selector_format_uint64_t", "control_value_type_selector_format_uint64" ),
     ( "avdecc_aem_control_value_type_selector_format_float_t", "control_value_type_selector_format_float" ),
     ( "avdecc_aem_control_value_type_selector_format_double_t", "control_value_type_selector_format_double" ),
     ( "avdecc_aem_control_value_type_utf8_format_t", "control_value_type_utf8_format" ),
     ( "avdecc_aem_control_value_type_bode_plot_limits_t", "control_value_type_bode_plot_limits" ),
     ( "avdecc_aem_control_value_type_bode_plot_entry_t", "control_value_type_bode_plot_entry" ),
     ( "avdecc_aem_control_value_type_bode_plot_format_t", "control_value_type_bode_plot_format" ),
     ( "avdecc_aem_control_value_type_array_format_int8_t", "control_value_type_array_format_int8" ),
     ( "avdecc_aem_control_value_type_array_format_uint8_t", "control_value_type_array_format_uint8" ),
     ( "avdecc_aem_control_value_type_array_format_int16_t", "control_value_type_array_format_int16" ),
     ( "avdecc_aem_control_value_type_array_format_uint16_t", "control_value_type_array_format_uint16" ),
     ( "avdecc_aem_control_value_type_array_format_int32_t", "control_value_type_array_format_int32" ),
     ( "avdecc_aem_control_value_type_array_format_uint32_t", "control_value_type_array_format_uint32" ),
     ( "avdecc_aem_control_value_type_array_format_int64_t", "control_value_type_array_format_int64" ),
     ( "avdecc_aem_control_value_type_array_format_uint64_t", "control_value_type_array_format_uint64" ),
     ( "avdecc_aem_control_value_type_array_format_float_t", "control_value_type_array_format_float" ),
     ( "avdecc_aem_control_value_type_array_format_double_t", "control_value_type_array_format_double" ),
     ( "avdecc_aem_control_value_type_selector_format_string_t", "control_value_type_selector_format_string" ),
     ( "avdecc_aem_control_value_type_vendor_format_t", "control_value_type_vendor_format" ),
     ( "avdecc_aem_descriptor_control_t", "descriptor_control" ),
     ( "avdecc_aem_sources_t", "sources" ),
     ( "avdecc_aem_descriptor_signal_selector_t", "descriptor_signal_selector" ),
     ( "avdecc_aem_descriptor_mixer_t", "descriptor_mixer" ),
     ( "avdecc_aem_descriptor_matrix_t", "descriptor_matrix" ),
     ( "avdecc_aem_descriptor_locale_t", "descriptor_locale" ),
     ( "avdecc_aem_descriptor_strings_t", "descriptor_strings" ),
     ( "avdecc_aem_descriptor_matrix_signal_entry_t", "descriptor_matrix_signal_entry" ),
     ( "avdecc_aem_descriptor_matrix_signal_t", "descriptor_matrix_signal" ),
     ( "avdecc_aem_memory_object_type_t", "memory_object_type" ),
     ( "avdecc_aem_memory_object_operation_t", "memory_object_operation" ),
     ( "avdecc_aem_descriptor_memory_object_t", "descriptor_memory_object" ),
]

aem_command_types = [
   ( "avdecc_aem_command_lock_entity_t", "command_lock_entity" ),
   ( "avdecc_aem_response_lock_entity_t", "response_lock_entity" ),
   ( "avdecc_aem_command_read_descriptor_t", "command_read_descriptor" ),
   ( "avdecc_aem_response_read_descriptor_t", "response_read_descriptor" ),
   ( "avdecc_aem_command_write_descriptor_t", "command_write_descriptor" ),
   ( "avdecc_aem_response_write_descriptor_t", "response_write_descriptor" ),
   ( "avdecc_aem_command_acquire_entity_t", "command_acquire_entity" ),
   ( "avdecc_aem_response_acquire_entity_t", "response_acquire_entity" ),
   ( "avdecc_aem_command_controller_available_t", "command_controller_available" ),
   ( "avdecc_aem_response_controller_available_t", "response_controller_available" ),
   ( "avdecc_aem_command_set_clock_source_t", "command_set_clock_source" ),
   ( "avdecc_aem_response_set_clock_source_t", "response_set_clock_source" ),
   ( "avdecc_aem_command_get_clock_source_t", "command_get_clock_source" ),
   ( "avdecc_aem_response_get_clock_source_t", "response_get_clock_source" ),
   ( "avdecc_aem_command_set_stream_format_t", "command_set_stream_format" ),
   ( "avdecc_aem_response_set_stream_format_t", "response_set_stream_format" ),
   ( "avdecc_aem_command_get_stream_format_t", "command_get_stream_format" ),
   ( "avdecc_aem_response_get_stream_format_t", "response_get_stream_format" ),
   ( "avdecc_aem_command_set_configuration_t", "command_set_configuration" ),
   ( "avdecc_aem_response_set_configuration_t", "response_set_configuration" ),
   ( "avdecc_aem_command_get_configuration_t", "command_get_configuration" ),
   ( "avdecc_aem_response_get_configuration_t", "response_get_configuration" ),
   ( "avdecc_aem_command_set_control_value_t", "command_set_control_value" ),
   ( "avdecc_aem_response_set_control_value_t", "response_set_control_value" ),
   ( "avdecc_aem_command_get_control_value_t", "command_get_control_value" ),
   ( "avdecc_aem_response_get_control_value_t", "response_get_control_value" ),
   ( "avdecc_aem_command_set_signal_selector_t", "command_set_signal_selector" ),
   ( "avdecc_aem_response_set_signal_selector_t", "response_set_signal_selector" ),
   ( "avdecc_aem_command_get_signal_selector_t", "command_get_signal_selector" ),
   ( "avdecc_aem_response_get_signal_selector_t", "response_get_signal_selector" ),
   ( "avdecc_aem_command_set_mixer_t", "command_set_mixer" ),
   ( "avdecc_aem_response_set_mixer_t", "response_set_mixer" ),
   ( "avdecc_aem_command_get_mixer_t", "command_get_mixer" ),
   ( "avdecc_aem_response_get_mixer_t", "response_get_mixer" ),
   ( "avdecc_aem_command_set_matrix_t", "command_set_matrix" ),
   ( "avdecc_aem_response_set_matrix_t", "response_set_matrix" ),
   ( "avdecc_aem_command_get_matrix_t", "command_get_matrix" ),
   ( "avdecc_aem_response_get_matrix_t", "response_get_matrix" ),
   ( "avdecc_aem_command_start_streaming_t", "command_start_streaming" ),
   ( "avdecc_aem_response_start_streaming_t", "response_start_streaming" ),
   ( "avdecc_aem_command_stop_streaming_t", "command_stop_streaming" ),
   ( "avdecc_aem_response_stop_streaming_t", "response_stop_streaming" ),
   ( "avdecc_aem_command_set_stream_info_t", "command_set_stream_info" ),
   ( "avdecc_aem_response_set_stream_info_t", "response_set_stream_info" ),
   ( "avdecc_aem_command_get_stream_info_t", "command_get_stream_info" ),
   ( "avdecc_aem_response_get_stream_info_t", "response_get_stream_info" ),
   ( "avdecc_aem_command_set_name_t", "command_set_name" ),
   ( "avdecc_aem_response_set_name_t", "response_set_name" ),
   ( "avdecc_aem_command_get_name_t", "command_get_name" ),
   ( "avdecc_aem_response_get_name_t", "response_get_name" ),
   ( "avdecc_aem_command_set_association_id_t", "command_set_association_id" ),
   ( "avdecc_aem_response_set_association_id_t", "response_set_association_id" ),
   ( "avdecc_aem_command_get_association_id_t", "command_get_association_id" ),
   ( "avdecc_aem_response_get_association_id_t", "response_get_association_id" ),
   ( "avdecc_aem_command_auth_add_key_t", "command_auth_add_key" ),
   ( "avdecc_aem_response_auth_add_key_t", "response_auth_add_key" ),
   ( "avdecc_aem_command_auth_get_key_t", "command_auth_get_key" ),
   ( "avdecc_aem_response_auth_get_key_t", "response_auth_get_key" ),
   ( "avdecc_aem_command_authenticate_t", "command_authenticate" ),
   ( "avdecc_aem_response_authenticate_t", "response_authenticate" ),
   ( "avdecc_aem_command_get_counters_t", "command_get_counters" ),
   ( "avdecc_aem_response_get_counters_t", "response_get_counters" ),
   ( "avdecc_aem_command_reboot_t", "command_reboot" ),
   ( "avdecc_aem_response_reboot_t", "response_reboot" ),
   ( "avdecc_aem_command_set_media_format_t", "command_set_media_format" ),
   ( "avdecc_aem_response_set_media_format_t", "response_set_media_format" ),
   ( "avdecc_aem_command_get_media_format_t", "command_get_media_format" ),
   ( "avdecc_aem_response_get_media_format_t", "response_get_media_format" ),
   ( "avdecc_aem_command_register_state_notification_t", "command_register_state_notification" ),
   ( "avdecc_aem_response_register_state_notification_t", "response_register_state_notification" ),
   ( "avdecc_aem_command_deregister_state_notification_t", "command_deregister_state_notification" ),
   ( "avdecc_aem_response_deregister_state_notification_t", "response_deregister_state_notification" ),
   ( "avdecc_aem_command_register_query_notification_t", "command_register_query_notification" ),
   ( "avdecc_aem_response_register_query_notification_t", "response_register_query_notification" ),
   ( "avdecc_aem_command_deregister_query_notification_t", "command_deregister_query_notification" ),
   ( "avdecc_aem_response_deregister_query_notification_t", "response_deregister_query_notification" ),
   ( "avdecc_aem_command_identify_notification_t", "command_identify_notification" ),
   ( "avdecc_aem_response_identify_notification_t", "response_identify_notification" ),
   ( "avdecc_aem_command_state_change_notification_t", "command_state_change_notification" ),
   ( "avdecc_aem_response_state_change_notification_t", "response_state_change_notification" ),
   ( "avdecc_aem_command_increment_control_value_t", "command_increment_control_value" ),
   ( "avdecc_aem_response_increment_control_value_t", "response_increment_control_value" ),
   ( "avdecc_aem_command_decrement_control_value_t", "command_decrement_control_value" ),
   ( "avdecc_aem_response_decrement_control_value_t", "response_decrement_control_value" ),
   ( "avdecc_aem_command_start_operation_t", "command_start_operation" ),
   ( "avdecc_aem_response_start_operation_t", "response_start_operation" ),
   ( "avdecc_aem_command_abort_operation_t", "command_abort_operation" ),
   ( "avdecc_aem_response_abort_operation_t", "response_abort_operation" ),
   ( "avdecc_aem_command_operation_status_t", "command_operation_status" ),
   ( "avdecc_aem_response_operation_status_t", "response_operation_status" ),
   ( "avdecc_aem_command_auth_get_key_count_t", "command_auth_get_key_count" ),
   ( "avdecc_aem_response_auth_get_key_count_t", "response_auth_get_key_count" ),
   ( "avdecc_aem_command_get_as_path_t", "command_get_as_path" ),
   ( "avdecc_aem_response_get_as_path_t", "response_get_as_path" ),
   ( "avdecc_aem_command_deauthenticate_t", "command_deauthenticate" ),
   ( "avdecc_aem_response_deauthenticate_t", "response_deauthenticate" ),
   ( "avdecc_aem_command_auth_revoke_key_t", "command_auth_revoke_key" ),
   ( "avdecc_aem_response_auth_revoke_key_t", "response_auth_revoke_key" )
]

top_list = [
    ("avdecc-pdu_mac","mac",mac_types),
    ("avdecc-pdu_eui64","eui64",eui64_types),
    ("avdecc-pdu_stream","stream",stream_types),
    ("avdecc-pdu_aem_descriptor","aem_descriptor",aem_descriptor_types),
    ("avdecc-pdu_aem_command","aem_command",aem_command_types),
    ("avdecc-pdu_avtp","avtp",avtp_types),
    ("avdecc-pdu_aecp","aecp",aecp_types),
    ("avdecc-pdu_acmp","acmp",acmp_types),
    ("avdecc-pdu_adp","adp",adp_types)
    ]

def generate_h_print(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write("""
bool avdecc%(sect)s_%(name)s_print( 
   char *buf, 
   size_t *pos, 
   size_t len, 
   const %(type)s *self 
   ); 
""" % v)

def generate_c_print(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
bool avdecc%(sect)s_%(name)s_print( 
    char *buf, 
    size_t *pos, 
    size_t len, 
    const %(type)s *self 
    )
{
    bool r=true;

    r&=false; /* TODO */

    return r;
}

""" % v )

def generate_h_struct(f,module,sect,v):
    stag=v[0]
    stag=stag[:-2] + "_s"
    v = { "stag" : stag, "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
/** %(type)s
*/

typedef struct %(stag)s
{
    /* TODO */
} %(type)s;

""" % v )

    

def generate_h_init(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """

/** avdecc%(sect)s_%(name)s_init 
 *  
 *  Initialize a %(type)s
 *
 *  @param self pointer to object to initialize
 *  @returns void
 */

void avdecc%(sect)s_%(name)s_init( %(type)s *self ); 
""" % v )

def generate_h_read(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """

/** avdecc%(sect)s_%(name)s_read 
 *  
 *  Read a %(type)s from a PDU
 *
 *  @param self pointer to object to fill
 *  @param pdu pointer to base of pdu to read
 *  @param offset offset from base of pdu in octets to start reading from
 */

bool avdecc%(sect)s_%(name)s_read( 
    %(type)s *self, 
    const void *pdu, 
    size_t offset 
    );

""" % v )

def generate_h_write(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
/** avdecc%(sect)s_%(name)s_write
 *  
 *  write a %(type)s into a pdu
 *
 *  @param self pointer to object to store into pdu
 *  @param pdu pointer to base of pdu to write to
 *  @param offset offset from base of pdu in octets to start writing to
 */

bool avdecc%(sect)s_%(name)s_write( 
    const %(type)s *self, 
    void *pdu, 
    size_t offset 
    );

""" % v )

def generate_c_init(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
void avdecc%(sect)s_%(name)s_init( %(type)s *self )
{
    bzero( (void *)self, sizeof(%(type)s) );
}

""" % v )


def generate_c_read(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
bool avdecc%(sect)s_%(name)s_read( 
    %(type)s *self, 
    const void *pdu, 
    size_t offset 
    )
{
    bool r=true;

    r&=false; /* TODO */

    return r;
}

""" % v )

def generate_c_write(f,module,sect,v): 
    v = { "module" : module, "sect" : sect, "name" : v[1], "type" : v[0] }
    f.write( """
bool avdecc%(sect)s_%(name)s_write( 
    const %(type)s *self, 
    void *pdu, 
    size_t offset
    )
{
    bool r=true;

    r&=false; /* TODO */

    return r;
}

""" % v )

def prefix_h_print_with_inc(f,module,sect):
    guard = "AVDECC_PDU_%s%s_PRINT_H_" % (module.upper(),sect.upper(),)
    v={"copyright" : copyright, "guard" : guard, "module" : module, "sect" : sect }
    
    f.write("""#ifndef %(guard)s
#define %(guard)s

%(copyright)s

#include "avdecc-pdu_%(module)s.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
    \\addtogroup %(module)s%(sect)s
    */
    /* @{ */


""" % v)

def prefix_h(f,module,sect):
    guard = "AVDECC_PDU_%s%s_H_" % (module.upper(),sect.upper(),)
    v={"copyright" : copyright, "guard" : guard, "module" : module, "sect" : sect }
    
    f.write("""#ifndef %(guard)s
#define %(guard)s

%(copyright)s

#ifdef __cplusplus
extern "C" {
#endif

    /**
    \\addtogroup %(module)s%(sect)s
    */
    /* @{ */

""" % v)

def suffix_h(f,module,sect):
    guard = "AVDECC_PDU_%s%s_H_" % (module.upper(),sect.upper(),)
    v={"guard" : guard, "module" : module, "sect" : sect }
    

    f.write("""

    /* @} */

#ifdef __cplusplus
}
#endif

#endif
""" % v)


def prefix_c(f,module,sect):
    v={"copyright" : copyright, "module" : module, "sect" : sect }
    
    f.write("""
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_%(module)s.h"

%(copyright)s

""" % v)

def suffix_c(f,module,sect):
    v={"module" : module, "sect" : sect }
    
    f.write("""

""" % v)


def generate_file(filename,module,sect,prefix,suffix,items,procs):
    with open(filename,"w") as f:
        prefix(f,module,sect)
        for i in items:
            for proc in procs:
                proc(f,module,sect,i)
        suffix(f,module,sect)

def generate_print_module(filename,module,sect,items):
    generate_file(filename+".h",module,sect,prefix_h_print_with_inc,suffix_h,items,[generate_h_print])
    generate_file(filename+".c",module,sect,prefix_c,suffix_c,items,[generate_c_print])

def generate_module(filename,module,sect,items):
    generate_file(filename+".h",module,sect,prefix_h,suffix_h,items,[generate_h_struct,generate_h_init,generate_h_read,generate_h_write])
    generate_file(filename+".c",module,sect,prefix_c,suffix_c,items,[generate_c_init,generate_c_read,generate_c_write])


def generate_all_module(filename,module,sect,items):
    if sect!="":
        sect = "_" + sect
    generate_print_module(filename+"_print",module,sect,items)
    generate_module(filename+"",module,sect,items)

def generate(filename,module,items):
    generate_module(filename,module,"print",items)
    generate_all_module(filename,module,"",items)


for filename,module,items in top_list:
    generate(filename,module,items)
    

