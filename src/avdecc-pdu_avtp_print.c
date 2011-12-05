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
#include "avdecc-pdu_avtp_print.h"


bool avdecc_pdu_avtp_print_presentation_time (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_presentation_time_t v
)
{
    return avdecc_pdu_print ( buf,offset,len, "%016X", v );
}


bool avdecc_pdu_print_presentation_time_offset (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_presentation_time_offset_t v
)
{
    return avdecc_pdu_print ( buf,offset,len, "%d", v );
}



bool avdecc_pdu_avtp_print_subtype (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_subtype_t subtype
)
{
    const char *s=0;
    
    switch ( subtype )
    {
        case avdecc_avtp_subtype_61883_IICD:
            s= "61883 IICD";
            break;
            
        case avdecc_avtp_subtype_mma:
            s= "MMA";
            break;
            
        case avdecc_avtp_subtype_aaf:
            s= "AAF";
            break;
            
        case avdecc_avtp_subtype_avf:
            s= "AVF";
            break;
            
        case avdecc_avtp_subtype_cs:
            s= "CS";
            break;
            
        case avdecc_avtp_subtype_adp:
            s= "ADP";
            break;
            
        case avdecc_avtp_subtype_aecp:
            s= "AECP";
            break;
            
        case avdecc_avtp_subtype_acmp:
            s= "ACMP";
            break;
            
        case avdecc_avtp_subtype_mcn:
            s= "MCN";
            break;
            
        case avdecc_avtp_subtype_maap:
            s= "MAAP";
            break;
            
        case avdecc_avtp_subtype_experimental:
            s= "Experimental";
            break;
            
        default:
            return avdecc_pdu_print ( buf,offset,len, "Unknown (0x%02x)", (int)subtype );            
            break;
    }
    
    return avdecc_pdu_print ( buf,offset,len, "%s", s );
}



bool avdecc_pdu_avtp_print_sv (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_sv_t v
)
{
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_avtp_sv_not_valid:
            s="Not valid";
            break;
            
        default:
        case avdecc_avtp_sv_valid:
            s="Valid";
            break;
    }
    
    return avdecc_pdu_print ( buf,offset,len, "%s", s );
}




