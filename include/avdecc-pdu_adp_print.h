#ifndef AVDECC_PDU_ADP_PRINT_H_
#define AVDECC_PDU_ADP_PRINT_H_


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


#include "avdecc-pdu_adp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \addtogroup adp
    */
/* @{ */


bool avdecc_adp_message_type_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_message_type_t v
    );

bool avdecc_adp_valid_time_print (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_valid_time_t v
    );

bool avdecc_print_adp_control_data_length (
    char *buf,
    size_t *offset,
    size_t len,
    avdecc_adp_control_data_length_t control_data_length
    );


bool avdecc_adp_talker_capabilities_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_talker_capabilities_t *talker_capabilities
    );

bool avdecc_adp_listener_capabilities_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_listener_capabilities_t *listener_capabilities
    );

bool avdecc_adp_controller_capabilities_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_controller_capabilities_t *controller_capabilities
    );

bool avdecc_adp_entity_capabilities_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_entity_capabilities_t *entity_capabilities
    );

bool avdecc_adp_print (
    char *buf,
    size_t *offset,
    size_t len,
    const avdecc_adp_t *adp
    );

/* @} */

#ifdef __cplusplus
}
#endif

#endif
