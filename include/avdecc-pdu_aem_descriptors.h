#ifndef AVDECC_PDU_AEM_DESCRIPTORS_H_
#define AVDECC_PDU_AEM_DESCRIPTORS_H_

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
#include "avdecc-pdu_adp.h"
#include "avdecc-pdu_aecp.h"
#include "avdecc-pdu_aem.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** \addtogroup aem_descriptors aem_descriptors */
    /*@{*/
    
    
#define AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE (AVDECC_PDU_MAX_PAYLOAD_SIZE-32) /* See IEEE 1722.1 Section 7.4.2.1 */
 
    typedef enum
    {
        avdecc_pdu_aem_descriptortype_entity= 0x0000, /* descriptor defining the entity. */
        avdecc_pdu_aem_descriptortype_configuration= 0x0001,  /* descriptor defining a configuration of the entity. */
        avdecc_pdu_aem_descriptortype_audio= 0x0002,  /* descriptor defining an audio unit. */
        avdecc_pdu_aem_descriptortype_video= 0x0003,  /* descriptor defining a video unit. */
        avdecc_pdu_aem_descriptortype_sensor= 0x0004, /* descriptor defining a sensor unit, containing one or more sensors sampled with the same clock. */
        avdecc_pdu_aem_descriptortype_stream_input= 0x0005,   /* descriptor defining an input stream to the entity. */
        avdecc_pdu_aem_descriptortype_stream_output= 0x0006,  /* descriptor defining an output stream from the entity. */
        avdecc_pdu_aem_descriptortype_external_jack_input= 0x0007,    /* descriptor defining an external input jack on the entity. */
        avdecc_pdu_aem_descriptortype_external_jack_output= 0x0008,   /* descriptor defining an external output jack on the entity. */
        avdecc_pdu_aem_descriptortype_audio_port_input= 0x0009,   /* descriptor defining an input port on an audio unit. */
        avdecc_pdu_aem_descriptortype_audio_port_output= 0x000a,  /* descriptor defining an output port on an audio unit. */
        avdecc_pdu_aem_descriptortype_video_port_input= 0x000b,   /* descriptor defining an input port on a video unit. */
        avdecc_pdu_aem_descriptortype_video_port_output= 0x000c,  /* descriptor defining an output port on a video unit. */
        avdecc_pdu_aem_descriptortype_external_port_input= 0x000d,    /* descriptor defining an input external port on a unit. */
        avdecc_pdu_aem_descriptortype_external_port_output= 0x000e,   /* descriptor defining an output external port on a unit. */
        avdecc_pdu_aem_descriptortype_sensor_port_input= 0x000f,  /* descriptor defining an input port on a sensor unit. */
        avdecc_pdu_aem_descriptortype_sensor_port_output= 0x0010, /* descriptor defining an output port on a sensor unit. */
        avdecc_pdu_aem_descriptortype_internal_port_input= 0x0011,    /* descriptor defining an input port on a unit sourced from another unit within the entity. */
        avdecc_pdu_aem_descriptortype_internal_port_output= 0x0012,   /* descriptor defining an output port on a unit sinked to another unit within the entity. */
        avdecc_pdu_aem_descriptortype_avb_interface= 0x0013,  /* descriptor defining an avb interface. */
        avdecc_pdu_aem_descriptortype_clock_source= 0x0014,   /* descriptor describing a clock source. */
        avdecc_pdu_aem_descriptortype_audio_map= 0x0015,  /* descriptor defining the mapping between the channels of an audio stream and the channels of the audio port. */
        avdecc_pdu_aem_descriptortype_audio_cluster= 0x0016,  /* descriptor defining a cluster of channels within an audio port. */
        avdecc_pdu_aem_descriptortype_control= 0x0017,    /* descriptor defining a generic control. */
        avdecc_pdu_aem_descriptortype_signal_selector= 0x0018,    /* descriptor defining a signal selector control. */
        avdecc_pdu_aem_descriptortype_mixer= 0x0019,  /* descriptor defining a mixer control. */
        avdecc_pdu_aem_descriptortype_matrix= 0x001a, /* descriptor defining a matrix control. */
        avdecc_pdu_aem_descriptortype_locale= 0x001b, /* descriptor defining a locale. */
        avdecc_pdu_aem_descriptortype_strings= 0x001c,    /* descriptor defining localized strings. */        
        avdecc_pdu_aem_descriptortypes=0x001d
    } avdecc_pdu_aem_descriptortype_t;
    
    typedef struct avdecc_pdu_aem_descriptor_s
    {
        avdecc_pdu_aem_descriptortype_t descriptor_type;
        uint16_t descriptor_id;
    } avdecc_pdu_aem_descriptor_t;
    
    /** See IEEE 1722.1 Section 7.2.3.1.1 */    
    typedef enum
    {
        avdecc_pdu_aem_audio_pull_mul_1=0,
        avdecc_pdu_aem_audio_pull_mul_1_div_1_001,
        avdecc_pdu_aem_audio_pull_mul_1_001,
        avdecc_pdu_aem_audio_pull_mul_24_div_25,
        avdecc_pdu_aem_audio_pull_mul_25_div_24
    } avdecc_pdu_aem_audio_pull_t;
    
    /** See IEEE 1722.1 Section 7.2.3.1 */
    
    typedef struct avdecc_pdu_aem_audio_sample_rate_s
    {
        uint32_t base_frequency;
        avdecc_pdu_aem_audio_pull_t pull;
    } avdecc_pdu_aem_audio_sample_rate_t;

    /** See IEEE 1722.1 Section 7.2.1 */
    
    typedef struct avdecc_pdu_aem_descriptor_entity_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_eui64_t entity_guid;
        avdecc_pdu_eui64_t vendor_model_id;
        avdecc_adp_entity_capabilities_t entity_capabilities;
        uint16_t talker_stream_sources;
        avdecc_adp_talker_capabilities_t talker_capabilities;
        uint16_t listener_stream_sinks;
        avdecc_adp_listener_capabilities_t listener_capabilities;
        avdecc_adp_controller_capabilities_t controller_capabilities;
        uint32_t available_index;
        avdecc_pdu_eui64_t as_grandmaster_id;
        avdecc_pdu_eui64_t association_id;
        avdecc_adp_entity_type_t entity_type;
        avdecc_pdu_string64_t entity_name;
        uint16_t vendor_name_string;
        uint16_t model_name_string;
        avdecc_pdu_string64_t firmware_version;
        avdecc_pdu_string64_t group_name;
        avdecc_pdu_string64_t serial_number;
        uint16_t configurations_count;
        uint16_t current_configuration;
    } avdecc_pdu_aem_descriptor_entity_t;
    
    
    /** See IEEE 1722.1 Section 7.2.2.1 */
    typedef struct avdecc_pdu_aem_descriptor_configuration_counts_s
    {
        uint16_t descriptor_type;
        uint16_t descriptor_count;
    } avdecc_pdu_aem_descriptor_configuration_counts_t;
    
