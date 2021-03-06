#ifndef AVDECC_PDU_AEM_DESCRIPTOR_HPP_XXX
#define AVDECC_PDU_AEM_DESCRIPTOR_HPP_XXX


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

#include "avdecc-pdu_world.hpp"
#include "avdecc-pdu_stream.hpp"
#include "avdecc-pdu_mac.hpp"
#include "avdecc-pdu_eui64.hpp"
#include "avdecc-pdu_avtp.hpp"
#include "avdecc-pdu_adp.hpp"


/**
    \addtogroup aem_descriptor AEM Descriptor
    */
/* @{ */


#define AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE (AVDECC_PDU_MAX_PAYLOAD_SIZE-28) /*!< See IEEE 1722.1 Clause 7.4.2.2 */

typedef enum avdecc_aem_descriptor_type_e
{
    avdecc_aem_descriptor_entity= 0x0000, /*!< descriptor defining the entity. */
    avdecc_aem_descriptor_configuration= 0x0001,  /*!< descriptor defining a configuration of the entity. */
    avdecc_aem_descriptor_audio= 0x0002,  /*!< descriptor defining an audio unit. */
    avdecc_aem_descriptor_video= 0x0003,  /*!< descriptor defining a video unit. */
    avdecc_aem_descriptor_sensor= 0x0004, /*!< descriptor defining a sensor unit, containing one or more sensors sampled with the same clock. */
    avdecc_aem_descriptor_stream_input= 0x0005,   /*!< descriptor defining an input stream to the entity. */
    avdecc_aem_descriptor_stream_output= 0x0006,  /*!< descriptor defining an output stream from the entity. */
    avdecc_aem_descriptor_external_jack_input= 0x0007,    /*!< descriptor defining an external input jack on the entity. */
    avdecc_aem_descriptor_external_jack_output= 0x0008,   /*!< descriptor defining an external output jack on the entity. */
    avdecc_aem_descriptor_audio_port_input= 0x0009,   /*!< descriptor defining an input port on an audio unit. */
    avdecc_aem_descriptor_audio_port_output= 0x000a,  /*!< descriptor defining an output port on an audio unit. */
    avdecc_aem_descriptor_video_port_input= 0x000b,   /*!< descriptor defining an input port on a video unit. */
    avdecc_aem_descriptor_video_port_output= 0x000c,  /*!< descriptor defining an output port on a video unit. */
    avdecc_aem_descriptor_external_port_input= 0x000d,    /*!< descriptor defining an input external port on a unit. */
    avdecc_aem_descriptor_external_port_output= 0x000e,   /*!< descriptor defining an output external port on a unit. */
    avdecc_aem_descriptor_sensor_port_input= 0x000f,  /*!< descriptor defining an input port on a sensor unit. */
    avdecc_aem_descriptor_sensor_port_output= 0x0010, /*!< descriptor defining an output port on a sensor unit. */
    avdecc_aem_descriptor_internal_port_input= 0x0011,    /*!< descriptor defining an input port on a unit sourced from another unit within the entity. */
    avdecc_aem_descriptor_internal_port_output= 0x0012,   /*!< descriptor defining an output port on a unit sinked to another unit within the entity. */
    avdecc_aem_descriptor_avb_interface= 0x0013,  /*!< descriptor defining an avb interface. */
    avdecc_aem_descriptor_clock_source= 0x0014,   /*!< descriptor describing a clock source. */
    avdecc_aem_descriptor_audio_map= 0x0015,  /*!< descriptor defining the mapping between the channels of an audio stream and the channels of the audio port. */
    avdecc_aem_descriptor_audio_cluster= 0x0016,  /*!< descriptor defining a cluster of channels within an audio port. */
    avdecc_aem_descriptor_control= 0x0017,    /*!< descriptor defining a generic control. */
    avdecc_aem_descriptor_signal_selector= 0x0018,    /*!< descriptor defining a signal selector control. */
    avdecc_aem_descriptor_mixer= 0x0019,  /*!< descriptor defining a mixer control. */
    avdecc_aem_descriptor_matrix= 0x001a, /*!< descriptor defining a matrix control. */
    avdecc_aem_descriptor_locale= 0x001b, /*!< descriptor defining a locale. */
    avdecc_aem_descriptor_strings= 0x001c,  /*!< descriptor defining localized strings. */
    avdecc_aem_descriptor_matrix_signal=0x001d, /*!< descriptor defining part of a list of signal sources or destinations for a matrix */
    avdecc_aem_descriptor_memory_object=0x001e, /*!< descriptor describes a region of memory that may be used for settings, log files, or device firmware upgrades. */
    avdecc_aem_max_descriptor_type
}
avdecc_aem_descriptor_type_t;


typedef struct
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
} avdecc_aem_descriptor_list_item_t;


bool avdecc_aem_descriptor_type_write (
    const avdecc_aem_descriptor_type_t *self,
    void *pdu,
    size_t offset
    );

bool avdecc_aem_descriptor_type_read (
    avdecc_aem_descriptor_type_t *self,
    const void *pdu,
    size_t offset
    );

#define AVDECC_PDU_AEM_DESCRIPTOR_MAX_CONTENT_SIZE  (AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE-4) /*!< See IEEE 1722.1 Clause 7.4.2.2 */

/** See IEEE 1722.1 Clause 7.4.2.2 */

typedef struct avdecc_aem_descriptor_s
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
    uint8_t m_padding[ AVDECC_PDU_AEM_DESCRIPTOR_MAX_CONTENT_SIZE ];
} avdecc_aem_descriptor_t;


/** avdecc_descriptor_init
     *
     *  Initialize a avdecc_aem_descriptor_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_init ( avdecc_aem_descriptor_t *self );


/** avdecc_descriptor_read
     *
     *  Read a avdecc_aem_descriptor_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_read (
    avdecc_aem_descriptor_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_write
     *
     *  write a avdecc_aem_descriptor_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_write (
    const avdecc_aem_descriptor_t *self,
    void *pdu,
    size_t offset
    );

/**
     * \addtogroup aem_descriptor_localized_string_reference Localized String Reference
     */
/* @{ */

typedef struct avdecc_aem_localized_string_ref_s
{
    uint16_t m_offset:13;
    uint16_t m_index:3;
} avdecc_aem_localized_string_ref_t;

/** avdecc_localized_string_ref_init
     *
     *  Initialize a avdecc_aem_localized_string_ref_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_localized_string_ref_init ( avdecc_aem_localized_string_ref_t *self );

/** avdecc_localized_string_is_empty
     *
     *  Test if the string reference is empty
     *
     *  @param self pointer to object to test
     *  @returns bool true if string ref is NO_STRING (Clause 7.3.5) or any variant where bottom 3 bits are set
     */

static inline bool avdecc_localized_string_ref_is_empty ( const avdecc_aem_localized_string_ref_t *self )
{
    return self->m_index==7;
}

/** avdecc_localized_string_ref_read
     *
     *  Read a avdecc_aem_localized_string_ref_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_localized_string_ref_read (
    avdecc_aem_localized_string_ref_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_localized_string_ref_write
     *
     *  write a avdecc_aem_localized_string_ref_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_localized_string_ref_write (
    const avdecc_aem_localized_string_ref_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_entity entity */
/* @{ */
/** avdecc_aem_descriptor_entity_t
    */

/** See IEEE 1722.1 Clause 7.2.1 */

typedef struct avdecc_aem_descriptor_entity_s
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
    avdecc_eui64_t m_entity_guid;
    avdecc_eui64_t m_vendor_model_id;
    avdecc_adp_entity_capabilities_t m_entity_capabilities;
    uint16_t m_talker_stream_sources;
    avdecc_adp_talker_capabilities_t m_talker_capabilities;
    uint16_t m_listener_stream_sinks;
    avdecc_adp_listener_capabilities_t m_listener_capabilities;
    avdecc_adp_controller_capabilities_t m_controller_capabilities;
    uint32_t m_available_index;
    avdecc_eui64_t m_as_grandmaster_id;
    avdecc_eui64_t m_association_id;
    uint32_t m_entity_type;
    avdecc_string64_t m_entity_name;
    avdecc_aem_localized_string_ref_t m_vendor_name_string;
    avdecc_aem_localized_string_ref_t m_model_name_string;
    avdecc_string64_t m_firmware_version;
    avdecc_string64_t m_group_name;
    avdecc_string64_t m_serial_number;
    uint16_t m_configurations_count;
    uint16_t m_current_configuration;
} avdecc_aem_descriptor_entity_t;



/** avdecc_descriptor_entity_init
     *
     *  Initialize a avdecc_aem_descriptor_entity_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_entity_init ( avdecc_aem_descriptor_entity_t *self );


/** avdecc_descriptor_entity_read
     *
     *  Read a avdecc_aem_descriptor_entity_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_entity_read (
    avdecc_aem_descriptor_entity_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_entity_write
     *
     *  write a avdecc_aem_descriptor_entity_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_entity_write (
    const avdecc_aem_descriptor_entity_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_configuration configuration */
/* @{ */

/** \addtogroup aem_descriptor_configuration_counts configuration_counts */
/* @{ */

/** avdecc_aem_descriptor_configuration_counts_t
    */

/** See IEEE 1722.1 Clause 7.2.2.1 */
typedef struct avdecc_aem_descriptor_configuration_counts_s
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_count;
} avdecc_aem_descriptor_configuration_counts_t;


/** avdecc_descriptor_configuration_counts_init
     *
     *  Initialize a avdecc_aem_descriptor_configuration_counts_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_configuration_counts_init ( avdecc_aem_descriptor_configuration_counts_t *self );


/** avdecc_descriptor_configuration_counts_read
     *
     *  Read a avdecc_aem_descriptor_configuration_counts_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_configuration_counts_read (
    avdecc_aem_descriptor_configuration_counts_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_configuration_counts_write
     *
     *  write a avdecc_aem_descriptor_configuration_counts_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_configuration_counts_write (
    const avdecc_aem_descriptor_configuration_counts_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_configuration_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_CONFIGURATION_MAX_COUNTS (108) /*!< See IEEE 1722.1 Clause 7.2.2 */

/** See IEEE 1722.1 Clause 7.2.2 */
typedef struct avdecc_aem_descriptor_configuration_s
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
    avdecc_string64_t m_configuration_name;
    avdecc_aem_localized_string_ref_t m_configuration_name_string;
    uint16_t m_descriptor_counts_count;
    avdecc_aem_descriptor_configuration_counts_t m_descriptor_counts[AVDECC_PDU_AEM_DESCRIPTOR_CONFIGURATION_MAX_COUNTS];
} avdecc_aem_descriptor_configuration_t;



/** avdecc_descriptor_configuration_init
     *
     *  Initialize a avdecc_aem_descriptor_configuration_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_configuration_init ( avdecc_aem_descriptor_configuration_t *self );


/** avdecc_descriptor_configuration_read
     *
     *  Read a avdecc_aem_descriptor_configuration_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_configuration_read (
    avdecc_aem_descriptor_configuration_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_configuration_write
     *
     *  write a avdecc_aem_descriptor_configuration_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_configuration_write (
    const avdecc_aem_descriptor_configuration_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/**
    \addtogroup aem_descriptor_audio_unit audio_unit
    */
/* @{ */

/**
    \addtogroup aem_descriptor_sample_rate sample_rate
    */
