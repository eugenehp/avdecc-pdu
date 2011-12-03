#ifndef AVDECC_PDU_BITS_H_
#define AVDECC_PDU_BITS_H_

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

#define AVDECC_BITS_GET_OCTET_7(v) (uint8_t)((( (v)) >> 56)&0xff)
#define AVDECC_BITS_GET_OCTET_6(v) (uint8_t)((( (v)) >> 48)&0xff)
#define AVDECC_BITS_GET_OCTET_5(v) (uint8_t)((( (v)) >> 40)&0xff)
#define AVDECC_BITS_GET_OCTET_4(v) (uint8_t)((( (v)) >> 32)&0xff)
#define AVDECC_BITS_GET_OCTET_3(v) (uint8_t)((( (v)) >> 24)&0xff)
#define AVDECC_BITS_GET_OCTET_2(v) (uint8_t)((( (v)) >> 16)&0xff)
#define AVDECC_BITS_GET_OCTET_1(v) (uint8_t)((( (v)) >> 8)&0xff)
#define AVDECC_BITS_GET_OCTET_0(v) (uint8_t)((( (v)) >> 0)&0xff)

#define AVDECC_BITS_MAKE_DOUBLET( b1, b0 ) \
( (((uint16_t)(b1))<<8) | (((uint16_t)(b0))<<0) )

#define AVDECC_BITS_MAKE_QUADLET( b3, b2, b1, b0 ) \
( (((uint32_t)(b3))<<24) | (((uint32_t)(b2))<<16) | (((uint32_t)(b1))<<8) | (((uint32_t)(b0))<<0) )

#define AVDECC_BITS_MAKE_SEXLET( b5, b4, b3, b2, b1, b0 ) \
(((uint64_t)AVDECC_BITS_MAKE_QUADLET( 0, 0, (b5), (b4) )<<32) | ((uint64_t)AVDECC_BITS_MAKE_QUADLET((b3),(b2),(b1),(b0))))

#define AVDECC_BITS_MAKE_OCTLET( b7, b6, b5, b4, b3, b2, b1, b0 ) \
(((uint64_t)AVDECC_BITS_MAKE_QUADLET( (b7), (b6), (b5), (b4) )<<32) | ((uint64_t)AVDECC_BITS_MAKE_QUADLET((b3),(b2),(b1),(b0))))


/**
 \addtogroup avdecc_bits IEEE bit packing utilities
 */

/*@{*/

