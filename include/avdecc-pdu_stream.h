#ifndef AVDECC_PDU_STREAM_H_
#define AVDECC_PDU_STREAM_H_

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
#include "avdecc-pdu_eui64.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup Stream Properties
      * @{
      */
    
    /**
       The possible states for a stream source
    */
    typedef enum
    {
        avdecc_pdu_stream_source_state_none,
        avdecc_pdu_stream_source_state_potential,
        avdecc_pdu_stream_source_state_reserved,
        avdecc_pdu_stream_source_state_active
    }
    avdecc_pdu_stream_source_state_t;
    
    /**
       The possible states for a stream sink
    */
    typedef enum
    {
        avdecc_pdu_stream_sink_state_inactive,
        avdecc_pdu_stream_sink_state_active,
        avdecc_pdu_stream_sink_state_error
    } avdecc_pdu_stream_sink_state_t;
    
    /**
        The possible stream classes
    */
    typedef enum
    {
        avdecc_pdu_stream_class_a,
        avdecc_pdu_stream_class_b
    } avdecc_pdu_stream_class_t;
    
    
    typedef uint64_t avdecc_pdu_stream_id_t;
    
    static inline void avdecc_pdu_stream_id_init ( avdecc_pdu_stream_id_t *self )
    {
        *self = 0;
    }
    
#ifdef __cplusplus
}
#endif

#endif