/* @{ */


/** avdecc_aem_audio_pull_t
    */

/** See IEEE 1722.1 Clause 7.2.3.1.1 */
typedef enum
{
    avdecc_aem_audio_pull_mul_1=0,
    avdecc_aem_audio_pull_mul_1_div_1_001,
    avdecc_aem_audio_pull_mul_1_001,
    avdecc_aem_audio_pull_mul_24_div_25,
    avdecc_aem_audio_pull_mul_25_div_24
} avdecc_aem_audio_pull_t;

/** avdecc_audio_pull_init
     *
     *  Initialize a avdecc_aem_audio_pull_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_audio_pull_init ( avdecc_aem_audio_pull_t *self );


/** avdecc_audio_pull_read
     *
     *  Read a avdecc_aem_audio_pull_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_audio_pull_read (
    avdecc_aem_audio_pull_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_audio_pull_write
     *
     *  write a avdecc_aem_audio_pull_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_audio_pull_write (
    const avdecc_aem_audio_pull_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_audio_sample_rate_t
    */

typedef struct avdecc_aem_audio_sample_rate_s
{
    uint32_t m_base_frequency;
    avdecc_aem_audio_pull_t m_pull;
} avdecc_aem_audio_sample_rate_t;



/** avdecc_audio_sample_rate_init
     *
     *  Initialize a avdecc_aem_audio_sample_rate_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_audio_sample_rate_init ( avdecc_aem_audio_sample_rate_t *self );


/** avdecc_audio_sample_rate_read
     *
     *  Read a avdecc_aem_audio_sample_rate_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_audio_sample_rate_read (
    avdecc_aem_audio_sample_rate_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_audio_sample_rate_write
     *
     *  write a avdecc_aem_audio_sample_rate_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_audio_sample_rate_write (
    const avdecc_aem_audio_sample_rate_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_audio_unit_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAX_SAMPLE_RATES (97) /*!< See IEEE 1722.1 Clause 7.2.3 */

/** See IEEE 1722.1 Clause 7.2.3 */
typedef struct avdecc_aem_descriptor_audio_unit_s
{
    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
    uint16_t m_number_of_stream_input_ports;
    uint16_t m_base_stream_input_port;
    uint16_t m_number_of_stream_output_ports;
    uint16_t m_base_stream_output_port;
    uint16_t m_number_of_external_input_ports;
    uint16_t m_base_external_input_port;
    uint16_t m_number_of_external_output_ports;
    uint16_t m_base_external_output_port;
    uint16_t m_number_of_internal_input_ports;
    uint16_t m_base_internal_input_port;
    uint16_t m_number_of_internal_output_ports;
    uint16_t m_base_internal_output_port;
    uint16_t m_clock_source_index;
    uint16_t m_number_of_controls;
    uint16_t m_base_control;
    avdecc_string64_t m_unit_name;
    avdecc_aem_localized_string_ref_t m_unit_name_string;
    uint16_t m_number_of_signal_selectors;
    uint16_t m_base_signal_selector;
    uint16_t m_number_of_mixers;
    uint16_t m_base_mixer;
    uint16_t m_number_of_matrices;
    uint16_t m_base_matrix;
    avdecc_aem_audio_sample_rate_t m_current_sample_rate;
    uint16_t m_sample_rates_count;
    avdecc_aem_audio_sample_rate_t m_sample_rates[AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAX_SAMPLE_RATES];
} avdecc_aem_descriptor_audio_unit_t;



/** avdecc_descriptor_audio_unit_init
     *
     *  Initialize a avdecc_aem_descriptor_audio_unit_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_audio_unit_init ( avdecc_aem_descriptor_audio_unit_t *self );


/** avdecc_descriptor_audio_unit_read
     *
     *  Read a avdecc_aem_descriptor_audio_unit_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_audio_unit_read (
    avdecc_aem_descriptor_audio_unit_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_audio_unit_write
     *
     *  write a avdecc_aem_descriptor_audio_unit_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_audio_unit_write (
    const avdecc_aem_descriptor_audio_unit_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_video_unit video_unit */
/* @{ */

/** avdecc_aem_descriptor_video_unit_t
    */

/** See IEEE 1722.1 Clause 7.2.4 */
typedef struct avdecc_aem_descriptor_video_unit_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t number_of_stream_input_ports;
    uint16_t base_stream_input_port;
    uint16_t number_of_stream_output_ports;
    uint16_t base_stream_output_port;
    uint16_t number_of_external_input_ports;
    uint16_t base_external_input_port;
    uint16_t number_of_external_output_ports;
    uint16_t base_external_output_port;
    uint16_t number_of_internal_input_ports;
    uint16_t base_internal_input_port;
    uint16_t number_of_internal_output_ports;
    uint16_t base_internal_output_port;
    uint16_t clock_source_index;
    uint16_t number_of_controls;
    uint16_t base_control;
    avdecc_string64_t unit_name;
    avdecc_aem_localized_string_ref_t unit_name_string;
    uint16_t number_of_signal_selectors;
    uint16_t base_signal_selector;
    uint16_t number_of_mixers;
    uint16_t base_mixer;
    uint16_t number_of_matrices;
    uint16_t base_matrix;
} avdecc_aem_descriptor_video_unit_t;


/** avdecc_descriptor_video_unit_init
     *
     *  Initialize a avdecc_aem_descriptor_video_unit_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_video_unit_init ( avdecc_aem_descriptor_video_unit_t *self );


/** avdecc_descriptor_video_unit_read
     *
     *  Read a avdecc_aem_descriptor_video_unit_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_video_unit_read (
    avdecc_aem_descriptor_video_unit_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_video_unit_write
     *
     *  write a avdecc_aem_descriptor_video_unit_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_video_unit_write (
    const avdecc_aem_descriptor_video_unit_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_sensor_unit sensor_unit */
/* @{ */

/** avdecc_aem_descriptor_sensor_unit_t
    */

/** See IEEE 1722.1 Clause 7.2.5 */
typedef struct avdecc_aem_descriptor_sensor_unit_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t number_of_stream_input_ports;
    uint16_t base_stream_input_port;
    uint16_t number_of_stream_output_ports;
    uint16_t base_stream_output_port;
    uint16_t number_of_external_input_ports;
    uint16_t base_external_input_port;
    uint16_t number_of_external_output_ports;
    uint16_t base_external_output_port;
    uint16_t number_of_internal_input_ports;
    uint16_t base_internal_input_port;
    uint16_t number_of_internal_output_ports;
    uint16_t base_internal_output_port;
    uint16_t clock_source_index;
    uint16_t number_of_controls;
    uint16_t base_control;
    avdecc_string64_t unit_name;
    avdecc_aem_localized_string_ref_t unit_name_string;
    uint16_t number_of_signal_selectors;
    uint16_t base_signal_selector;
    uint16_t number_of_mixers;
    uint16_t base_mixer;
    uint16_t number_of_matrices;
    uint16_t base_matrix;
} avdecc_aem_descriptor_sensor_unit_t;



/** avdecc_descriptor_sensor_unit_init
     *
     *  Initialize a avdecc_aem_descriptor_sensor_unit_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_sensor_unit_init ( avdecc_aem_descriptor_sensor_unit_t *self );


/** avdecc_descriptor_sensor_unit_read
     *
     *  Read a avdecc_aem_descriptor_sensor_unit_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_sensor_unit_read (
    avdecc_aem_descriptor_sensor_unit_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_sensor_unit_write
     *
     *  write a avdecc_aem_descriptor_sensor_unit_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_sensor_unit_write (
    const avdecc_aem_descriptor_sensor_unit_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_stream_format stream_format */
/* @{ */

/** avdecc_aem_stream_format_t
    */

/** See IEEE 1722.1 Clause 7.2.6.1 */
typedef struct avdecc_aem_stream_flags_s
{
    uint8_t clock_sync_source:1;
    uint8_t class_a:1;
    uint8_t class_b:1;
} avdecc_aem_stream_flags_t;


/** See IEEE 1722.1 Clause 7.3.1 */
typedef struct avdecc_aem_stream_format_s
{
    uint64_t format;
} avdecc_aem_stream_format_t;



/** avdecc_stream_format_init
     *
     *  Initialize a avdecc_aem_stream_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_stream_format_init ( avdecc_aem_stream_format_t *self );


/** avdecc_stream_format_read
     *
     *  Read a avdecc_aem_stream_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_stream_format_read (
    avdecc_aem_stream_format_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_stream_format_write
     *
     *  write a avdecc_aem_stream_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_stream_format_write (
    const avdecc_aem_stream_format_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_descriptor_stream stream */
/* @{ */

/** avdecc_aem_descriptor_stream_t
    */


#define AVDECC_PDU_AEM_DESCRIPTOR_STREAM_MAX_FORMATS (47) /*!< See IEEE 1722.1 Clause 7.2.6 */

/** See IEEE 1722.1 Clause 7.2.6 */
typedef struct avdecc_aem_descriptor_stream_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_string64_t stream_name;
    avdecc_aem_localized_string_ref_t stream_name_string;
    avdecc_aem_stream_flags_t stream_flags;
    uint16_t stream_channels;
    uint16_t clock_source_index;
    avdecc_aem_stream_format_t current_format;
    uint16_t number_of_formats;
    avdecc_eui64_t backup_talker_guid_0;
    uint16_t backup_talker_unique_0;
    avdecc_eui64_t backup_talker_guid_1;
    uint16_t backup_talker_unique_1;
    avdecc_eui64_t backup_talker_guid_2;
    uint16_t backup_talker_unique_2;
    avdecc_eui64_t backedup_talker_guid;
    uint16_t backedup_talker_unique;
    uint16_t avb_interface_id;
    avdecc_aem_stream_format_t formats[AVDECC_PDU_AEM_DESCRIPTOR_STREAM_MAX_FORMATS];
} avdecc_aem_descriptor_stream_t;


/** avdecc_descriptor_stream_init
     *
     *  Initialize a avdecc_aem_descriptor_stream_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_stream_init ( avdecc_aem_descriptor_stream_t *self );


/** avdecc_descriptor_stream_read
     *
     *  Read a avdecc_aem_descriptor_stream_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_stream_read (
    avdecc_aem_descriptor_stream_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_stream_write
     *
     *  write a avdecc_aem_descriptor_stream_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_stream_write (
    const avdecc_aem_descriptor_stream_t *self,
    void *pdu,
    size_t offset
    );
/* @} */


/** avdecc_aem_jack_flags_t
    */

/** See IEEE 1722.1 Clause 7.2.7.1 */
typedef struct avdecc_aem_jack_flags_s
{
    uint8_t clock_sync_source:1;
    uint8_t captive:1;
} avdecc_aem_jack_flags_t;


/* @} */
/** \addtogroup aem_descriptor_jack descriptor_jack */
/* @{ */

/** \addtogroup aem_jack_flags jack_flags */
/* @{ */

/** avdecc_jack_flags_init
     *
     *  Initialize a avdecc_aem_jack_flags_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_jack_flags_init ( avdecc_aem_jack_flags_t *self );


/** avdecc_jack_flags_read
     *
     *  Read a avdecc_aem_jack_flags_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_jack_flags_read (
    avdecc_aem_jack_flags_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_jack_flags_write
     *
     *  write a avdecc_aem_jack_flags_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_jack_flags_write (
    const avdecc_aem_jack_flags_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/** \addtogroup aem_jack_type jack_type */
