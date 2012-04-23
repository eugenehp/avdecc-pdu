
#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_eui64_print.hpp"
#include "avdecc-pdu_mac_print.hpp"
#include "avdecc-pdu_aecp_print.hpp"
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

bool avdecc_aecp_message_type_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_aecp_message_type_t v
    )
{
    bool r=false;
    static const char *text[] =
    {
        "aem_command",
        "aem_response",
        "address_access_command",
        "address_access_response",
        "avc_command",
        "avc_response",
        "vendor_unique_command",
        "vendor_unique_response",
        "reserved  (8)",
        "reserved (9)",
        "reserved (10)",
        "reserved (11)",
        "reserved (12)",
        "reserved (13)",
        "extended_command",
        "extended_response"
    };

    if ( v<= avdecc_aecp_message_type_extended_response )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) v );
    }

    return r;
}

bool avdecc_aecp_status_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_aecp_status_t v
    )
{
    bool r=false;
    static const char *text[] =
    {
        "success",
        "not_implemented"
    };

    if ( v<= avdecc_aecp_status_not_implemented )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) v ] );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) v );
    }

    return r;
}



bool avdecc_aecp_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aecp_t *self
    )
{
    bool r=true;
    r&=avdecc_print (buf,pos,len,"AECP:\n");
    r&=avdecc_print (buf,pos,len,"%-28s","Message Type");
    r&=avdecc_aecp_message_type_print(buf,pos,len, self->message_type );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Status:" );
    r&=avdecc_aecp_status_print ( buf,pos,len,self->status );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Control Data Length:", &self->control_data_length );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Target GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->target_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Controller GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->controller_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Sequence ID:", &self->sequence_id );

    return r;
}

bool avdecc_aecp_aem_status_print(
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_aecp_aem_status_t status
    )
{
    bool r=false;
    static const char *text[] =
    {
        "success",
        "not_implemented",
        "no_such_descriptor",
        "entity_locked",
        "entity_acquired",
        "not_authorized",
        "insufficient_privileges",
        "bad_arguments",
        "no_resources",
        "in_progress"
    };

    if ( status<= avdecc_aem_status_in_progress )
    {
        r = avdecc_print ( buf,pos,len,"%s", text[ ( int ) status ] );
    }
    else
    {
        r = avdecc_print ( buf,pos,len,"reserved (%d)", ( int ) status );
    }

    return r;
}

bool avdecc_aecp_aem_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aecp_aem_t *self
    )
{
    bool r=true;
    r&=avdecc_print (buf,pos,len, "AECP AEM:\n");
    r&=avdecc_print (buf,pos,len,"%-28s","Message Type");
    r&=avdecc_aecp_message_type_print(buf,pos,len, self->message_type );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Status:" );
    r&=avdecc_aecp_aem_status_print ( buf,pos,len,self->status );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Control Data Length:", &self->control_data_length );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Target GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->target_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Controller GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->controller_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Sequence ID:", self->sequence_id );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%s", "Unsolicited:",self->unsolicited ? "true" : "false" );
    r&=avdecc_print ( buf,pos,len,"\n%-28s%s (%d)", "AEM Command:", avdecc_command_type_string(self->command_type), self->command_type );

    return r;
}


bool avdecc_aecp_aa_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aecp_aa_t *self
    )
{
    bool r=true;

    r&=avdecc_print (buf,pos,len, "AECP Address Access:\n");
    r&=avdecc_print (buf,pos,len,"%-28s","Message Type");
    r&=avdecc_aecp_message_type_print(buf,pos,len, self->message_type );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Status:" );
    r&=avdecc_aecp_status_print ( buf,pos,len,self->status );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Control Data Length:", &self->control_data_length );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Target GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->target_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s", "Controller GUID:" );
    r&=avdecc_eui64_print ( buf,pos,len, &self->controller_guid );

    r&=avdecc_print ( buf,pos,len,"\n%-28s%d", "Sequence ID:", &self->sequence_id );


    return r;
}


bool avdecc_aecp_avc_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aecp_avc_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_vu_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_aecp_vu_t *self
    )
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



