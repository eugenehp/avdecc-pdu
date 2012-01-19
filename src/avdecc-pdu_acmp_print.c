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
#include "avdecc-pdu_acmp_print.h"

int avdecc_print_acmp_status (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_status_t v
)
{
    bool r=false;
    static const char *text[] =
    {
        "success",
        "listener_unknown_id",
        "talker_unknown_id",
        "talker_dest_mac_fail",
        "talker_no_stream_index",
        "talker_no_bandwidth",
        "talker_exclusive",
        "listener_talker_timeout",
        "listener_exclusive",
        "state_unavailable",
        "not_connected",
        "no_such_connection",
        "could_not_send_message",
        "listener_default_format_invalid",
        "talker_default_format_invalid",
        "default_set_different",
        "controller_not_authorized",
        "incompatible_request"
    };
    
    if ( v< avdecc_acmp_status_reserved )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) v );
    }
    
    return r;
    
}

int avdecc_print_acmp_message_type (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_message_type_t v
)
{
    bool r=false;
    static const char *text[] =
    {
        "connect_tx_command",
        "connect_tx_response",
        "disconnect_tx_command",
        "disconnect_tx_response",
        "get_tx_state_command",
        "get_tx_state_response",
        "connect_rx_command",
        "connect_rx_response",
        "disconnect_rx_command",
        "disconnect_rx_response",
        "get_rx_state_command",
        "get_rx_state_response",
        "get_tx_connection_command",
        "get_tx_connection_response"
    };
    
    if ( v< avdecc_acmp_message_reserved )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) v );
    }
    
    return r;
}

int avdecc_print_acmp_flags (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_flags_t v
)
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len, " [ " );
    
    if ( v.fast_connect )
    {
        r&=avdecc_print ( buf,pos,len, "FAST_CONNECT " );
    }
    
    if ( v.saved_state )
    {
        r&=avdecc_print ( buf,pos,len, "SAVED_STATE " );
    }
    
    if ( v.class_b )
    {
        r&=avdecc_print ( buf,pos,len, "CLASS_B " );
    }
    
    if ( v.streaming_wait )
    {
        r&=avdecc_print ( buf,pos,len, "STREAMING_WAIT " );
    }
    
    r&=avdecc_print ( buf,pos,len, " ] " );
    
    return r;
}

int avdecc_print_acmp (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_acmp_t *acmp
)
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len,"ACMP:\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "Message Type:" );
    r&=avdecc_print_acmp_message_type ( buf,pos,len, acmp->message_type );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Status:" );
    r&=avdecc_print_acmp_status ( buf,pos,len,acmp->status );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Control Data Length:", &acmp->control_data_length );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Controller GUID:" );
    r&=avdecc_print_eui64 ( buf,pos,len, &acmp->controller_guid );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Talker GUID:" );
    r&=avdecc_print_eui64 ( buf,pos,len, &acmp->talker_guid );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Listener GUID:" );
    r&=avdecc_print_eui64 ( buf,pos,len, &acmp->listener_guid );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s%0x04x", "Talker Unique ID:", acmp->talker_unique_id );
    r&=avdecc_print ( buf,pos,len,"\n%-28s%0x04x", "Listener Unique ID:", acmp->listener_unique_id );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Destination MAC:" );
    r&=avdecc_print_mac ( buf,pos,len, &acmp->dest_mac );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s%0x04x", "Connection Count:", acmp->connection_count );
    r&=avdecc_print ( buf,pos,len,"\n%-28s%0x04x", "Sequence ID:", acmp->sequence_id );
    
    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Flags:" );
    r&=avdecc_print_acmp_flags ( buf,pos,len, acmp->flags );
    
    return r;
}