/* @{ */

/** avdecc_aem_jack_type_t
    */

/** See IEEE 1722.1 Clause 7.2.7.2 */
typedef enum
{
    avdecc_aem_jack_type_speaker = 0,
    avdecc_aem_jack_type_headphone,
    avdecc_aem_jack_type_analog_microphone,
    avdecc_aem_jack_type_spdif,
    avdecc_aem_jack_type_adat,
    avdecc_aem_jack_type_tdif,
    avdecc_aem_jack_type_madi,
    avdecc_aem_jack_type_unbalanced_analog,
    avdecc_aem_jack_type_balanced_analog,
    avdecc_aem_jack_type_digital,
    avdecc_aem_jack_type_midi,
    avdecc_aem_jack_type_aes_ebu,
    avdecc_aem_jack_type_composite_video,
    avdecc_aem_jack_type_s_vhs_video,
    avdecc_aem_jack_type_component_video,
    avdecc_aem_jack_type_dvi,
    avdecc_aem_jack_type_hdmi,
    avdecc_aem_jack_type_udi,
    avdecc_aem_jack_type_displayport,
    avdecc_aem_jack_type_antenna,
    avdecc_aem_jack_type_analog_tuner,
    avdecc_aem_jack_type_ethernet,
    avdecc_aem_jack_type_wifi,
    avdecc_aem_jack_type_usb,
    avdecc_aem_jack_type_pci,
    avdecc_aem_jack_type_pci_e,
    avdecc_aem_jack_type_scsi,
    avdecc_aem_jack_type_ata,
    avdecc_aem_jack_type_imager,
    avdecc_aem_jack_type_ir,
    avdecc_aem_jack_type_thunderbolt,
    avdecc_aem_jack_type_sata,
    avdecc_aem_jack_type_smpte_ltc,
    avdecc_aem_jack_type_digital_microphone
} avdecc_aem_jack_type_t;


/** avdecc_jack_type_init
     *
     *  Initialize a avdecc_aem_jack_type_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_jack_type_init ( avdecc_aem_jack_type_t *self );


/** avdecc_jack_type_read
     *
     *  Read a avdecc_aem_jack_type_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_jack_type_read (
    avdecc_aem_jack_type_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_jack_type_write
     *
     *  write a avdecc_aem_jack_type_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_jack_type_write (
    const avdecc_aem_jack_type_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_jack_t
    */

/** See IEEE 1722.1 Clause 7.2.7 */
typedef struct avdecc_aem_descriptor_jack_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_string64_t jack_name;
    avdecc_aem_localized_string_ref_t jack_name_string;
    avdecc_aem_jack_flags_t jack_flags;
    avdecc_aem_jack_type_t jack_type;
} avdecc_aem_descriptor_jack_t;



/** avdecc_descriptor_jack_init
     *
     *  Initialize a avdecc_aem_descriptor_jack_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_jack_init ( avdecc_aem_descriptor_jack_t *self );


/** avdecc_descriptor_jack_read
     *
     *  Read a avdecc_aem_descriptor_jack_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_jack_read (
    avdecc_aem_descriptor_jack_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_jack_write
     *
     *  write a avdecc_aem_descriptor_jack_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_jack_write (
    const avdecc_aem_descriptor_jack_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_port descriptor_port */
/* @{ */

/* \addtogroup aem_port_flags port_flags */
/* @{ */

/** avdecc_aem_port_flags_t
    */

/** See IEEE 1722.1 Clause 7.2.8.1 */
typedef struct avdecc_aem_port_flags_s
{
    unsigned int clock_sync_source:1;
    unsigned int async_sample_rate_conv:1;
    unsigned int sync_sample_rate_conv:1;
} avdecc_aem_port_flags_t;



/** avdecc_port_flags_init
     *
     *  Initialize a avdecc_aem_port_flags_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_port_flags_init ( avdecc_aem_port_flags_t *self );


/** avdecc_port_flags_read
     *
     *  Read a avdecc_aem_port_flags_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_port_flags_read (
    avdecc_aem_port_flags_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_port_flags_write
     *
     *  write a avdecc_aem_port_flags_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_port_flags_write (
    const avdecc_aem_port_flags_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_audio_port_t
    */

/** See IEEE 1722.1 Clause 7.2.8 */
typedef struct avdecc_aem_descriptor_audio_port_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_port_flags_t port_flags;
    uint16_t audio_channels;
    uint16_t number_of_clusters;
    uint16_t base_cluster;
    uint16_t base_audio_map;
    uint16_t number_of_audio_maps;
} avdecc_aem_descriptor_audio_port_t;



/** avdecc_descriptor_audio_port_init
     *
     *  Initialize a avdecc_aem_descriptor_audio_port_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_audio_port_init ( avdecc_aem_descriptor_audio_port_t *self );


/** avdecc_descriptor_audio_port_read
     *
     *  Read a avdecc_aem_descriptor_audio_port_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_audio_port_read (
    avdecc_aem_descriptor_audio_port_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_audio_port_write
     *
     *  write a avdecc_aem_descriptor_audio_port_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_audio_port_write (
    const avdecc_aem_descriptor_audio_port_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/* \addtogroup aem_descriptor_video_port video_port */
/* @{ */

/* \addtogroup aem_media_format media_format */
/* @{ */

/** avdecc_aem_media_format_t
    */

/** See IEEE 1722.1 Clause 7.3.2 */

typedef struct avdecc_aem_media_format_s
{
    uint64_t raw[2]; /* TODO: */
} avdecc_aem_media_format_t;



/** avdecc_media_format_init
     *
     *  Initialize a avdecc_aem_media_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_media_format_init ( avdecc_aem_media_format_t *self );


/** avdecc_media_format_read
     *
     *  Read a avdecc_aem_media_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_media_format_read (
    avdecc_aem_media_format_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_media_format_write
     *
     *  write a avdecc_aem_media_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_media_format_write (
    const avdecc_aem_media_format_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_video_port_t
    */
#define AVDECC_PDU_AEM_DESCRIPTOR_VIDEO_PORT_MAX_FORMATS (29) /*!< See IEEE 1722.1 Clause 7.2.9 */

/** See IEEE 1722.1 Clause 7.2.9 */
typedef struct avdecc_aem_descriptor_video_port_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_port_flags_t port_flags;
    avdecc_aem_media_format_t current_format;
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
    uint16_t stream_id;
    uint16_t formats_count;
    uint32_t block_latency;
    avdecc_aem_media_format_t formats[AVDECC_PDU_AEM_DESCRIPTOR_VIDEO_PORT_MAX_FORMATS];
} avdecc_aem_descriptor_video_port_t;



/** avdecc_descriptor_video_port_init
     *
     *  Initialize a avdecc_aem_descriptor_video_port_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_video_port_init ( avdecc_aem_descriptor_video_port_t *self );


/** avdecc_descriptor_video_port_read
     *
     *  Read a avdecc_aem_descriptor_video_port_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_video_port_read (
    avdecc_aem_descriptor_video_port_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_video_port_write
     *
     *  write a avdecc_aem_descriptor_video_port_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_video_port_write (
    const avdecc_aem_descriptor_video_port_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_external_port external_port */
/* @{ */

/** avdecc_aem_descriptor_external_port_t
    */

/** See IEEE 1722.1 Clause 7.2.10 */
typedef struct avdecc_aem_descriptor_external_port_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_port_flags_t port_flags;
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
    uint32_t block_latency;
} avdecc_aem_descriptor_external_port_t;



/** avdecc_descriptor_external_port_init
     *
     *  Initialize a avdecc_aem_descriptor_external_port_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_external_port_init ( avdecc_aem_descriptor_external_port_t *self );


/** avdecc_descriptor_external_port_read
     *
     *  Read a avdecc_aem_descriptor_external_port_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_external_port_read (
    avdecc_aem_descriptor_external_port_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_external_port_write
     *
     *  write a avdecc_aem_descriptor_external_port_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_external_port_write (
    const avdecc_aem_descriptor_external_port_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/* \addtogroup aem_descriptor_sensor_port sensor_port */
/* @{ */

/** avdecc_aem_descriptor_sensor_port_t
    */

/** See IEEE 1722.1 Clause 7.2.11 */
typedef struct avdecc_aem_descriptor_sensor_port_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_port_flags_t port_flags;
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
    uint16_t stream_id;
    uint32_t block_latency;
} avdecc_aem_descriptor_sensor_port_t;



/** avdecc_descriptor_sensor_port_init
     *
     *  Initialize a avdecc_aem_descriptor_sensor_port_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_sensor_port_init ( avdecc_aem_descriptor_sensor_port_t *self );


/** avdecc_descriptor_sensor_port_read
     *
     *  Read a avdecc_aem_descriptor_sensor_port_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_sensor_port_read (
    avdecc_aem_descriptor_sensor_port_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_sensor_port_write
     *
     *  write a avdecc_aem_descriptor_sensor_port_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_sensor_port_write (
    const avdecc_aem_descriptor_sensor_port_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_internal_port internal_port */
/* @{ */


/** avdecc_aem_descriptor_internal_port_t
    */

/** See IEEE 1722.1 Clause 7.2.12 */
typedef struct avdecc_aem_descriptor_internal_port_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_port_flags_t port_flags;
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
    uint16_t internal_id;
    uint32_t block_latency;
} avdecc_aem_descriptor_internal_port_t;




/** avdecc_descriptor_internal_port_init
     *
     *  Initialize a avdecc_aem_descriptor_internal_port_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_internal_port_init ( avdecc_aem_descriptor_internal_port_t *self );


/** avdecc_descriptor_internal_port_read
     *
     *  Read a avdecc_aem_descriptor_internal_port_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_internal_port_read (
    avdecc_aem_descriptor_internal_port_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_internal_port_write
     *
     *  write a avdecc_aem_descriptor_internal_port_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_internal_port_write (
    const avdecc_aem_descriptor_internal_port_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_avb_interface avb_interface */
/* @{ */
/* \addtogroup aem_msrp_mappings msrp_mappings */
/* @{ */

/** avdecc_aem_msrp_mappings_t
    */

/** See IEEE 1722.1 Clause 7.2.13.1 */
typedef struct avdecc_aem_msrp_mappings_s
{
    uint8_t traffic_class;
    uint8_t priority;
    uint16_t vlan_id;
} avdecc_aem_msrp_mappings_t;



/** avdecc_msrp_mappings_init
     *
     *  Initialize a avdecc_aem_msrp_mappings_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_msrp_mappings_init ( avdecc_aem_msrp_mappings_t *self );


/** avdecc_msrp_mappings_read
     *
     *  Read a avdecc_aem_msrp_mappings_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_msrp_mappings_read (
    avdecc_aem_msrp_mappings_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_msrp_mappings_write
     *
     *  write a avdecc_aem_msrp_mappings_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_msrp_mappings_write (
    const avdecc_aem_msrp_mappings_t *self,
    void *pdu,
    size_t offset
    );

/* @} */


/** avdecc_aem_descriptor_avb_interface_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_AVB_INTERFACE_MAX_MAPPINGS (105) /*!< See IEEE 1722.1 Clause 7.2.13 */