#define AVDECC_PDU_AEM_DESCRIPTOR_CONFIGURATION_MAX_COUNTS (( AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE - 74 ) / 4 ) /* See IEEE 1722.1 Section 7.2.2 */
    
    /** See IEEE 1722.1 Section 7.2.2 */    
    typedef struct avdecc_pdu_aem_descriptor_configuration_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_string64_t configuration_name;
        uint16_t configuration_name_string;
        uint16_t descriptor_counts_count;
        avdecc_pdu_aem_descriptor_configuration_counts_t descriptor_counts[AVDECC_PDU_AEM_DESCRIPTOR_CONFIGURATION_MAX_COUNTS];
    } avdecc_pdu_aem_descriptor_configuration_t;
    
#define AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAX_SAMPLE_RATES (( AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE - 108 ) / 4 ) /* See IEEE 1722.1 Section 7.2.3 */

    /** See IEEE 1722.1 Section 7.2.3 */
    typedef struct avdecc_pdu_aem_descriptor_audio_s
    {
        avdecc_pdu_aem_descriptor_t base;
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
        uint16_t clock_source_id;
        uint16_t number_of_controls;
        uint16_t base_control;
        avdecc_pdu_string64_t unit_name;
        uint16_t unit_name_string;
        avdecc_pdu_aem_audio_sample_rate_t current_sample_rate;
        uint16_t sample_rates_count;
        avdecc_pdu_aem_audio_sample_rate_t sample_rates[AVDECC_PDU_AEM_DESCRIPTOR_AUDIO_MAX_SAMPLE_RATES];
    } avdecc_pdu_aem_descriptor_audio_t;
    
    
    /** See IEEE 1722.1 Section 7.2.4 */    
    typedef struct avdecc_pdu_aem_descriptor_video_s
    {
        avdecc_pdu_aem_descriptor_t base;
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
        uint16_t clock_source_id;
        uint16_t number_of_controls;
        uint16_t base_control;
        avdecc_pdu_string64_t unit_name;
        uint16_t unit_name_string;
    } avdecc_pdu_aem_descriptor_video_t;
    
    
    /** See IEEE 1722.1 Section 7.2.5 */
    typedef struct avdecc_pdu_aem_descriptor_sensor_s
    {
        avdecc_pdu_aem_descriptor_t base;
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
        uint16_t clock_source_id;
        uint16_t number_of_controls;
        uint16_t base_control;
        avdecc_pdu_string64_t unit_name;
        uint16_t unit_name_string;
    } avdecc_pdu_aem_descriptor_sensor_t;
    
    /** See IEEE 1722.1 Section 7.2.6.1 */
    typedef struct avdecc_pdu_aem_stream_flags_s
    {
        uint8_t clock_sync_source:1;
        uint8_t class_a:1;
        uint8_t class_b:1;
    } avdecc_pdu_aem_stream_flags_t;
    
    
    /** See IEEE 1722.1 Section 7.3.1 */
    typedef struct avdecc_pdu_aem_stream_format_s
    {
        uint64_t format;
    } avdecc_pdu_aem_stream_format_t;
    
