#ifndef AVDECC_PDU_MAC_H_
#define AVDECC_PDU_MAC_H_


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


#ifdef __cplusplus
extern "C" {
#endif

    /**
    \addtogroup mac
    */
    /* @{ */
    
    
    /** avdecc_mac_t
    */
    
    typedef struct avdecc_mac_s
    {
        /* TODO */
    } avdecc_mac_t;
    
    
    
    /** avdecc_mac_init
     *
     *  Initialize a avdecc_mac_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_mac_init ( avdecc_mac_t *self );
    
    
    /** avdecc_mac_read
     *
     *  Read a avdecc_mac_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_mac_read (
        avdecc_mac_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_mac_write
     *
     *  write a avdecc_mac_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_mac_write (
        const avdecc_mac_t *self,
        void *pdu,
        size_t offset
    );
    
    
    
    /* @} */
    
#ifdef __cplusplus
}
#endif

#endif