/** See IEEE 1722.1 Clause 7.2.13 */
typedef struct avdecc_aem_descriptor_avb_interface_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_mac_t mac_address;
    avdecc_eui64_t as_grandmaster_id;
    uint16_t msrp_mappings_count;
    avdecc_string64_t interface_name;
    avdecc_aem_localized_string_ref_t interface_name_string;
    avdecc_aem_msrp_mappings_t msrp_mappings[AVDECC_PDU_AEM_DESCRIPTOR_AVB_INTERFACE_MAX_MAPPINGS];
} avdecc_aem_descriptor_avb_interface_t;



/** avdecc_descriptor_avb_interface_init
     *
     *  Initialize a avdecc_aem_descriptor_avb_interface_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_avb_interface_init ( avdecc_aem_descriptor_avb_interface_t *self );


/** avdecc_descriptor_avb_interface_read
     *
     *  Read a avdecc_aem_descriptor_avb_interface_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_avb_interface_read (
    avdecc_aem_descriptor_avb_interface_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_avb_interface_write
     *
     *  write a avdecc_aem_descriptor_avb_interface_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_avb_interface_write (
    const avdecc_aem_descriptor_avb_interface_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_clock_source clock_source */
/* @{ */

/* \addtogroup aem_clock_source_flags clock_source_flags */
/* @{ */

/** avdecc_aem_clock_source_flags_t
    */

/** See IEEE 1722.1 Clause 7.2.14.1 */

typedef struct avdecc_aem_clock_source_flags_s
{
    bool todo;
} avdecc_aem_clock_source_flags_t;



/** avdecc_clock_source_flags_init
     *
     *  Initialize a avdecc_aem_clock_source_flags_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_clock_source_flags_init ( avdecc_aem_clock_source_flags_t *self );


/** avdecc_clock_source_flags_read
     *
     *  Read a avdecc_aem_clock_source_flags_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_clock_source_flags_read (
    avdecc_aem_clock_source_flags_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_clock_source_flags_write
     *
     *  write a avdecc_aem_clock_source_flags_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_clock_source_flags_write (
    const avdecc_aem_clock_source_flags_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_clock_source_type clock_source_type */
/* @{ */

/** avdecc_aem_clock_source_type_t
    */

/** See IEEE 1722.1 Clause 7.2.14.2 */

typedef enum
{
    avdecc_aem_clock_source_local_oscillator = 0,
    avdecc_aem_clock_source_input_stream,
    avdecc_aem_clock_source_word_clock,
    avdecc_aem_clock_source_analog_input,
    avdecc_aem_clock_source_digital_input,
    avdecc_aem_clock_source_802_1_as,
    avdecc_aem_clock_source_thunderbolt
} avdecc_aem_clock_source_type_t;



/** avdecc_clock_source_type_init
     *
     *  Initialize a avdecc_aem_clock_source_type_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_clock_source_type_init ( avdecc_aem_clock_source_type_t *self );


/** avdecc_clock_source_type_read
     *
     *  Read a avdecc_aem_clock_source_type_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_clock_source_type_read (
    avdecc_aem_clock_source_type_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_clock_source_type_write
     *
     *  write a avdecc_aem_clock_source_type_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_clock_source_type_write (
    const avdecc_aem_clock_source_type_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_descriptor_clock_source_t
    */

/** See IEEE 1722.1 Clause 7.2.14 */

typedef struct avdecc_aem_descriptor_clock_source_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_string64_t clock_source_name;
    avdecc_aem_localized_string_ref_t clock_source_name_string;
    avdecc_aem_clock_source_flags_t clock_source_flags;
    avdecc_aem_clock_source_type_t clock_source_type;
    avdecc_eui64_t clock_source_index;
    uint16_t clock_source_location_type;
    uint16_t clock_source_location_id;
} avdecc_aem_descriptor_clock_source_t;



/** avdecc_descriptor_clock_source_init
     *
     *  Initialize a avdecc_aem_descriptor_clock_source_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_clock_source_init ( avdecc_aem_descriptor_clock_source_t *self );


/** avdecc_descriptor_clock_source_read
     *
     *  Read a avdecc_aem_descriptor_clock_source_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_clock_source_read (
    avdecc_aem_descriptor_clock_source_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_clock_source_write
     *
     *  write a avdecc_aem_descriptor_clock_source_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_clock_source_write (
    const avdecc_aem_descriptor_clock_source_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/* \addtogroup aem_descriptor_audio_map audio_map */
/* @{ */

/* \addtogroup aem_audio_mapping audio_mapping */
/* @{ */

/** avdecc_aem_audio_mapping_t
    */

/** See IEEE 1722.1 Clause 7.2.15.1 */

typedef struct avdecc_aem_audio_mapping_s
{
    uint16_t mapping_stream_index;
    uint16_t mapping_stream_channel;
    uint16_t mapping_audio_channel;
} avdecc_aem_audio_mapping_t;



/** avdecc_audio_mapping_init
     *
     *  Initialize a avdecc_aem_audio_mapping_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_audio_mapping_init ( avdecc_aem_audio_mapping_t *self );


/** avdecc_audio_mapping_read
     *
     *  Read a avdecc_aem_audio_mapping_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_audio_mapping_read (
    avdecc_aem_audio_mapping_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_audio_mapping_write
     *
     *  write a avdecc_aem_audio_mapping_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_audio_mapping_write (
    const avdecc_aem_audio_mapping_t *self,
    void *pdu,
    size_t offset
    );
/* @} */

/** avdecc_aem_descriptor_audio_map_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAP_MAX_MAPPINGS (83) /*!< See IEEE 1722.1 Clause 7.2.26 */

/** See IEEE 1722.1 Clause 7.2.15 */
typedef struct avdecc_aem_descriptor_audio_map_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t number_of_mappings;
    avdecc_aem_audio_mapping_t mappings[AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAP_MAX_MAPPINGS];
} avdecc_aem_descriptor_audio_map_t;


/** avdecc_descriptor_audio_map_init
     *
     *  Initialize a avdecc_aem_descriptor_audio_map_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_audio_map_init ( avdecc_aem_descriptor_audio_map_t *self );


/** avdecc_descriptor_audio_map_read
     *
     *  Read a avdecc_aem_descriptor_audio_map_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_audio_map_read (
    avdecc_aem_descriptor_audio_map_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_audio_map_write
     *
     *  write a avdecc_aem_descriptor_audio_map_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_audio_map_write (
    const avdecc_aem_descriptor_audio_map_t *self,
    void *pdu,
    size_t offset
    );

/* @} */
/* \addtogroup aem_descriptor_audio_cluster audio_cluster */
/* @{ */

/** avdecc_aem_descriptor_audio_cluster_t
    */

/** See IEEE 1722.1 Clause 7.2.16 */

typedef struct avdecc_aem_descriptor_audio_cluster_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t channel_count;
    uint32_t latency;
    uint8_t am824_label;
    avdecc_string64_t cluster_name;
    avdecc_aem_localized_string_ref_t cluster_name_string;
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
    uint32_t block_latency;
} avdecc_aem_descriptor_audio_cluster_t;



/** avdecc_descriptor_audio_cluster_init
     *
     *  Initialize a avdecc_aem_descriptor_audio_cluster_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_audio_cluster_init ( avdecc_aem_descriptor_audio_cluster_t *self );


/** avdecc_descriptor_audio_cluster_read
     *
     *  Read a avdecc_aem_descriptor_audio_cluster_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_audio_cluster_read (
    avdecc_aem_descriptor_audio_cluster_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_audio_cluster_write
     *
     *  write a avdecc_aem_descriptor_audio_cluster_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_audio_cluster_write (
    const avdecc_aem_descriptor_audio_cluster_t *self,
    void *pdu,
    size_t offset
    );

/* @} */

/** avdecc_aem_control_type_t
    */

#define AVDECC_PDU_AEM_CONTROL_DESCRIPTOR_MAX_PAYLOAD_SIZE (406) /** See IEEE 1722.1 Clause 7.2.17 */

/** See IEEE 1722.1 D19 Clause 7.3.4 */
static const uint64_t avdecc_aem_control_type_enable = 0x90e0f00000000ULL; /*!< enable or disable the unit or entity. */
static const uint64_t avdecc_aem_control_type_delay = 0x90e0f00000001ULL; /*!< apply a delay to the signal. */
static const uint64_t avdecc_aem_control_type_pow_line_freq = 0x90e0f00000002ULL; /*!< power line frequency. */
static const uint64_t avdecc_aem_control_type_orientation_abs = 0x90e0f00000003ULL; /*!< orientation absolute. */
static const uint64_t avdecc_aem_control_type_orientation_rel = 0x90e0f00000004ULL; /*!< orientation relative. */

