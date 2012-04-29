
#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_eui64_print.hpp"
#include "avdecc-pdu_mac_print.hpp"
#include "avdecc-pdu_aecp_print.hpp"
#include "avdecc-pdu_aem_print.hpp"
#include "avdecc-pdu_aem_command_print.hpp"


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

const char *avdecc_command_type_string( avdecc_aem_command_type_t v )
{
    const char *r = "reserved";

    const char *text[] =
    {
        "lock_entity",
        "read_descriptor",
        "write_descriptor",
        "acquire_entity",
        "controller_available",
        "set_clock_source",
        "get_clock_source",
        "set_stream_format",
        "get_stream_format",
        "set_configuration",
        "get_configuration",
        "set_control_value",
        "get_control_value",
        "set_signal_selector",
        "get_signal_selector",
        "set_mixer",
        "get_mixer",
        "set_matrix",
        "get_matrix",
        "start_streaming",
        "stop_streaming",
        "set_stream_info",
        "get_stream_info",
        "set_name",
        "get_name",
        "set_association_id",
        "get_association_id",
        "auth_add_key",
        "auth_get_key",
        "authenticate",
        "get_counters",
        "reboot",
        "set_media_format",
        "get_media_format",
        "register_state_notification",
        "deregister_state_notification",
        "register_query_notification",
        "deregister_query_notification",
        "identify_notification",
        "state_change_notification",
        "increment_control_value",
        "decrement_control_value",
        "start_operation",
        "abort_operation",
        "operation_status",
        "auth_get_key_count",
        "get_as_path",
        "deauthenticate",
        "auth_revoke_key"
    };
    if ( v<= avdecc_aem_command_auth_revoke_key )
    {
        r=text[(int)v];
    }

    return r;
}


bool avdecc_command_type_print(
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_aem_command_type_t command
    )
{
    bool r=true;

    r&=avdecc_print( buf, pos, len, "%s", avdecc_command_type_string(command) );

    return r;
}


bool avdecc_command_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_t *self
    )
{
    bool r=true;
    r&=avdecc_print (buf,pos,len,"AECP AEM Command:\n");
    r&=avdecc_print (buf,pos,len,"%-28s","Message Type");
    r&=avdecc_aecp_message_type_print(buf,pos,len, self->message_type );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Status:" );
    r&=avdecc_aecp_aem_status_print( buf,pos,len,self->status );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Control Data Length:", self->control_data_length );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Target GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->target_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Controller GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->controller_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Sequence ID:", self->sequence_id );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%s", "Unsolicited:",self->unsolicited ? "true" : "false" );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s%s (%d)", "AEM Command:", avdecc_command_type_string(self->command_type), self->command_type );

    return r;
}


bool avdecc_command_lock_entity_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_lock_entity_t *self
    )
{
    bool r=true;
    
    r&=avdecc_command_print( buf, pos, len, &self->base );
    r&=avdecc_print( buf, pos, len, "\n%-28s: 0x%08x", "Lock Entity Flags", self->flags );
    r&=avdecc_print( buf, pos, len, "\n%-28s:", "Lock Entity Locked guid" );

    return r;
}


bool avdecc_response_lock_entity_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_lock_entity_t *self
    )
{
    return avdecc_command_lock_entity_print( buf,pos,len,self);
}


bool avdecc_command_read_descriptor_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_read_descriptor_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_read_descriptor_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_read_descriptor_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_write_descriptor_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_write_descriptor_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_write_descriptor_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_write_descriptor_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_acquire_entity_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_acquire_entity_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_acquire_entity_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_acquire_entity_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_controller_available_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_controller_available_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_controller_available_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_controller_available_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_clock_source_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_clock_source_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_clock_source_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_clock_source_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_clock_source_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_clock_source_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_clock_source_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_clock_source_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_stream_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_stream_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_stream_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_stream_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_stream_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_stream_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_stream_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_stream_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_configuration_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_configuration_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_configuration_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_configuration_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_configuration_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_configuration_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_configuration_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_configuration_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_control_value_t *self
    )
{
    bool r=avdecc_command_print(buf,pos,len,&self->base);
    //TODO print control specific parts.
    //r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_control_value_t *self
    )
{
    bool r=avdecc_command_print(buf,pos,len,&self->base);;
    //TODO print control specific parts.

    return r;
}


bool avdecc_response_get_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_signal_selector_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_signal_selector_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_signal_selector_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_signal_selector_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_signal_selector_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_signal_selector_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_signal_selector_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_signal_selector_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_mixer_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_mixer_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_mixer_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_mixer_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_mixer_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_mixer_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_mixer_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_mixer_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_matrix_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_matrix_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_matrix_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_matrix_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_matrix_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_matrix_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_matrix_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_matrix_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_start_streaming_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_start_streaming_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_start_streaming_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_start_streaming_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_stop_streaming_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_stop_streaming_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_stop_streaming_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_stop_streaming_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_stream_info_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_stream_info_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_stream_info_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_stream_info_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_stream_info_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_stream_info_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_stream_info_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_stream_info_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_name_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_name_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_name_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_name_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_name_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_name_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_name_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_name_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_association_id_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_association_id_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_association_id_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_association_id_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_association_id_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_association_id_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_association_id_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_association_id_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_add_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_auth_add_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_add_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_auth_add_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_get_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_auth_get_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_get_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_auth_get_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_authenticate_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_authenticate_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_authenticate_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_authenticate_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_counters_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_counters_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_counters_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_counters_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_reboot_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_reboot_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_reboot_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_reboot_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_set_media_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_set_media_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_set_media_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_set_media_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_media_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_media_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_media_format_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_media_format_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_register_state_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_register_state_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_register_state_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_register_state_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deregister_state_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_deregister_state_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deregister_state_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_deregister_state_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_register_query_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_register_query_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_register_query_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_register_query_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deregister_query_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_deregister_query_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deregister_query_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_deregister_query_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



bool avdecc_response_identify_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_identify_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



bool avdecc_response_state_change_notification_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_state_change_notification_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_increment_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_increment_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_increment_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_increment_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_decrement_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_decrement_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_decrement_control_value_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_decrement_control_value_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_start_operation_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_start_operation_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_start_operation_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_start_operation_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_abort_operation_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_abort_operation_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_abort_operation_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_abort_operation_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



bool avdecc_response_operation_status_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_operation_status_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_get_key_count_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_auth_get_key_count_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_get_key_count_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_auth_get_key_count_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_get_as_path_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_get_as_path_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_get_as_path_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_get_as_path_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_deauthenticate_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_deauthenticate_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_deauthenticate_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_deauthenticate_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_command_auth_revoke_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_command_auth_revoke_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_response_auth_revoke_key_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aem_response_auth_revoke_key_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



