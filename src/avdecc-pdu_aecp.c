
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_aecp.h"


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



void avdecc_aecp_init ( avdecc_aecp_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_aecp_t ) );
}


bool avdecc_aecp_read (
    avdecc_aecp_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_write (
    const avdecc_aecp_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_aem_init ( avdecc_aecp_aem_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_aecp_aem_t ) );
}


bool avdecc_aecp_aem_read (
    avdecc_aecp_aem_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_aem_write (
    const avdecc_aecp_aem_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_aa_init ( avdecc_aecp_aa_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_aecp_aa_t ) );
}


bool avdecc_aecp_aa_read (
    avdecc_aecp_aa_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_aa_write (
    const avdecc_aecp_aa_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_avc_init ( avdecc_aecp_avc_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_aecp_avc_t ) );
}


bool avdecc_aecp_avc_read (
    avdecc_aecp_avc_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_avc_write (
    const avdecc_aecp_avc_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


void avdecc_aecp_vu_init ( avdecc_aecp_vu_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_aecp_vu_t ) );
}


bool avdecc_aecp_vu_read (
    avdecc_aecp_vu_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_aecp_vu_write (
    const avdecc_aecp_vu_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