#ifdef __cplusplus
extern "C"
{
#endif



    /** \addtogtoup bit_util bit utilities */
    
    /*@{*/
    
#define AVDECC_BITS_OCTET_BIT(bit) (((uint8_t)0x80)>>(bit))
#define AVDECC_BITS_DOUBLET_BIT(bit) (((uint16_t)0x8000)>>(bit))
#define AVDECC_BITS_QUADLET_BIT(bit) (((uint32_t)0x80000000ULL)>>(bit))
#define AVDECC_BITS_SEXLET_BIT(bit) (((uint64_t)0x800000000000ULL)>>(bit))
#define AVDECC_BITS_OCTLET_BIT(bit) (((uint64_t)0x8000000000000000ULL)>>(bit))
    
#define AVDECC_BITS_OCTET_MASK_BIT(bit) ((~AVDECC_BITS_OCTET_BIT(bit))&0xff)
#define AVDECC_BITS_DOUBLET_MASK_BIT(bit) ((~AVDECC_BITS_DOUBLET_BIT(bit))&0xffff)
#define AVDECC_BITS_QUADLET_MASK_BIT(bit) ((~AVDECC_BITS_QUADLET_BIT(bit))&0xffffffff)
#define AVDECC_BITS_SEXLET_MASK_BIT(bit) ((~AVDECC_BITS_SEXLET_BIT(bit))&0xffffffffffffULL)
#define AVDECC_BITS_OCTLET_MASK_BIT(bit) ((~AVDECC_BITS_OCTLET_BIT(bit))&0xffffffffffffffffULL)
    
#define AVDECC_BITS_IS_BITVALUE_SET( value, bit_value ) (((value)&(bit_value))!=0)
#define AVDECC_BITS_IS_BITVALUE_CLEAR( value, bit_value ) (((value)&(bit_value))==0)
    
#define AVDECC_BITS_MAP_FROM_OCTET_BIT( value, bit, on, off ) ( AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_OCTET_BIT(bit)) ? (on) : (off))
#define AVDECC_BITS_MAP_FROM_DOUBLET_BIT( value, bit, on, off ) ( AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_DOUBLET_BIT(bit)) ? (on) : (off))
#define AVDECC_BITS_MAP_FROM_QUADLET_BIT( value, bit, on, off ) ( AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_QUADLET_BIT(bit)) ? (on) : (off))
#define AVDECC_BITS_MAP_FROM_SEXLET_BIT( value, bit, on, off ) ( AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_SEXLET_BIT(bit)) ? (on) : (off))
#define AVDECC_BITS_MAP_FROM_OCTLET_BIT( value, bit, on, off ) ( AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_OCTLET_BIT(bit)) ? (on) : (off))
    
#define AVDECC_BITS_IS_OCTET_BIT_SET( value, bit ) AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_OCTET_BIT(bit))
#define AVDECC_BITS_IS_DOUBLET_BIT_SET( value, bit ) AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_DOUBLET_BIT(bit))
#define AVDECC_BITS_IS_QUADLET_BIT_SET( value, bit ) AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_QUADLET_BIT(bit))
#define AVDECC_BITS_IS_SEXLET_BIT_SET( value, bit ) AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_SEXLET_BIT(bit))
#define AVDECC_BITS_IS_OCTLET_BIT_SET( value, bit ) AVDECC_BITS_IS_BITVALUE_SET(value,AVDECC_BITS_OCTLET_BIT(bit))
    
#define AVDECC_BITS_IS_OCTET_BIT_CLEAR( value, bit ) AVDECC_BITS_IS_BITVALUE_CLEAR(value,AVDECC_BITS_OCTET_BIT(bit))
#define AVDECC_BITS_IS_DOUBLET_BIT_CLEAR( value, bit ) AVDECC_BITS_IS_BITVALUE_CLEAR(value,AVDECC_BITS_DOUBLET_BIT(bit))
#define AVDECC_BITS_IS_QUADLET_BIT_CLEAR( value, bit ) AVDECC_BITS_IS_BITVALUE_CLEAR(value,AVDECC_BITS_QUADLET_BIT(bit))
#define AVDECC_BITS_IS_SEXLET_BIT_CLEAR( value, bit ) AVDECC_BITS_IS_BITVALUE_CLEAR(value,AVDECC_BITS_SEXLET_BIT(bit))
#define AVDECC_BITS_IS_OCTLET_BIT_CLEAR( value, bit ) AVDECC_BITS_IS_BITVALUE_CLEAR(value,AVDECC_BITS_OCTLET_BIT(bit))
    
#define AVDECC_BITS_GET_OCTET_BIT( value, bit ) AVDECC_BITS_IS_OCTET_BIT_SET( (value), (bit) )
#define AVDECC_BITS_GET_DOUBLET_BIT( value, bit ) AVDECC_BITS_IS_DOUBLET_BIT_SET( (value), (bit) )
#define AVDECC_BITS_GET_QUADLET_BIT( value, bit ) AVDECC_BITS_IS_QUADLET_BIT_SET( (value), (bit) )
#define AVDECC_BITS_GET_SEXLET_BIT( value, bit ) AVDECC_BITS_IS_SEXLET_BIT_SET( (value), (bit) )
#define AVDECC_BITS_GET_OCTLET_BIT( value, bit ) AVDECC_BITS_IS_OCTLET_BIT_SET( (value), (bit) )
    
#define AVDECC_BITS_SET_OCTET_BIT( val, bit )  ((val) | AVDECC_BITS_OCTET_BIT(bit))
#define AVDECC_BITS_SET_DOUBLET_BIT( val, bit )  ((val) | AVDECC_BITS_DOUBLET_BIT(bit))
#define AVDECC_BITS_SET_QUADLET_BIT( val, bit )  ((val) | AVDECC_BITS_QUADLET_BIT(bit))
#define AVDECC_BITS_SET_SEXLET_BIT( val, bit )  ((val) | AVDECC_BITS_SEXLET_BIT(bit))
#define AVDECC_BITS_SET_OCTLET_BIT( val, bit )  ((val) | AVDECC_BITS_OCTLET_BIT(bit))
    
#define AVDECC_BITS_CLEAR_OCTET_BIT( val, bit ) ((val) & AVDECC_BITS_OCTET_MASK_BIT(bit))
#define AVDECC_BITS_CLEAR_DOUBLET_BIT( val, bit ) ((val) & AVDECC_BITS_DOUBLET_MASK_BIT(bit))
#define AVDECC_BITS_CLEAR_QUADLET_BIT( val, bit ) ((val) & AVDECC_BITS_QUADLET_MASK_BIT(bit))
#define AVDECC_BITS_CLEAR_SEXLET_BIT( val, bit ) ((val) & AVDECC_BITS_SEXLET_MASK_BIT(bit))
#define AVDECC_BITS_CLEAR_OCTLET_BIT( val, bit ) ((val) & AVDECC_BITS_OCTLET_MASK_BIT(bit))
    
#define AVDECC_BITS_SET_OCTET_BIT_IF( val, bit, query )  ((query) ? AVDECC_BITS_SET_OCTET_BIT(val,bit) : AVDECC_BITS_CLEAR_OCTET_BIT(val,bit))
#define AVDECC_BITS_SET_DOUBLET_BIT_IF( val, bit, query )  ((query) ? AVDECC_BITS_SET_DOUBLET_BIT(val,bit) : AVDECC_BITS_CLEAR_DOUBLET_BIT(val,bit))
#define AVDECC_BITS_SET_QUADLET_BIT_IF( val, bit, query )  ((query) ? AVDECC_BITS_SET_QUADLET_BIT(val,bit) : AVDECC_BITS_CLEAR_QUADLET_BIT(val,bit))
#define AVDECC_BITS_SET_SEXLET_BIT_IF( val, bit, query )  ((query) ? AVDECC_BITS_SET_SEXLET_BIT(val,bit) : AVDECC_BITS_CLEAR_SEXLET_BIT(val,bit))
#define AVDECC_BITS_SET_OCTLET_BIT_IF( val, bit, query )  ((query) ? AVDECC_BITS_SET_OCTLET_BIT(val,bit) : AVDECC_BITS_CLEAR_OCTLET_BIT(val,bit))
    
#define AVDECC_BITS_CLEAR_OCTET_BIT_IF( val, bit, query )  ((!query) ? AVDECC_BITS_SET_OCTET_BIT(val,bit) : AVDECC_BITS_CLEAR_OCTET_BIT(val,bit))
#define AVDECC_BITS_CLEAR_DOUBLET_BIT_IF( val, bit, query )  ((!query) ? AVDECC_BITS_SET_DOUBLET_BIT(val,bit) : AVDECC_BITS_CLEAR_DOUBLET_BIT(val,bit))
#define AVDECC_BITS_CLEAR_QUADLET_BIT_IF( val, bit, query )  ((!query) ? AVDECC_BITS_SET_QUADLET_BIT(val,bit) : AVDECC_BITS_CLEAR_QUADLET_BIT(val,bit))
#define AVDECC_BITS_CLEAR_SEXLET_BIT_IF( val, bit, query )  ((!query) ? AVDECC_BITS_SET_SEXLET_BIT(val,bit) : AVDECC_BITS_CLEAR_SEXLET_BIT(val,bit))
#define AVDECC_BITS_CLEAR_OCTLET_BIT_IF( val, bit, query )  ((!query) ? AVDECC_BITS_SET_OCTLET_BIT(val,bit) : AVDECC_BITS_CLEAR_OCTLET_BIT(val,bit))
    
    
    /*@}*/
    
    /** \addtogtoup bitfield bitfield utility functions. bit is IEEE style bit number of the lsb of the field */
    
    /*@{*/
    
#define AVDECC_BITS_OCTET_BITFIELD(bit,width) (((0xff)>>(8-(width)))<<(7-(bit)))
#define AVDECC_BITS_DOUBLET_BITFIELD(bit,width) (((0xffff)>>(16-(width)))<<(15-(bit)))
#define AVDECC_BITS_QUADLET_BITFIELD(bit,width) (((0xffffffff)>>(32-(width)))<<(31-(bit)))
#define AVDECC_BITS_SEXLET_BITFIELD(bit,width) (((0xffffffffffffULL)>>(48-(width)))<<(47-(bit)))
#define AVDECC_BITS_OCTLET_BITFIELD(bit,width) (((0xffffffffffffffffULL)>>(64-(width)))<<(63-(bit)))
    
#define AVDECC_BITS_OCTET_MASK_BITFIELD(bit,width) ((~AVDECC_BITS_OCTET_BITFIELD((bit),(width)))&0xff)
#define AVDECC_BITS_DOUBLET_MASK_BITFIELD(bit,width) ((~AVDECC_BITS_DOUBLET_BITFIELD((bit),(width)))&0xffff)
#define AVDECC_BITS_QUADLET_MASK_BITFIELD(bit,width) ((~AVDECC_BITS_QUADLET_BITFIELD((bit),(width)))&0xffffffff)
#define AVDECC_BITS_SEXLET_MASK_BITFIELD(bit,width) ((~AVDECC_BITS_SEXLET_BITFIELD((bit),(width)))&0xffffffffffffULL)
#define AVDECC_BITS_OCTLET_MASK_BITFIELD(bit,width) ((~AVDECC_BITS_OCTLET_BITFIELD((bit),(width)))&0xffffffffffffffffULL)
    
#define AVDECC_BITS_GET_OCTET_BITFIELD_W(val,bit,width)  (((val) & AVDECC_BITS_OCTET_BITFIELD(bit,width)) >> (7-(bit)))
#define AVDECC_BITS_GET_DOUBLET_BITFIELD_W(val,bit,width)  (((val) & AVDECC_BITS_DOUBLET_BITFIELD(bit,width)) >> (15-(bit)))
#define AVDECC_BITS_GET_QUADLET_BITFIELD_W(val,bit,width)  (((val) & AVDECC_BITS_QUADLET_BITFIELD(bit,width)) >> (31-(bit)))
#define AVDECC_BITS_GET_SEXLET_BITFIELD_W(val,bit,width)  (((val) & AVDECC_BITS_SEXLET_BITFIELD(bit,width)) >> (47-(bit)))
#define AVDECC_BITS_GET_OCTLET_BITFIELD_W(val,bit,width)  (((val) & AVDECC_BITS_OCTLET_BITFIELD(bit,width)) >> (63-(bit)))
    
#define AVDECC_BITS_SET_OCTET_BITFIELD_W(val,bit,width,fieldval) (((fieldval)<<(7-(bit))) | ((val) & AVDECC_BITS_OCTET_MASK_BITFIELD((bit),(width))))
#define AVDECC_BITS_SET_DOUBLET_BITFIELD_W(val,bit,width,fieldval) (((fieldval)<<(15-(bit))) | ((val) & AVDECC_BITS_DOUBLET_MASK_BITFIELD((bit),(width))))
#define AVDECC_BITS_SET_QUADLET_BITFIELD_W(val,bit,width,fieldval) (((fieldval)<<(31-(bit))) | ((val) & AVDECC_BITS_QUADLET_MASK_BITFIELD((bit),(width))))
#define AVDECC_BITS_SET_SEXLET_BITFIELD_W(val,bit,width,fieldval) (((fieldval)<<(47-(bit))) | ((val) & AVDECC_BITS_SEXLET_MASK_BITFIELD((bit),(width))))
#define AVDECC_BITS_SET_OCTLET_BITFIELD_W(val,bit,width,fieldval) (((fieldval)<<(63-(bit))) | ((val) & AVDECC_BITS_OCTLET_MASK_BITFIELD((bit),(width))))
    
#define AVDECC_BITS_GET_OCTET_BITFIELD(val,msb,lsb) AVDECC_BITS_GET_OCTET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1 )
#define AVDECC_BITS_GET_DOUBLET_BITFIELD(val,msb,lsb) AVDECC_BITS_GET_DOUBLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1 )
#define AVDECC_BITS_GET_QUADLET_BITFIELD(val,msb,lsb) AVDECC_BITS_GET_QUADLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1 )
#define AVDECC_BITS_GET_SEXLET_BITFIELD(val,msb,lsb) AVDECC_BITS_GET_SEXLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1 )
#define AVDECC_BITS_GET_OCTLET_BITFIELD(val,msb,lsb) AVDECC_BITS_GET_OCTLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1 )
    
#define AVDECC_BITS_SET_OCTET_BITFIELD(val,msb,lsb,fieldval) AVDECC_BITS_SET_OCTET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1, fieldval )
#define AVDECC_BITS_SET_DOUBLET_BITFIELD(val,msb,lsb,fieldval) AVDECC_BITS_SET_DOUBLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1, fieldval )
#define AVDECC_BITS_SET_QUADLET_BITFIELD(val,msb,lsb,fieldval) AVDECC_BITS_SET_QUADLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1, fieldval )
#define AVDECC_BITS_SET_SEXLET_BITFIELD(val,msb,lsb,fieldval) AVDECC_BITS_SET_SEXLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1, fieldval )
#define AVDECC_BITS_SET_OCTLET_BITFIELD(val,msb,lsb,fieldval) AVDECC_BITS_SET_OCTLET_BITFIELD_W( (val), (lsb), (lsb)-(msb)+1, fieldval )
    
    
    /*@}*/
    
#define AVDECC_BITS_MAP_OCTET( prefix, fieldname, type, octet_offset_of_octet ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octet(base, octet_offset_of_octet ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octet( base, octet_offset_of_octet, (uint8_t)new_field_value ); \
}
    
