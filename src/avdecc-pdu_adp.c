
#include "avdecc-pdu_world.h"
#include "avdecc-pdu_adp.h"


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



void avdecc_adp_init ( avdecc_adp_t *self )
{
    bzero ( ( void * ) self, sizeof ( avdecc_adp_t ) );
}


bool avdecc_adp_read (
    avdecc_adp_t *self,
    const void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}


bool avdecc_adp_write (
    const avdecc_adp_t *self,
    void *pdu,
    size_t offset
)
{
    bool r=true;
    
    r&=false; /* TODO */
    
    return r;
}



