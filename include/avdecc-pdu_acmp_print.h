#ifndef AVDECC_PDU_ACMP_PRINT_H_
#define AVDECC_PDU_ACMP_PRINT_H_


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

#include "avdecc-pdu_world.h"
#include "avdecc-pdu_acmp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \addtogroup acmp
    */
/* @{ */

bool avdecc_acmp_status_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_status_t v
    );

bool avdecc_acmp_message_type_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_message_type_t v
    );

bool avdecc_acmp_flags_print (
    char *buf,
    size_t *pos,
    size_t len,
    avdecc_acmp_flags_t v
    );


bool avdecc_acmp_print (
    char *buf,
    size_t *pos,
    size_t len,
    const avdecc_acmp_t *self
    );


/* @} */

#ifdef __cplusplus
}
#endif

#endif