#define AVDECC_BITS_MAP_DOUBLET( prefix, fieldname, type, octet_offset_of_doublet ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_doublet(base, octet_offset_of_doublet ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_doublet( base, octet_offset_of_doublet, (uint16_t)new_field_value ); \
}
    
#define AVDECC_BITS_MAP_QUADLET( prefix, fieldname, type, octet_offset_of_quadlet ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_quadlet(base, octet_offset_of_quadlet ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_quadlet( base, octet_offset_of_quadlet, (uint32_t)new_field_value ); \
}
    
#define AVDECC_BITS_MAP_SEXLET( prefix, fieldname, type, octet_offset_of_sexlet ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_sexlet(base, octet_offset_of_sexlet ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_sexlet( base, octet_offset_of_sexlet, (uint64_t)new_field_value ); \
}
    
#define AVDECC_BITS_MAP_OCTLET( prefix, fieldname, type, octet_offset_of_octlet ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octlet(base, octet_offset_of_octlet ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octlet( base, octet_offset_of_octlet, (uint64_t)new_field_value ); \
}
    
    
    
#define AVDECC_BITS_MAP_OCTET_BITFIELD( prefix, fieldname, type, octet_offset_of_octet, msb, lsb ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octet_bitfield(base, octet_offset_of_octet, msb, lsb ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octet_bitfield( base, octet_offset_of_octet, msb, lsb, (uint8_t)new_field_value ); \
}
    
    
    
