#ifndef AVDECC_PDU_STREAM_PRINT_HPP_
#define AVDECC_PDU_STREAM_PRINT_HPP_


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


#include "avdecc-pdu_stream.hpp"


/**
    \addtogroup stream
    */
/* @{ */



bool avdecc_stream_source_state_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_stream_source_state_t v
    );

bool avdecc_stream_source_sink_state_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_stream_sink_state_t v
    );

bool avdecc_stream_class_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_stream_class_t v
    );


bool avdecc_stream_id_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_stream_id_t *stream_id
    );

bool avdecc_stream_id_to_text ( const avdecc_stream_id_t *sid, char *buf, int buf_len );

bool avdecc_stream_id_from_text ( avdecc_stream_id_t *sid, const char *buf );



/* @} */


#endif