#define AVDECC_PDU_AEM_DESCRIPTOR_STREAM_MAX_FORMATS (( AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE - 136 ) / 8 ) /* See IEEE 1722.1 Section 7.2.6 */
    
    /** See IEEE 1722.1 Section 7.2.6 */
    typedef struct avdecc_pdu_aem_descriptor_stream_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_string64_t stream_name;
        uint16_t stream_name_string;
        avdecc_pdu_aem_stream_flags_t stream_flags;
        uint16_t stream_channels;
        avdecc_pdu_eui64_t clock_source_id;
        avdecc_pdu_aem_stream_format_t current_format;
        uint16_t number_of_formats;
        avdecc_pdu_eui64_t backup_talker_guid_0;
        uint16_t backup_talker_unique_0;
        avdecc_pdu_eui64_t backup_talker_guid_1;
        uint16_t backup_talker_unique_1;
        avdecc_pdu_eui64_t backup_talker_guid_2;
        uint16_t backup_talker_unique_2;
        avdecc_pdu_eui64_t backedup_talker_guid;
        uint16_t backedup_talker_unique;
        uint16_t avb_interface_id;
        avdecc_pdu_aem_stream_format_t formats[AVDECC_PDU_AEM_DESCRIPTOR_STREAM_MAX_FORMATS];
    } avdecc_pdu_aem_descriptor_stream_t;
    
    /** See IEEE 1722.1 Section 7.2.7.1 */
    typedef struct avdecc_pdu_aem_jack_flags_s
    {
        uint8_t clock_sync_source:1;
        uint8_t captive:1;
    } avdecc_pdu_aem_jack_flags_t;

    
    /** See IEEE 1722.1 Section 7.2.7.2 */
    typedef enum
    {
        avdecc_pdu_aem_jack_type_speaker = 0,
        avdecc_pdu_aem_jack_type_headphone,
        avdecc_pdu_aem_jack_type_analog_microphone,
        avdecc_pdu_aem_jack_type_spdif,
        avdecc_pdu_aem_jack_type_adat,
        avdecc_pdu_aem_jack_type_tdif,
        avdecc_pdu_aem_jack_type_madi,
        avdecc_pdu_aem_jack_type_unbalanced_analog,
        avdecc_pdu_aem_jack_type_balanced_analog,
        avdecc_pdu_aem_jack_type_digital,
        avdecc_pdu_aem_jack_type_midi,
        avdecc_pdu_aem_jack_type_aes_ebu,
        avdecc_pdu_aem_jack_type_composite_video,
        avdecc_pdu_aem_jack_type_s_vhs_video,
        avdecc_pdu_aem_jack_type_component_video,
        avdecc_pdu_aem_jack_type_dvi,
        avdecc_pdu_aem_jack_type_hdmi,
        avdecc_pdu_aem_jack_type_udi,
        avdecc_pdu_aem_jack_type_displayport,
        avdecc_pdu_aem_jack_type_antenna,
        avdecc_pdu_aem_jack_type_analog_tuner,
        avdecc_pdu_aem_jack_type_ethernet,
        avdecc_pdu_aem_jack_type_wifi,
        avdecc_pdu_aem_jack_type_usb,
        avdecc_pdu_aem_jack_type_pci,
        avdecc_pdu_aem_jack_type_pci_e,
        avdecc_pdu_aem_jack_type_scsi,
        avdecc_pdu_aem_jack_type_ata,
        avdecc_pdu_aem_jack_type_imager,
        avdecc_pdu_aem_jack_type_ir,
        avdecc_pdu_aem_jack_type_thunderbolt,
        avdecc_pdu_aem_jack_type_sata,
        avdecc_pdu_aem_jack_type_smpte_ltc,
        avdecc_pdu_aem_jack_type_digital_microphone
    } avdecc_pdu_aem_jack_type_t;
    
    
    /** See IEEE 1722.1 Section 7.2.7 */
    typedef struct avdecc_pdu_aem_descriptor_external_jack_s
    {
        uint16_t descriptor_id;
        avdecc_pdu_string64_t jack_name;
        uint16_t jack_name_string;
        avdecc_pdu_aem_jack_flags_t jack_flags;
        avdecc_pdu_aem_jack_type_t jack_type;
    } avdecc_pdu_aem_descriptor_external_jack_t;
    
    
    /** See IEEE 1722.1 Section 7.2.8.1 */
    typedef struct avdecc_pdu_aem_port_flags_s
    {
        unsigned int clock_sync_source:1;
        unsigned int async_sample_rate_conv:1;
        unsigned int sync_sample_rate_conv:1;
    } avdecc_pdu_aem_port_flags_t;
    
    /** See IEEE 1722.1 Section 7.2.8 */
    typedef struct avdecc_pdu_aem_descriptor_audio_port_s
    {
        uint16_t descriptor_id;
        avdecc_pdu_aem_port_flags_t port_flags;
        uint16_t audio_channels;
        uint16_t number_of_clusters;
        uint16_t base_cluster;
        uint16_t audio_map_id;
    } avdecc_pdu_aem_descriptor_audio_port_t;
    
    /** See IEEE 1722.1 Section 7.3.2 */

    typedef struct avdecc_pdu_aem_media_format_s
    {
        uint64_t raw[2]; /* TODO: */
    } avdecc_pdu_aem_media_format_t;

    /** See IEEE 1722.1 Section 7.2.9 */

    typedef struct avdecc_pdu_aem_descriptor_video_port_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_aem_port_flags_t port_flags;
        avdecc_pdu_aem_media_format_t current_format;
        uint16_t source_type;
        uint16_t source_id;
        uint16_t stream_id;
        uint16_t formats_count;
        avdecc_pdu_aem_media_format_t formats[];
    } avdecc_pdu_aem_descriptor_video_port_t;
    
    
    /** See IEEE 1722.1 Section 7.2.10 */    
    typedef struct avdecc_pdu_aem_descriptor_external_port_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_aem_port_flags_t port_flags;
        uint16_t source_type;
        uint16_t source_id;
    } avdecc_pdu_aem_descriptor_external_port_t;
    
    
    /** See IEEE 1722.1 Section 7.2.11 */
    typedef struct avdecc_pdu_aem_descriptor_sensor_port_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_aem_port_flags_t port_flags;
        uint16_t source_type;
        uint16_t source_id;
        uint16_t stream_id;
    } avdecc_pdu_aem_descriptor_sensor_port_t;
    
    
    /** See IEEE 1722.1 Section 7.2.12 */
    typedef struct avdecc_pdu_aem_descriptor_internal_port_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_aem_port_flags_t port_flags;
        uint16_t source_type;
        uint16_t source_id;
        uint16_t internal_id;
    } avdecc_pdu_aem_descriptor_internal_port_t;
    
    
    /** See IEEE 1722.1 Section 7.2.13.1 */
    typedef struct avdecc_pdu_aem_msrp_mappings_s
    {
        uint8_t traffic_class;
        uint8_t priority;
        uint16_t vlan_id;
    } avdecc_pdu_aem_msrp_mappings_t;
    
    
    /** See IEEE 1722.1 Section 7.2.13 */
    typedef struct avdecc_pdu_aem_descriptor_avb_interface_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_mac_t mac_address;
        avdecc_pdu_eui64_t as_grandmaster_id;
        uint16_t msrp_mappings_count;
        avdecc_pdu_aem_msrp_mappings_t msrp_mappings[];
    } avdecc_pdu_aem_descriptor_avb_interface_t;
    
    /** See IEEE 1722.1 Section 7.2.14.1 */

    typedef struct avdecc_pdu_aem_clock_source_flags_s
    {
    } avdecc_pdu_aem_clock_source_flags_t;
    
    /** See IEEE 1722.1 Section 7.2.14.2 */

    typedef enum
    {
        avdecc_pdu_aem_clock_source_local_oscillator = 0,
        avdecc_pdu_aem_clock_source_input_stream,
        avdecc_pdu_aem_clock_source_word_clock,
        avdecc_pdu_aem_clock_source_analog_input,
        avdecc_pdu_aem_clock_source_digital_input,
        avdecc_pdu_aem_clock_source_802_1_as,
        avdecc_pdu_aem_clock_source_thunderbolt
    } avdecc_pdu_aem_clock_source_type_t;
    
    /** See IEEE 1722.1 Section 7.2.14 */

    typedef struct avdecc_pdu_aem_descriptor_clock_source_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_string64_t clock_source_name;
        uint16_t clock_source_name_string;
        avdecc_pdu_aem_clock_source_flags_t clock_source_flags;
        avdecc_pdu_aem_clock_source_type_t clock_source_type;
        avdecc_pdu_eui64_t clock_source_id;
        uint16_t clock_source_location_type;
        uint16_t clock_source_location_id;
    } avdecc_pdu_aem_descriptor_clock_source_t;
    
    /** See IEEE 1722.1 Section 7.2.15.1 */

    typedef struct avdecc_pdu_aem_audio_mapping_s
    {
        uint16_t mapping_stream_index;
        uint16_t mapping_stream_channel;
        uint16_t mapping_audio_channel;
    } avdecc_pdu_aem_audio_mapping_t;
    
    
    /** See IEEE 1722.1 Section 7.2.15 */
    typedef struct avdecc_pdu_aem_descriptor_audio_map_s
    {
        avdecc_pdu_aem_descriptor_t base;
        uint16_t number_of_mappings;
        avdecc_pdu_aem_audio_mapping_t mappings[];
    } avdecc_pdu_aem_descriptor_audio_map_t;
    
    /** See IEEE 1722.1 Section 7.2.16 */

    typedef struct avdecc_pdu_aem_descriptor_audio_cluster_s
    {
        avdecc_pdu_aem_descriptor_t base;
        uint16_t channel_count;
        uint32_t latency;
        uint8_t am824_label;
        avdecc_pdu_string64_t cluster_name;
        uint16_t cluster_name_string;
        uint16_t source_type;
        uint16_t source_id;
    } avdecc_pdu_aem_descriptor_audio_cluster_t;
    
    /** See IEEE 1722.1 Section 7.3.4 */

    typedef enum
    {
        avdecc_pdu_aem_control_type_enable = 0x00000, /* enable or disable the unit or entity. */
        avdecc_pdu_aem_control_type_delay = 0x00001, /* apply a delay to the signal. */
        avdecc_pdu_aem_control_type_pow_line_freq = 0x00002, /* power line frequency. */
        avdecc_pdu_aem_control_type_rollpitchyaw_abs = 0x00003, /* roll, pitch (tilt), yaw (pan) absolute. */
        avdecc_pdu_aem_control_type_rollpitchyaw_rel = 0x00004, /* roll, pitch (tilt), yaw (pan) relative. */
        avdecc_pdu_aem_control_type_surgeswayheave_abs = 0x00005, /* surge, sway, heave absolute. */
        avdecc_pdu_aem_control_type_surgeswayheave_rel = 0x00006, /* surge, sway, heave relative. */
        avdecc_pdu_aem_control_type_identify = 0x00007, /* identify the entity. */
        avdecc_pdu_aem_control_type_power_status = 0x00008, /* system power supply status. */
        avdecc_pdu_aem_control_type_fan_status = 0x00009, /* system fan status. */
        avdecc_pdu_aem_control_type_temperature = 0x0000a, /* temperature setting. */
        avdecc_pdu_aem_control_type_temperature_sensor = 0x0000b, /* temperature sensor. */
        avdecc_pdu_aem_control_type_altitude = 0x0000c, /* altitude. */
        avdecc_pdu_aem_control_type_humidity = 0x0000d, /* humidity. */
        avdecc_pdu_aem_control_type_mute = 0x10000, /* mute the audio. */
        avdecc_pdu_aem_control_type_volume = 0x10001, /* adjust the volume. */
        avdecc_pdu_aem_control_type_invert = 0x10002, /* invert the signal polarity. */
        avdecc_pdu_aem_control_type_panpot = 0x10003, /* stereo pan position. */
        avdecc_pdu_aem_control_type_isolate = 0x10004, /* isolate control from modifications. */
        avdecc_pdu_aem_control_type_position = 0x10005, /* set three dimensional position. */
        avdecc_pdu_aem_control_type_phantom = 0x10006, /* set phantom power for analog or digital microphones. */
        avdecc_pdu_aem_control_type_audio_scale = 0x10007, /* select analog audio scale. */
        avdecc_pdu_aem_control_type_audio_meters = 0x10008, /* audio meter values. */
        avdecc_pdu_aem_control_type_audio_spectrum = 0x10009, /* audio signal spectrum values. */
        avdecc_pdu_aem_control_type_filter_response = 0x1000a, /* filter response bode plot values. */
        avdecc_pdu_aem_control_type_scanning_mode = 0x20000, /* video scanning mode. */
        avdecc_pdu_aem_control_type_auto_exp_mode = 0x20001, /* auto-exposure mode. */
        avdecc_pdu_aem_control_type_auto_exp_prio = 0x20002, /* auto-exposure priority */
        avdecc_pdu_aem_control_type_exp_time_abs = 0x20003, /* exposure time absolute */
        avdecc_pdu_aem_control_type_exp_time_rel = 0x20004, /* exposure time relative */
        avdecc_pdu_aem_control_type_focus_abs = 0x20005, /* focus absolute. */
        avdecc_pdu_aem_control_type_focus_rel = 0x20006, /* focus relative. */
        avdecc_pdu_aem_control_type_focus_auto = 0x20007, /* focus automatic. */
        avdecc_pdu_aem_control_type_iris_abs = 0x20008, /* iris absolute. */
        avdecc_pdu_aem_control_type_iris_rel = 0x20009, /* iris relative. */
        avdecc_pdu_aem_control_type_zoom_abs = 0x2000a, /* zoom absolute. */
        avdecc_pdu_aem_control_type_zoom_rel = 0x2000b, /* zoom relative. */
        avdecc_pdu_aem_control_type_privacy = 0x2000c, /* privacy. */
        avdecc_pdu_aem_control_type_backlight = 0x2000d, /* backlight compensation. */
        avdecc_pdu_aem_control_type_brightness = 0x2000e, /* brightness. */
        avdecc_pdu_aem_control_type_contrast = 0x2000f, /* contrast. */
        avdecc_pdu_aem_control_type_gain = 0x20010, /* gain */
        avdecc_pdu_aem_control_type_hue = 0x20011, /* hue */
        avdecc_pdu_aem_control_type_saturation = 0x20012, /* saturation. */
        avdecc_pdu_aem_control_type_sharpness = 0x20013, /* sharpness */
        avdecc_pdu_aem_control_type_gamma = 0x20014, /* gamma. */
        avdecc_pdu_aem_control_type_white_bal_temp = 0x20015, /* white balance temperature. */
        avdecc_pdu_aem_control_type_white_bal_temp_auto = 0x20016, /* white balance temperature auto. */
        avdecc_pdu_aem_control_type_white_bal_comp = 0x20017, /* white balance components. */
        avdecc_pdu_aem_control_type_white_bal_comp_auto = 0x20018, /* white balance components auto. */
        avdecc_pdu_aem_control_type_digital_zoom = 0x20019 /* digital zoom. */
    } avdecc_pdu_aem_control_type_t;
    
    /** See IEEE 1722.1 Section 7.3.3 */
    typedef enum
    {
        avdecc_pdu_aem_units_none=0x00, /* "", "Unitless" */
        avdecc_pdu_aem_units_inc_count =0x01, /* "", "Incrementing Count" */
        avdecc_pdu_aem_units_percentage =0x02, /* "%", "Percentage" */
        avdecc_pdu_aem_units_fstop =0x03, /* "", "fstop" */
        avdecc_pdu_aem_units_time_seconds=0x08, /* "s", "Time in seconds" */
        avdecc_pdu_aem_units_time_minutes=0x09, /* "m", "Time in minutes" */
        avdecc_pdu_aem_units_time_hours =0x0a, /* "h", "Time in hours" */
        avdecc_pdu_aem_units_time_days =0x0b, /* "d", "Time in days" */
        avdecc_pdu_aem_units_time_months =0x0c, /* "M", "Time in months" */
        avdecc_pdu_aem_units_time_years =0x0d, /* "Y", "Time in years" */
        avdecc_pdu_aem_units_time_samples =0x0e, /* "samples", "Time in audio samples" */
        avdecc_pdu_aem_units_time_frames =0x0f, /* "f", "Time in video/film frames" */
        avdecc_pdu_aem_units_freq_hz =0x10, /* "Hz", "Frequency in Hertz" */
        avdecc_pdu_aem_units_freq_note =0x11, /* "Note", "Frequency in MIDI note value (semitones)" */
        avdecc_pdu_aem_units_freq_cents =0x12, /* "Cent", "Frequency in Cents" */
        avdecc_pdu_aem_units_freq_octaves =0x13, /* "Octave", "Frequency in Octaves" */
        avdecc_pdu_aem_units_distance_meteres =0x18, /* "m", "Distance in meters" */
        avdecc_pdu_aem_units_temperature_kelvin =0x20, /* "K", "Temperature in kelvin" */
        avdecc_pdu_aem_units_level_db =0x28, /* "dB", "Level or gain in decibels" */
        avdecc_pdu_aem_units_level_dba =0x29, /* "dB(A)", "A-weighted level in decibels" */
        avdecc_pdu_aem_units_level_dbb =0x2a, /* "dB(B)", "B-weighted level in decibels" */
        avdecc_pdu_aem_units_level_dbc =0x2b, /* "dB(C)", "C-weighted level in decibels" */
        avdecc_pdu_aem_units_level_dbfs =0x2c, /* "dBFS", "Full scale level in decibels" */
        avdecc_pdu_aem_units_level_dbtp =0x2d, /* "dBTP", "True peak level in decibels" */
        avdecc_pdu_aem_units_level_dbspl =0x2e, /* "dB(SPL)", "Sound pressure level in decibels" */
        avdecc_pdu_aem_units_voltage_volts =0x30, /* "V", "Voltage in volts" */
        avdecc_pdu_aem_units_voltage_dbv =0x31, /* "dBV", "Voltage in dBV" */
        avdecc_pdu_aem_units_voltage_dbu =0x32, /* "dBu", "Voltage in dBu" */
        avdecc_pdu_aem_units_current_amperes =0x38, /* "A", "Electric current in amperes" */
        avdecc_pdu_aem_units_power_watts =0x40, /* "W", "Electric power in watts" */
        avdecc_pdu_aem_units_power_dbm =0x41, /* "dBm", "Signal power in dBm" */
        avdecc_pdu_aem_units_power_dbw =0x42, /* "dBW", "Signal power in dBW" */
        avdecc_pdu_aem_units_pressure_pascals =0x48, /* "Pa", "Pressure in pascals" */
        avdecc_pdu_aem_units_mem_bits =0x50, /* "b", "Bit count" */
        avdecc_pdu_aem_units_mem_bytes =0x51, /* "B", "Byte count" */
        avdecc_pdu_aem_units_mem_kibibytes =0x52, /* "KiB", "Kibibyte count" */
        avdecc_pdu_aem_units_mem_mebibytes =0x53, /* "MiB", "Mebibyte count" */
        avdecc_pdu_aem_units_mem_gibibytes =0x54, /* "GiB", "Gibibyte count" */
        avdecc_pdu_aem_units_mem_tebibytes =0x55, /* "TiB", "Tebibyte count" */
        avdecc_pdu_aem_units_bw_bits_per_second =0x58, /* "b/s", "Bits per second" */
        avdecc_pdu_aem_units_bw_bytes_per_second =0x59, /* "B/s", "Bytes per second" */
        avdecc_pdu_aem_units_bw_kibibytes_per_second =0x5a, /* "KiB/s", "Kibibytes per second" */
        avdecc_pdu_aem_units_bw_mebibytes_per_second =0x5b, /* "MiB/s", "Mebibytes per second" */
        avdecc_pdu_aem_units_bw_gibibytes_per_second =0x5c, /* "GiB/s", "Gibibytes per second" */
        avdecc_pdu_aem_units_bw_tebibytes_per_second =0x5d, /* "TiB/s", "Tebibytes per second" */
        avdecc_pdu_aem_units_luminosity_candela =0x60, /* "cd", "Candela" */
        avdecc_pdu_aem_units_energy_joules =0x68, /* "J", "Joules" */
        avdecc_pdu_aem_units_angle_radians =0x70, /* "rad", "Radians" */
        avdecc_pdu_aem_units_force_newtons =0x78, /* "N", "Newtons" */
        avdecc_pdu_aem_units_resistance_ohms =0x80, /* "Ω", "Ohms" */
        avdecc_pdu_aem_units_velocity_meters_per_second =0x88, /* "m/s", "Meters per second" */
        avdecc_pdu_aem_units_angular_velocity_radians_per_second =0x89, /* "rad/s", "Angular velocity in radians per second" */
        avdecc_pdu_aem_units_acceleration_meters_per_second_per_second  =0x90, /* "m/s·s", "Meters per second per second" */
        avdecc_pdu_aem_units_area_meters_squared =0xa0, /* "m·m", "Meters squared" */
        avdecc_pdu_aem_units_volume_meters_cubed =0xa8, /* "m·m·m", "Meters cubed" */
        avdecc_pdu_aem_units_volume_litres =0xa9, /* "l", "Litres" */
        avdecc_pdu_aem_units_mass_grams =0xb0, /* "gram", "Grams" */
        avdecc_pdu_aem_units_magnetic_flux_tesla =0xb8 /* "T", "Tesla" */
    } avdecc_pdu_aem_units_t;
    
    extern const char *avdecc_pdu_aem_units_symbol[256];
    
    /** See IEEE 1722.1 Section 7.2.17.1 */

    typedef enum
    {
        avdecc_pdu_aem_control_linear_int8 = 0x0000,
        avdecc_pdu_aem_control_linear_uint8 = 0x0001,
        avdecc_pdu_aem_control_linear_int16 = 0x0002,
        avdecc_pdu_aem_control_linear_uint16 = 0x0003,
        avdecc_pdu_aem_control_linear_int32 = 0x0004,
        avdecc_pdu_aem_control_linear_uint32 = 0x0005,
        avdecc_pdu_aem_control_linear_int64 = 0x0006,
        avdecc_pdu_aem_control_linear_uint64 = 0x0007,
        avdecc_pdu_aem_control_linear_float = 0x0008,
        avdecc_pdu_aem_control_linear_double = 0x0009,
        avdecc_pdu_aem_control_selector_int8 = 0x000a,
        avdecc_pdu_aem_control_selector_uint8 = 0x000b,
        avdecc_pdu_aem_control_selector_int16 = 0x000c,
        avdecc_pdu_aem_control_selector_uint16 = 0x000d,
        avdecc_pdu_aem_control_selector_int32 = 0x000e,
        avdecc_pdu_aem_control_selector_uint32 = 0x000f,
        avdecc_pdu_aem_control_selector_int64 = 0x0010,
        avdecc_pdu_aem_control_selector_uint64 = 0x0011,
        avdecc_pdu_aem_control_selector_float = 0x0012,
        avdecc_pdu_aem_control_selector_double = 0x0013,
        avdecc_pdu_aem_control_utf8 = 0x0014,
        avdecc_pdu_aem_control_bode_plot = 0x0015,
        avdecc_pdu_aem_control_array_int8 = 0x0016,
        avdecc_pdu_aem_control_array_uint8 = 0x0017,
        avdecc_pdu_aem_control_array_int16 = 0x0018,
        avdecc_pdu_aem_control_array_uint16 = 0x0019,
        avdecc_pdu_aem_control_array_int32 = 0x001a,
        avdecc_pdu_aem_control_array_uint32 = 0x001b,
        avdecc_pdu_aem_control_array_int64 = 0x001c,
        avdecc_pdu_aem_control_array_uint64 = 0x001d,
        avdecc_pdu_aem_control_array_float = 0x001e,
        avdecc_pdu_aem_control_array_double = 0x001f,
        avdecc_pdu_aem_control_vendor = 0xfffe,
        avdecc_pdu_aem_control_expansion = 0xffff
    } avdecc_pdu_aem_control_value_type_t;
    