static const uint64_t avdecc_aem_control_type_power_status = 0x90e0f00000006ULL; /*!< system power supply status. */
static const uint64_t avdecc_aem_control_type_fan_status = 0x90e0f00000007ULL; /*!< system fan status. */
static const uint64_t avdecc_aem_control_type_temperature = 0x90e0f00000008ULL; /*!< temperature setting. */
static const uint64_t avdecc_aem_control_type_temperature_sensor = 0x90e0f00000009ULL; /*!< temperature sensor. */
static const uint64_t avdecc_aem_control_type_altitude = 0x90e0f0000000aULL; /*!< altitude. */
static const uint64_t avdecc_aem_control_type_humidity = 0x90e0f0000000bULL; /*!< humidity. */
static const uint64_t avdecc_aem_control_type_invert = 0x90e0f0001000cULL; /*!< invert the signal polarity. */
static const uint64_t avdecc_aem_control_type_accelerate_abs = 0x90e0f0001000dULL; /*!< Accelerate absolute */
static const uint64_t avdecc_aem_control_type_accelerate_rel = 0x90e0f0001000eULL; /*!< Accelerate relative */
static const uint64_t avdecc_aem_control_type_velocity_abs = 0x90e0f0001000fULL; /*!< Velocity absolute */
static const uint64_t avdecc_aem_control_type_velocity_rel = 0x90e0f00010010ULL; /*!< Velocity relative */
static const uint64_t avdecc_aem_control_type_mute = 0x90e0f00010000ULL; /*!< mute the audio. */
static const uint64_t avdecc_aem_control_type_volume = 0x90e0f00010001ULL; /*!< adjust the volume. */
static const uint64_t avdecc_aem_control_type_panpot = 0x90e0f00010002ULL; /*!< stereo pan position. */
static const uint64_t avdecc_aem_control_type_position = 0x90e0f00010003ULL; /*!< set three dimensional position. */
static const uint64_t avdecc_aem_control_type_phantom = 0x90e0f00010004ULL; /*!< set phantom power for analog or digital microphones. */
static const uint64_t avdecc_aem_control_type_audio_scale = 0x90e0f00010005ULL; /*!< select analog audio scale. */
static const uint64_t avdecc_aem_control_type_audio_metres = 0x90e0f00010006ULL; /*!< audio meter values. */
static const uint64_t avdecc_aem_control_type_audio_spectrum = 0x90e0f00010007ULL; /*!< audio signal spectrum values. */
static const uint64_t avdecc_aem_control_type_filter_response = 0x90e0f00010008ULL; /*!< filter response bode plot values. */
static const uint64_t avdecc_aem_control_type_scanning_mode = 0x90e0f00020000ULL; /*!< video scanning mode. */
static const uint64_t avdecc_aem_control_type_auto_exp_mode = 0x90e0f00020001ULL; /*!< auto-exposure mode. */
static const uint64_t avdecc_aem_control_type_auto_exp_prio = 0x90e0f00020002ULL; /*!< auto-exposure priority */
static const uint64_t avdecc_aem_control_type_exp_time_abs = 0x90e0f00020003ULL; /*!< exposure time absolute */
static const uint64_t avdecc_aem_control_type_exp_time_rel = 0x90e0f00020004ULL; /*!< exposure time relative */
static const uint64_t avdecc_aem_control_type_focus_abs = 0x90e0f00020005ULL; /*!< focus absolute. */
static const uint64_t avdecc_aem_control_type_focus_rel = 0x90e0f00020006ULL; /*!< focus relative. */
static const uint64_t avdecc_aem_control_type_focus_auto = 0x90e0f00020007ULL; /*!< focus automatic. */
static const uint64_t avdecc_aem_control_type_iris_abs = 0x90e0f00020008ULL; /*!< iris absolute. */
static const uint64_t avdecc_aem_control_type_iris_rel = 0x90e0f00020009ULL; /*!< iris relative. */
static const uint64_t avdecc_aem_control_type_zoom_abs = 0x90e0f0002000aULL; /*!< zoom absolute. */
static const uint64_t avdecc_aem_control_type_zoom_rel = 0x90e0f0002000bULL; /*!< zoom relative. */
static const uint64_t avdecc_aem_control_type_privacy = 0x90e0f0002000cULL; /*!< privacy. */
static const uint64_t avdecc_aem_control_type_backlight = 0x90e0f0002000dULL; /*!< backlight compensation. */
static const uint64_t avdecc_aem_control_type_brightness = 0x90e0f0002000eULL; /*!< brightness. */
static const uint64_t avdecc_aem_control_type_contrast = 0x90e0f0002000fULL; /*!< contrast. */
static const uint64_t avdecc_aem_control_type_gain = 0x90e0f00020010ULL; /*!< gain */
static const uint64_t avdecc_aem_control_type_hue = 0x90e0f00020011ULL; /*!< hue */
static const uint64_t avdecc_aem_control_type_saturation = 0x90e0f00020012ULL; /*!< saturation. */
static const uint64_t avdecc_aem_control_type_sharpness = 0x90e0f00020013ULL; /*!< sharpness */
static const uint64_t avdecc_aem_control_type_gamma = 0x90e0f00020014ULL; /*!< gamma. */
static const uint64_t avdecc_aem_control_type_white_bal_temp = 0x90e0f00020015ULL; /*!< white balance temperature. */
static const uint64_t avdecc_aem_control_type_white_bal_temp_auto = 0x90e0f00020016ULL; /*!< white balance temperature auto. */
static const uint64_t avdecc_aem_control_type_white_bal_comp = 0x90e0f00020017ULL; /*!< white balance components. */
static const uint64_t avdecc_aem_control_type_white_bal_comp_auto = 0x90e0f00020018ULL; /*!< white balance components auto. */
static const uint64_t avdecc_aem_control_type_digital_zoom = 0x90e0f00020019ULL;/*!< digital zoom. */

typedef uint64_t avdecc_aem_control_type_t;

/** avdecc_control_type_init
     *
     *  Initialize a avdecc_aem_control_type_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_control_type_init ( avdecc_aem_control_type_t *self );


/** avdecc_control_type_read
     *
     *  Read a avdecc_aem_control_type_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_control_type_read (
    avdecc_aem_control_type_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_control_type_write
     *
     *  write a avdecc_aem_control_type_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_control_type_write (
    const avdecc_aem_control_type_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_units_t
    */

/** See IEEE 1722.1 D19 Clause 7.3.3 */
enum avdecc_aem_unit_t
{
    // Unitless - See 7.3.3.1
    avdecc_aem_unit_none=0x00, /*!< "", "Unitless" */
    avdecc_aem_unit_inc_count =0x01, /*!< "", "Incrementing Count" */
    avdecc_aem_unit_percentage =0x02, /*!< "%", "Percentage" */
    avdecc_aem_unit_fstop =0x03, /*!< "", "fstop" */
    // Time - See 7.3.3.2
    avdecc_aem_unit_time_seconds=0x08, /*!< "s", "Time in seconds" */
    avdecc_aem_unit_time_minutes=0x09, /*!< "m", "Time in minutes" */
    avdecc_aem_unit_time_hours =0x0a, /*!< "h", "Time in hours" */
    avdecc_aem_unit_time_days =0x0b, /*!< "d", "Time in days" */
    avdecc_aem_unit_time_months =0x0c, /*!< "M", "Time in months" */
    avdecc_aem_unit_time_years =0x0d, /*!< "Y", "Time in years" */
    avdecc_aem_unit_time_samples =0x0e, /*!< "samples", "Time in audio samples" */
    avdecc_aem_unit_time_frames =0x0f, /*!< "f", "Time in video/film frames" */
    // Frequency - See 7.3.3.3
    avdecc_aem_unit_freq_hz =0x10, /*!< "Hz", "Frequency in Hertz" */
    avdecc_aem_unit_freq_note =0x11, /*!< "Note", "Frequency in MIDI note value (semitones)" */
    avdecc_aem_unit_freq_cents =0x12, /*!< "Cent", "Frequency in Cents" */
    avdecc_aem_unit_freq_octaves =0x13, /*!< "Octave", "Frequency in Octaves" */
    // Distance - See 7.3.3.4
    avdecc_aem_unit_distance_meteres =0x18, /*!< "m", "Distance in metres" */
    // Temperature - See 7.3.3.5
    avdecc_aem_unit_temperature_kelvin =0x20, /*!< "K", "Temperature in kelvin" */
    // Mass - See 7.3.3.6
    avdecc_aem_unit_mass_grams =0x28, /*!< "gram", "Grams" */
    // Voltage - See 7.3.3.7
    avdecc_aem_unit_voltage_volts =0x30, /*!< "V", "Voltage in volts" */
    avdecc_aem_unit_voltage_dbv =0x31, /*!< "dBV", "Voltage in dBV" */
    avdecc_aem_unit_voltage_dbu =0x32, /*!< "dBu", "Voltage in dBu" */
    // Current - See 7.3.3.8
    avdecc_aem_unit_current_amperes =0x38, /*!< "A", "Electric current in amperes" */
    // Power - See 7.3.3.9
    avdecc_aem_unit_power_watts =0x40, /*!< "W", "Electric power in watts" */
    avdecc_aem_unit_power_dbm =0x41, /*!< "dBm", "Signal power in dBm" */
    avdecc_aem_unit_power_dbw =0x42, /*!< "dBW", "Signal power in dBW" */
    // Pressure - See 7.3.3.10
    avdecc_aem_unit_pressure_pascals =0x48, /*!< "Pa", "Pressure in pascals" */
    // Memory - See 7.3.3.11
    avdecc_aem_unit_mem_bits =0x50, /*!< "b", "Bit count" */
    avdecc_aem_unit_mem_bytes =0x51, /*!< "B", "Byte count" */
    avdecc_aem_unit_mem_kibibytes =0x52, /*!< "KiB", "Kibibyte count" */
    avdecc_aem_unit_mem_mebibytes =0x53, /*!< "MiB", "Mebibyte count" */
    avdecc_aem_unit_mem_gibibytes =0x54, /*!< "GiB", "Gibibyte count" */
    avdecc_aem_unit_mem_tebibytes =0x55, /*!< "TiB", "Tebibyte count" */
    // Bandwidth - See 7.3.3.12
    avdecc_aem_unit_bw_bits_per_second =0x58, /*!< "b/s", "Bits per second" */
    avdecc_aem_unit_bw_bytes_per_second =0x59, /*!< "B/s", "Bytes per second" */
    avdecc_aem_unit_bw_kibibytes_per_second =0x5a, /*!< "KiB/s", "Kibibytes per second" */
    avdecc_aem_unit_bw_mebibytes_per_second =0x5b, /*!< "MiB/s", "Mebibytes per second" */
    avdecc_aem_unit_bw_gibibytes_per_second =0x5c, /*!< "GiB/s", "Gibibytes per second" */
    avdecc_aem_unit_bw_tebibytes_per_second =0x5d, /*!< "TiB/s", "Tebibytes per second" */
    // Luminosity - See 7.3.3.13
    avdecc_aem_unit_luminosity_candela =0x60, /*!< "cd", "Candela" */
    // Energy - See 7.3.3.14
    avdecc_aem_unit_energy_joules =0x68, /*!< "J", "Joules" */
    // Angle - See 7.3.3.15
    avdecc_aem_unit_angle_radians =0x70, /*!< "rad", "Radians" */
    // Force - See 7.3.3.16
    avdecc_aem_unit_force_newtons =0x78, /*!< "N", "Newtons" */
    // Resistance - See 7.3.3.17
    avdecc_aem_unit_resistance_ohms =0x80, /*!< "Ω", "Ohms" */
    // Velocity - See 7.3.3.18
    avdecc_aem_unit_velocity_metres_per_second =0x88, /*!< "m/s", "Meters per second" */
    avdecc_aem_unit_angular_velocity_radians_per_second =0x89, /*!< "rad/s", "Angular velocity in radians per second" */
    // Acceleration - See 7.3.3.19
    avdecc_aem_unit_acceleration_metres_per_second_per_second  =0x90, /* "m/s·s", "Meters per second per second" */
    avdecc_aem_unit_acceleration_rad_per_second_per_second  =0x91, /* "rad/s·s", "Radians per second per second" */
    // Magnetic Flux - See 7.3.3.20
    avdecc_aem_unit_magnetic_flux_tesla =0x98, /*!< "T", "Tesla" */
    // Area - See 7.3.3.21
    avdecc_aem_unit_area_metres_squared =0xa0, /*!< "m·m", "Meters squared" */
    // Volume - See 7.3.3.22
    avdecc_aem_unit_volume_metres_cubed =0xa8, /*!< "m·m·m", "Meters cubed" */
    avdecc_aem_unit_volume_litres =0xa9, /*!< "l", "Litres" */
    // Levels and Loudness - See 7.3.3.23
    avdecc_aem_unit_level_db =0xb0, /*!< "dB", "Level or gain in decibels" */
    avdecc_aem_unit_level_db_peak =0xb1, /*!< "dB (Peak)", "'Peak' level or gain in decibels */
    avdecc_aem_unit_level_db_rms =0xb2, /*!< "dB (RMS)", "'RMS' level in decibels */
    avdecc_aem_unit_level_dbfs =0xb3, /*!< "dBFS", "Full scale level in decibels" */
    avdecc_aem_unit_level_dbfs_peak =0xb4, /*!< "dBFS (Peak)", "Full scale 'peak' level in decibels" */
    avdecc_aem_unit_level_dbfs_rms =0xb5, /*!< "dBFS (RMS)", "Full scale 'RMS' level in decibels" */
    avdecc_aem_unit_level_dbtp =0xb6, /*!< "dBTP", "True peak level in decibels" */
    avdecc_aem_unit_level_dba =0xb7, /*!< "dB(A)", "A-weighted level in decibels" */
    avdecc_aem_unit_level_dbb =0xb8, /*!< "dB(B)", "B-weighted level in decibels" */
    avdecc_aem_unit_level_dbc =0xb9, /*!< "dB(C)", "C-weighted level in decibels" */
    avdecc_aem_unit_level_dbspl =0xba, /*!< "dB(SPL)", "Sound pressure level in decibels" */
    avdecc_aem_unit_level_lu =0xbb, /*!< "LU", "ITU-R. BS. 1770-2 loudness level" */
    avdecc_aem_unit_level_lufs =0xbc /*!< "LUFS", "ITU-R. BS. 1770-2 full scale loudness level" */
};

