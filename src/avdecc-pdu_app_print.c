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
        "nop",
        "hello",
        "upgrade",
        "starttls",
        "authenticate",
        "port_status",
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

bool avdecc_app_status_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_app_status_t v
    )
{
    bool r=false;
    static const char *text[] =
    {
        "success",
        "invalid_header"
        "unsupported_version",
        "not_implemented",
        "invalid_status",
        "invalid_message_type",
        "invalid_destination",
        "invalid_source",
        "invalid_payload_length",
        "invalid_payload",
        "authentication_required",
        "authentication_failed",
        "tls_required",
        "reserved"
    };

    if ( v<=avdecc_app_status_reserved )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
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

    r&=avdecc_print ( buf,pos,len,"\n%-28s %d", "Version:", self->version );

    r&=avdecc_print ( buf,pos,len,"%-28s ", "Status:" );
    r&=avdecc_app_message_type_print ( buf,pos,len, self->status );

    r&=avdecc_print ( buf,pos,len,"\n%-28s %s", "Unsolicited:", self->unsolicited ? "true" : "false" );

    r&=avdecc_print ( buf,pos,len,"%-28s ", "Message Type:" );
    r&=avdecc_app_message_type_print ( buf,pos,len, self->message_type );

    r&=avdecc_print ( buf,pos,len,"\n%-28s %s (%d)", "rc:", self->rc ? "response" : "command", self->rc );

    r&=avdecc_print ( buf,pos,len,"\n%-28s %d", "Payload Length:", self->payload_length );

    r&=avdecc_print ( buf,pos,len,"\n%-28s ", "Source:" );
    r&=avdecc_mac_print(buf,pos,len, &self->source );

    r&=avdecc_print ( buf,pos,len,"\n%-28s ", "Destination:" );
    r&=avdecc_mac_print(buf,pos,len, &self->destination );

    r&=avdecc_print ( buf,pos,len,"\n%-28s ", "Payload: " );
    r&=avdecc_print_block( buf, pos, len, self->payload, self->payload_length );

    return r;
}

