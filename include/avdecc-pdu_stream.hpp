#ifndef AVDECC_PDU_STREAM_HPP_
#define AVDECC_PDU_STREAM_HPP_


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



/**
    \addtogroup stream
    */
/* @{ */


/**
     The possible states for a stream source
     */
typedef enum
{
    avdecc_stream_source_state_none,
    avdecc_stream_source_state_potential,
    avdecc_stream_source_state_reserved,
    avdecc_stream_source_state_active
}
avdecc_stream_source_state_t;

/**
     The possible states for a stream sink
     */
typedef enum
{
    avdecc_stream_sink_state_inactive,
    avdecc_stream_sink_state_active,
    avdecc_stream_sink_state_error
} avdecc_stream_sink_state_t;

/**
     The possible stream classes
     */
typedef enum
{
    avdecc_stream_class_a,
    avdecc_stream_class_b
} avdecc_stream_class_t;


typedef uint64_t avdecc_stream_id_t;

static inline void avdecc_stream_id_init ( avdecc_stream_id_t *self )
{
    *self = 0;
}

bool avdecc_stream_id_read (
    avdecc_stream_id_t *self,
    const void *pdu,
    size_t offset
    );

bool avdecc_stream_id_write (
    const avdecc_stream_id_t *self,
    void *pdu,
    size_t offset
    );

/* @} */


#endif