extern const char *avdecc_aem_units_symbol[256];


/** avdecc_units_init
     *
     *  Initialize a avdecc_aem_units_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_units_init ( avdecc_aem_unit_t *self );


/** avdecc_units_read
     *
     *  Read a avdecc_aem_units_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_units_read (
    avdecc_aem_unit_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_units_write
     *
     *  write a avdecc_aem_units_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_units_write (
    const avdecc_aem_unit_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_control_value_type_t
    */

/** See IEEE 1722.1 Clause 7.2.17.1 */

typedef enum
{
    avdecc_aem_control_linear_int8 = 0x0000,
    avdecc_aem_control_linear_uint8 = 0x0001,
    avdecc_aem_control_linear_int16 = 0x0002,
    avdecc_aem_control_linear_uint16 = 0x0003,
    avdecc_aem_control_linear_int32 = 0x0004,
    avdecc_aem_control_linear_uint32 = 0x0005,
    avdecc_aem_control_linear_int64 = 0x0006,
    avdecc_aem_control_linear_uint64 = 0x0007,
    avdecc_aem_control_linear_float = 0x0008,
    avdecc_aem_control_linear_double = 0x0009,
    avdecc_aem_control_selector_int8 = 0x000a,
    avdecc_aem_control_selector_uint8 = 0x000b,
    avdecc_aem_control_selector_int16 = 0x000c,
    avdecc_aem_control_selector_uint16 = 0x000d,
    avdecc_aem_control_selector_int32 = 0x000e,
    avdecc_aem_control_selector_uint32 = 0x000f,
    avdecc_aem_control_selector_int64 = 0x0010,
    avdecc_aem_control_selector_uint64 = 0x0011,
    avdecc_aem_control_selector_float = 0x0012,
    avdecc_aem_control_selector_double = 0x0013,
    avdecc_aem_control_utf8 = 0x0014,
    avdecc_aem_control_bode_plot = 0x0015,
    avdecc_aem_control_array_int8 = 0x0016,
    avdecc_aem_control_array_uint8 = 0x0017,
    avdecc_aem_control_array_int16 = 0x0018,
    avdecc_aem_control_array_uint16 = 0x0019,
    avdecc_aem_control_array_int32 = 0x001a,
    avdecc_aem_control_array_uint32 = 0x001b,
    avdecc_aem_control_array_int64 = 0x001c,
    avdecc_aem_control_array_uint64 = 0x001d,
    avdecc_aem_control_array_float = 0x001e,
    avdecc_aem_control_array_double = 0x001f,
    avdecc_aem_control_selector_string = 0x0020,
    avdecc_aem_control_vendor = 0xfffe,
    avdecc_aem_control_expansion = 0xffff
} avdecc_aem_control_value_type_t;


/** avdecc_control_value_type_init
     *
     *  Initialize a avdecc_aem_control_value_type_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_control_value_type_init ( avdecc_aem_control_value_type_t *self );


/** avdecc_control_value_type_read
     *
     *  Read a avdecc_aem_control_value_type_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_control_value_type_read (
    avdecc_aem_control_value_type_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_control_value_type_write
     *
     *  write a avdecc_aem_control_value_type_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_control_value_type_write (
    const avdecc_aem_control_value_type_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_control_value_type_linear_format_int8_t
    */

/** See IEEE 1722.1 Clause 7.2.17.2.1 */

template <typename T>
struct avdecc_aem_control_value_type_linear_format_t
{
    typedef T value_type;

    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    T m_minimum;
    T m_maximum;
    T m_step;
    T m_default;
    T m_current;
    avdecc_aem_unit_t m_unit;
    int8_t m_multiplier;
    uint16_t m_string;
};

typedef avdecc_aem_control_value_type_linear_format_t<int8_t> avdecc_aem_control_value_type_linear_format_int8_t;
typedef avdecc_aem_control_value_type_linear_format_t<uint8_t> avdecc_aem_control_value_type_linear_format_uint8_t;
typedef avdecc_aem_control_value_type_linear_format_t<int16_t> avdecc_aem_control_value_type_linear_format_int16_t;
typedef avdecc_aem_control_value_type_linear_format_t<uint16_t> avdecc_aem_control_value_type_linear_format_uint16_t;
typedef avdecc_aem_control_value_type_linear_format_t<int32_t> avdecc_aem_control_value_type_linear_format_int32_t;
typedef avdecc_aem_control_value_type_linear_format_t<uint32_t> avdecc_aem_control_value_type_linear_format_uint32_t;
typedef avdecc_aem_control_value_type_linear_format_t<int64_t> avdecc_aem_control_value_type_linear_format_int64_t;
typedef avdecc_aem_control_value_type_linear_format_t<uint64_t> avdecc_aem_control_value_type_linear_format_uint64_t;
typedef avdecc_aem_control_value_type_linear_format_t<float> avdecc_aem_control_value_type_linear_format_float_t;
typedef avdecc_aem_control_value_type_linear_format_t<double> avdecc_aem_control_value_type_linear_format_double_t;



#define AVDECC_PDU_AEM_CONTROL_SELECTOR_MAX_OPTIONS(item_size) \
    (((AVDECC_PDU_AEM_CONTROL_DESCRIPTOR_MAX_PAYLOAD_SIZE) - (2+(2*(item_size))))/(item_size)) /*!< See IEEE 1722.1 Clause 7.2.17.2.1 */

template <typename T>
struct avdecc_aem_control_value_type_selector_traits
{
    enum { max_options = AVDECC_PDU_AEM_CONTROL_SELECTOR_MAX_OPTIONS(sizeof(T)) };
};

template <>
struct avdecc_aem_control_value_type_selector_traits< avdecc_aem_localized_string_ref_t >
{
    enum { max_options = AVDECC_PDU_AEM_CONTROL_SELECTOR_MAX_OPTIONS(sizeof(uint16_t)) };
};



template <typename T>
struct avdecc_aem_control_value_type_selector_format_t
{
    typedef T value_type;

    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    T m_current;
    T m_default;
    uint16_t m_number_of_options;
    T m_option[ avdecc_aem_control_value_type_selector_traits<T>::max_options ];
    avdecc_aem_unit_t m_unit;
    int8_t m_multiplier;
};


typedef avdecc_aem_control_value_type_selector_format_t<int8_t> avdecc_aem_control_value_type_selector_format_int8_t;
typedef avdecc_aem_control_value_type_selector_format_t<uint8_t> avdecc_aem_control_value_type_selector_format_uint8_t;
typedef avdecc_aem_control_value_type_selector_format_t<int16_t> avdecc_aem_control_value_type_selector_format_int16_t;
typedef avdecc_aem_control_value_type_selector_format_t<uint16_t> avdecc_aem_control_value_type_selector_format_uint16_t;
typedef avdecc_aem_control_value_type_selector_format_t<int32_t> avdecc_aem_control_value_type_selector_format_int32_t;
typedef avdecc_aem_control_value_type_selector_format_t<uint32_t> avdecc_aem_control_value_type_selector_format_uint32_t;
typedef avdecc_aem_control_value_type_selector_format_t<int64_t> avdecc_aem_control_value_type_selector_format_int64_t;
typedef avdecc_aem_control_value_type_selector_format_t<uint64_t> avdecc_aem_control_value_type_selector_format_uint64_t;
typedef avdecc_aem_control_value_type_selector_format_t<float> avdecc_aem_control_value_type_selector_format_float_t;
typedef avdecc_aem_control_value_type_selector_format_t<double> avdecc_aem_control_value_type_selector_format_double_t;
typedef avdecc_aem_control_value_type_selector_format_t<avdecc_aem_localized_string_ref_t> avdecc_aem_control_value_type_selector_format_string_t;


/** avdecc_aem_control_value_type_utf8_format_t
    */

#define AVDECC_PDU_AEM_CONTROL_UTF_MAX_LEN (AVDECC_PDU_AEM_CONTROL_DESCRIPTOR_MAX_PAYLOAD_SIZE)

/** See IEEE 1722.1 Clause 7.2.17.2.3 */

struct avdecc_aem_control_value_type_utf8_format_t
{
    avdecc_aem_control_value_type_utf8_format_t()
        :
          m_length(0)
    {
        memset(m_string,0,sizeof(m_string));
    }

    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    int16_t m_length;
    char m_string[ AVDECC_PDU_AEM_CONTROL_UTF_MAX_LEN ];
};



/** avdecc_aem_control_value_type_bode_plot_limits_t
    */

/** See IEEE 1722.1 Clause 7.2.17.2.4 */

struct avdecc_aem_control_value_type_bode_plot_limits_t
{
    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    float m_minimum;
    float m_maximum;
    float m_step;
    float m_default;
};


/** avdecc_aem_control_value_type_bode_plot_entry_t
    */

/** See IEEE 1722.1 Clause 7.2.17.2.4 */

struct avdecc_aem_control_value_type_bode_plot_entry_t
{
    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    float m_frequency;
    float m_mag;
    float m_phase;
};


/** avdecc_aem_control_value_type_bode_plot_format_t
    */

#define AVDECC_PDU_AEM_CONTROL_BODE_PLOT_MAX_ITEMS ((AVDECC_PDU_AEM_CONTROL_DESCRIPTOR_MAX_PAYLOAD_SIZE - (3*4*4))/(3*4))

struct avdecc_aem_control_value_type_bode_plot_format_t
{
    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    avdecc_aem_control_value_type_bode_plot_limits_t m_frequency;
    avdecc_aem_control_value_type_bode_plot_limits_t m_magnitude;
    avdecc_aem_control_value_type_bode_plot_limits_t m_phase;
    uint16_t m_number_of_items;
    avdecc_aem_control_value_type_bode_plot_entry_t m_current[ AVDECC_PDU_AEM_CONTROL_BODE_PLOT_MAX_ITEMS ];
};



#define AVDECC_PDU_AEM_CONTROL_ARRAY_MAX_ITEMS(item_size) \
    (((AVDECC_PDU_AEM_CONTROL_DESCRIPTOR_MAX_PAYLOAD_SIZE) - (4+(3*(item_size))))/(item_size)) /** See IEEE 1722.1 Clause 7.2.17.2.5 */

template <typename T>
struct avdecc_aem_control_value_type_array_traits
{
    enum { max_items = AVDECC_PDU_AEM_CONTROL_ARRAY_MAX_ITEMS(sizeof(T)) };
};

/** See IEEE 1722.1 Clause 7.2.17.2.5 */

template <typename T>
struct avdecc_aem_control_value_type_array_format_t
{
    typedef T value_type;

    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    uint16_t m_array_size;
    T m_minimum;
    T m_maximum;
    T m_step;
    T m_default;
    avdecc_aem_unit_t m_unit;
    T m_current[ avdecc_aem_control_value_type_array_traits<T>::max_items ];
    int8_t m_multiplier;
    uint16_t m_string;
};


