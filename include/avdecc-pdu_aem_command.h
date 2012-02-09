#ifndef AVDECC_PDU_AEM_COMMAND_H_
#define AVDECC_PDU_AEM_COMMAND_H_


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
    \addtogroup aem_command
    */
    /* @{ */
    
    
    /** avdecc_aem_command_lock_entity_t
    */
    
    typedef struct avdecc_aem_command_lock_entity_s
    {
        /* TODO */
    } avdecc_aem_command_lock_entity_t;
    
    
    
    /** avdecc_command_lock_entity_init
     *
     *  Initialize a avdecc_aem_command_lock_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_lock_entity_init ( avdecc_aem_command_lock_entity_t *self );
    
    
    /** avdecc_command_lock_entity_read
     *
     *  Read a avdecc_aem_command_lock_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_lock_entity_read (
        avdecc_aem_command_lock_entity_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_lock_entity_write
     *
     *  write a avdecc_aem_command_lock_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_lock_entity_write (
        const avdecc_aem_command_lock_entity_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_lock_entity_t
    */
    
    typedef struct avdecc_aem_response_lock_entity_s
    {
        /* TODO */
    } avdecc_aem_response_lock_entity_t;
    
    
    
    /** avdecc_response_lock_entity_init
     *
     *  Initialize a avdecc_aem_response_lock_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_lock_entity_init ( avdecc_aem_response_lock_entity_t *self );
    
    
    /** avdecc_response_lock_entity_read
     *
     *  Read a avdecc_aem_response_lock_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_lock_entity_read (
        avdecc_aem_response_lock_entity_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_lock_entity_write
     *
     *  write a avdecc_aem_response_lock_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_lock_entity_write (
        const avdecc_aem_response_lock_entity_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_read_descriptor_t
    */
    
    typedef struct avdecc_aem_command_read_descriptor_s
    {
        /* TODO */
    } avdecc_aem_command_read_descriptor_t;
    
    
    
    /** avdecc_command_read_descriptor_init
     *
     *  Initialize a avdecc_aem_command_read_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_read_descriptor_init ( avdecc_aem_command_read_descriptor_t *self );
    
    
    /** avdecc_command_read_descriptor_read
     *
     *  Read a avdecc_aem_command_read_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_read_descriptor_read (
        avdecc_aem_command_read_descriptor_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_read_descriptor_write
     *
     *  write a avdecc_aem_command_read_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_read_descriptor_write (
        const avdecc_aem_command_read_descriptor_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_read_descriptor_t
    */
    
    typedef struct avdecc_aem_response_read_descriptor_s
    {
        /* TODO */
    } avdecc_aem_response_read_descriptor_t;
    
    
    
    /** avdecc_response_read_descriptor_init
     *
     *  Initialize a avdecc_aem_response_read_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_read_descriptor_init ( avdecc_aem_response_read_descriptor_t *self );
    
    
    /** avdecc_response_read_descriptor_read
     *
     *  Read a avdecc_aem_response_read_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_read_descriptor_read (
        avdecc_aem_response_read_descriptor_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_read_descriptor_write
     *
     *  write a avdecc_aem_response_read_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_read_descriptor_write (
        const avdecc_aem_response_read_descriptor_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_write_descriptor_t
    */
    
    typedef struct avdecc_aem_command_write_descriptor_s
    {
        /* TODO */
    } avdecc_aem_command_write_descriptor_t;
    
    
    
    /** avdecc_command_write_descriptor_init
     *
     *  Initialize a avdecc_aem_command_write_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_write_descriptor_init ( avdecc_aem_command_write_descriptor_t *self );
    
    
    /** avdecc_command_write_descriptor_read
     *
     *  Read a avdecc_aem_command_write_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_write_descriptor_read (
        avdecc_aem_command_write_descriptor_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_write_descriptor_write
     *
     *  write a avdecc_aem_command_write_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_write_descriptor_write (
        const avdecc_aem_command_write_descriptor_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_write_descriptor_t
    */
    
    typedef struct avdecc_aem_response_write_descriptor_s
    {
        /* TODO */
    } avdecc_aem_response_write_descriptor_t;
    
    
    
    /** avdecc_response_write_descriptor_init
     *
     *  Initialize a avdecc_aem_response_write_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_write_descriptor_init ( avdecc_aem_response_write_descriptor_t *self );
    
    
    /** avdecc_response_write_descriptor_read
     *
     *  Read a avdecc_aem_response_write_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_write_descriptor_read (
        avdecc_aem_response_write_descriptor_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_write_descriptor_write
     *
     *  write a avdecc_aem_response_write_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_write_descriptor_write (
        const avdecc_aem_response_write_descriptor_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_acquire_entity_t
    */
    
    typedef struct avdecc_aem_command_acquire_entity_s
    {
        /* TODO */
    } avdecc_aem_command_acquire_entity_t;
    
    
    
    /** avdecc_command_acquire_entity_init
     *
     *  Initialize a avdecc_aem_command_acquire_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_acquire_entity_init ( avdecc_aem_command_acquire_entity_t *self );
    
    
    /** avdecc_command_acquire_entity_read
     *
     *  Read a avdecc_aem_command_acquire_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_acquire_entity_read (
        avdecc_aem_command_acquire_entity_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_acquire_entity_write
     *
     *  write a avdecc_aem_command_acquire_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_acquire_entity_write (
        const avdecc_aem_command_acquire_entity_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_acquire_entity_t
    */
    
    typedef struct avdecc_aem_response_acquire_entity_s
    {
        /* TODO */
    } avdecc_aem_response_acquire_entity_t;
    
    
    
    /** avdecc_response_acquire_entity_init
     *
     *  Initialize a avdecc_aem_response_acquire_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_acquire_entity_init ( avdecc_aem_response_acquire_entity_t *self );
    
    
    /** avdecc_response_acquire_entity_read
     *
     *  Read a avdecc_aem_response_acquire_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_acquire_entity_read (
        avdecc_aem_response_acquire_entity_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_acquire_entity_write
     *
     *  write a avdecc_aem_response_acquire_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_acquire_entity_write (
        const avdecc_aem_response_acquire_entity_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_controller_available_t
    */
    
    typedef struct avdecc_aem_command_controller_available_s
    {
        /* TODO */
    } avdecc_aem_command_controller_available_t;
    
    
    
    /** avdecc_command_controller_available_init
     *
     *  Initialize a avdecc_aem_command_controller_available_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_controller_available_init ( avdecc_aem_command_controller_available_t *self );
    
    
    /** avdecc_command_controller_available_read
     *
     *  Read a avdecc_aem_command_controller_available_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_controller_available_read (
        avdecc_aem_command_controller_available_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_controller_available_write
     *
     *  write a avdecc_aem_command_controller_available_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_controller_available_write (
        const avdecc_aem_command_controller_available_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_controller_available_t
    */
    
    typedef struct avdecc_aem_response_controller_available_s
    {
        /* TODO */
    } avdecc_aem_response_controller_available_t;
    
    
    
    /** avdecc_response_controller_available_init
     *
     *  Initialize a avdecc_aem_response_controller_available_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_controller_available_init ( avdecc_aem_response_controller_available_t *self );
    
    
    /** avdecc_response_controller_available_read
     *
     *  Read a avdecc_aem_response_controller_available_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_controller_available_read (
        avdecc_aem_response_controller_available_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_controller_available_write
     *
     *  write a avdecc_aem_response_controller_available_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_controller_available_write (
        const avdecc_aem_response_controller_available_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_clock_source_t
    */
    
    typedef struct avdecc_aem_command_set_clock_source_s
    {
        /* TODO */
    } avdecc_aem_command_set_clock_source_t;
    
    
    
    /** avdecc_command_set_clock_source_init
     *
     *  Initialize a avdecc_aem_command_set_clock_source_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_clock_source_init ( avdecc_aem_command_set_clock_source_t *self );
    
    
    /** avdecc_command_set_clock_source_read
     *
     *  Read a avdecc_aem_command_set_clock_source_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_clock_source_read (
        avdecc_aem_command_set_clock_source_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_clock_source_write
     *
     *  write a avdecc_aem_command_set_clock_source_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_clock_source_write (
        const avdecc_aem_command_set_clock_source_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_clock_source_t
    */
    
    typedef struct avdecc_aem_response_set_clock_source_s
    {
        /* TODO */
    } avdecc_aem_response_set_clock_source_t;
    
    
    
    /** avdecc_response_set_clock_source_init
     *
     *  Initialize a avdecc_aem_response_set_clock_source_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_clock_source_init ( avdecc_aem_response_set_clock_source_t *self );
    
    
    /** avdecc_response_set_clock_source_read
     *
     *  Read a avdecc_aem_response_set_clock_source_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_clock_source_read (
        avdecc_aem_response_set_clock_source_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_clock_source_write
     *
     *  write a avdecc_aem_response_set_clock_source_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_clock_source_write (
        const avdecc_aem_response_set_clock_source_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_clock_source_t
    */
    
    typedef struct avdecc_aem_command_get_clock_source_s
    {
        /* TODO */
    } avdecc_aem_command_get_clock_source_t;
    
    
    
    /** avdecc_command_get_clock_source_init
     *
     *  Initialize a avdecc_aem_command_get_clock_source_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_clock_source_init ( avdecc_aem_command_get_clock_source_t *self );
    
    
    /** avdecc_command_get_clock_source_read
     *
     *  Read a avdecc_aem_command_get_clock_source_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_clock_source_read (
        avdecc_aem_command_get_clock_source_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_clock_source_write
     *
     *  write a avdecc_aem_command_get_clock_source_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_clock_source_write (
        const avdecc_aem_command_get_clock_source_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_clock_source_t
    */
    
    typedef struct avdecc_aem_response_get_clock_source_s
    {
        /* TODO */
    } avdecc_aem_response_get_clock_source_t;
    
    
    
    /** avdecc_response_get_clock_source_init
     *
     *  Initialize a avdecc_aem_response_get_clock_source_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_clock_source_init ( avdecc_aem_response_get_clock_source_t *self );
    
    
    /** avdecc_response_get_clock_source_read
     *
     *  Read a avdecc_aem_response_get_clock_source_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_clock_source_read (
        avdecc_aem_response_get_clock_source_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_clock_source_write
     *
     *  write a avdecc_aem_response_get_clock_source_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_clock_source_write (
        const avdecc_aem_response_get_clock_source_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_stream_format_t
    */
    
    typedef struct avdecc_aem_command_set_stream_format_s
    {
        /* TODO */
    } avdecc_aem_command_set_stream_format_t;
    
    
    
    /** avdecc_command_set_stream_format_init
     *
     *  Initialize a avdecc_aem_command_set_stream_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_stream_format_init ( avdecc_aem_command_set_stream_format_t *self );
    
    
    /** avdecc_command_set_stream_format_read
     *
     *  Read a avdecc_aem_command_set_stream_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_stream_format_read (
        avdecc_aem_command_set_stream_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_stream_format_write
     *
     *  write a avdecc_aem_command_set_stream_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_stream_format_write (
        const avdecc_aem_command_set_stream_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_stream_format_t
    */
    
    typedef struct avdecc_aem_response_set_stream_format_s
    {
        /* TODO */
    } avdecc_aem_response_set_stream_format_t;
    
    
    
    /** avdecc_response_set_stream_format_init
     *
     *  Initialize a avdecc_aem_response_set_stream_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_stream_format_init ( avdecc_aem_response_set_stream_format_t *self );
    
    
    /** avdecc_response_set_stream_format_read
     *
     *  Read a avdecc_aem_response_set_stream_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_stream_format_read (
        avdecc_aem_response_set_stream_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_stream_format_write
     *
     *  write a avdecc_aem_response_set_stream_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_stream_format_write (
        const avdecc_aem_response_set_stream_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_stream_format_t
    */
    
    typedef struct avdecc_aem_command_get_stream_format_s
    {
        /* TODO */
    } avdecc_aem_command_get_stream_format_t;
    
    
    
    /** avdecc_command_get_stream_format_init
     *
     *  Initialize a avdecc_aem_command_get_stream_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_stream_format_init ( avdecc_aem_command_get_stream_format_t *self );
    
    
    /** avdecc_command_get_stream_format_read
     *
     *  Read a avdecc_aem_command_get_stream_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_stream_format_read (
        avdecc_aem_command_get_stream_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_stream_format_write
     *
     *  write a avdecc_aem_command_get_stream_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_stream_format_write (
        const avdecc_aem_command_get_stream_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_stream_format_t
    */
    
    typedef struct avdecc_aem_response_get_stream_format_s
    {
        /* TODO */
    } avdecc_aem_response_get_stream_format_t;
    
    
    
    /** avdecc_response_get_stream_format_init
     *
     *  Initialize a avdecc_aem_response_get_stream_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_stream_format_init ( avdecc_aem_response_get_stream_format_t *self );
    
    
    /** avdecc_response_get_stream_format_read
     *
     *  Read a avdecc_aem_response_get_stream_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_stream_format_read (
        avdecc_aem_response_get_stream_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_stream_format_write
     *
     *  write a avdecc_aem_response_get_stream_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_stream_format_write (
        const avdecc_aem_response_get_stream_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_configuration_t
    */
    
    typedef struct avdecc_aem_command_set_configuration_s
    {
        /* TODO */
    } avdecc_aem_command_set_configuration_t;
    
    
    
    /** avdecc_command_set_configuration_init
     *
     *  Initialize a avdecc_aem_command_set_configuration_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_configuration_init ( avdecc_aem_command_set_configuration_t *self );
    
    
    /** avdecc_command_set_configuration_read
     *
     *  Read a avdecc_aem_command_set_configuration_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_configuration_read (
        avdecc_aem_command_set_configuration_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_configuration_write
     *
     *  write a avdecc_aem_command_set_configuration_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_configuration_write (
        const avdecc_aem_command_set_configuration_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_configuration_t
    */
    
    typedef struct avdecc_aem_response_set_configuration_s
    {
        /* TODO */
    } avdecc_aem_response_set_configuration_t;
    
    
    
    /** avdecc_response_set_configuration_init
     *
     *  Initialize a avdecc_aem_response_set_configuration_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_configuration_init ( avdecc_aem_response_set_configuration_t *self );
    
    
    /** avdecc_response_set_configuration_read
     *
     *  Read a avdecc_aem_response_set_configuration_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_configuration_read (
        avdecc_aem_response_set_configuration_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_configuration_write
     *
     *  write a avdecc_aem_response_set_configuration_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_configuration_write (
        const avdecc_aem_response_set_configuration_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_configuration_t
    */
    
    typedef struct avdecc_aem_command_get_configuration_s
    {
        /* TODO */
    } avdecc_aem_command_get_configuration_t;
    
    
    
    /** avdecc_command_get_configuration_init
     *
     *  Initialize a avdecc_aem_command_get_configuration_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_configuration_init ( avdecc_aem_command_get_configuration_t *self );
    
    
    /** avdecc_command_get_configuration_read
     *
     *  Read a avdecc_aem_command_get_configuration_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_configuration_read (
        avdecc_aem_command_get_configuration_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_configuration_write
     *
     *  write a avdecc_aem_command_get_configuration_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_configuration_write (
        const avdecc_aem_command_get_configuration_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_configuration_t
    */
    
    typedef struct avdecc_aem_response_get_configuration_s
    {
        /* TODO */
    } avdecc_aem_response_get_configuration_t;
    
    
    
    /** avdecc_response_get_configuration_init
     *
     *  Initialize a avdecc_aem_response_get_configuration_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_configuration_init ( avdecc_aem_response_get_configuration_t *self );
    
    
    /** avdecc_response_get_configuration_read
     *
     *  Read a avdecc_aem_response_get_configuration_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_configuration_read (
        avdecc_aem_response_get_configuration_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_configuration_write
     *
     *  write a avdecc_aem_response_get_configuration_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_configuration_write (
        const avdecc_aem_response_get_configuration_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_control_value_t
    */
    
    typedef struct avdecc_aem_command_set_control_value_s
    {
        /* TODO */
    } avdecc_aem_command_set_control_value_t;
    
    
    
    /** avdecc_command_set_control_value_init
     *
     *  Initialize a avdecc_aem_command_set_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_control_value_init ( avdecc_aem_command_set_control_value_t *self );
    
    
    /** avdecc_command_set_control_value_read
     *
     *  Read a avdecc_aem_command_set_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_control_value_read (
        avdecc_aem_command_set_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_control_value_write
     *
     *  write a avdecc_aem_command_set_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_control_value_write (
        const avdecc_aem_command_set_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_control_value_t
    */
    
    typedef struct avdecc_aem_response_set_control_value_s
    {
        /* TODO */
    } avdecc_aem_response_set_control_value_t;
    
    
    
    /** avdecc_response_set_control_value_init
     *
     *  Initialize a avdecc_aem_response_set_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_control_value_init ( avdecc_aem_response_set_control_value_t *self );
    
    
    /** avdecc_response_set_control_value_read
     *
     *  Read a avdecc_aem_response_set_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_control_value_read (
        avdecc_aem_response_set_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_control_value_write
     *
     *  write a avdecc_aem_response_set_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_control_value_write (
        const avdecc_aem_response_set_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_control_value_t
    */
    
    typedef struct avdecc_aem_command_get_control_value_s
    {
        /* TODO */
    } avdecc_aem_command_get_control_value_t;
    
    
    
    /** avdecc_command_get_control_value_init
     *
     *  Initialize a avdecc_aem_command_get_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_control_value_init ( avdecc_aem_command_get_control_value_t *self );
    
    
    /** avdecc_command_get_control_value_read
     *
     *  Read a avdecc_aem_command_get_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_control_value_read (
        avdecc_aem_command_get_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_control_value_write
     *
     *  write a avdecc_aem_command_get_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_control_value_write (
        const avdecc_aem_command_get_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_control_value_t
    */
    
    typedef struct avdecc_aem_response_get_control_value_s
    {
        /* TODO */
    } avdecc_aem_response_get_control_value_t;
    
    
    
    /** avdecc_response_get_control_value_init
     *
     *  Initialize a avdecc_aem_response_get_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_control_value_init ( avdecc_aem_response_get_control_value_t *self );
    
    
    /** avdecc_response_get_control_value_read
     *
     *  Read a avdecc_aem_response_get_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_control_value_read (
        avdecc_aem_response_get_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_control_value_write
     *
     *  write a avdecc_aem_response_get_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_control_value_write (
        const avdecc_aem_response_get_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_signal_selector_t
    */
    
    typedef struct avdecc_aem_command_set_signal_selector_s
    {
        /* TODO */
    } avdecc_aem_command_set_signal_selector_t;
    
    
    
    /** avdecc_command_set_signal_selector_init
     *
     *  Initialize a avdecc_aem_command_set_signal_selector_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_signal_selector_init ( avdecc_aem_command_set_signal_selector_t *self );
    
    
    /** avdecc_command_set_signal_selector_read
     *
     *  Read a avdecc_aem_command_set_signal_selector_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_signal_selector_read (
        avdecc_aem_command_set_signal_selector_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_signal_selector_write
     *
     *  write a avdecc_aem_command_set_signal_selector_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_signal_selector_write (
        const avdecc_aem_command_set_signal_selector_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_signal_selector_t
    */
    
    typedef struct avdecc_aem_response_set_signal_selector_s
    {
        /* TODO */
    } avdecc_aem_response_set_signal_selector_t;
    
    
    
    /** avdecc_response_set_signal_selector_init
     *
     *  Initialize a avdecc_aem_response_set_signal_selector_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_signal_selector_init ( avdecc_aem_response_set_signal_selector_t *self );
    
    
    /** avdecc_response_set_signal_selector_read
     *
     *  Read a avdecc_aem_response_set_signal_selector_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_signal_selector_read (
        avdecc_aem_response_set_signal_selector_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_signal_selector_write
     *
     *  write a avdecc_aem_response_set_signal_selector_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_signal_selector_write (
        const avdecc_aem_response_set_signal_selector_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_signal_selector_t
    */
    
    typedef struct avdecc_aem_command_get_signal_selector_s
    {
        /* TODO */
    } avdecc_aem_command_get_signal_selector_t;
    
    
    
    /** avdecc_command_get_signal_selector_init
     *
     *  Initialize a avdecc_aem_command_get_signal_selector_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_signal_selector_init ( avdecc_aem_command_get_signal_selector_t *self );
    
    
    /** avdecc_command_get_signal_selector_read
     *
     *  Read a avdecc_aem_command_get_signal_selector_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_signal_selector_read (
        avdecc_aem_command_get_signal_selector_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_signal_selector_write
     *
     *  write a avdecc_aem_command_get_signal_selector_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_signal_selector_write (
        const avdecc_aem_command_get_signal_selector_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_signal_selector_t
    */
    
    typedef struct avdecc_aem_response_get_signal_selector_s
    {
        /* TODO */
    } avdecc_aem_response_get_signal_selector_t;
    
    
    
    /** avdecc_response_get_signal_selector_init
     *
     *  Initialize a avdecc_aem_response_get_signal_selector_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_signal_selector_init ( avdecc_aem_response_get_signal_selector_t *self );
    
    
    /** avdecc_response_get_signal_selector_read
     *
     *  Read a avdecc_aem_response_get_signal_selector_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_signal_selector_read (
        avdecc_aem_response_get_signal_selector_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_signal_selector_write
     *
     *  write a avdecc_aem_response_get_signal_selector_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_signal_selector_write (
        const avdecc_aem_response_get_signal_selector_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_mixer_t
    */
    
    typedef struct avdecc_aem_command_set_mixer_s
    {
        /* TODO */
    } avdecc_aem_command_set_mixer_t;
    
    
    
    /** avdecc_command_set_mixer_init
     *
     *  Initialize a avdecc_aem_command_set_mixer_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_mixer_init ( avdecc_aem_command_set_mixer_t *self );
    
    
    /** avdecc_command_set_mixer_read
     *
     *  Read a avdecc_aem_command_set_mixer_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_mixer_read (
        avdecc_aem_command_set_mixer_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_mixer_write
     *
     *  write a avdecc_aem_command_set_mixer_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_mixer_write (
        const avdecc_aem_command_set_mixer_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_mixer_t
    */
    
    typedef struct avdecc_aem_response_set_mixer_s
    {
        /* TODO */
    } avdecc_aem_response_set_mixer_t;
    
    
    
    /** avdecc_response_set_mixer_init
     *
     *  Initialize a avdecc_aem_response_set_mixer_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_mixer_init ( avdecc_aem_response_set_mixer_t *self );
    
    
    /** avdecc_response_set_mixer_read
     *
     *  Read a avdecc_aem_response_set_mixer_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_mixer_read (
        avdecc_aem_response_set_mixer_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_mixer_write
     *
     *  write a avdecc_aem_response_set_mixer_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_mixer_write (
        const avdecc_aem_response_set_mixer_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_mixer_t
    */
    
    typedef struct avdecc_aem_command_get_mixer_s
    {
        /* TODO */
    } avdecc_aem_command_get_mixer_t;
    
    
    
    /** avdecc_command_get_mixer_init
     *
     *  Initialize a avdecc_aem_command_get_mixer_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_mixer_init ( avdecc_aem_command_get_mixer_t *self );
    
    
    /** avdecc_command_get_mixer_read
     *
     *  Read a avdecc_aem_command_get_mixer_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_mixer_read (
        avdecc_aem_command_get_mixer_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_mixer_write
     *
     *  write a avdecc_aem_command_get_mixer_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_mixer_write (
        const avdecc_aem_command_get_mixer_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_mixer_t
    */
    
    typedef struct avdecc_aem_response_get_mixer_s
    {
        /* TODO */
    } avdecc_aem_response_get_mixer_t;
    
    
    
    /** avdecc_response_get_mixer_init
     *
     *  Initialize a avdecc_aem_response_get_mixer_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_mixer_init ( avdecc_aem_response_get_mixer_t *self );
    
    
    /** avdecc_response_get_mixer_read
     *
     *  Read a avdecc_aem_response_get_mixer_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_mixer_read (
        avdecc_aem_response_get_mixer_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_mixer_write
     *
     *  write a avdecc_aem_response_get_mixer_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_mixer_write (
        const avdecc_aem_response_get_mixer_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_matrix_t
    */
    
    typedef struct avdecc_aem_command_set_matrix_s
    {
        /* TODO */
    } avdecc_aem_command_set_matrix_t;
    
    
    
    /** avdecc_command_set_matrix_init
     *
     *  Initialize a avdecc_aem_command_set_matrix_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_matrix_init ( avdecc_aem_command_set_matrix_t *self );
    
    
    /** avdecc_command_set_matrix_read
     *
     *  Read a avdecc_aem_command_set_matrix_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_matrix_read (
        avdecc_aem_command_set_matrix_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_matrix_write
     *
     *  write a avdecc_aem_command_set_matrix_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_matrix_write (
        const avdecc_aem_command_set_matrix_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_matrix_t
    */
    
    typedef struct avdecc_aem_response_set_matrix_s
    {
        /* TODO */
    } avdecc_aem_response_set_matrix_t;
    
    
    
    /** avdecc_response_set_matrix_init
     *
     *  Initialize a avdecc_aem_response_set_matrix_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_matrix_init ( avdecc_aem_response_set_matrix_t *self );
    
    
    /** avdecc_response_set_matrix_read
     *
     *  Read a avdecc_aem_response_set_matrix_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_matrix_read (
        avdecc_aem_response_set_matrix_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_matrix_write
     *
     *  write a avdecc_aem_response_set_matrix_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_matrix_write (
        const avdecc_aem_response_set_matrix_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_matrix_t
    */
    
    typedef struct avdecc_aem_command_get_matrix_s
    {
        /* TODO */
    } avdecc_aem_command_get_matrix_t;
    
    
    
    /** avdecc_command_get_matrix_init
     *
     *  Initialize a avdecc_aem_command_get_matrix_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_matrix_init ( avdecc_aem_command_get_matrix_t *self );
    
    
    /** avdecc_command_get_matrix_read
     *
     *  Read a avdecc_aem_command_get_matrix_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_matrix_read (
        avdecc_aem_command_get_matrix_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_matrix_write
     *
     *  write a avdecc_aem_command_get_matrix_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_matrix_write (
        const avdecc_aem_command_get_matrix_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_matrix_t
    */
    
    typedef struct avdecc_aem_response_get_matrix_s
    {
        /* TODO */
    } avdecc_aem_response_get_matrix_t;
    
    
    
    /** avdecc_response_get_matrix_init
     *
     *  Initialize a avdecc_aem_response_get_matrix_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_matrix_init ( avdecc_aem_response_get_matrix_t *self );
    
    
    /** avdecc_response_get_matrix_read
     *
     *  Read a avdecc_aem_response_get_matrix_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_matrix_read (
        avdecc_aem_response_get_matrix_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_matrix_write
     *
     *  write a avdecc_aem_response_get_matrix_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_matrix_write (
        const avdecc_aem_response_get_matrix_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_start_streaming_t
    */
    
    typedef struct avdecc_aem_command_start_streaming_s
    {
        /* TODO */
    } avdecc_aem_command_start_streaming_t;
    
    
    
    /** avdecc_command_start_streaming_init
     *
     *  Initialize a avdecc_aem_command_start_streaming_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_start_streaming_init ( avdecc_aem_command_start_streaming_t *self );
    
    
    /** avdecc_command_start_streaming_read
     *
     *  Read a avdecc_aem_command_start_streaming_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_start_streaming_read (
        avdecc_aem_command_start_streaming_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_start_streaming_write
     *
     *  write a avdecc_aem_command_start_streaming_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_start_streaming_write (
        const avdecc_aem_command_start_streaming_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_start_streaming_t
    */
    
    typedef struct avdecc_aem_response_start_streaming_s
    {
        /* TODO */
    } avdecc_aem_response_start_streaming_t;
    
    
    
    /** avdecc_response_start_streaming_init
     *
     *  Initialize a avdecc_aem_response_start_streaming_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_start_streaming_init ( avdecc_aem_response_start_streaming_t *self );
    
    
    /** avdecc_response_start_streaming_read
     *
     *  Read a avdecc_aem_response_start_streaming_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_start_streaming_read (
        avdecc_aem_response_start_streaming_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_start_streaming_write
     *
     *  write a avdecc_aem_response_start_streaming_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_start_streaming_write (
        const avdecc_aem_response_start_streaming_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_stop_streaming_t
    */
    
    typedef struct avdecc_aem_command_stop_streaming_s
    {
        /* TODO */
    } avdecc_aem_command_stop_streaming_t;
    
    
    
    /** avdecc_command_stop_streaming_init
     *
     *  Initialize a avdecc_aem_command_stop_streaming_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_stop_streaming_init ( avdecc_aem_command_stop_streaming_t *self );
    
    
    /** avdecc_command_stop_streaming_read
     *
     *  Read a avdecc_aem_command_stop_streaming_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_stop_streaming_read (
        avdecc_aem_command_stop_streaming_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_stop_streaming_write
     *
     *  write a avdecc_aem_command_stop_streaming_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_stop_streaming_write (
        const avdecc_aem_command_stop_streaming_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_stop_streaming_t
    */
    
    typedef struct avdecc_aem_response_stop_streaming_s
    {
        /* TODO */
    } avdecc_aem_response_stop_streaming_t;
    
    
    
    /** avdecc_response_stop_streaming_init
     *
     *  Initialize a avdecc_aem_response_stop_streaming_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_stop_streaming_init ( avdecc_aem_response_stop_streaming_t *self );
    
    
    /** avdecc_response_stop_streaming_read
     *
     *  Read a avdecc_aem_response_stop_streaming_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_stop_streaming_read (
        avdecc_aem_response_stop_streaming_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_stop_streaming_write
     *
     *  write a avdecc_aem_response_stop_streaming_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_stop_streaming_write (
        const avdecc_aem_response_stop_streaming_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_stream_info_t
    */
    
    typedef struct avdecc_aem_command_set_stream_info_s
    {
        /* TODO */
    } avdecc_aem_command_set_stream_info_t;
    
    
    
    /** avdecc_command_set_stream_info_init
     *
     *  Initialize a avdecc_aem_command_set_stream_info_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_stream_info_init ( avdecc_aem_command_set_stream_info_t *self );
    
    
    /** avdecc_command_set_stream_info_read
     *
     *  Read a avdecc_aem_command_set_stream_info_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_stream_info_read (
        avdecc_aem_command_set_stream_info_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_stream_info_write
     *
     *  write a avdecc_aem_command_set_stream_info_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_stream_info_write (
        const avdecc_aem_command_set_stream_info_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_stream_info_t
    */
    
    typedef struct avdecc_aem_response_set_stream_info_s
    {
        /* TODO */
    } avdecc_aem_response_set_stream_info_t;
    
    
    
    /** avdecc_response_set_stream_info_init
     *
     *  Initialize a avdecc_aem_response_set_stream_info_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_stream_info_init ( avdecc_aem_response_set_stream_info_t *self );
    
    
    /** avdecc_response_set_stream_info_read
     *
     *  Read a avdecc_aem_response_set_stream_info_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_stream_info_read (
        avdecc_aem_response_set_stream_info_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_stream_info_write
     *
     *  write a avdecc_aem_response_set_stream_info_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_stream_info_write (
        const avdecc_aem_response_set_stream_info_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_stream_info_t
    */
    
    typedef struct avdecc_aem_command_get_stream_info_s
    {
        /* TODO */
    } avdecc_aem_command_get_stream_info_t;
    
    
    
    /** avdecc_command_get_stream_info_init
     *
     *  Initialize a avdecc_aem_command_get_stream_info_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_stream_info_init ( avdecc_aem_command_get_stream_info_t *self );
    
    
    /** avdecc_command_get_stream_info_read
     *
     *  Read a avdecc_aem_command_get_stream_info_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_stream_info_read (
        avdecc_aem_command_get_stream_info_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_stream_info_write
     *
     *  write a avdecc_aem_command_get_stream_info_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_stream_info_write (
        const avdecc_aem_command_get_stream_info_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_stream_info_t
    */
    
    typedef struct avdecc_aem_response_get_stream_info_s
    {
        /* TODO */
    } avdecc_aem_response_get_stream_info_t;
    
    
    
    /** avdecc_response_get_stream_info_init
     *
     *  Initialize a avdecc_aem_response_get_stream_info_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_stream_info_init ( avdecc_aem_response_get_stream_info_t *self );
    
    
    /** avdecc_response_get_stream_info_read
     *
     *  Read a avdecc_aem_response_get_stream_info_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_stream_info_read (
        avdecc_aem_response_get_stream_info_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_stream_info_write
     *
     *  write a avdecc_aem_response_get_stream_info_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_stream_info_write (
        const avdecc_aem_response_get_stream_info_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_name_t
    */
    
    typedef struct avdecc_aem_command_set_name_s
    {
        /* TODO */
    } avdecc_aem_command_set_name_t;
    
    
    
    /** avdecc_command_set_name_init
     *
     *  Initialize a avdecc_aem_command_set_name_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_name_init ( avdecc_aem_command_set_name_t *self );
    
    
    /** avdecc_command_set_name_read
     *
     *  Read a avdecc_aem_command_set_name_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_name_read (
        avdecc_aem_command_set_name_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_name_write
     *
     *  write a avdecc_aem_command_set_name_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_name_write (
        const avdecc_aem_command_set_name_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_name_t
    */
    
    typedef struct avdecc_aem_response_set_name_s
    {
        /* TODO */
    } avdecc_aem_response_set_name_t;
    
    
    
    /** avdecc_response_set_name_init
     *
     *  Initialize a avdecc_aem_response_set_name_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_name_init ( avdecc_aem_response_set_name_t *self );
    
    
    /** avdecc_response_set_name_read
     *
     *  Read a avdecc_aem_response_set_name_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_name_read (
        avdecc_aem_response_set_name_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_name_write
     *
     *  write a avdecc_aem_response_set_name_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_name_write (
        const avdecc_aem_response_set_name_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_name_t
    */
    
    typedef struct avdecc_aem_command_get_name_s
    {
        /* TODO */
    } avdecc_aem_command_get_name_t;
    
    
    
    /** avdecc_command_get_name_init
     *
     *  Initialize a avdecc_aem_command_get_name_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_name_init ( avdecc_aem_command_get_name_t *self );
    
    
    /** avdecc_command_get_name_read
     *
     *  Read a avdecc_aem_command_get_name_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_name_read (
        avdecc_aem_command_get_name_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_name_write
     *
     *  write a avdecc_aem_command_get_name_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_name_write (
        const avdecc_aem_command_get_name_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_name_t
    */
    
    typedef struct avdecc_aem_response_get_name_s
    {
        /* TODO */
    } avdecc_aem_response_get_name_t;
    
    
    
    /** avdecc_response_get_name_init
     *
     *  Initialize a avdecc_aem_response_get_name_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_name_init ( avdecc_aem_response_get_name_t *self );
    
    
    /** avdecc_response_get_name_read
     *
     *  Read a avdecc_aem_response_get_name_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_name_read (
        avdecc_aem_response_get_name_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_name_write
     *
     *  write a avdecc_aem_response_get_name_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_name_write (
        const avdecc_aem_response_get_name_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_association_id_t
    */
    
    typedef struct avdecc_aem_command_set_association_id_s
    {
        /* TODO */
    } avdecc_aem_command_set_association_id_t;
    
    
    
    /** avdecc_command_set_association_id_init
     *
     *  Initialize a avdecc_aem_command_set_association_id_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_association_id_init ( avdecc_aem_command_set_association_id_t *self );
    
    
    /** avdecc_command_set_association_id_read
     *
     *  Read a avdecc_aem_command_set_association_id_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_association_id_read (
        avdecc_aem_command_set_association_id_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_association_id_write
     *
     *  write a avdecc_aem_command_set_association_id_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_association_id_write (
        const avdecc_aem_command_set_association_id_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_association_id_t
    */
    
    typedef struct avdecc_aem_response_set_association_id_s
    {
        /* TODO */
    } avdecc_aem_response_set_association_id_t;
    
    
    
    /** avdecc_response_set_association_id_init
     *
     *  Initialize a avdecc_aem_response_set_association_id_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_association_id_init ( avdecc_aem_response_set_association_id_t *self );
    
    
    /** avdecc_response_set_association_id_read
     *
     *  Read a avdecc_aem_response_set_association_id_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_association_id_read (
        avdecc_aem_response_set_association_id_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_association_id_write
     *
     *  write a avdecc_aem_response_set_association_id_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_association_id_write (
        const avdecc_aem_response_set_association_id_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_association_id_t
    */
    
    typedef struct avdecc_aem_command_get_association_id_s
    {
        /* TODO */
    } avdecc_aem_command_get_association_id_t;
    
    
    
    /** avdecc_command_get_association_id_init
     *
     *  Initialize a avdecc_aem_command_get_association_id_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_association_id_init ( avdecc_aem_command_get_association_id_t *self );
    
    
    /** avdecc_command_get_association_id_read
     *
     *  Read a avdecc_aem_command_get_association_id_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_association_id_read (
        avdecc_aem_command_get_association_id_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_association_id_write
     *
     *  write a avdecc_aem_command_get_association_id_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_association_id_write (
        const avdecc_aem_command_get_association_id_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_association_id_t
    */
    
    typedef struct avdecc_aem_response_get_association_id_s
    {
        /* TODO */
    } avdecc_aem_response_get_association_id_t;
    
    
    
    /** avdecc_response_get_association_id_init
     *
     *  Initialize a avdecc_aem_response_get_association_id_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_association_id_init ( avdecc_aem_response_get_association_id_t *self );
    
    
    /** avdecc_response_get_association_id_read
     *
     *  Read a avdecc_aem_response_get_association_id_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_association_id_read (
        avdecc_aem_response_get_association_id_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_association_id_write
     *
     *  write a avdecc_aem_response_get_association_id_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_association_id_write (
        const avdecc_aem_response_get_association_id_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_auth_add_key_t
    */
    
    typedef struct avdecc_aem_command_auth_add_key_s
    {
        /* TODO */
    } avdecc_aem_command_auth_add_key_t;
    
    
    
    /** avdecc_command_auth_add_key_init
     *
     *  Initialize a avdecc_aem_command_auth_add_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_auth_add_key_init ( avdecc_aem_command_auth_add_key_t *self );
    
    
    /** avdecc_command_auth_add_key_read
     *
     *  Read a avdecc_aem_command_auth_add_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_auth_add_key_read (
        avdecc_aem_command_auth_add_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_auth_add_key_write
     *
     *  write a avdecc_aem_command_auth_add_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_auth_add_key_write (
        const avdecc_aem_command_auth_add_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_auth_add_key_t
    */
    
    typedef struct avdecc_aem_response_auth_add_key_s
    {
        /* TODO */
    } avdecc_aem_response_auth_add_key_t;
    
    
    
    /** avdecc_response_auth_add_key_init
     *
     *  Initialize a avdecc_aem_response_auth_add_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_auth_add_key_init ( avdecc_aem_response_auth_add_key_t *self );
    
    
    /** avdecc_response_auth_add_key_read
     *
     *  Read a avdecc_aem_response_auth_add_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_auth_add_key_read (
        avdecc_aem_response_auth_add_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_auth_add_key_write
     *
     *  write a avdecc_aem_response_auth_add_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_auth_add_key_write (
        const avdecc_aem_response_auth_add_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_auth_get_key_t
    */
    
    typedef struct avdecc_aem_command_auth_get_key_s
    {
        /* TODO */
    } avdecc_aem_command_auth_get_key_t;
    
    
    
    /** avdecc_command_auth_get_key_init
     *
     *  Initialize a avdecc_aem_command_auth_get_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_auth_get_key_init ( avdecc_aem_command_auth_get_key_t *self );
    
    
    /** avdecc_command_auth_get_key_read
     *
     *  Read a avdecc_aem_command_auth_get_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_auth_get_key_read (
        avdecc_aem_command_auth_get_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_auth_get_key_write
     *
     *  write a avdecc_aem_command_auth_get_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_auth_get_key_write (
        const avdecc_aem_command_auth_get_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_auth_get_key_t
    */
    
    typedef struct avdecc_aem_response_auth_get_key_s
    {
        /* TODO */
    } avdecc_aem_response_auth_get_key_t;
    
    
    
    /** avdecc_response_auth_get_key_init
     *
     *  Initialize a avdecc_aem_response_auth_get_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_auth_get_key_init ( avdecc_aem_response_auth_get_key_t *self );
    
    
    /** avdecc_response_auth_get_key_read
     *
     *  Read a avdecc_aem_response_auth_get_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_auth_get_key_read (
        avdecc_aem_response_auth_get_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_auth_get_key_write
     *
     *  write a avdecc_aem_response_auth_get_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_auth_get_key_write (
        const avdecc_aem_response_auth_get_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_authenticate_t
    */
    
    typedef struct avdecc_aem_command_authenticate_s
    {
        /* TODO */
    } avdecc_aem_command_authenticate_t;
    
    
    
    /** avdecc_command_authenticate_init
     *
     *  Initialize a avdecc_aem_command_authenticate_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_authenticate_init ( avdecc_aem_command_authenticate_t *self );
    
    
    /** avdecc_command_authenticate_read
     *
     *  Read a avdecc_aem_command_authenticate_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_authenticate_read (
        avdecc_aem_command_authenticate_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_authenticate_write
     *
     *  write a avdecc_aem_command_authenticate_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_authenticate_write (
        const avdecc_aem_command_authenticate_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_authenticate_t
    */
    
    typedef struct avdecc_aem_response_authenticate_s
    {
        /* TODO */
    } avdecc_aem_response_authenticate_t;
    
    
    
    /** avdecc_response_authenticate_init
     *
     *  Initialize a avdecc_aem_response_authenticate_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_authenticate_init ( avdecc_aem_response_authenticate_t *self );
    
    
    /** avdecc_response_authenticate_read
     *
     *  Read a avdecc_aem_response_authenticate_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_authenticate_read (
        avdecc_aem_response_authenticate_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_authenticate_write
     *
     *  write a avdecc_aem_response_authenticate_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_authenticate_write (
        const avdecc_aem_response_authenticate_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_counters_t
    */
    
    typedef struct avdecc_aem_command_get_counters_s
    {
        /* TODO */
    } avdecc_aem_command_get_counters_t;
    
    
    
    /** avdecc_command_get_counters_init
     *
     *  Initialize a avdecc_aem_command_get_counters_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_counters_init ( avdecc_aem_command_get_counters_t *self );
    
    
    /** avdecc_command_get_counters_read
     *
     *  Read a avdecc_aem_command_get_counters_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_counters_read (
        avdecc_aem_command_get_counters_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_counters_write
     *
     *  write a avdecc_aem_command_get_counters_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_counters_write (
        const avdecc_aem_command_get_counters_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_counters_t
    */
    
    typedef struct avdecc_aem_response_get_counters_s
    {
        /* TODO */
    } avdecc_aem_response_get_counters_t;
    
    
    
    /** avdecc_response_get_counters_init
     *
     *  Initialize a avdecc_aem_response_get_counters_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_counters_init ( avdecc_aem_response_get_counters_t *self );
    
    
    /** avdecc_response_get_counters_read
     *
     *  Read a avdecc_aem_response_get_counters_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_counters_read (
        avdecc_aem_response_get_counters_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_counters_write
     *
     *  write a avdecc_aem_response_get_counters_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_counters_write (
        const avdecc_aem_response_get_counters_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_reboot_t
    */
    
    typedef struct avdecc_aem_command_reboot_s
    {
        /* TODO */
    } avdecc_aem_command_reboot_t;
    
    
    
    /** avdecc_command_reboot_init
     *
     *  Initialize a avdecc_aem_command_reboot_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_reboot_init ( avdecc_aem_command_reboot_t *self );
    
    
    /** avdecc_command_reboot_read
     *
     *  Read a avdecc_aem_command_reboot_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_reboot_read (
        avdecc_aem_command_reboot_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_reboot_write
     *
     *  write a avdecc_aem_command_reboot_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_reboot_write (
        const avdecc_aem_command_reboot_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_reboot_t
    */
    
    typedef struct avdecc_aem_response_reboot_s
    {
        /* TODO */
    } avdecc_aem_response_reboot_t;
    
    
    
    /** avdecc_response_reboot_init
     *
     *  Initialize a avdecc_aem_response_reboot_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_reboot_init ( avdecc_aem_response_reboot_t *self );
    
    
    /** avdecc_response_reboot_read
     *
     *  Read a avdecc_aem_response_reboot_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_reboot_read (
        avdecc_aem_response_reboot_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_reboot_write
     *
     *  write a avdecc_aem_response_reboot_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_reboot_write (
        const avdecc_aem_response_reboot_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_set_media_format_t
    */
    
    typedef struct avdecc_aem_command_set_media_format_s
    {
        /* TODO */
    } avdecc_aem_command_set_media_format_t;
    
    
    
    /** avdecc_command_set_media_format_init
     *
     *  Initialize a avdecc_aem_command_set_media_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_set_media_format_init ( avdecc_aem_command_set_media_format_t *self );
    
    
    /** avdecc_command_set_media_format_read
     *
     *  Read a avdecc_aem_command_set_media_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_set_media_format_read (
        avdecc_aem_command_set_media_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_set_media_format_write
     *
     *  write a avdecc_aem_command_set_media_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_set_media_format_write (
        const avdecc_aem_command_set_media_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_set_media_format_t
    */
    
    typedef struct avdecc_aem_response_set_media_format_s
    {
        /* TODO */
    } avdecc_aem_response_set_media_format_t;
    
    
    
    /** avdecc_response_set_media_format_init
     *
     *  Initialize a avdecc_aem_response_set_media_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_set_media_format_init ( avdecc_aem_response_set_media_format_t *self );
    
    
    /** avdecc_response_set_media_format_read
     *
     *  Read a avdecc_aem_response_set_media_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_set_media_format_read (
        avdecc_aem_response_set_media_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_set_media_format_write
     *
     *  write a avdecc_aem_response_set_media_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_set_media_format_write (
        const avdecc_aem_response_set_media_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_media_format_t
    */
    
    typedef struct avdecc_aem_command_get_media_format_s
    {
        /* TODO */
    } avdecc_aem_command_get_media_format_t;
    
    
    
    /** avdecc_command_get_media_format_init
     *
     *  Initialize a avdecc_aem_command_get_media_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_media_format_init ( avdecc_aem_command_get_media_format_t *self );
    
    
    /** avdecc_command_get_media_format_read
     *
     *  Read a avdecc_aem_command_get_media_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_media_format_read (
        avdecc_aem_command_get_media_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_media_format_write
     *
     *  write a avdecc_aem_command_get_media_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_media_format_write (
        const avdecc_aem_command_get_media_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_media_format_t
    */
    
    typedef struct avdecc_aem_response_get_media_format_s
    {
        /* TODO */
    } avdecc_aem_response_get_media_format_t;
    
    
    
    /** avdecc_response_get_media_format_init
     *
     *  Initialize a avdecc_aem_response_get_media_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_media_format_init ( avdecc_aem_response_get_media_format_t *self );
    
    
    /** avdecc_response_get_media_format_read
     *
     *  Read a avdecc_aem_response_get_media_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_media_format_read (
        avdecc_aem_response_get_media_format_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_media_format_write
     *
     *  write a avdecc_aem_response_get_media_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_media_format_write (
        const avdecc_aem_response_get_media_format_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_register_state_notification_t
    */
    
    typedef struct avdecc_aem_command_register_state_notification_s
    {
        /* TODO */
    } avdecc_aem_command_register_state_notification_t;
    
    
    
    /** avdecc_command_register_state_notification_init
     *
     *  Initialize a avdecc_aem_command_register_state_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_register_state_notification_init ( avdecc_aem_command_register_state_notification_t *self );
    
    
    /** avdecc_command_register_state_notification_read
     *
     *  Read a avdecc_aem_command_register_state_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_register_state_notification_read (
        avdecc_aem_command_register_state_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_register_state_notification_write
     *
     *  write a avdecc_aem_command_register_state_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_register_state_notification_write (
        const avdecc_aem_command_register_state_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_register_state_notification_t
    */
    
    typedef struct avdecc_aem_response_register_state_notification_s
    {
        /* TODO */
    } avdecc_aem_response_register_state_notification_t;
    
    
    
    /** avdecc_response_register_state_notification_init
     *
     *  Initialize a avdecc_aem_response_register_state_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_register_state_notification_init ( avdecc_aem_response_register_state_notification_t *self );
    
    
    /** avdecc_response_register_state_notification_read
     *
     *  Read a avdecc_aem_response_register_state_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_register_state_notification_read (
        avdecc_aem_response_register_state_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_register_state_notification_write
     *
     *  write a avdecc_aem_response_register_state_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_register_state_notification_write (
        const avdecc_aem_response_register_state_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_deregister_state_notification_t
    */
    
    typedef struct avdecc_aem_command_deregister_state_notification_s
    {
        /* TODO */
    } avdecc_aem_command_deregister_state_notification_t;
    
    
    
    /** avdecc_command_deregister_state_notification_init
     *
     *  Initialize a avdecc_aem_command_deregister_state_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_deregister_state_notification_init ( avdecc_aem_command_deregister_state_notification_t *self );
    
    
    /** avdecc_command_deregister_state_notification_read
     *
     *  Read a avdecc_aem_command_deregister_state_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_deregister_state_notification_read (
        avdecc_aem_command_deregister_state_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_deregister_state_notification_write
     *
     *  write a avdecc_aem_command_deregister_state_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_deregister_state_notification_write (
        const avdecc_aem_command_deregister_state_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_deregister_state_notification_t
    */
    
    typedef struct avdecc_aem_response_deregister_state_notification_s
    {
        /* TODO */
    } avdecc_aem_response_deregister_state_notification_t;
    
    
    
    /** avdecc_response_deregister_state_notification_init
     *
     *  Initialize a avdecc_aem_response_deregister_state_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_deregister_state_notification_init ( avdecc_aem_response_deregister_state_notification_t *self );
    
    
    /** avdecc_response_deregister_state_notification_read
     *
     *  Read a avdecc_aem_response_deregister_state_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_deregister_state_notification_read (
        avdecc_aem_response_deregister_state_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_deregister_state_notification_write
     *
     *  write a avdecc_aem_response_deregister_state_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_deregister_state_notification_write (
        const avdecc_aem_response_deregister_state_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_register_query_notification_t
    */
    
    typedef struct avdecc_aem_command_register_query_notification_s
    {
        /* TODO */
    } avdecc_aem_command_register_query_notification_t;
    
    
    
    /** avdecc_command_register_query_notification_init
     *
     *  Initialize a avdecc_aem_command_register_query_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_register_query_notification_init ( avdecc_aem_command_register_query_notification_t *self );
    
    
    /** avdecc_command_register_query_notification_read
     *
     *  Read a avdecc_aem_command_register_query_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_register_query_notification_read (
        avdecc_aem_command_register_query_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_register_query_notification_write
     *
     *  write a avdecc_aem_command_register_query_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_register_query_notification_write (
        const avdecc_aem_command_register_query_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_register_query_notification_t
    */
    
    typedef struct avdecc_aem_response_register_query_notification_s
    {
        /* TODO */
    } avdecc_aem_response_register_query_notification_t;
    
    
    
    /** avdecc_response_register_query_notification_init
     *
     *  Initialize a avdecc_aem_response_register_query_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_register_query_notification_init ( avdecc_aem_response_register_query_notification_t *self );
    
    
    /** avdecc_response_register_query_notification_read
     *
     *  Read a avdecc_aem_response_register_query_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_register_query_notification_read (
        avdecc_aem_response_register_query_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_register_query_notification_write
     *
     *  write a avdecc_aem_response_register_query_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_register_query_notification_write (
        const avdecc_aem_response_register_query_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_deregister_query_notification_t
    */
    
    typedef struct avdecc_aem_command_deregister_query_notification_s
    {
        /* TODO */
    } avdecc_aem_command_deregister_query_notification_t;
    
    
    
    /** avdecc_command_deregister_query_notification_init
     *
     *  Initialize a avdecc_aem_command_deregister_query_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_deregister_query_notification_init ( avdecc_aem_command_deregister_query_notification_t *self );
    
    
    /** avdecc_command_deregister_query_notification_read
     *
     *  Read a avdecc_aem_command_deregister_query_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_deregister_query_notification_read (
        avdecc_aem_command_deregister_query_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_deregister_query_notification_write
     *
     *  write a avdecc_aem_command_deregister_query_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_deregister_query_notification_write (
        const avdecc_aem_command_deregister_query_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_deregister_query_notification_t
    */
    
    typedef struct avdecc_aem_response_deregister_query_notification_s
    {
        /* TODO */
    } avdecc_aem_response_deregister_query_notification_t;
    
    
    
    /** avdecc_response_deregister_query_notification_init
     *
     *  Initialize a avdecc_aem_response_deregister_query_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_deregister_query_notification_init ( avdecc_aem_response_deregister_query_notification_t *self );
    
    
    /** avdecc_response_deregister_query_notification_read
     *
     *  Read a avdecc_aem_response_deregister_query_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_deregister_query_notification_read (
        avdecc_aem_response_deregister_query_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_deregister_query_notification_write
     *
     *  write a avdecc_aem_response_deregister_query_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_deregister_query_notification_write (
        const avdecc_aem_response_deregister_query_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_identify_notification_t
    */
    
    typedef struct avdecc_aem_command_identify_notification_s
    {
        /* TODO */
    } avdecc_aem_command_identify_notification_t;
    
    
    
    /** avdecc_command_identify_notification_init
     *
     *  Initialize a avdecc_aem_command_identify_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_identify_notification_init ( avdecc_aem_command_identify_notification_t *self );
    
    
    /** avdecc_command_identify_notification_read
     *
     *  Read a avdecc_aem_command_identify_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_identify_notification_read (
        avdecc_aem_command_identify_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_identify_notification_write
     *
     *  write a avdecc_aem_command_identify_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_identify_notification_write (
        const avdecc_aem_command_identify_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_identify_notification_t
    */
    
    typedef struct avdecc_aem_response_identify_notification_s
    {
        /* TODO */
    } avdecc_aem_response_identify_notification_t;
    
    
    
    /** avdecc_response_identify_notification_init
     *
     *  Initialize a avdecc_aem_response_identify_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_identify_notification_init ( avdecc_aem_response_identify_notification_t *self );
    
    
    /** avdecc_response_identify_notification_read
     *
     *  Read a avdecc_aem_response_identify_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_identify_notification_read (
        avdecc_aem_response_identify_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_identify_notification_write
     *
     *  write a avdecc_aem_response_identify_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_identify_notification_write (
        const avdecc_aem_response_identify_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_state_change_notification_t
    */
    
    typedef struct avdecc_aem_command_state_change_notification_s
    {
        /* TODO */
    } avdecc_aem_command_state_change_notification_t;
    
    
    
    /** avdecc_command_state_change_notification_init
     *
     *  Initialize a avdecc_aem_command_state_change_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_state_change_notification_init ( avdecc_aem_command_state_change_notification_t *self );
    
    
    /** avdecc_command_state_change_notification_read
     *
     *  Read a avdecc_aem_command_state_change_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_state_change_notification_read (
        avdecc_aem_command_state_change_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_state_change_notification_write
     *
     *  write a avdecc_aem_command_state_change_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_state_change_notification_write (
        const avdecc_aem_command_state_change_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_state_change_notification_t
    */
    
    typedef struct avdecc_aem_response_state_change_notification_s
    {
        /* TODO */
    } avdecc_aem_response_state_change_notification_t;
    
    
    
    /** avdecc_response_state_change_notification_init
     *
     *  Initialize a avdecc_aem_response_state_change_notification_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_state_change_notification_init ( avdecc_aem_response_state_change_notification_t *self );
    
    
    /** avdecc_response_state_change_notification_read
     *
     *  Read a avdecc_aem_response_state_change_notification_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_state_change_notification_read (
        avdecc_aem_response_state_change_notification_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_state_change_notification_write
     *
     *  write a avdecc_aem_response_state_change_notification_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_state_change_notification_write (
        const avdecc_aem_response_state_change_notification_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_increment_control_value_t
    */
    
    typedef struct avdecc_aem_command_increment_control_value_s
    {
        /* TODO */
    } avdecc_aem_command_increment_control_value_t;
    
    
    
    /** avdecc_command_increment_control_value_init
     *
     *  Initialize a avdecc_aem_command_increment_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_increment_control_value_init ( avdecc_aem_command_increment_control_value_t *self );
    
    
    /** avdecc_command_increment_control_value_read
     *
     *  Read a avdecc_aem_command_increment_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_increment_control_value_read (
        avdecc_aem_command_increment_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_increment_control_value_write
     *
     *  write a avdecc_aem_command_increment_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_increment_control_value_write (
        const avdecc_aem_command_increment_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_increment_control_value_t
    */
    
    typedef struct avdecc_aem_response_increment_control_value_s
    {
        /* TODO */
    } avdecc_aem_response_increment_control_value_t;
    
    
    
    /** avdecc_response_increment_control_value_init
     *
     *  Initialize a avdecc_aem_response_increment_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_increment_control_value_init ( avdecc_aem_response_increment_control_value_t *self );
    
    
    /** avdecc_response_increment_control_value_read
     *
     *  Read a avdecc_aem_response_increment_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_increment_control_value_read (
        avdecc_aem_response_increment_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_increment_control_value_write
     *
     *  write a avdecc_aem_response_increment_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_increment_control_value_write (
        const avdecc_aem_response_increment_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_decrement_control_value_t
    */
    
    typedef struct avdecc_aem_command_decrement_control_value_s
    {
        /* TODO */
    } avdecc_aem_command_decrement_control_value_t;
    
    
    
    /** avdecc_command_decrement_control_value_init
     *
     *  Initialize a avdecc_aem_command_decrement_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_decrement_control_value_init ( avdecc_aem_command_decrement_control_value_t *self );
    
    
    /** avdecc_command_decrement_control_value_read
     *
     *  Read a avdecc_aem_command_decrement_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_decrement_control_value_read (
        avdecc_aem_command_decrement_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_decrement_control_value_write
     *
     *  write a avdecc_aem_command_decrement_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_decrement_control_value_write (
        const avdecc_aem_command_decrement_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_decrement_control_value_t
    */
    
    typedef struct avdecc_aem_response_decrement_control_value_s
    {
        /* TODO */
    } avdecc_aem_response_decrement_control_value_t;
    
    
    
    /** avdecc_response_decrement_control_value_init
     *
     *  Initialize a avdecc_aem_response_decrement_control_value_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_decrement_control_value_init ( avdecc_aem_response_decrement_control_value_t *self );
    
    
    /** avdecc_response_decrement_control_value_read
     *
     *  Read a avdecc_aem_response_decrement_control_value_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_decrement_control_value_read (
        avdecc_aem_response_decrement_control_value_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_decrement_control_value_write
     *
     *  write a avdecc_aem_response_decrement_control_value_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_decrement_control_value_write (
        const avdecc_aem_response_decrement_control_value_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_start_operation_t
    */
    
    typedef struct avdecc_aem_command_start_operation_s
    {
        /* TODO */
    } avdecc_aem_command_start_operation_t;
    
    
    
    /** avdecc_command_start_operation_init
     *
     *  Initialize a avdecc_aem_command_start_operation_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_start_operation_init ( avdecc_aem_command_start_operation_t *self );
    
    
    /** avdecc_command_start_operation_read
     *
     *  Read a avdecc_aem_command_start_operation_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_start_operation_read (
        avdecc_aem_command_start_operation_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_start_operation_write
     *
     *  write a avdecc_aem_command_start_operation_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_start_operation_write (
        const avdecc_aem_command_start_operation_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_start_operation_t
    */
    
    typedef struct avdecc_aem_response_start_operation_s
    {
        /* TODO */
    } avdecc_aem_response_start_operation_t;
    
    
    
    /** avdecc_response_start_operation_init
     *
     *  Initialize a avdecc_aem_response_start_operation_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_start_operation_init ( avdecc_aem_response_start_operation_t *self );
    
    
    /** avdecc_response_start_operation_read
     *
     *  Read a avdecc_aem_response_start_operation_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_start_operation_read (
        avdecc_aem_response_start_operation_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_start_operation_write
     *
     *  write a avdecc_aem_response_start_operation_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_start_operation_write (
        const avdecc_aem_response_start_operation_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_abort_operation_t
    */
    
    typedef struct avdecc_aem_command_abort_operation_s
    {
        /* TODO */
    } avdecc_aem_command_abort_operation_t;
    
    
    
    /** avdecc_command_abort_operation_init
     *
     *  Initialize a avdecc_aem_command_abort_operation_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_abort_operation_init ( avdecc_aem_command_abort_operation_t *self );
    
    
    /** avdecc_command_abort_operation_read
     *
     *  Read a avdecc_aem_command_abort_operation_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_abort_operation_read (
        avdecc_aem_command_abort_operation_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_abort_operation_write
     *
     *  write a avdecc_aem_command_abort_operation_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_abort_operation_write (
        const avdecc_aem_command_abort_operation_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_abort_operation_t
    */
    
    typedef struct avdecc_aem_response_abort_operation_s
    {
        /* TODO */
    } avdecc_aem_response_abort_operation_t;
    
    
    
    /** avdecc_response_abort_operation_init
     *
     *  Initialize a avdecc_aem_response_abort_operation_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_abort_operation_init ( avdecc_aem_response_abort_operation_t *self );
    
    
    /** avdecc_response_abort_operation_read
     *
     *  Read a avdecc_aem_response_abort_operation_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_abort_operation_read (
        avdecc_aem_response_abort_operation_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_abort_operation_write
     *
     *  write a avdecc_aem_response_abort_operation_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_abort_operation_write (
        const avdecc_aem_response_abort_operation_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_operation_status_t
    */
    
    typedef struct avdecc_aem_command_operation_status_s
    {
        /* TODO */
    } avdecc_aem_command_operation_status_t;
    
    
    
    /** avdecc_command_operation_status_init
     *
     *  Initialize a avdecc_aem_command_operation_status_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_operation_status_init ( avdecc_aem_command_operation_status_t *self );
    
    
    /** avdecc_command_operation_status_read
     *
     *  Read a avdecc_aem_command_operation_status_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_operation_status_read (
        avdecc_aem_command_operation_status_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_operation_status_write
     *
     *  write a avdecc_aem_command_operation_status_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_operation_status_write (
        const avdecc_aem_command_operation_status_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_operation_status_t
    */
    
    typedef struct avdecc_aem_response_operation_status_s
    {
        /* TODO */
    } avdecc_aem_response_operation_status_t;
    
    
    
    /** avdecc_response_operation_status_init
     *
     *  Initialize a avdecc_aem_response_operation_status_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_operation_status_init ( avdecc_aem_response_operation_status_t *self );
    
    
    /** avdecc_response_operation_status_read
     *
     *  Read a avdecc_aem_response_operation_status_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_operation_status_read (
        avdecc_aem_response_operation_status_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_operation_status_write
     *
     *  write a avdecc_aem_response_operation_status_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_operation_status_write (
        const avdecc_aem_response_operation_status_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_auth_get_key_count_t
    */
    
    typedef struct avdecc_aem_command_auth_get_key_count_s
    {
        /* TODO */
    } avdecc_aem_command_auth_get_key_count_t;
    
    
    
    /** avdecc_command_auth_get_key_count_init
     *
     *  Initialize a avdecc_aem_command_auth_get_key_count_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_auth_get_key_count_init ( avdecc_aem_command_auth_get_key_count_t *self );
    
    
    /** avdecc_command_auth_get_key_count_read
     *
     *  Read a avdecc_aem_command_auth_get_key_count_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_auth_get_key_count_read (
        avdecc_aem_command_auth_get_key_count_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_auth_get_key_count_write
     *
     *  write a avdecc_aem_command_auth_get_key_count_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_auth_get_key_count_write (
        const avdecc_aem_command_auth_get_key_count_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_auth_get_key_count_t
    */
    
    typedef struct avdecc_aem_response_auth_get_key_count_s
    {
        /* TODO */
    } avdecc_aem_response_auth_get_key_count_t;
    
    
    
    /** avdecc_response_auth_get_key_count_init
     *
     *  Initialize a avdecc_aem_response_auth_get_key_count_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_auth_get_key_count_init ( avdecc_aem_response_auth_get_key_count_t *self );
    
    
    /** avdecc_response_auth_get_key_count_read
     *
     *  Read a avdecc_aem_response_auth_get_key_count_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_auth_get_key_count_read (
        avdecc_aem_response_auth_get_key_count_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_auth_get_key_count_write
     *
     *  write a avdecc_aem_response_auth_get_key_count_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_auth_get_key_count_write (
        const avdecc_aem_response_auth_get_key_count_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_get_as_path_t
    */
    
    typedef struct avdecc_aem_command_get_as_path_s
    {
        /* TODO */
    } avdecc_aem_command_get_as_path_t;
    
    
    
    /** avdecc_command_get_as_path_init
     *
     *  Initialize a avdecc_aem_command_get_as_path_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_get_as_path_init ( avdecc_aem_command_get_as_path_t *self );
    
    
    /** avdecc_command_get_as_path_read
     *
     *  Read a avdecc_aem_command_get_as_path_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_get_as_path_read (
        avdecc_aem_command_get_as_path_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_get_as_path_write
     *
     *  write a avdecc_aem_command_get_as_path_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_get_as_path_write (
        const avdecc_aem_command_get_as_path_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_get_as_path_t
    */
    
    typedef struct avdecc_aem_response_get_as_path_s
    {
        /* TODO */
    } avdecc_aem_response_get_as_path_t;
    
    
    
    /** avdecc_response_get_as_path_init
     *
     *  Initialize a avdecc_aem_response_get_as_path_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_get_as_path_init ( avdecc_aem_response_get_as_path_t *self );
    
    
    /** avdecc_response_get_as_path_read
     *
     *  Read a avdecc_aem_response_get_as_path_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_get_as_path_read (
        avdecc_aem_response_get_as_path_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_get_as_path_write
     *
     *  write a avdecc_aem_response_get_as_path_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_get_as_path_write (
        const avdecc_aem_response_get_as_path_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_deauthenticate_t
    */
    
    typedef struct avdecc_aem_command_deauthenticate_s
    {
        /* TODO */
    } avdecc_aem_command_deauthenticate_t;
    
    
    
    /** avdecc_command_deauthenticate_init
     *
     *  Initialize a avdecc_aem_command_deauthenticate_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_deauthenticate_init ( avdecc_aem_command_deauthenticate_t *self );
    
    
    /** avdecc_command_deauthenticate_read
     *
     *  Read a avdecc_aem_command_deauthenticate_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_deauthenticate_read (
        avdecc_aem_command_deauthenticate_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_deauthenticate_write
     *
     *  write a avdecc_aem_command_deauthenticate_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_deauthenticate_write (
        const avdecc_aem_command_deauthenticate_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_deauthenticate_t
    */
    
    typedef struct avdecc_aem_response_deauthenticate_s
    {
        /* TODO */
    } avdecc_aem_response_deauthenticate_t;
    
    
    
    /** avdecc_response_deauthenticate_init
     *
     *  Initialize a avdecc_aem_response_deauthenticate_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_deauthenticate_init ( avdecc_aem_response_deauthenticate_t *self );
    
    
    /** avdecc_response_deauthenticate_read
     *
     *  Read a avdecc_aem_response_deauthenticate_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_deauthenticate_read (
        avdecc_aem_response_deauthenticate_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_deauthenticate_write
     *
     *  write a avdecc_aem_response_deauthenticate_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_deauthenticate_write (
        const avdecc_aem_response_deauthenticate_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_command_auth_revoke_key_t
    */
    
    typedef struct avdecc_aem_command_auth_revoke_key_s
    {
        /* TODO */
    } avdecc_aem_command_auth_revoke_key_t;
    
    
    
    /** avdecc_command_auth_revoke_key_init
     *
     *  Initialize a avdecc_aem_command_auth_revoke_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_auth_revoke_key_init ( avdecc_aem_command_auth_revoke_key_t *self );
    
    
    /** avdecc_command_auth_revoke_key_read
     *
     *  Read a avdecc_aem_command_auth_revoke_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_auth_revoke_key_read (
        avdecc_aem_command_auth_revoke_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_auth_revoke_key_write
     *
     *  write a avdecc_aem_command_auth_revoke_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_auth_revoke_key_write (
        const avdecc_aem_command_auth_revoke_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    /** avdecc_aem_response_auth_revoke_key_t
    */
    
    typedef struct avdecc_aem_response_auth_revoke_key_s
    {
        /* TODO */
    } avdecc_aem_response_auth_revoke_key_t;
    
    
    
    /** avdecc_response_auth_revoke_key_init
     *
     *  Initialize a avdecc_aem_response_auth_revoke_key_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_response_auth_revoke_key_init ( avdecc_aem_response_auth_revoke_key_t *self );
    
    
    /** avdecc_response_auth_revoke_key_read
     *
     *  Read a avdecc_aem_response_auth_revoke_key_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_response_auth_revoke_key_read (
        avdecc_aem_response_auth_revoke_key_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_response_auth_revoke_key_write
     *
     *  write a avdecc_aem_response_auth_revoke_key_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_response_auth_revoke_key_write (
        const avdecc_aem_response_auth_revoke_key_t *self,
        void *pdu,
        size_t offset
    );
    
    
    
    /* @} */
    
#ifdef __cplusplus
}
#endif

#endif
