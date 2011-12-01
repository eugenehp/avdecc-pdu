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
#include "avdecc-pdu_stream_print.h"


bool avdecc_pdu_print_stream_source_state (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_pdu_stream_source_state_t v
)
{
    bool r;
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_pdu_stream_source_state_none:
            s="None";
            break;
            
        case avdecc_pdu_stream_source_state_potential:
            s="Potential";
            break;
            
        case avdecc_pdu_stream_source_state_reserved:
            s="Reserved";
            break;
            
        case avdecc_pdu_stream_source_state_active:
            s="Active";
            break;
    }
    
    /* @TODO: */
}


bool avdecc_pdu_print_stream_source_sink_state (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_pdu_stream_sink_state_t v
)
{
    bool r;
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_pdu_stream_sink_state_inactive:
            s="Inactive";
            break;
            
        case avdecc_pdu_stream_sink_state_active:
            s="Active";
            break;
            
        case avdecc_pdu_stream_sink_state_error:
            s="Error";
            break;
    }
    
    /* @TODO: */
}


bool avdecc_pdu_print_stream_class (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_pdu_stream_class_t v
)
{
    bool r;
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_pdu_stream_class_a:
            s="Class A";
            break;
            
        case avdecc_pdu_stream_class_b:
            s="Class B";
            break;
    }
    
    /* @TODO: */
    return r;
    
}


bool avdecc_pdu_print_stream_id (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_pdu_stream_id_t *stream_id
)
{
    /* @TODO: */
    
}



bool avdecc_pdu_stream_id_to_text ( const avdecc_pdu_stream_id_t *sid, char *buf, int buf_len )
{
    bool r=false;
    uint64_t v= *sid;
    
    if ( buf_len>24 )
    {
        uint8_t bytes[8];
        bytes[0] = AVDECC_BITS_GET_OCTET_7 ( v );
        bytes[1] = AVDECC_BITS_GET_OCTET_6 ( v );
        bytes[2] = AVDECC_BITS_GET_OCTET_5 ( v );
        bytes[3] = AVDECC_BITS_GET_OCTET_4 ( v );
        bytes[4] = AVDECC_BITS_GET_OCTET_3 ( v );
        bytes[5] = AVDECC_BITS_GET_OCTET_2 ( v );
        bytes[6] = AVDECC_BITS_GET_OCTET_1 ( v );
        bytes[7] = AVDECC_BITS_GET_OCTET_0 ( v );
        
        snprintf (
            buf, buf_len,
            "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X",
            bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7]
        );
        
        r=true;
    }
    
    if ( !r )
    {
        *buf='\0';
    }
    
    return r;
}

bool avdecc_pdu_stream_id_from_text ( avdecc_pdu_stream_id_t *sid, const char *buf )
{
    bool r=false;
    int cnt;
    unsigned int bytes[8];
    
    cnt=sscanf ( buf,
                 "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X",
                 &bytes[0],
                 &bytes[1],
                 &bytes[2],
                 &bytes[3],
                 &bytes[4],
                 &bytes[5],
                 &bytes[6],
                 &bytes[7]
               );
               
    if ( cnt==8 )
    {
        *sid = AVDECC_BITS_MAKE_OCTLET (
                   bytes[0], bytes[1], bytes[2], bytes[3],
                   bytes[4], bytes[5], bytes[6], bytes[7]
               );
        r=true;
    }
    
    return r;
}