#if 0
    /** See IEEE 1722.1 Section 7.2.17.2.1 */
    
    template <typename T>
    class control_value_type_linear_format_t : public control_value_type_format_t
    {
    public:
        
        T minimum_value;
        T maximum_value;
        T step;
        T default_value;
        T current_value;
        units_t units;
        uint16_t string_id;
    };
    
    /** See IEEE 1722.1 Section 7.2.17.2.2 */
    
    template <typename T>
    class control_value_type_selector_format_t : public control_value_type_format_t
    {
    public:
        
        T current_value;
        T default_value;
        std::vector<T> option;
        units_t units;
    };
    
    /** See IEEE 1722.1 Section 7.2.17.2.3 */
    
    class control_value_type_utf8_format_t : public control_value_type_format_t
    {
    public:
        
        string value;
    };
    
    /** See IEEE 1722.1 Section 7.2.17.2.4 */
    
    class control_value_type_bode_plot_entry_t : public control_value_type_format_t
    {
    public:
        float frequency_value;
        float gain_value;
        float phase_value;
    };
    
    /** See IEEE 1722.1 Section 7.2.17.2.5 */
    
    template <typename T>
    class control_value_type_array_format_t : public control_value_type_format_t
    {
    public:
        units_t units;
        T minimum_value;
        T maximum_value;
        T step;
        T default_value;
        std::vector<T> current_value;
    };
    
    /** See IEEE 1722.1 Section 7.2.17.2.4 */
    
    class control_value_type_bode_plot_format_t : public control_value_type_format_t
    {
    public:
        float frequency_minimum_value;
        float frequency_maximum_value;
        float frequency_step;
        float frequency_default_value;
        float mag_minimum_value;
        float mag_maximum_value;
        float mag_step;
        float mag_default_value;
        float phase_minimum_value;
        float phase_maximum_value;
        float phase_step;
        float phase_default_value;
        std::vector<control_value_type_bode_plot_entry_t> entries;
    };
    
