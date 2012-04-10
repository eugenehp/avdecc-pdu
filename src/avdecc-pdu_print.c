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
#include "avdecc-pdu_print.h"


bool avdecc_print (
    char *buf,
    size_t *offset,
    size_t len,
    const char *fmt,
    ...
    )
{
    bool r = false;
    va_list ap;
    va_start ( ap, fmt );
    
    {
        char *cur_ptr = buf + ( *offset );
        ssize_t max_len = len - ( *offset );
        
        if ( max_len > 0 )
        {
            int result = vsnprintf ( cur_ptr, max_len, fmt, ap );
            
            if ( result < max_len )
            {
                *offset += result;
                r = true;
            }
        }
    }
    
    va_end ( ap );
    return r;
}


bool avdecc_print_block (
    char *buf,
    size_t *offset,
    size_t len,
    const void *packet,
    size_t packet_len
    )
{
    bool r=true;
    const uint8_t *data = ( const uint8_t * ) packet;
    size_t i;

    r&=avdecc_print ( buf,offset,len, "[ " );

    for ( i=0; i<packet_len; i++ )
    {        
        r&=avdecc_print ( buf,offset,len, " %02x", data );
    }
    
    r&=avdecc_print ( buf,offset,len, " ]\n" );
    
    return r;
}

bool avdecc_print_utf8 (
        char *buf,
        size_t *offset,
        size_t len,
        const uint8_t *s,
        size_t s_len
        )
{
    bool r=true;
    size_t i;

    for ( i=0; i<s_len; i++ )
    {
        r&=avdecc_print ( buf,offset,len, "%c", s[i] );
    }

    return r;
}
