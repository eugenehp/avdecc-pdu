#ifndef AVDECC_PDU_STREAM_PRINT_H_
#define AVDECC_PDU_STREAM_PRINT_H_

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
#include "avdecc-pdu_stream.h"

#ifdef __cplusplus
extern "C" {
#endif

    
    bool avdecc_pdu_print_stream_source_state (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_pdu_stream_source_state_t v
    );
    
    bool avdecc_pdu_print_stream_source_sink_state (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_pdu_stream_sink_state_t v
    );
    
    bool avdecc_pdu_print_stream_class (
        char *buf,
        size_t *offset,
        size_t len,
        avdecc_pdu_stream_class_t v
    );
    
    
    bool avdecc_pdu_print_stream_id (
        char *buf,
        size_t *offset,
        size_t len,
        const avdecc_pdu_stream_id_t *stream_id
    );
    
    bool avdecc_pdu_stream_id_to_text ( const avdecc_pdu_stream_id_t *sid, char *buf, int buf_len );
    
    bool avdecc_pdu_stream_id_from_text ( avdecc_pdu_stream_id_t *sid, const char *buf );
    
    
    
    
    
#ifdef __cplusplus
}
#endif

#endif