#endif
    
#define AVDECC_PDU_AEM_CONTROL_VALUE_TYPE_VENDOR_FORMAT_MAX_BLOB (256)
    
    /** See IEEE 1722.1 Section 7.2.17.2.6 */
        
    typedef struct avdecc_pdu_aem_control_value_type_vendor_format_s
    {
        avdecc_pdu_eui64_t guid;
        uint8_t blob[ AVDECC_PDU_AEM_CONTROL_VALUE_TYPE_VENDOR_FORMAT_MAX_BLOB ];
    } avdecc_pdu_aem_control_value_type_vendor_format_t;    
    
    typedef union avdecc_pdu_aem_control_value_union_s
    {
        avdecc_pdu_aem_control_value_type_vendor_format_t vendor_format;
        /* TODO: Add all types here */
    } avdecc_pdu_aem_control_value_union_t;
    
    /** See IEEE 1722.1 Section 7.2.17 */
    
    typedef struct avdecc_pdu_aem_descriptor_control_s
    {
        avdecc_pdu_aem_descriptor_t base;
        bool read_only;
        avdecc_pdu_aem_control_type_t control_type;
        uint16_t control_location_id;
        uint16_t control_value_type;
        uint16_t control_domain;
        avdecc_pdu_string64_t control_name;
        uint16_t control_name_string;
        uint16_t number_of_values;
        uint16_t source_type;
        uint16_t source_id;
        avdecc_pdu_aem_control_value_union_t formats;
    } avdecc_pdu_aem_descriptor_control_t;
    
    
    /** See IEEE 1722.1 Section 7.2.18.1 */
    
    typedef struct avdecc_pdu_aem_sources_s
    {
        uint16_t source_type;
        uint16_t source_id;
    } avdecc_pdu_aem_sources_t;
    
