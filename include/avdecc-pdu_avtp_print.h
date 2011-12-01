#ifndef AVDECC_PDU_AVTP_PRINT_H_
#define AVDECC_PDU_AVTP_PRINT_H_

/*
 Copyright (c) 2010, Jeff Koftinoff <jeff.koftinoff@ieee.org>
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
#include "avdecc-pdu_avtp.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup avtp avtp */
    /*@{*/
    
    bool avdecc_avtp_print_subtype (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_avtp_subtype_t subtype
    );
    
    bool avdecc_avtp_print_sv (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_avtp_sv_t v
    );
    
    
    bool avdecc_avtp_print_presentation_time (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_avtp_presentation_time_t v
    );
    
    
    bool avdecc_avtp_print_presentation_time_offset (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_avtp_presentation_time_offset_t v
    );
    
    
    
    
    /*@}*/
    
#ifdef __cplusplus
}
#endif

#endif