typedef avdecc_aem_control_value_type_array_format_t<int8_t> avdecc_aem_control_value_type_array_format_int8_t;
typedef avdecc_aem_control_value_type_array_format_t<uint8_t> avdecc_aem_control_value_type_array_format_uint8_t;
typedef avdecc_aem_control_value_type_array_format_t<int16_t> avdecc_aem_control_value_type_array_format_int16_t;
typedef avdecc_aem_control_value_type_array_format_t<uint16_t> avdecc_aem_control_value_type_array_format_uint16_t;
typedef avdecc_aem_control_value_type_array_format_t<int32_t> avdecc_aem_control_value_type_array_format_int32_t;
typedef avdecc_aem_control_value_type_array_format_t<uint32_t> avdecc_aem_control_value_type_array_format_uint32_t;
typedef avdecc_aem_control_value_type_array_format_t<int64_t> avdecc_aem_control_value_type_array_format_int64_t;
typedef avdecc_aem_control_value_type_array_format_t<uint64_t> avdecc_aem_control_value_type_array_format_uint64_t;
typedef avdecc_aem_control_value_type_array_format_t<float> avdecc_aem_control_value_type_array_format_float_t;
typedef avdecc_aem_control_value_type_array_format_t<double> avdecc_aem_control_value_type_array_format_double_t;


/** avdecc_aem_control_value_type_vendor_format_t
    */

#define AVDECC_PDU_AEM_CONTROL_VENDOR_FORMAT_MAX_BLOB (394) /*!< See IEEE 1722 D18 Clause 7.2.17.2.9 */

/** See IEEE 1722.1 Clause 7.2.17.2.6 */

typedef struct avdecc_aem_control_value_type_vendor_format_s
{
    avdecc_eui64_t guid;
    int16_t blob_length;
    uint8_t blob[ AVDECC_PDU_AEM_CONTROL_VENDOR_FORMAT_MAX_BLOB ];
} avdecc_aem_control_value_type_vendor_format_t;



/** avdecc_control_value_type_vendor_format_init
     *
     *  Initialize a avdecc_aem_control_value_type_vendor_format_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_control_value_type_vendor_format_init ( avdecc_aem_control_value_type_vendor_format_t *self );


/** avdecc_control_value_type_vendor_format_read
     *
     *  Read a avdecc_aem_control_value_type_vendor_format_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_control_value_type_vendor_format_read (
    avdecc_aem_control_value_type_vendor_format_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_control_value_type_vendor_format_write
     *
     *  write a avdecc_aem_control_value_type_vendor_format_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_control_value_type_vendor_format_write (
    const avdecc_aem_control_value_type_vendor_format_t *self,
    void *pdu,
    size_t offset
    );

/** avdecc_aem_control_value_format_union_t */

typedef union avdecc_aem_control_value_format_union_s
{
    avdecc_aem_control_value_type_linear_format_int8_t linear_int8;
    avdecc_aem_control_value_type_linear_format_uint8_t linear_uint8;
    avdecc_aem_control_value_type_linear_format_int16_t linear_int16;
    avdecc_aem_control_value_type_linear_format_uint16_t linear_uint16;
    avdecc_aem_control_value_type_linear_format_int32_t linear_int32;
    avdecc_aem_control_value_type_linear_format_uint32_t linear_uint32;
    avdecc_aem_control_value_type_linear_format_int64_t linear_int64;
    avdecc_aem_control_value_type_linear_format_uint64_t linear_uint64;
    avdecc_aem_control_value_type_linear_format_float_t linear_float;
    avdecc_aem_control_value_type_linear_format_double_t linear_double;

    avdecc_aem_control_value_type_bode_plot_format_t bode_plot;

    avdecc_aem_control_value_type_selector_format_int8_t selector_int8;
    avdecc_aem_control_value_type_selector_format_uint8_t selector_uint8;
    avdecc_aem_control_value_type_selector_format_int16_t selector_int16;
    avdecc_aem_control_value_type_selector_format_uint16_t selector_uint16;
    avdecc_aem_control_value_type_selector_format_int32_t selector_int32;
    avdecc_aem_control_value_type_selector_format_uint32_t selector_uint32;
    avdecc_aem_control_value_type_selector_format_int64_t selector_int64;
    avdecc_aem_control_value_type_selector_format_uint64_t selector_uint64;
    avdecc_aem_control_value_type_selector_format_float_t selector_float;
    avdecc_aem_control_value_type_selector_format_double_t selector_double;

    avdecc_aem_control_value_type_array_format_int8_t array_int8;
    avdecc_aem_control_value_type_array_format_uint8_t array_uint8;
    avdecc_aem_control_value_type_array_format_int16_t array_int16;
    avdecc_aem_control_value_type_array_format_uint16_t array_uint16;
    avdecc_aem_control_value_type_array_format_int32_t array_int32;
    avdecc_aem_control_value_type_array_format_uint32_t array_uint32;
    avdecc_aem_control_value_type_array_format_int64_t array_int64;
    avdecc_aem_control_value_type_array_format_uint64_t array_uint64;
    avdecc_aem_control_value_type_array_format_float_t array_float;
    avdecc_aem_control_value_type_array_format_double_t array_double;

    avdecc_aem_control_value_type_selector_format_string_t selector_string;

    avdecc_aem_control_value_type_vendor_format_t vendor;
} avdecc_aem_control_value_format_union_t;


typedef union avdecc_aem_control_value_union_s
{
    int8_t linear_int8;
    uint8_t linear_uint8;
    int16_t linear_int16;
    uint16_t linear_uint16;
    int32_t linear_int32;
    uint32_t linear_uint32;
    int64_t linear_int64;
    uint64_t linear_uint64;
    float linear_float;
    double linear_double;

    avdecc_aem_control_value_type_bode_plot_entry_t bode_plot[ AVDECC_PDU_AEM_CONTROL_BODE_PLOT_MAX_ITEMS ];

    int8_t selector_int8[ avdecc_aem_control_value_type_selector_traits<int8_t>::max_options ];
    uint8_t selector_uint8[ avdecc_aem_control_value_type_selector_traits<uint8_t>::max_options ];
    int16_t selector_int16[ avdecc_aem_control_value_type_selector_traits<int16_t>::max_options ];
    uint16_t selector_uint16[ avdecc_aem_control_value_type_selector_traits<uint16_t>::max_options ];
    int32_t selector_int32[ avdecc_aem_control_value_type_selector_traits<int32_t>::max_options ];
    uint32_t selector_uint32[ avdecc_aem_control_value_type_selector_traits<uint32_t>::max_options ];
    int64_t selector_int64[ avdecc_aem_control_value_type_selector_traits<int64_t>::max_options ];
    uint64_t selector_uint64[ avdecc_aem_control_value_type_selector_traits<uint64_t>::max_options ];
    float selector_float[ avdecc_aem_control_value_type_selector_traits<float>::max_options ];
    double selector_double[ avdecc_aem_control_value_type_selector_traits<double>::max_options ];

    int8_t array_int8[ avdecc_aem_control_value_type_array_traits<int8_t>::max_items ];
    uint8_t array_uint8[ avdecc_aem_control_value_type_array_traits<uint8_t>::max_items ];
    int16_t array_int16[ avdecc_aem_control_value_type_array_traits<int16_t>::max_items ];
    uint16_t array_uint16[ avdecc_aem_control_value_type_array_traits<uint16_t>::max_items ];
    int32_t array_int32[ avdecc_aem_control_value_type_array_traits<int32_t>::max_items ];
    uint32_t array_uint32[ avdecc_aem_control_value_type_array_traits<uint32_t>::max_items ];
    int64_t array_int64[ avdecc_aem_control_value_type_array_traits<int64_t>::max_items ];
    uint64_t array_uint64[ avdecc_aem_control_value_type_array_traits<uint64_t>::max_items ];
    float array_float[ avdecc_aem_control_value_type_array_traits<float>::max_items ];
    double array_double[ avdecc_aem_control_value_type_array_traits<double>::max_items ];

    uint16_t selector_string[ avdecc_aem_control_value_type_selector_traits<avdecc_aem_localized_string_ref_t>::max_options ];
    uint8_t vendor[ AVDECC_PDU_AEM_CONTROL_VENDOR_FORMAT_MAX_BLOB ];
} avdecc_aem_control_value_union_t;


/** avdecc_aem_descriptor_control_t
    */

/** See IEEE 1722.1 Clause 7.2.17 */

struct avdecc_aem_descriptor_control_t
{
    avdecc_aem_descriptor_control_t()
        : m_descriptor_type(avdecc_aem_descriptor_control),
          m_descriptor_index(0),
          m_read_only(false),
          m_unknown_value(false),
          m_control_type(avdecc_aem_control_type_enable),
          m_control_location_id(0),
          m_control_value_type(avdecc_aem_control_linear_uint8),
          m_control_domain(0),
          m_control_name(),
          m_control_name_string(),
          m_number_of_values(1),
          m_source_type(avdecc_aem_descriptor_entity),
          m_source_index(0),
          m_block_latency(0),
          m_control_latency(0)
    {
    }

    bool read( const void *pdu, size_t offset );
    bool write( const void *pdu, size_t offset );

    avdecc_aem_descriptor_type_t m_descriptor_type;
    uint16_t m_descriptor_index;
    bool m_read_only;
    bool m_unknown_value;
    avdecc_aem_control_type_t m_control_type;
    uint16_t m_control_location_id;
    avdecc_aem_control_value_type_t m_control_value_type;
    uint16_t m_control_domain;
    avdecc_string64_t m_control_name;
    avdecc_aem_localized_string_ref_t m_control_name_string;
    uint16_t m_number_of_values;
    avdecc_aem_descriptor_type_t m_source_type;
    uint16_t m_source_index;
    uint32_t m_block_latency;
    uint32_t m_control_latency;
    avdecc_aem_control_value_format_union_t m_format;
};


/** avdecc_aem_sources_t
    */

/** See IEEE 1722.1 Clause 7.2.18.1 */

typedef struct avdecc_aem_sources_s
{
    avdecc_aem_descriptor_type_t source_type;
    uint16_t source_index;
} avdecc_aem_sources_t;



/** avdecc_sources_init
     *
     *  Initialize a avdecc_aem_sources_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_sources_init ( avdecc_aem_sources_t *self );


/** avdecc_sources_read
     *
     *  Read a avdecc_aem_sources_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_sources_read (
    avdecc_aem_sources_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_sources_write
     *
     *  write a avdecc_aem_sources_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_sources_write (
    const avdecc_aem_sources_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_signal_selector_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_SIGNAL_SELECTOR_MAX_SOURCES (103) /*!< See IEEE 1722.1 D18 Clause 7.2.18 */

/** See IEEE 1722.1 D18 Clause 7.2.18 */

typedef struct avdecc_aem_descriptor_signal_selector_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t control_location_type;
    uint16_t control_location_id;
    uint16_t control_domain;
    avdecc_string64_t control_name;
    avdecc_aem_localized_string_ref_t control_name_string;
    uint16_t number_of_sources;
    avdecc_aem_descriptor_type_t current_source_type;
    uint16_t current_source_index;
    avdecc_aem_descriptor_type_t default_source_type;
    uint16_t default_source_index;
    uint32_t block_latency;
    uint32_t control_latency;
    avdecc_aem_sources_t sources[AVDECC_PDU_AEM_DESCRIPTOR_SIGNAL_SELECTOR_MAX_SOURCES];
} avdecc_aem_descriptor_signal_selector_t;


