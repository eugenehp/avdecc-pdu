#include "avdecc-pdu_world.h"
#include "avdecc-pdu_app.h"
#include "avdecc-pdu_app_print.h"
#include "avdecc-pdu_eui64_print.h"
#include "avdecc-pdu_mac_print.h"


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


bool avdecc_app_message_type_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_app_message_type_t v
    )
{
    bool r=false;
    static const char *text[] =
    {
        "starttls",
        "auth",
        "active",
        "inactive",
        "port_state_up",
        "port_state_down",
        "avdecc",
        "join_group",
        "leave_group",
        "reserved"
    };

    if ( v<=avdecc_app_message_type_reserved )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
    }
    else if( v==avdecc_app_message_type_vendor )
    {
        r = avdecc_print ( buf,pos,len,"vendor" );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) v );
    }

    return r;
}


int avdecc_app_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_app_t *self
    )
{
    bool r=true;
    r&=avdecc_print ( buf,pos,len,"APP:\n" );
    r&=avdecc_print ( buf,pos,len,"\n%-28s %d", "Version", self->app_version );
    r&=avdecc_print ( buf,pos,len,"%-28s ", "Message Type" );
    r&=avdecc_app_message_type_print ( buf,pos,len, self->app_msg_type );
    r&=avdecc_print ( buf,pos,len,"\n%-28s %d", "Payload Length", self->payload_length );
    r&=avdecc_print ( buf,pos,len,"\n%-28s ", "Source" );
    r&=avdecc_mac_print(buf,pos,len, &self->source );
    r&=avdecc_print ( buf,pos,len,"\n%-28s ", "Destination" );
    r&=avdecc_mac_print(buf,pos,len, &self->destination );

    return r;
}