#define AVDECC_PDU_AEM_DESCRIPTOR_SIGNAL_SELECTOR_MAX_SOURCES (( AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE - 88 ) / 4 ) /* See IEEE 1722.1 Section 7.2.18 */
    
    /** See IEEE 1722.1 Section 7.2.18 */    
    
    typedef struct avdecc_pdu_aem_descriptor_signal_selector_s
    {
        avdecc_pdu_aem_descriptor_t base;
        uint16_t control_location_type;
        uint16_t control_location_id;
        uint16_t control_domain;
        avdecc_pdu_string64_t control_name;
        uint16_t control_name_string;
        uint16_t number_of_sources;
        uint16_t current_source_type;
        uint16_t current_source_id;
        uint16_t default_source_type;
        uint16_t default_source_id;
        avdecc_pdu_aem_sources_t sources[AVDECC_PDU_AEM_DESCRIPTOR_SIGNAL_SELECTOR_MAX_SOURCES];
    } avdecc_pdu_aem_descriptor_signal_selector_t;
    
#define AVDECC_PDU_AEM_DESCRIPTOR_MIXER_MAX_SOURCES (( AVDECC_PDU_AEM_DESCRIPTOR_MAX_PAYLOAD_SIZE - 88 ) / 4 ) /* TODO: Citation needed is it correct */
    
    /** See IEEE 1722.1 Section 7.2.19 */
    typedef struct avdecc_pdu_aem_descriptor_mixer_s
    {
        avdecc_pdu_aem_descriptor_t base;
        bool read_only;
        uint16_t control_location_type;
        uint16_t control_location_id;
        uint16_t control_value_type;
        uint16_t control_domain;
        avdecc_pdu_string64_t control_name;
        uint16_t control_name_string;
        avdecc_pdu_aem_sources_t sources[AVDECC_PDU_AEM_DESCRIPTOR_MIXER_MAX_SOURCES];
        avdecc_pdu_aem_control_value_union_t formats;
    } avdecc_pdu_aem_descriptor_mixer_t;
    
    /** See IEEE 1722.1 Section 7.2.20 */
    typedef struct avdecc_pdu_aem_descriptor_matrix_s
    {
        avdecc_pdu_aem_descriptor_t base;
        bool read_only;
        avdecc_pdu_aem_control_type_t control_type;
        uint16_t control_location_id;
        uint16_t control_value_type;
        uint16_t control_domain;
        avdecc_pdu_string64_t control_name;
        uint16_t control_name_string;
        uint16_t width;
        uint16_t height;
        uint16_t number_of_values;
        avdecc_pdu_aem_control_value_union_t formats;
    } avdecc_pdu_aem_descriptor_matrix_t;
    
    /** See IEEE 1722.1 Section 7.2.21 */

    typedef struct avdecc_pdu_aem_descriptor_locale_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_string64_t locale_identifier;
        uint16_t number_of_strings;
        uint16_t base_strings;
    } avdecc_pdu_aem_descriptor_locale_t;

    
#define AVDECC_PDU_AEM_DESCRIPTOR_STRING_MAX_STRINGS (7)     /** See IEEE 1722.1 Section 7.2.22 */  
    
    /** See IEEE 1722.1 Section 7.2.22 */    
    typedef struct avdecc_pdu_aem_descriptor_strings_s
    {
        avdecc_pdu_aem_descriptor_t base;
        avdecc_pdu_string64_t string[AVDECC_PDU_AEM_DESCRIPTOR_STRING_MAX_STRINGS];
    } avdecc_pdu_aem_descriptor_strings_t;
    
    
    /*@}*/
    
#ifdef __cplusplus
}
#endif


#endif

