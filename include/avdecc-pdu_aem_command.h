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

#include "avdecc-pdu_world.h"
#include "avdecc-pdu_aecp.h"
#include "avdecc-pdu_aem_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
    \addtogroup aem_command AEM Command
    */
    /* @{ */
    
    typedef enum
    {
        avdecc_aem_command_lock_entity = 0x0000, /*!< lock or unlock the entity for atomic access. */
        avdecc_aem_command_read_descriptor = 0x0001, /*!< read a descriptor from the entity. */
        avdecc_aem_command_write_descriptor = 0x0002, /*!< write a descriptor to the entity. */
        avdecc_aem_command_acquire_entity = 0x0003, /*!< acquire the entity for single controller access. */
        avdecc_aem_command_controller_available = 0x0004, /*!< verify that the controller is still there. */
        avdecc_aem_command_set_clock_source = 0x0005, /*!< set the clock source of a unit. */
        avdecc_aem_command_get_clock_source = 0x0006, /*!< get the clock source of a unit. */
        avdecc_aem_command_set_stream_format = 0x0007, /*!< set the format of a stream. */
        avdecc_aem_command_get_stream_format = 0x0008, /*!< get the current format of a stream. */
        avdecc_aem_command_set_configuration = 0x0009, /*!< set the configuration of the entity. */
        avdecc_aem_command_get_configuration = 0x000a, /*!< get the configuration of the entity. */
        avdecc_aem_command_set_control_value = 0x000b, /*!< set the values of a control. */
        avdecc_aem_command_get_control_value = 0x000c, /*!< get the current values of a control. */
        avdecc_aem_command_set_signal_selector = 0x000d, /*!< set the source of a selector. */
        avdecc_aem_command_get_signal_selector = 0x000e, /*!< get the current source of a selector. */
        avdecc_aem_command_set_mixer = 0x000f, /*!< set the parameters of a mixer. */
        avdecc_aem_command_get_mixer = 0x0010, /*!< get the parameters of a mixer. */
        avdecc_aem_command_set_matrix = 0x0011, /*!< set the parameters of a matrix. */
        avdecc_aem_command_get_matrix = 0x0012, /*!< get the parameters of a matrix. */
        avdecc_aem_command_start_streaming = 0x0013, /*!< start streaming on a previously connected stream. */
        avdecc_aem_command_stop_streaming = 0x0014, /*!< stop streaming on a previously connected stream. */
        avdecc_aem_command_set_stream_info = 0x0015, /*!< set changeable parameters for a stream. */
        avdecc_aem_command_get_stream_info = 0x0016, /*!< get the current info for a stream. */
        avdecc_aem_command_set_name = 0x0017, /*!< set the value of a name within a descriptor. */
        avdecc_aem_command_get_name = 0x0018, /*!< get the value of a name within a descriptor. */
        avdecc_aem_command_set_association_id = 0x0019, /*!< set the association id of the entity. */
        avdecc_aem_command_get_association_id = 0x001a, /*!< get the association id of the entity. */
        avdecc_aem_command_auth_add_key = 0x001b, /*!< add key to a keychain. */
        avdecc_aem_command_auth_get_key = 0x001c, /*!< get key or key count from a keychain. */
        avdecc_aem_command_authenticate = 0x001d, /*!< authenticate. */
        avdecc_aem_command_get_counters = 0x001e, /*!< get the performance counters of the entity. */
        avdecc_aem_command_reboot = 0x001f, /*!< reboot the entity. */
        avdecc_aem_command_set_media_format = 0x0020, /*!< set the media format of a video port. */
        avdecc_aem_command_get_media_format = 0x0021, /*!< get the media format of a video port. */
        avdecc_aem_command_register_state_notification = 0x0022, /*!< register for state changed update notifications. */
        avdecc_aem_command_deregister_state_notification = 0x0023, /*!< deregister from state change update notifications. */
        avdecc_aem_command_register_query_notification = 0x0024, /*!< register for specific query notifications. */
        avdecc_aem_command_deregister_query_notification = 0x0025, /*!< deregister from specific query notifications. */
        avdecc_aem_command_identify_notification = 0x0026, /*!< identification notification message. */
        avdecc_aem_command_state_change_notification = 0x0027, /*!< state change notification message. */
        avdecc_aem_command_increment_control_value = 0x0028, /*!< increment control value. */
        avdecc_aem_command_decrement_control_value = 0x0029, /*!< decrement control value. */
        avdecc_aem_command_start_operation = 0x002a, /*!< start operation. */
        avdecc_aem_command_abort_operation = 0x002b, /*!< abort operation. */
        avdecc_aem_command_operation_status = 0x002c, /*!< operation status report. */
        avdecc_aem_command_auth_get_key_count = 0x002d, /*!< get count of keys in a keychain. */
        avdecc_aem_command_get_as_path = 0x002e, /*!< get the path sequence from the pathtrace tlv of 802.1AS. */
        avdecc_aem_command_deauthenticate = 0x002f, /*!< release authenticated permissions. */
        avdecc_aem_command_auth_revoke_key = 0x0030, /*!< revoke a key from a keychain. */
        avdecc_aem_command_expansion = 0x7fff /*!< reserved for future use. */
    }
                                   avdecc_aem_command_type_t;
                                   
                                   
                                   
    /** avdecc_aem_command_t
     */
    
    typedef struct avdecc_aem_command_s
    {
        avdecc_aecp_message_type_t message_type;
        avdecc_aecp_status_t status;
        avdecc_eui64_t controller_guid;
        avdecc_aecp_control_data_length_t control_data_length;
        avdecc_aecp_sequence_id_t sequence_id;
        bool unsolicited;
        avdecc_aem_command_type_t command_type;
    } avdecc_aem_command_t;
    
    /** avdecc_command_init
     *
     *  Initialize a avdecc_aem_commmand_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    void avdecc_command_init ( avdecc_aem_command_t *self );
    
    
    /** avdecc_command_read
     *
     *  Read a avdecc_aem_command_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    bool avdecc_command_read (
        avdecc_aem_command_t *self,
        const void *pdu,
        size_t offset
    );
    
    
    /** avdecc_command_write
     *
     *  write a avdecc_aem_command_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    bool avdecc_command_write (
        const avdecc_aem_command_t *self,
        void *pdu,
        size_t offset
    );
    
    /**
     \addtogroup aem_command_lock_entity lock_entity
     */
    /* @{ */
    
    /** avdecc_aem_command_lock_entity_t
     * See Clause 7.4.1.1
    */
    
    typedef struct avdecc_aem_command_lock_entity_s
    {
        avdecc_aem_command_t base;
        unsigned int lock:1;
        avdecc_eui64_t locked_guid;
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
     * See Clause 7.4.1.1
    */
    
    typedef struct avdecc_aem_command_lock_entity_s avdecc_aem_response_lock_entity_t;
    
    
    
    /** avdecc_response_lock_entity_init
     *
     *  Initialize a avdecc_aem_response_lock_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    static inline void avdecc_response_lock_entity_init ( avdecc_aem_response_lock_entity_t *self )
    {
        avdecc_command_lock_entity_init ( self );
    }
    
    
    /** avdecc_response_lock_entity_read
     *
     *  Read a avdecc_aem_response_lock_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    static inline bool avdecc_response_lock_entity_read (
        avdecc_aem_response_lock_entity_t *self,
        const void *pdu,
        size_t offset
    )
    {
        return avdecc_command_lock_entity_read ( self, pdu, offset );
    }
    
    
    /** avdecc_response_lock_entity_write
     *
     *  write a avdecc_aem_response_lock_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    static inline bool avdecc_response_lock_entity_write (
        const avdecc_aem_response_lock_entity_t *self,
        void *pdu,
        size_t offset
    )
    {
        return avdecc_command_lock_entity_write ( self, pdu, offset );
    }
    
    /* @} */
    /**
     \addtogroup aem_command_read_descriptor read_descriptor
     */
    /* @{ */
    
    /** avdecc_aem_command_read_descriptor_t
    * See Clause 7.4.2.1
    */
    
    typedef struct avdecc_aem_command_read_descriptor_s
    {
        avdecc_aem_command_t base;
        uint16_t configuration;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
     * See Clause 7.4.2.2
    */
    
    typedef struct avdecc_aem_response_read_descriptor_s
    {
        avdecc_aem_command_read_descriptor_t base;
        avdecc_aem_descriptor_t descriptor;
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
    
    /* @} */
    /**
     \addtogroup aem_command_write_descriptor write_descriptor
     */
    /* @{ */
    
    
    /** avdecc_aem_command_write_descriptor_t
    */
    
    typedef struct avdecc_aem_command_write_descriptor_s
    {
        avdecc_aem_command_t base;
        uint16_t configuration;
        avdecc_aem_descriptor_t descriptor;
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
    
    typedef struct avdecc_aem_response_write_descriptor_s avdecc_aem_response_write_descriptor_t;
    
    
    /** avdecc_response_write_descriptor_init
     *
     *  Initialize a avdecc_aem_response_write_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    static inline void avdecc_response_write_descriptor_init ( avdecc_aem_response_write_descriptor_t *self )
    {
        avdecc_command_write_descriptor_init ( self );
    }
    
    
    /** avdecc_response_write_descriptor_read
     *
     *  Read a avdecc_aem_response_write_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    static inline bool avdecc_response_write_descriptor_read (
        avdecc_aem_response_write_descriptor_t *self,
        const void *pdu,
        size_t offset
    )
    {
        return avdecc_command_write_descriptor_read ( self, pdu, offset );
    }
    
    
    /** avdecc_response_write_descriptor_write
     *
     *  write a avdecc_aem_response_write_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    static inline bool avdecc_response_write_descriptor_write (
        const avdecc_aem_response_write_descriptor_t *self,
        void *pdu,
        size_t offset
    )
    {
        return avdecc_command_write_descriptor_write ( self, pdu, offset );
    }
    
    /* @} */
    /**
     \addtogroup aem_command_acquire_entity acquire_entity
     */
    /* @{ */
    
    
    /** avdecc_aem_command_acquire_entity_t
    */
    
    typedef struct avdecc_aem_command_acquire_entity_s
    {
        avdecc_aem_command_t base;
        unsigned int persistent:1;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
    
    typedef struct avdecc_aem_command_acquire_entity_s  avdecc_aem_response_acquire_entity_t;
    
    
    
    /** avdecc_response_acquire_entity_init
     *
     *  Initialize a avdecc_aem_response_acquire_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */
    
    static inline void avdecc_response_acquire_entity_init ( avdecc_aem_response_acquire_entity_t *self )
    {
        return avdecc_command_acquire_entity_init ( self );
    }
    
    
    /** avdecc_response_acquire_entity_read
     *
     *  Read a avdecc_aem_response_acquire_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */
    
    static inline bool avdecc_response_acquire_entity_read (
        avdecc_aem_response_acquire_entity_t *self,
        const void *pdu,
        size_t offset
    )
    {
        return avdecc_command_acquire_entity_read ( self, pdu, offset );
    }
    
    
    /** avdecc_response_acquire_entity_write
     *
     *  write a avdecc_aem_response_acquire_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */
    
    static inline bool avdecc_response_acquire_entity_write (
        const avdecc_aem_response_acquire_entity_t *self,
        void *pdu,
        size_t offset
    )
    {
        return avdecc_command_acquire_entity_write ( self, pdu, offset );
    }
    
    /* @} */
    /**
     \addtogroup aem_command_controller_available controller_available
     */
    /* @{ */
    
    /** avdecc_aem_command_controller_available_t
    */
    
    typedef struct avdecc_aem_command_controller_available_s
    {
        avdecc_aem_command_t base;
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
        avdecc_aem_command_t base;
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_clock_source set_clock_source
     */
    /* @{ */
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_clock_source get_clock_source
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_stream_format set_stream_format
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_stream_format get_stream_format
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_configuration set_configuration
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_configuration get_configuration
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_control_value set_control_value
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_control_value get_control_value
     */
    /* @{ */
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_signal_selector set_signal_selector
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_signal_selector get_signal_selector
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_mixer set_mixer
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_mixer get_mixer
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_matrix set_matrix
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_matrix get_matrix
     */
    /* @{ */
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_start_streaming start_streaming
     */
    /* @{ */
    
    
    /** avdecc_aem_command_start_streaming_t
    */
    
    typedef struct avdecc_aem_command_start_streaming_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
    
    typedef struct avdecc_aem_command_start_streaming_s avdecc_aem_response_start_streaming_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_stop_streaming stop_streaming
     */
    /* @{ */
    
    
    /** avdecc_aem_command_stop_streaming_t
    */
    
    typedef struct avdecc_aem_command_start_streaming_s avdecc_aem_command_stop_streaming_t;
    
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
    
    typedef struct avdecc_aem_command_start_streaming_s avdecc_aem_response_stop_streaming_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_stream_info set_stream_info
     */
    /* @{ */
    
    
    /** avdecc_aem_command_set_stream_info_t
    */
    
    typedef struct avdecc_aem_command_set_stream_info_s
    {
        avdecc_aem_command_t base;
        unsigned int class_b:1;
        unsigned int fast_connect:1;
        unsigned int saved_state:1;
        unsigned int streaming_wait:1;
        unsigned int msrp_acc_lat_valid:1;
        unsigned int stream_id_valid:1;
        unsigned int dest_mac_valid:1;
        uint32_t msrp_accumulated_latency;
        avdecc_stream_id_t stream_id;
        avdecc_mac_t dest_mac;
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
    
    typedef struct avdecc_aem_command_set_stream_info_s avdecc_aem_response_set_stream_info_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_stream_info get_stream_info
     */
    /* @{ */
    
    /** avdecc_aem_command_get_stream_info_t
    */
    
    typedef struct avdecc_aem_command_get_stream_info_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        unsigned int class_b:1;
        unsigned int fast_connect:1;
        unsigned int saved_state:1;
        unsigned int streaming_wait:1;
        unsigned int connected:1;
        unsigned int stream_id_valid:1;
        unsigned int msrp_acc_lat_valid:1;
        unsigned int dest_mac_valid:1;
        avdecc_eui64_t stream_format;
        avdecc_stream_id_t stream_id;
        uint32_t msrp_accumulated_latency;
        avdecc_mac_t dest_mac;
        uint16_t clock_source_id;
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_name set_name
     */
    /* @{ */
    
    
    /** avdecc_aem_command_set_name_t
    */
    
    typedef struct avdecc_aem_command_set_name_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint16_t name_index;
        avdecc_string64_t name;
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
    
    typedef struct avdecc_aem_command_set_name_s avdecc_aem_response_set_name_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_name get_name
     */
    /* @{ */
    
    /** avdecc_aem_command_get_name_t
    */
    
    typedef struct avdecc_aem_command_get_name_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint16_t name_index;
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
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint16_t name_index;
        avdecc_string64_t name;
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_association_id set_association_id
     */
    /* @{ */
    
    /** avdecc_aem_command_set_association_id_t
    */
    
    typedef struct avdecc_aem_command_set_association_id_s
    {
        avdecc_aem_command_t base;
        avdecc_eui64_t association_id;
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
    
    typedef struct avdecc_aem_command_set_association_id_s avdecc_aem_response_set_association_id_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_association_id get_association_id
     */
    /* @{ */
    
    
    /** avdecc_aem_command_get_association_id_t
    */
    
    typedef struct avdecc_aem_command_set_association_id_s avdecc_aem_command_get_association_id_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_set_association_id_s avdecc_aem_response_get_association_id_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_auth_add_key auth_add_key
     */
    /* @{ */
    
    
    /** See Clause 7.4.28.1 */
    typedef enum
    {
        avdecc_aem_auth_keychain_none=0,
        avdecc_aem_auth_keychain_manu_public=1,
        avdecc_aem_auth_keychain_product_public=2,
        avdecc_aem_auth_keychain_entity_private=3,
        avdecc_aem_auth_keychain_entity_public=4,
        avdecc_aem_auth_keychain_user_private=5,
        avdecc_aem_auth_keychain_user_public=6,
        avdecc_aem_auth_keychain_reserved=7
    } avdecc_aem_auth_keychain_id_t;
    
    /** See Clause 7.4.28.1.2 */
    typedef enum
    {
        avdecc_aem_auth_key_type_none=0,
        avdecc_aem_auth_key_type_sha256=1,
        avdecc_aem_auth_key_type_aes128=2,
        avdecc_aem_auth_key_type_aes256=3,
        avdecc_aem_auth_key_type_rsa1024_public=4,
        avdecc_aem_auth_key_type_rsa1024_private=5,
        avdecc_aem_auth_key_type_x509=6,
        avdecc_aem_auth_key_type_reserved=7
    } avdecc_aem_auth_key_type_t;
    
    /** See Clause 7.4.28.1 */
    
    typedef struct avdecc_aem_auth_key_permissions_s
    {
        unsigned int private_key_read:1;
        unsigned int private_key_write:1;
        unsigned int public_key_write:1;
        unsigned int connection:1;
        unsigned int control_admin:1;
        unsigned int mem_obj_admin:1;
        unsigned int mem_obj_settings:1;
        unsigned int entity_specific:1;
        unsigned int control_user_l4:1;
        unsigned int control_user_l3:1;
        unsigned int control_user_l2:1;
        unsigned int control_user_l1:1;
    } avdecc_aem_auth_key_permissions_t;
    
    
    /** See Clause 7.4.28.1.2.4 */
    typedef struct avdecc_aem_auth_key_rsa1024_public_s
    {
        uint8_t exponent[8];
        uint8_t modulus[128];
    } avdecc_aem_auth_key_rsa1024_public_t;
    
    /** See Clause 7.4.28.1.2.5 */
    typedef struct avdecc_aem_auth_key_rsa1024_private_s
    {
        uint8_t exponent[8];
        uint8_t modulus[128];
        uint8_t private_exponent[8];
        uint8_t p[72];
        uint8_t q[72];
    } avdecc_aem_auth_key_rsa1024_private_t;
    
    
    typedef struct avdecc_aem_auth_key_s
    {
        union
        {
            uint8_t sha256[32]; /*!< See Clause 7.4.28.1.2.1 */
            uint8_t aes128[16]; /*!< See Clause 7.4.28.1.2.2 */
            uint8_t aes256[16]; /*!< See Clause 7.4.28.1.2.3 */
            avdecc_aem_auth_key_rsa1024_public_t rsa1024_public;
            avdecc_aem_auth_key_rsa1024_private_t rsa1024_private;
            uint8_t x509[384]; /*!< See Clause 7.4.28.1.2.6 TODO find max octet count */
        } key;
    } avdecc_aem_auth_key_t;
    
    /** avdecc_aem_command_auth_add_key_t
    */
    
    typedef struct avdecc_aem_command_auth_add_key_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_auth_keychain_id_t keychainid;
        avdecc_aem_auth_key_type_t keytype;
        uint16_t key_number;
        bool c;
        uint16_t key_part;
        uint16_t key_length;
        avdecc_aem_auth_key_permissions_t key_permissions;
        avdecc_eui64_t key_guid;
        avdecc_aem_auth_key_t key;
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
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_response_auth_add_key_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_auth_get_key auth_get_key
     */
    /* @{ */
    
    
    /** avdecc_aem_command_auth_get_key_t
    */
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_command_auth_get_key_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_response_auth_get_key_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_auth_get_key auth_get_key
     */
    /* @{ */
    
    typedef struct avdecc_aem_auth_token_s
    {
        union
        {
            uint8_t sha256[32]; /*!< See Clause 7.4.30.1.1.2 */
            uint8_t aes128[32]; /*!< See Clause 7.4.30.1.1.3 */
            uint8_t aes256[16]; /*!< See Clause 7.4.30.1.1.4 */
            uint8_t rsa[32]; /*!< See Clause 7.4.30.1.1.5 */
        } token;
    } avdecc_aem_auth_token_t;
    
    /** avdecc_aem_command_authenticate_t
    */
    
    typedef struct avdecc_aem_command_authenticate_s
    {
        avdecc_aem_command_t base;
        uint16_t token_length;
        avdecc_aem_auth_key_permissions_t permissions;
        avdecc_eui64_t key_guid;
        avdecc_aem_auth_token_t auth_token;
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
    
    typedef struct avdecc_aem_command_authenticate_s avdecc_aem_response_authenticate_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_counters get_counters
     */
    /* @{ */
    
    
    /** avdecc_aem_command_get_counters_t
    */
    
    typedef struct avdecc_aem_command_get_counters_s
    {
        avdecc_aem_command_t base;
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
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        unsigned int gptp_unlocked_valid:1;
        unsigned int gptp_locked_valid:1;
        unsigned int media_unlocked_valid:1;
        unsigned int media_locked_valid:1;
        unsigned int stream_reset_valid:1;
        unsigned int srp_refused_valid:1;
        unsigned int backup_stream_switch_valid:1;
        unsigned int missed_avdecc_response_valid:1;
        unsigned int refused_avdecc_command_valid:1;
        unsigned int seq_num_mismatch_valid:1;
        unsigned int media_clock_toggles_valid:1;
        unsigned int timestamp_uncertains_valid:1;
        unsigned int timestamp_valids_valid:1;
        unsigned int unsupported_formats_valid:1;
        unsigned int bad_presentation_times_valid:1;
        unsigned int srp_latency_violations_valid:1;
        unsigned int packets_tx_valid:1;
        unsigned int packets_rx_valid:1;
        unsigned int packets_of_interest_rx_valid:1;
        unsigned int talker_bw_reserved_valid:1;
        unsigned int reserved1_valid:1;
        unsigned int reserved2_valid:1;
        unsigned int entity_specific_1_valid:1;
        unsigned int entity_specific_2_valid:1;
        unsigned int entity_specific_3_valid:1;
        unsigned int entity_specific_4_valid:1;
        unsigned int entity_specific_5_valid:1;
        unsigned int entity_specific_6_valid:1;
        unsigned int entity_specific_7_valid:1;
        unsigned int entity_specific_8_valid:1;
        
        uint32_t gptp_unlocked;
        uint32_t gptp_locked;
        uint32_t media_unlocked;
        uint32_t media_locked;
        uint32_t stream_reset;
        uint32_t srp_refused;
        uint32_t backup_stream_switch;
        uint32_t missed_avdecc_response;
        uint32_t refused_avdecc_command;
        uint32_t seq_num_mismatch;
        uint32_t media_clock_toggles;
        uint32_t timestamp_uncertains;
        uint32_t timestamp_valids;
        uint32_t unsupported_formats;
        uint32_t bad_presentation_times;
        uint32_t srp_latency_violations;
        uint32_t packets_tx;
        uint32_t packets_rx;
        uint32_t packets_of_interest_rx;
        uint32_t talker_bw_reserved;
        uint32_t reserved1;
        uint32_t reserved2;
        uint32_t entity_specific_1;
        uint32_t entity_specific_2;
        uint32_t entity_specific_3;
        uint32_t entity_specific_4;
        uint32_t entity_specific_5;
        uint32_t entity_specific_6;
        uint32_t entity_specific_7;
        uint32_t entity_specific_8;
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
    
    /* @} */
    /**
     \addtogroup aem_command_reboot reboot
     */
    /* @{ */
    
    /** avdecc_aem_command_reboot_t
    */
    
    typedef struct avdecc_aem_command_reboot_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
    
    typedef struct avdecc_aem_command_reboot_s avdecc_aem_response_reboot_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_set_media_format set_media_format
     */
    /* @{ */
    
    
    /** avdecc_aem_command_set_media_format_t
    */
    
    typedef struct avdecc_aem_command_set_media_format_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        avdecc_aem_media_format_t media_format;
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
    
    typedef struct avdecc_aem_command_set_media_format_s avdecc_aem_response_set_media_format_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_media_format get_media_format
     */
    /* @{ */
    
    /** avdecc_aem_command_get_media_format_t
    */
    
    typedef struct avdecc_aem_command_set_media_format_s avdecc_aem_command_get_media_format_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_set_media_format_s avdecc_aem_response_get_media_format_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_register_state_notification register_state_notification
     */
    /* @{ */
    
    typedef enum
    {
        avdecc_aem_address_type_mac=0,
        avdecc_aem_address_type_ipv4=1,
        avdecc_aem_address_type_ipv6=2
    } avdecc_aem_address_type_t;
    
    /** avdecc_aem_command_register_state_notification_t
    */
    
    typedef struct avdecc_aem_command_register_state_notification_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_address_type_t address_type;
        uint8_t address[16];
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
    
    typedef struct avdecc_aem_command_register_state_notification_s avdecc_aem_response_register_state_notification_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_deregister_state_notification deregister_state_notification
     */
    /* @{ */
    
    
    /** avdecc_aem_command_deregister_state_notification_t
    */
    
    typedef struct avdecc_aem_command_deregister_state_notification_s
    {
        avdecc_aem_command_t base;
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
    
    typedef struct avdecc_aem_command_deregister_state_notification_s avdecc_aem_response_deregister_state_notification_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_register_query_notification register_query_notification
     */
    /* @{ */
    
    
    /** avdecc_aem_command_register_query_notification_t
    */
    
    typedef struct avdecc_aem_command_register_query_notification_s
    {
        avdecc_aem_command_t base;
        uint16_t query_period;
        uint16_t query_limit;
        avdecc_aem_command_type_t query_type;
        uint16_t query_id;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint8_t query_specific[ 600 ]; /* TODO: find maximum length  */
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
    
    typedef struct avdecc_aem_command_register_query_notification_s avdecc_aem_response_register_query_notification_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_deregister_query_notification deregister_query_notification
     */
    /* @{ */
    
    
    /** avdecc_aem_command_deregister_query_notification_t
    */
    
    typedef struct avdecc_aem_command_deregister_query_notification_s
    {
        avdecc_aem_command_t base;
        uint16_t query_id;
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
    
    typedef struct avdecc_aem_command_deregister_query_notification_s avdecc_aem_response_deregister_query_notification_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_identify_notification identify_notification
     */
    /* @{ */
    
    
    
    /** avdecc_aem_response_identify_notification_t
    */
    
    typedef struct avdecc_aem_response_identify_notification_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
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
    
    /* @} */
    /**
     \addtogroup aem_command_state_change_notification state_change_notification
     */
    /* @{ */
    
    /** avdecc_aem_response_state_change_notification_t
    */
    
    typedef struct avdecc_aem_response_state_change_notification_s
    {
        avdecc_aem_command_t base;
        uint16_t count;
        avdecc_aem_descriptor_list_item_t items[100]; /* TODO: decide on the max value of descriptor items */
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
    
    /* @} */
    /**
     \addtogroup aem_command_increment_control_value increment_control_value
     */
    /* @{ */
    
    
    /** avdecc_aem_command_increment_control_value_t
    */
    
    typedef struct avdecc_aem_command_increment_control_value_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint8_t values_list[ 500 ]; /* TODO: decide on maximum length */
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
    
    typedef struct avdecc_aem_command_set_control_value_s avdecc_aem_response_increment_control_value_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_decrement_control_value  decrement_control_value
     */
    /* @{ */
    
    /** avdecc_aem_command_decrement_control_value_t
    */
    
    typedef struct avdecc_aem_command_increment_control_value_s avdecc_aem_command_decrement_control_value_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_set_control_value_s avdecc_aem_response_decrement_control_value_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_start_operation start_operation
     */
    /* @{ */
    
    
    /** avdecc_aem_command_start_operation_t
    */
    
    typedef struct avdecc_aem_command_start_operation_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint16_t operation_id;
        uint16_t operation_type;
        uint8_t values[500]; /* TODO: decide on maximum value for values size */
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
    
    typedef struct avdecc_aem_command_start_operation_s avdecc_aem_response_start_operation_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_abort_operation abort_operation
     */
    /* @{ */
    
    
    /** avdecc_aem_command_abort_operation_t
    */
    
    typedef struct avdecc_aem_command_start_operation_s avdecc_aem_command_abort_operation_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_start_operation_s avdecc_aem_response_abort_operation_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_operation_status operation_status
     */
    /* @{ */
    
    
    /** avdecc_aem_response_operation_status_t
    */
    
    typedef struct avdecc_aem_response_operation_status_s
    {
        avdecc_aem_command_t base;
        avdecc_aem_descriptor_type_t descriptor_type;
        uint16_t descriptor_index;
        uint16_t operation_id;
        uint16_t percent_complete;
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
    
    /* @} */
    /**
     \addtogroup aem_command_auth_get_key_count auth_get_key_count
     */
    /* @{ */
    
    
    /** avdecc_aem_command_auth_get_key_count_t
    */
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_command_auth_get_key_count_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_response_auth_get_key_count_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_get_as_path get_as_path
     */
    /* @{ */
    
    
    /** avdecc_aem_command_get_as_path_t
    */
    
    typedef struct avdecc_aem_command_get_as_path_s
    {
        avdecc_aem_command_t base;
        uint16_t descriptor_index;
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
        avdecc_aem_command_t base;
        uint16_t descriptor_index;
        uint16_t num_items;
        avdecc_eui64_t clock_identity[128]; /* TODO: find out the maximum count of clock identities */
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
    
    /* @} */
    /**
     \addtogroup aem_command_deauthenticate deauthenticate
     */
    /* @{ */
    
    
    
    /** avdecc_aem_command_deauthenticate_t
    */
    
    typedef struct avdecc_aem_command_authenticate_s avdecc_aem_command_deauthenticate_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_authenticate_s avdecc_aem_response_deauthenticate_t;
    
    
    
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
    
    /* @} */
    /**
     \addtogroup aem_command_auth_revoke_key auth_revoke_key
     */
    /* @{ */
    
    
    
    /** avdecc_aem_command_auth_revoke_key_t
    */
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_command_auth_revoke_key_t;
    
    
    
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
    
    typedef struct avdecc_aem_command_auth_add_key_s avdecc_aem_response_auth_revoke_key_t;
    
    
    
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
    /* @} */
    
#ifdef __cplusplus
}
#endif

#endif
