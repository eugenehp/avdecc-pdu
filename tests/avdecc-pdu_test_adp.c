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
#include "avdecc-pdu_avtp.h"
#include "avdecc-pdu_adp.h"
#include "avdecc-pdu_adp_print.h"
#include "avdecc-pdu_testharness.h"
#if 0
bool test_adp ( void );


bool test_adp ( void )
{
    bool r = true;
    size_t i;
    avdecc_adp_t adp;
    uint8_t adpdu[68];
    avdecc_adp_t adp1;
    uint8_t adpdu1[68];
    
    START_TEST();
    avdecc_adp_init ( &adp );
    adp.m_message_type = avdecc_adp_message_type_entity_available;
    
    avdecc_entity_type_init ( &adp.m_entity_type );
    adp.m_entity_type.audio_source = true;
    adp.m_entity_type.loudspeaker = true;
    adp.m_entity_capabilities.association_id_supported = true;
    
    adp.m_vendor_model_id=0x1323334353637383;
    
    adp.m_entity_guid=0x1222324252627282;
    
    adp.m_controller_capabilities.implemented = false;
    adp.m_listener_stream_sinks = 1;
    adp.m_listener_capabilities.implemented = true;
    adp.m_listener_capabilities.audio_sink = true;
    adp.m_listener_capabilities.media_clock_sink = true;
    adp.m_talker_stream_sources = 1;
    adp.m_talker_capabilities.implemented = true;
    adp.m_talker_capabilities.audio_source = true;
    adp.m_talker_capabilities.media_clock_source = true;
    
    adp.m_default_audio_format.audio_sr_48k = true;
    adp.m_default_audio_format.audio_sr_96k = true;
    adp.m_default_audio_format.audio_aaf = true;
    adp.m_default_audio_format.audio_8_ch = true;
    adp.m_default_audio_format.max_channels = 8;
    
    adp.m_default_video_format.video_avf = false;
    
    adp.m_association_id = 0x1020304050607080;
    
    adp.m_as_grandmaster_id = 0x1121314151617181;
    
    adp.m_available_index = 2;
    
    adp.m_valid_time = 1;
    
    
    us_stdout->printf ( us_stdout, "\n\nADP:\n" );
    avdecc_adp_print_adp ( us_stdout, &adp );
    
    avdecc_adp_write_pdu ( &adp, &adpdu );
    
    us_stdout->printf ( us_stdout, "\n\ngenerated ADPDU:\n" );
    avdecc_adp_print_adpdu ( us_stdout, &adpdu );
    
    if ( !avdecc_adp_read_pdu ( &adp1, &adpdu ) )
    {
        us_stdout->printf ( us_stderr, "\n\nRead_pdu failed\n" );
        r=false;
    }
    
    us_stdout->printf ( us_stdout, "\nre-generated ADP1:\n" );
    avdecc_adp_print_adp ( us_stdout, &adp1 );
    
    avdecc_adp_write_pdu ( &adp1, &adpdu1 );
    
    us_stdout->printf ( us_stdout, "\nre-generated ADPDU1:\n" );
    avdecc_adp_print_adpdu ( us_stdout, &adpdu1 );
    
    avdecc_adp_print_adpdu ( us_stdout, &adpdu );
    
    for ( i=0; i<sizeof ( adpdu ); ++i )
    {
        if ( adpdu[i] != adpdu1[i] )
        {
            us_stdout->printf (
                us_stdout, "byte %d of pdu is different: 0x%02x != 0x%02x\n",
                i, adpdu[i], adpdu1[i]
            );
            r=false;
        }
    }
    
    
    END_TEST ( r );
    return r;
}
#endif

int main ( int argc, char **argv )
{
    bool r = true;
    
    if ( r )
    {
        return 0;
    }
    
    else
    {
        return 1;
    }
}

