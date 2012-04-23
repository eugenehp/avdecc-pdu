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

#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_avtp.hpp"
#include "avdecc-pdu_testharness.hpp"
#include "avdecc-pdu_mac_print.hpp"
#include "avdecc-pdu_eui64_print.hpp"
#include "avdecc-pdu_avtp_print.hpp"
#include "avdecc-pdu_stream_print.hpp"

bool test_avdecc_mac ( avdecc_mac_t *mac, const char *mac_as_text );
bool test_avdecc_stream_id ( avdecc_stream_id_t *mac, const char *stream_id_as_text );
bool test_avdecc_macs ( void );
bool test_avdecc_stream_ids ( void );
bool test_avtpdu ( void );

bool test_avdecc_mac ( avdecc_mac_t *mac, const char *mac_as_text )
{
    bool r = true;
    char buf[18];
    avdecc_mac_t mac1;
    START_TEST();
    avdecc_mac_to_text ( mac, buf, sizeof ( buf ) );
    
    if ( strcmp ( buf, mac_as_text ) != 0 )
    {
        printf ( "got %s, expected %s\n", buf, mac_as_text );
        r = false;
    }
    
    mac1 = 0;
    avdecc_mac_from_text ( &mac1, mac_as_text );
    
    if ( *mac!=mac1 )
    {
        char mac_as_text[18];
        char mac1_as_text[18];
        avdecc_mac_to_text ( mac, mac_as_text, sizeof ( mac_as_text ) );
        avdecc_mac_to_text ( &mac1, mac1_as_text, sizeof ( mac_as_text ) );
        printf ( "macs did not compare: %s %s\n", mac_as_text, mac1_as_text );
        r = false;
    }
    
    END_TEST ( r );
    return r;
}

bool test_avdecc_eui64 ( avdecc_eui64_t *eui64, const char *eui64_as_text )
{
    bool r = true;
    char buf[22];
    avdecc_eui64_t eui641;
    START_TEST();
    avdecc_eui64_to_text ( eui64, buf, sizeof ( buf ) );
    
    if ( strcmp ( buf, eui64_as_text ) != 0 )
    {
        printf ( "got %s, expected %s\n", buf, eui64_as_text );
        r = false;
    }
    
    avdecc_eui64_from_text ( &eui641, eui64_as_text );
    
    if ( *eui64 != eui641 )
    {
        char eui64_as_text[18];
        char eui641_as_text[18];
        avdecc_eui64_to_text ( eui64, eui64_as_text, sizeof ( eui64_as_text ) );
        avdecc_eui64_to_text ( &eui641, eui641_as_text, sizeof ( eui64_as_text ) );
        printf ( "eui64s did not compare: %s %s\n", eui64_as_text, eui64_as_text );
        r = false;
    }
    
    END_TEST ( r );
    return r;
}



bool test_avdecc_stream_id ( avdecc_stream_id_t *sid, const char *stream_id_as_text )
{
    bool r = true;
    char buf[24];
    avdecc_stream_id_t sid1;
    START_TEST();
    avdecc_stream_id_to_text ( sid, buf, sizeof ( buf ) );
    
    if ( strcmp ( buf, stream_id_as_text ) != 0 )
    {
        printf ( "got %s, expected %s\n", buf, stream_id_as_text );
        r = false;
    }
    
    avdecc_stream_id_from_text ( &sid1, stream_id_as_text );
    
    if ( *sid != sid1 )
    {
        char sid_as_text[24];
        char sid1_as_text[24];
        avdecc_stream_id_to_text ( sid, sid_as_text, sizeof ( sid_as_text ) );
        avdecc_stream_id_to_text ( &sid1, sid1_as_text, sizeof ( sid1_as_text ) );
        printf ( "stream_ids did not compare: %s %s\n", sid_as_text, sid1_as_text );
        r = false;
    }
    
    END_TEST ( r );
    return r;
}


bool test_avdecc_macs ( void )
{
    bool r = true;
    avdecc_mac_t mac;
    START_TEST();
    mac= 0x123456789abcLL;
    r &= test_avdecc_mac ( &mac, "12:34:56:78:9a:bc" );
    END_TEST ( r );
    return r;
}

bool test_avdecc_eui64s ( void )
{
    bool r = true;
    avdecc_eui64_t eui64;
    START_TEST();
    eui64 = 0x123456789abcdef0LL;
    r &= test_avdecc_eui64 ( &eui64, "12:34:56:78:9a:bc:de:f0" );
    END_TEST ( r );
    return r;
}

bool test_avdecc_stream_ids ( void )
{
    bool r = true;
    avdecc_stream_id_t sid;
    START_TEST();
    sid = 0x123456789abcfaceLL;
    r &= test_avdecc_stream_id ( &sid, "12:34:56:78:9a:bc:fa:ce" );
    END_TEST ( r );
    return r;
}

bool test_avtpdu ( void )
{
    bool r = true;
    START_TEST();
    r &= test_avdecc_macs();
    r &= test_avdecc_eui64s();
    r &= test_avdecc_stream_ids();
    END_TEST ( r );
    return r;
}

int main ( int argc, char **argv )
{
    bool r = true;
    START_TEST();
    r &= test_avtpdu();
    END_TEST ( r );
    
    if ( r )
    {
        return 0;
    }
    
    else
    {
        return 1;
    }
}