#define AVDECC_BITS_MAP_DOUBLET_BITFIELD( prefix, fieldname, type, octet_offset_of_doublet, msb, lsb ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_doublet_bitfield(base, octet_offset_of_doublet, msb, lsb ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_doublet_bitfield( base, octet_offset_of_doublet, msb, lsb, (uint16_t)new_field_value ); \
}
    
    
    
#define AVDECC_BITS_MAP_QUADLET_BITFIELD( prefix, fieldname, type, octet_offset_of_quadlet, msb, lsb ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_quadlet_bitfield(base, octet_offset_of_quadlet, msb, lsb ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_quadlet_bitfield( base, octet_offset_of_quadlet, msb, lsb, (uint32_t)new_field_value ); \
}
    
#define AVDECC_BITS_MAP_SEXLET_BITFIELD( prefix, fieldname, type, octet_offset_of_sexlet, msb, lsb ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_sexlet_bitfield(base, octet_offset_of_sexlet, msb, lsb ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_sexlet_bitfield( base, octet_offset_of_sexlet, msb, lsb, (uint32_t)new_field_value ); \
}
    
    
#define AVDECC_BITS_MAP_OCTLET_BITFIELD( prefix, fieldname, type, octet_offset_of_octlet, msb, lsb ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octlet_bitfield(base, octet_offset_of_octlet, msb, lsb ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octlet_bitfield( base, octet_offset_of_octlet, msb, lsb, (uint64_t)new_field_value ); \
}
    
    /* bits */
    