/** avdecc_descriptor_signal_selector_init
     *
     *  Initialize a avdecc_aem_descriptor_signal_selector_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_signal_selector_init ( avdecc_aem_descriptor_signal_selector_t *self );


/** avdecc_descriptor_signal_selector_read
     *
     *  Read a avdecc_aem_descriptor_signal_selector_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_signal_selector_read (
    avdecc_aem_descriptor_signal_selector_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_signal_selector_write
     *
     *  write a avdecc_aem_descriptor_signal_selector_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_signal_selector_write (
    const avdecc_aem_descriptor_signal_selector_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_mixer_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_MIXER_MAX_SOURCES (101) /*!<  See IEEE 1722.1 Clause 7.2.19  */

/** See IEEE 1722.1 Clause 7.2.19 */
typedef struct avdecc_aem_descriptor_mixer_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    bool read_only;
    uint16_t control_location_type;
    uint16_t control_location_id;
    uint16_t control_value_type;
    uint16_t control_domain;
    avdecc_string64_t control_name;
    avdecc_aem_localized_string_ref_t control_name_string;
    uint16_t number_of_sources;
    uint32_t block_latency;
    uint32_t control_latency;
    avdecc_aem_sources_t sources[AVDECC_PDU_AEM_DESCRIPTOR_MIXER_MAX_SOURCES];
    avdecc_aem_control_value_format_union_t formats;
} avdecc_aem_descriptor_mixer_t;


/** avdecc_descriptor_mixer_init
     *
     *  Initialize a avdecc_aem_descriptor_mixer_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_mixer_init ( avdecc_aem_descriptor_mixer_t *self );


/** avdecc_descriptor_mixer_read
     *
     *  Read a avdecc_aem_descriptor_mixer_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_mixer_read (
    avdecc_aem_descriptor_mixer_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_mixer_write
     *
     *  write a avdecc_aem_descriptor_mixer_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_mixer_write (
    const avdecc_aem_descriptor_mixer_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_matrix_t
    */

/** See IEEE 1722.1 Clause 7.2.20 */
typedef struct avdecc_aem_descriptor_matrix_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    bool read_only;
    avdecc_aem_control_type_t control_type;
    uint16_t control_location_id;
    uint16_t control_value_type;
    uint16_t control_domain;
    avdecc_string64_t control_name;
    avdecc_aem_localized_string_ref_t control_name_string;
    uint16_t width;
    uint16_t height;
    uint16_t number_of_values;
    uint32_t block_latency;
    uint32_t control_latency;
    uint16_t number_of_sources;
    uint16_t base_source;
    uint16_t number_of_destinations;
    uint16_t base_destination;
    avdecc_aem_control_value_format_union_t formats;
} avdecc_aem_descriptor_matrix_t;



/** avdecc_descriptor_matrix_init
     *
     *  Initialize a avdecc_aem_descriptor_matrix_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_matrix_init ( avdecc_aem_descriptor_matrix_t *self );


/** avdecc_descriptor_matrix_read
     *
     *  Read a avdecc_aem_descriptor_matrix_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_matrix_read (
    avdecc_aem_descriptor_matrix_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_matrix_write
     *
     *  write a avdecc_aem_descriptor_matrix_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_matrix_write (
    const avdecc_aem_descriptor_matrix_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_locale_t
    */

/** See IEEE 1722.1 Clause 7.2.21 */

typedef struct avdecc_aem_descriptor_locale_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_string64_t locale_identifier;
    uint16_t number_of_strings;
    uint16_t base_strings;
} avdecc_aem_descriptor_locale_t;



/** avdecc_descriptor_locale_init
     *
     *  Initialize a avdecc_aem_descriptor_locale_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_locale_init ( avdecc_aem_descriptor_locale_t *self );


/** avdecc_descriptor_locale_read
     *
     *  Read a avdecc_aem_descriptor_locale_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_locale_read (
    avdecc_aem_descriptor_locale_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_locale_write
     *
     *  write a avdecc_aem_descriptor_locale_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_locale_write (
    const avdecc_aem_descriptor_locale_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_strings_t
    */

#define AVDECC_PDU_AEM_DESCRIPTOR_STRING_MAX_STRINGS (7)     /** See IEEE 1722.1 Clause 7.2.22 */

/** See IEEE 1722.1 Clause 7.2.22 */
typedef struct avdecc_aem_descriptor_strings_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_string64_t string[AVDECC_PDU_AEM_DESCRIPTOR_STRING_MAX_STRINGS];
} avdecc_aem_descriptor_strings_t;



/** avdecc_descriptor_strings_init
     *
     *  Initialize a avdecc_aem_descriptor_strings_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_strings_init ( avdecc_aem_descriptor_strings_t *self );


/** avdecc_descriptor_strings_read
     *
     *  Read a avdecc_aem_descriptor_strings_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_strings_read (
    avdecc_aem_descriptor_strings_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_strings_write
     *
     *  write a avdecc_aem_descriptor_strings_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_strings_write (
    const avdecc_aem_descriptor_strings_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_matrix_signal_entry_t
    */

/** See IEEE 1722.1 Clause 7.2.23.1 */
typedef struct avdecc_aem_descriptor_matrix_signal_entry_s
{
    avdecc_aem_descriptor_type_t signal_type;
    uint16_t signal_id;
} avdecc_aem_descriptor_matrix_signal_entry_t;



/** avdecc_descriptor_matrix_signal_entry_init
     *
     *  Initialize a avdecc_aem_descriptor_matrix_signal_entry_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_matrix_signal_entry_init ( avdecc_aem_descriptor_matrix_signal_entry_t *self );


/** avdecc_descriptor_matrix_signal_entry_read
     *
     *  Read a avdecc_aem_descriptor_matrix_signal_entry_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_matrix_signal_entry_read (
    avdecc_aem_descriptor_matrix_signal_entry_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_matrix_signal_entry_write
     *
     *  write a avdecc_aem_descriptor_matrix_signal_entry_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_matrix_signal_entry_write (
    const avdecc_aem_descriptor_matrix_signal_entry_t *self,
    void *pdu,
    size_t offset
    );

#define AVDECC_PDU_AEM_DESCRIPTOR_MATRIX_SIGNAL_MAX_SIGNALS (125) /*!< See IEEE Clause 7.2.23 */

/** avdecc_aem_descriptor_matrix_signal_t
    */

/** See IEEE 1722.1 Clause 7.2.23 */
typedef struct avdecc_aem_descriptor_matrix_signal_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    uint16_t signals_count;
    uint16_t signals_offset;
    avdecc_aem_descriptor_matrix_signal_entry_t signals_list[ AVDECC_PDU_AEM_DESCRIPTOR_MATRIX_SIGNAL_MAX_SIGNALS ];
} avdecc_aem_descriptor_matrix_signal_t;

/** avdecc_descriptor_matrix_signal_init
     *
     *  Initialize a avdecc_aem_descriptor_matrix_signal_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_matrix_signal_init ( avdecc_aem_descriptor_matrix_signal_t *self );


/** avdecc_descriptor_matrix_signal_read
     *
     *  Read a avdecc_aem_descriptor_matrix_signal_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_matrix_signal_read (
    avdecc_aem_descriptor_matrix_signal_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_matrix_signal_write
     *
     *  write a avdecc_aem_descriptor_matrix_signal_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_matrix_signal_write (
    const avdecc_aem_descriptor_matrix_signal_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_memory_object_type_t
    */

/** See IEEE 1722.1 Clause 7.2.24.1 */
typedef enum
{
    avdecc_aem_memory_object_type_firmware_image=0x0000,
    avdecc_aem_memory_object_type_vendor_specific=0x0001,
    avdecc_aem_memory_object_type_crash_dump=0x0002,
    avdecc_aem_memory_object_type_log_object=0x0003,
    avdecc_aem_memory_object_type_autostart_settings=0x0004,
    avdecc_aem_memory_object_type_snapshot_settings=0x0005
} avdecc_aem_memory_object_type_t;



/** avdecc_memory_object_type_init
     *
     *  Initialize a avdecc_aem_memory_object_type_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_memory_object_type_init ( avdecc_aem_memory_object_type_t *self );


/** avdecc_memory_object_type_read
     *
     *  Read a avdecc_aem_memory_object_type_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_memory_object_type_read (
    avdecc_aem_memory_object_type_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_memory_object_type_write
     *
     *  write a avdecc_aem_memory_object_type_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_memory_object_type_write (
    const avdecc_aem_memory_object_type_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_memory_object_operation_t
    */

/** See IEEE 1722.1 Clause 7.2.24.2 */
typedef enum
{
    avdecc_aem_memory_object_operation_store=0x0000,
    avdecc_aem_memory_object_operation_read=0x0001,
    avdecc_aem_memory_object_operation_erase=0x0002
} avdecc_aem_memory_object_operation_t;


/** avdecc_memory_object_operation_init
     *
     *  Initialize a avdecc_aem_memory_object_operation_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_memory_object_operation_init ( avdecc_aem_memory_object_operation_t *self );


/** avdecc_memory_object_operation_read
     *
     *  Read a avdecc_aem_memory_object_operation_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_memory_object_operation_read (
    avdecc_aem_memory_object_operation_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_memory_object_operation_write
     *
     *  write a avdecc_aem_memory_object_operation_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_memory_object_operation_write (
    const avdecc_aem_memory_object_operation_t *self,
    void *pdu,
    size_t offset
    );


/** avdecc_aem_descriptor_memory_object_t
    */

/** See IEEE 1722.1 Clause 7.2.24 */
typedef struct avdecc_aem_descriptor_memory_object_s
{
    avdecc_aem_descriptor_type_t descriptor_type;
    uint16_t descriptor_index;
    avdecc_aem_memory_object_type_t mem_obj_type;
    uint16_t target_descriptor_type;
    uint16_t target_descriptor_index;
    avdecc_string64_t object_name;
    avdecc_aem_localized_string_ref_t object_name_string;
    uint64_t start_address;
    uint64_t length;
} avdecc_aem_descriptor_memory_object_t;



/** avdecc_descriptor_memory_object_init
     *
     *  Initialize a avdecc_aem_descriptor_memory_object_t
     *
     *  @param self pointer to object to initialize
     *  @returns void
     */

void avdecc_descriptor_memory_object_init ( avdecc_aem_descriptor_memory_object_t *self );


/** avdecc_descriptor_memory_object_read
     *
     *  Read a avdecc_aem_descriptor_memory_object_t from a PDU
     *
     *  @param self pointer to object to fill
     *  @param pdu pointer to base of pdu to read
     *  @param offset offset from base of pdu in octets to start reading from
     */

bool avdecc_descriptor_memory_object_read (
    avdecc_aem_descriptor_memory_object_t *self,
    const void *pdu,
    size_t offset
    );


/** avdecc_descriptor_memory_object_write
     *
     *  write a avdecc_aem_descriptor_memory_object_t into a pdu
     *
     *  @param self pointer to object to store into pdu
     *  @param pdu pointer to base of pdu to write to
     *  @param offset offset from base of pdu in octets to start writing to
     */

bool avdecc_descriptor_memory_object_write (
    const avdecc_aem_descriptor_memory_object_t *self,
    void *pdu,
    size_t offset
    );



/* @} */


#endif
