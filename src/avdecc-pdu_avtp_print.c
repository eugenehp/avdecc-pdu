
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_avtp_print.h"


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


bool avdecc_avtp_presentation_time_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_presentation_time_t v
    )
{
    return avdecc_print ( buf,offset,len, "%016X", v );
}


bool avdecc_avtp_presentation_time_offset_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_avtp_presentation_time_offset_t v
    )
{
    return avdecc_print ( buf,offset,len, "%d", v );
}



bool avdecc_avtp_subtype_print (
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
        return avdecc_print ( buf,offset,len, "Unknown (0x%02x)", ( int ) subtype );
        break;
    }

    return avdecc_print ( buf,offset,len, "%s", s );
}


bool avdecc_avtp_cd_print (
                           char *buf,
                           size_t *offset,
                           size_t len,
                           avdecc_avtp_cd_t v
                           )
{
    const char *s=0;
    
    switch ( v )
    {
        case avdecc_avtp_cd_control:
            s="Control";
            break;
            
        default:
        case avdecc_avtp_cd_data:
            s="Data";
            break;
    }
    
    return avdecc_print ( buf,offset,len, "%s", s );
}


bool avdecc_avtp_sv_print (
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

    return avdecc_print ( buf,offset,len, "%s", s );
}





bool avdecc_avtp_common_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_avtp_common_t *self
    )
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len,"AVTP Common:\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "cd:" );
    r&=avdecc_avtp_cd_print ( buf,pos,len, self->cd );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "subtype:" );
    r&=avdecc_avtp_subtype_print(buf, pos, len, self->subtype);
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "sv:" );
    r&=avdecc_avtp_sv_print(buf, pos, len, self->sv );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s %d", "version:", self->version );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s 0x%x", "type_specific_data:", self->type_specific_data );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "stream_id: " );
    r&=avdecc_stream_id_print( buf,pos,len,&self->stream_id );
    r&=avdecc_print ( buf,pos,len,"\n" );
    return r;
}

bool avdecc_avtp_stream_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_avtp_stream_t *self
    )
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len,"AVTP Stream:\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "cd:" );
    r&=avdecc_avtp_cd_print ( buf,pos,len, self->cd );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "subtype:" );
    r&=avdecc_avtp_subtype_print(buf, pos, len, self->subtype);
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "sv:" );
    r&=avdecc_avtp_sv_print(buf, pos, len, self->sv );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s %d", "version:", self->version );

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "mr: %d", self->mr );    

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "gv: %d", self->gv );    

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "tv: %d", self->tv );    

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "sequence_num: %d", self->sequence_num );    

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "tu: %d", self->tu );    

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "stream_id: " );
    r&=avdecc_stream_id_print( buf,pos,len,&self->stream_id );

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "avtp_timestamp: " );
    r&=avdecc_avtp_presentation_time_print( buf,pos,len,self->avtp_timestamp );

    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s 0x%x", "gateway_info:", self->gateway_info );
    
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s 0x%x", "protocol_specific_header:", self->protocol_specific_header );
    r&=avdecc_print ( buf,pos,len,"\n" );
    return r;
}

bool avdecc_avtp_control_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_avtp_control_t *self
    )
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len,"AVTP Common:\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "cd:" );
    r&=avdecc_avtp_cd_print ( buf,pos,len, self->cd );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "subtype:" );
    r&=avdecc_avtp_subtype_print(buf, pos, len, self->subtype);
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "sv:" );
    r&=avdecc_avtp_sv_print(buf, pos, len, self->sv );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s %d", "version:", self->version );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s 0x%x", "control_data:", self->control_data );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s 0x%x", "control_status:", self->control_status );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s %d", "control_data_length:", self->control_data_length );
    r&=avdecc_print ( buf,pos,len,"\n" );
    r&=avdecc_print ( buf,pos,len,"%-28s", "stream_id: " );
    r&=avdecc_stream_id_print( buf,pos,len,&self->stream_id );
    r&=avdecc_print ( buf,pos,len,"\n" );
    return r;

}