#define AVDECC_BITS_MAP_OCTET_BIT( prefix, fieldname, type, octet_offset_of_octet, bit ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octet_bit(base, octet_offset_of_octet, bit ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octet_bit( base, octet_offset_of_octet, bit, new_field_value ? true : false ); \
}
    
    
    
#define AVDECC_BITS_MAP_DOUBLET_BIT( prefix, fieldname, type, octet_offset_of_doublet, bit ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_doublet_bit(base, octet_offset_of_doublet, bit ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_doublet_bit( base, octet_offset_of_doublet, bit,  new_field_value ? true : false ); \
}
    
    
    
#define AVDECC_BITS_MAP_QUADLET_BIT( prefix, fieldname, type, octet_offset_of_quadlet, bit ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_quadlet_bit(base, octet_offset_of_quadlet, bit ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_quadlet_bit( base, octet_offset_of_quadlet, bit,  new_field_value ? true : false ); \
}
    
#define AVDECC_BITS_MAP_SEXLET_BIT( prefix, fieldname, type, octet_offset_of_sexlet, bit ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_sexlet_bit(base, octet_offset_of_sexlet, bit ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_sexlet_bit( base, octet_offset_of_sexlet, bit,  new_field_value ? true : false ); \
}
    
    
#define AVDECC_BITS_MAP_OCTLET_BITD( prefix, fieldname, type, octet_offset_of_octlet, bit ) \
static inline type prefix ## _get_ ## fieldname( const void *base ) \
{ \
    return (type)avdecc_bits_get_octlet_bit(base, octet_offset_of_octlet, bit ); \
} \
static inline void prefix ## _set_ ## fieldname( void *base, type new_field_value ) \
{ \
    avdecc_bits_set_octlet_bit( base, octet_offset_of_octlet, bit, new_field_value ? true : false); \
}
    
    
    
    static inline
    uint8_t avdecc_bits_get_octet ( const void *base, uint16_t offset )
    {
        const uint8_t *data = ( const uint8_t * ) base;
        return data[offset];
    }
    
    static inline
    void avdecc_bits_set_octet ( void *base, uint16_t offset, uint8_t value )
    {
        uint8_t *data = ( uint8_t * ) base;
        data[offset] = value;
    }
    
    static inline
    uint16_t avdecc_bits_get_doublet ( const void *base, uint16_t offset )
    {
        const uint8_t *data = ( const uint8_t * ) base;
        return AVDECC_BITS_MAKE_DOUBLET ( data[offset], data[offset+1] );
    }
    
    static inline
    void avdecc_bits_set_doublet ( void *base, uint16_t offset, uint16_t value )
    {
        uint8_t *data = ( uint8_t * ) base;
        data[offset] = AVDECC_BITS_GET_OCTET_1 ( value );
        data[offset+1] = AVDECC_BITS_GET_OCTET_0 ( value );
    }
    
    static inline
    uint32_t avdecc_bits_get_quadlet ( const void *base, uint16_t offset )
    {
        const uint8_t *data = ( const uint8_t * ) base;
        return AVDECC_BITS_MAKE_QUADLET ( data[offset], data[offset+1], data[offset+2], data[offset+3] );
    }
    
    static inline
    void avdecc_bits_set_quadlet ( void *base, uint16_t offset, uint32_t v )
    {
        uint8_t *data = ( uint8_t * ) base;
        data[offset] = AVDECC_BITS_GET_OCTET_3 ( v );
        data[offset+1] = AVDECC_BITS_GET_OCTET_2 ( v );
        data[offset+2] = AVDECC_BITS_GET_OCTET_1 ( v );
        data[offset+3] = AVDECC_BITS_GET_OCTET_0 ( v );
    }
    
    static inline
    uint64_t avdecc_bits_get_sexlet ( const void *base, uint16_t offset )
    {
        const uint8_t *data = ( const uint8_t * ) base;
        uint64_t v;
        v=AVDECC_BITS_MAKE_SEXLET (
              data[offset],
              data[offset+1],
              data[offset+2],
              data[offset+3],
              data[offset+4],
              data[offset+5]
          );
        return v;
    }
    
    static inline
    void avdecc_bits_set_sexlet ( void *base, uint16_t offset, uint64_t v )
    {
        uint8_t *data = ( uint8_t * ) base;
        data[offset] = AVDECC_BITS_GET_OCTET_5 ( v );
        data[offset+1] = AVDECC_BITS_GET_OCTET_4 ( v );
        data[offset+2] = AVDECC_BITS_GET_OCTET_3 ( v );
        data[offset+3] = AVDECC_BITS_GET_OCTET_2 ( v );
        data[offset+4] = AVDECC_BITS_GET_OCTET_1 ( v );
        data[offset+5] = AVDECC_BITS_GET_OCTET_0 ( v );
    }
    
    static inline
    uint64_t avdecc_bits_get_octlet ( const void *base, uint16_t offset )
    {
        const uint8_t *data = ( const uint8_t * ) base;
        uint64_t v;
        v=AVDECC_BITS_MAKE_OCTLET (
              data[offset],
              data[offset+1],
              data[offset+2],
              data[offset+3],
              data[offset+4],
              data[offset+5],
              data[offset+6],
              data[offset+7]
          );
        return v;
    }
    
    static inline
    void avdecc_bits_set_octlet ( void *base, uint16_t offset, uint64_t v )
    {
        uint8_t *data = ( uint8_t * ) base;
        data[offset] = AVDECC_BITS_GET_OCTET_7 ( v );
        data[offset+1] = AVDECC_BITS_GET_OCTET_6 ( v );
        data[offset+2] = AVDECC_BITS_GET_OCTET_5 ( v );
        data[offset+3] = AVDECC_BITS_GET_OCTET_4 ( v );
        data[offset+4] = AVDECC_BITS_GET_OCTET_3 ( v );
        data[offset+5] = AVDECC_BITS_GET_OCTET_2 ( v );
        data[offset+6] = AVDECC_BITS_GET_OCTET_1 ( v );
        data[offset+7] = AVDECC_BITS_GET_OCTET_0 ( v );
    }
    
    static inline
    uint8_t avdecc_bits_get_octet_bitfield ( const void *base, uint16_t offset, uint16_t msb, uint16_t lsb )
    {
        uint8_t v=avdecc_bits_get_octet ( base, offset );
        uint8_t r=AVDECC_BITS_GET_OCTET_BITFIELD ( v, msb, lsb );
        return r;
    }
    
    static inline
    void avdecc_bits_set_octet_bitfield ( void *base, uint16_t offset, uint16_t msb, uint16_t lsb, uint32_t newbits )
    {
        uint8_t v=avdecc_bits_get_octet ( base, offset );
        v=AVDECC_BITS_SET_OCTET_BITFIELD ( v, msb, lsb, newbits );
        avdecc_bits_set_octet ( base, offset, v );
    }
    
    static inline
    uint16_t avdecc_bits_get_doublet_bitfield ( const void *base, uint16_t offset, uint16_t msb, uint16_t lsb )
    {
        uint32_t v=avdecc_bits_get_doublet ( base, offset );
        uint32_t r=AVDECC_BITS_GET_DOUBLET_BITFIELD ( v, msb, lsb );
        return r;
    }
    
    static inline
    void avdecc_bits_set_doublet_bitfield ( void *base, uint16_t offset, uint16_t msb, uint16_t lsb, uint32_t newbits )
    {
        uint16_t v=avdecc_bits_get_doublet ( base, offset );
        v=AVDECC_BITS_SET_DOUBLET_BITFIELD ( v, msb, lsb, newbits );
        avdecc_bits_set_doublet ( base, offset, v );
    }
    
    static inline
    uint32_t avdecc_bits_get_quadlet_bitfield ( const void *base, uint16_t offset, uint16_t msb, uint16_t lsb )
    {
        uint32_t v=avdecc_bits_get_quadlet ( base, offset );
        uint32_t r=AVDECC_BITS_GET_QUADLET_BITFIELD ( v, msb, lsb );
        return r;
    }
    
    static inline
    void avdecc_bits_set_quadlet_bitfield ( void *base, uint16_t offset, uint16_t msb, uint16_t lsb, uint32_t newbits )
    {
        uint32_t v=avdecc_bits_get_quadlet ( base, offset );
        v=AVDECC_BITS_SET_QUADLET_BITFIELD ( v, msb, lsb, newbits );
        avdecc_bits_set_quadlet ( base, offset, v );
    }
    
    static inline
    uint64_t avdecc_bits_get_sexlet_bitfield ( const void *base, uint16_t offset, uint16_t msb, uint16_t lsb )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        uint64_t r=AVDECC_BITS_GET_SEXLET_BITFIELD ( v, msb, lsb );
        return r;
    }
    
    static inline
    void avdecc_bits_set_sexlet_bitfield ( void *base, uint16_t offset, uint16_t msb, uint16_t lsb, uint64_t newbits )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        v=AVDECC_BITS_SET_SEXLET_BITFIELD ( v, msb, lsb, newbits );
        avdecc_bits_set_sexlet ( base, offset, v );
    }
    
    static inline
    uint64_t avdecc_bits_get_octlet_bitfield ( const void *base, uint16_t offset, uint16_t msb, uint16_t lsb )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        uint64_t r=AVDECC_BITS_GET_OCTLET_BITFIELD ( v, msb, lsb );
        return r;
    }
    
    static inline
    void avdecc_bits_set_octlet_bitfield ( void *base, uint16_t offset, uint16_t msb, uint16_t lsb, uint64_t newbits )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        v=AVDECC_BITS_SET_OCTLET_BITFIELD ( v, msb, lsb, newbits );
        avdecc_bits_set_octlet ( base, offset, v );
    }
    
    /* bits */
    
    static inline
    bool avdecc_bits_get_octet_bit ( const void *base, uint16_t offset, uint16_t bit )
    {
        uint8_t v=avdecc_bits_get_octet ( base, offset );
        bool r=AVDECC_BITS_GET_OCTET_BIT ( v, bit );
        return r;
    }
    
    static inline
    void avdecc_bits_set_octet_bit ( void *base, uint16_t offset, uint16_t bit, bool newbits )
    {
        uint8_t v=avdecc_bits_get_octet ( base, offset );
        v=AVDECC_BITS_SET_OCTET_BIT_IF ( v, bit, newbits );
        avdecc_bits_set_octet ( base, offset, v );
    }
    
    static inline
    bool avdecc_bits_get_doublet_bit ( const void *base, uint16_t offset, uint16_t bit )
    {
        uint32_t v=avdecc_bits_get_doublet ( base, offset );
        bool r=AVDECC_BITS_GET_DOUBLET_BIT ( v, bit );
        return r;
    }
    
    static inline
    void avdecc_bits_set_doublet_bit ( void *base, uint16_t offset, uint16_t bit, bool newbits )
    {
        uint16_t v=avdecc_bits_get_doublet ( base, offset );
        v=AVDECC_BITS_SET_DOUBLET_BIT_IF ( v, bit, newbits );
        avdecc_bits_set_doublet ( base, offset, v );
    }
    
    static inline
    bool avdecc_bits_get_quadlet_bit ( const void *base, uint16_t offset, uint16_t bit )
    {
        uint32_t v=avdecc_bits_get_quadlet ( base, offset );
        bool r=AVDECC_BITS_GET_QUADLET_BIT ( v, bit );
        return r;
    }
    
    static inline
    void avdecc_bits_set_quadlet_bit ( void *base, uint16_t offset, uint16_t bit, bool newbits )
    {
        uint32_t v=avdecc_bits_get_quadlet ( base, offset );
        v=AVDECC_BITS_SET_QUADLET_BIT_IF ( v, bit, newbits );
        avdecc_bits_set_quadlet ( base, offset, v );
    }
    
    static inline
    bool avdecc_bits_get_sexlet_bit ( const void *base, uint16_t offset, uint16_t bit )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        bool r=AVDECC_BITS_GET_SEXLET_BIT ( v, bit );
        return r;
    }
    
    static inline
    void avdecc_bits_set_sexlet_bit ( void *base, uint16_t offset, uint16_t bit, bool newbits )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        v=AVDECC_BITS_SET_SEXLET_BIT_IF ( v, bit, newbits );
        avdecc_bits_set_sexlet ( base, offset, v );
    }
    
    static inline
    bool avdecc_bits_get_octlet_bit ( const void *base, uint16_t offset, uint16_t bit )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        bool r=AVDECC_BITS_GET_OCTLET_BIT ( v, bit );
        return r;
    }
    
    static inline
    void avdecc_bits_set_octlet_bit ( void *base, uint16_t offset, uint16_t bit, bool newbits )
    {
        uint64_t v=avdecc_bits_get_octlet ( base, offset );
        v=AVDECC_BITS_SET_OCTLET_BIT_IF ( v, bit, newbits );
        avdecc_bits_set_octlet ( base, offset, v );
    }
    
#ifdef __cplusplus
}
#endif

/*@}*/

#endif
