#pragma once
#ifndef IEEE_HPP
#define IEEE_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdint.h>

#ifdef WIN32
#ifndef BYTE_ORDER
# define BYTE_ORDER 1234
#endif
#ifndef LITTLE_ENDIAN
# define LITTLE_ENDIAN 1234
#endif
#ifndef BIG_ENDIAN
# define BIG_ENDIAN 4321
#endif
#endif

namespace IEEE
{
/// noncopyable base class
struct noncopyable
{
    noncopyable() {}
private:
    noncopyable( noncopyable const & );
    noncopyable const & operator = ( noncopyable const & );
};



/** \addtogroup statesave stream state saver
 * @{
 */

/// output stream flag state saver
template < typename Ch=char, class Tr=std::char_traits<Ch> >
class basic_ostream_state_save_ : noncopyable
{
    std::basic_ostream<Ch,Tr> &s;
    typename std::basic_ios<Ch,Tr>::fmtflags f;
    std::streamsize prec;
    std::streamsize width;

public:
    basic_ostream_state_save_( std::basic_ostream<Ch,Tr> &s_ )
        :
          s( s_ ),
          f( s_.flags() ),
          prec( s_.precision() ),
          width( s_.width() )
    {
    }

    ~basic_ostream_state_save_()
    {
        s.flags( f );
        s.precision( prec );
        s.width( width );
    }
};

class ostream_state_save : public basic_ostream_state_save_<char,std::char_traits<char> >
{
public:
    ostream_state_save( std::basic_ostream<char,std::char_traits<char> > &s_ )
        : basic_ostream_state_save_<char,std::char_traits<char> >(s_)
    {
    }
};

/// output stream flag state saver
template < typename Ch=char, class Tr=std::char_traits<Ch> >
class basic_istream_state_save_ : noncopyable
{
    std::basic_istream<Ch,Tr> &s;
    typename std::basic_ios<Ch,Tr>::fmtflags f;
    std::streamsize prec;
    std::streamsize width;

public:
    basic_istream_state_save_( std::basic_istream<Ch,Tr> &s_ )
        :
          s( s_ ),
          f( s_.flags() ),
          prec( s_.precision() ),
          width( s_.width() )
    {
    }

    ~basic_istream_state_save_()
    {
        s.flags( f );
        s.precision( prec );
        s.width( width );
    }
};

class istream_state_save : public basic_istream_state_save_<char,std::char_traits<char> >
{
public:
    istream_state_save( std::basic_istream<char,std::char_traits<char> > &s_ )
        : basic_istream_state_save_<char,std::char_traits<char> >(s_)
    {
    }
};

/* @} */

/** \addtogroup fundamental Fundamental types IEEE names
 *  @{
 */

typedef uint8_t octet;
typedef uint16_t doublet;
typedef uint32_t quadlet;
typedef uint64_t octlet;

/* @} */

/** \addtogroup utility_traits Utility traits class to find appropriate storage type from size field
 * @{
 */

template <size_t SZ>
struct size_to_storage
{
    typedef void storage_type;
};

template <>
struct size_to_storage<1>
{
    typedef octet storage_type;
};

template <>
struct size_to_storage<2>
{
    typedef doublet storage_type;
};

template <>
struct size_to_storage<4>
{
    typedef quadlet storage_type;
};

template <>
struct size_to_storage<8>
{
    typedef octlet storage_type;
};

/* @} */

/** \addtogroup ostreamfmt ostream formatting helpers
 *
 *  @{
 */


/** \addtogroup nullfmt ostream nullfmt helper for output formatting.
 *  does no additional formatting.
 *  @{
 */

template <typename T>
struct nullfmt
{
    typedef void nullfmt_void;

    T value;
    nullfmt(T v) : value(v) {}
};

template <typename T>
inline std::ostream & operator << (std::ostream &o, nullfmt<T> const &f )
{
    o << f.value;
    return o;
}

/* @} */

/** \addtogroup boolfmt ostream octetfmt helper for output formatting.
 *  Outputs a octet in a two digit hexadecimal format.
 *  @{
 */

struct boolfmt
{
    typedef void boolfmt_void;

    bool value;

    boolfmt(bool v) : value(v)
    {
    }
};

inline std::ostream & operator << (std::ostream &o, boolfmt const &f )
{
    ostream_state_save flags(o);
    o << std::boolalpha << f.value << std::noboolalpha;
    return o;
}

struct boolref
{
    typedef void boolref_void;

    bool &value;

    boolref(bool &v) : value(v)
    {
    }
};

inline std::istream & operator >> (std::istream &i, boolref f )
{
    istream_state_save flags(i);
    i >> std::boolalpha >> f.value >> std::noboolalpha;
    return i;
}


/* @} */
/** \addtogroup octetfmt ostream octetfmt helper for output formatting.
 *  Outputs a octet in a two digit hexadecimal format.
 *  @{
 */

struct octetfmt
{
    typedef void octetfmt_void;

    octet value;
    
    octetfmt(octet v) : value(v)
    {
    }
};

inline std::ostream & operator << (std::ostream &o, octetfmt const &f )
{
    ostream_state_save flags(o);
    o << std::setfill('0') << std::setw( 2 ) << std::hex << uint16_t(f.value);
    return o;
}

struct octetref
{
    typedef void octetref_void;

    octet &value;
    
    octetref(octet &v) : value(v)
    {
    }
};

inline std::istream & operator >> (std::istream &i, octetref f )
{
    istream_state_save flags(i);
    uint16_t v;
    i >> std::hex >> v;
    if( v>0xff )
    {
        i.clear( std::ios_base::failbit );
    }
    f.value = static_cast<octet>(v&0xff);
    return i;
}


/* @} */

/** \addtogroup hexfmt ostream hexfmt helper for output formatting
 *  Outputs any type with the appropriate number of hex digits, prefaced with 0x
 *
 * @{
 */

template <size_t Digits,typename T>
struct hexfmt_obj
{
    typedef void hexfmt_obj_void;

    T value;

    hexfmt_obj(T v) : value(v)
    {
    }

};

template <typename T>
inline
hexfmt_obj<sizeof(T)*2, typename size_to_storage<sizeof(T)>::storage_type >
hexfmt( T v )
{
    return hexfmt_obj<sizeof(T)*2,typename size_to_storage<sizeof(T)>::storage_type>(
                static_cast<typename size_to_storage<sizeof(T)>::storage_type>(v)
                );
}

template <size_t Digits, typename T>
inline std::ostream & operator << (std::ostream &o, hexfmt_obj<Digits,T> const &f )
{
    ostream_state_save flags(o);
    if( f.value )
    {
        o << std::internal << std::setw( Digits+2 ) << std::showbase << std::setfill('0') << std::hex << f.value;
    }
    else // workaround for standard library insistence to not print 0x if value is 0
    {
        o << "0x" << std::internal << std::setw( Digits ) << std::setfill('0') << std::hex << f.value;
    }
    return o;
}

template <typename T>
inline std::ostream & operator << (std::ostream &o, hexfmt_obj<2,T> const &f )
{
    ostream_state_save flags(o);
    if( f.value )
    {
        o << std::internal << std::setw( 2+2 ) << std::showbase << std::setfill('0') << std::hex << doublet(f.value);
    }
    else // workaround for standard library insistence to not print 0x if value is 0
    {
        o << "0x" << std::internal << std::setw( 2 ) << std::setfill('0') << std::hex << doublet(f.value);
    }
    return o;
}

template <size_t Digits,typename T>
struct hexref_obj
{
    typedef void hexref_obj_void;

    T &value;

    hexref_obj(T &v) : value(v)
    {
    }

};

template <typename T>
inline
hexref_obj<sizeof(T)*2, typename size_to_storage<sizeof(T)>::storage_type >
hexref( T &v )
{
    return hexref_obj<sizeof(T)*2,typename size_to_storage<sizeof(T)>::storage_type>(
                *(typename size_to_storage<sizeof(T)>::storage_type *)(&v)
                );
}


template <size_t Digits, typename T>
inline std::istream & operator >> (std::istream &i, hexref_obj<Digits,T> const f )
{
    istream_state_save flags(i);
    i.unsetf(std::ios_base::basefield);
    i >> f.value;
    return i;
}

template <typename T>
inline std::istream & operator >> (std::istream &i, hexref_obj<2,T> const f )
{
    istream_state_save flags(i);
    i.unsetf(std::ios_base::basefield);
    uint16_t v=0;
    i >> v;
    if( v>0xff )
    {
        i.clear( std::ios_base::failbit );
    }
    f.value = static_cast<octet>(v&0xff);
    return i;
}


/* @} */



/** \addtogroup titlefmt ostream titlefmt helper for output formatting.
 *  Outputs a char * string or std::string left justified with a width padded with spaces.
 *
 * @{
 */
template <typename T>
struct titlefmt_obj
{
};


template <>
struct titlefmt_obj<char *>
{
    char const *text;
    size_t width;

    titlefmt_obj( char const *text_, size_t width_ )
        : text(text_), width( width_ )
    {
    }
};

template <>
struct titlefmt_obj<std::string>
{
    std::string const &text;
    size_t width;

    titlefmt_obj( std::string const &text_, size_t width_ )
        : text(text_), width( width_ )
    {
    }
};


inline titlefmt_obj<char *> titlefmt( char const *text, size_t width=0 )
{
    return titlefmt_obj<char *>(text,width);
}

inline titlefmt_obj<std::string> titlefmt( std::string const &text, size_t width=0 )
{
    return titlefmt_obj<std::string>(text,width);
}


template <typename T>
inline std::ostream & operator << ( std::ostream &o, titlefmt_obj<T> const &f )
{
    ostream_state_save flags(o);
    o << std::left << std::setfill(' ') << std::setw(f.width) << f.text << ':' << std::endl;
    return o;
}

/* @} */


/** \addtogroup labelfmt ostream labelfmt helper for output formatting.
 *  Outputs a char * string or std::string right justified with a width padded with spaces.
 *
 * @{
 */
template <typename T>
struct labelfmt_obj
{
};


template <>
struct labelfmt_obj<char *>
{
    char const *text;
    size_t width;

    labelfmt_obj( char const *text_, size_t width_ )
        : text(text_), width( width_ )
    {
    }
};

template <>
struct labelfmt_obj<std::string>
{
    std::string const &text;
    size_t width;

    labelfmt_obj( std::string const &text_, size_t width_ )
        : text(text_), width( width_ )
    {
    }
};


inline labelfmt_obj<char *> labelfmt( char const *text, size_t width=24 )
{
    return labelfmt_obj<char *>(text,width);
}

inline labelfmt_obj<std::string> labelfmt( std::string const &text, size_t width=24 )
{
    return labelfmt_obj<std::string>(text,width);
}


template <typename T>
inline std::ostream & operator << ( std::ostream &o, labelfmt_obj<T> const &f )
{
    ostream_state_save flags(o);
    o << std::right << std::setfill(' ') << std::setw(f.width) << f.text << ": ";
    return o;
}

/* @} */

/* @} */

/** \addtogroup pdu_buffer pdu_buffer classes
 * @{
 */

/** pdu_buffer_ref class, adaptor class to adapt a plain old array to a pdu_buffer
 *
 */
template <size_t MaxLen>
struct pdu_buffer_ref
{
    typedef void pdu_buffer_void_type;
    typedef std::istream pdu_buffer_istream_type;
    typedef std::ostream pdu_buffer_ostream_type;

    typedef pdu_buffer_ref<MaxLen> pdu_buffer_type;

    /// The reference to the array
    octet (&data)[MaxLen];
    /// The current payload length
    size_t len;
    /// The maximum length allowed
    static const size_t max_len = MaxLen;
    /// The offset into the array is 0 as this is never a slice
    static const size_t pre_offset = 0;

    /// Construct a pdu_buffer_ref to refer to a C array, initialized with payload length
    pdu_buffer_ref(octet (&data_)[MaxLen], size_t len_=0)
        :
          data(data_),
          len(len_)
    {
    }

    /// Construct a copy of a pdu_buffer_ref
    pdu_buffer_ref( pdu_buffer_type const &o)
        : data(o.data),
          len( o.len )
    {
    }

    /// Copy the contents of another pdu_buffer_ref of the same size
    pdu_buffer_type const & operator = ( pdu_buffer_type const &o )
    {
        if( &o != this )
        {
            memcpy( data, o.data, sizeof(data) );
            len = o.len;
        }
        return *this;
    }

    /// Get a pointer to the octet at the specific pos
    octet * at(size_t pos)
    {
        return &data[pos];
    }

    /// Get a pointer to the const octet at the specific pos
    octet const * at(size_t pos) const
    {
        return &data[pos];
    }

    /// Set the payload length
    void set_len(size_t l)
    {
        len=l;
    }

    /// Get the payload length
    size_t get_len() const
    {
        return len;
    }

    size_t get_maxlen() const
    {
        return max_len;
    }

};


template <size_t MaxLen>
struct const_pdu_buffer_ref
{
    typedef void pdu_buffer_void_type;
    typedef void const_pdu_buffer_void_type;
    typedef std::istream pdu_buffer_istream_type;
    typedef std::ostream pdu_buffer_ostream_type;
    typedef const_pdu_buffer_ref<MaxLen> pdu_buffer_type;

    octet const (&data)[MaxLen];
    size_t len;
    static const size_t max_len = MaxLen;
    static const size_t pre_offset = 0;

    const_pdu_buffer_ref(octet const (&data_)[MaxLen], size_t len_ )
        :
          data(data_), len(len_)
    {
    }

    const_pdu_buffer_ref( pdu_buffer_type const &o)
        : data(o.data),
          len( o.len )
    {
    }

    octet const * at(size_t pos) const
    {
        return &data[pos];
    }


    size_t get_len() const
    {
        return len;
    }

    size_t get_maxlen() const
    {
        return max_len;
    }
};



template <size_t MaxLen>
inline pdu_buffer_ref<MaxLen> make_pdu_buffer( octet (&data)[MaxLen], size_t len=MaxLen )
{
    return pdu_buffer_ref<MaxLen>(data,len);
}



template <size_t MaxLen>
inline const_pdu_buffer_ref<MaxLen> make_const_pdu_buffer( octet const (&data)[MaxLen], size_t len=0)
{
    return const_pdu_buffer_ref<MaxLen>(data,len);
}


template <size_t MaxLen>
struct pdu_buffer
{
    typedef void pdu_buffer_void_type;
    typedef std::istream pdu_buffer_istream_type;
    typedef std::ostream pdu_buffer_ostream_type;
    typedef pdu_buffer<MaxLen> pdu_buffer_type;

    octet data[MaxLen];
    size_t len;
    static const size_t max_len = MaxLen;
    static const size_t pre_offset = 0;

    pdu_buffer() : len(0)
    {
        memset( data,0, sizeof(data));
    }

    pdu_buffer( pdu_buffer_type const &o)
        : len( o.len )
    {
        memcpy( data, o.data, sizeof(data) );
    }

    pdu_buffer_type const & operator = ( pdu_buffer_type const &o )
    {
        if( &o != this )
        {
            memcpy( data, o.data, sizeof(data) );
            len = o.len;
        }
        return *this;
    }

    octet * at(size_t pos)
    {
        return &data[pos];
    }

    octet const * at(size_t pos) const
    {
        return &data[pos];
    }

    void set_len(size_t l)
    {
        len=l;
    }

    size_t get_len() const
    {
        return len;
    }

    size_t get_maxlen() const
    {
        return max_len;
    }

    octet operator [] ( size_t pos ) const
    {
        return data[pos];
    }

    octet & operator [] ( size_t pos )
    {
        return data[pos];
    }

};



template <typename TargetType>
struct pdu_buffer_slice
{
    typedef void pdu_buffer_void_type;
    typedef std::istream pdu_buffer_istream_type;
    typedef std::ostream pdu_buffer_ostream_type;
    typedef pdu_buffer_slice<TargetType> pdu_buffer_type;
    typedef typename TargetType::pdu_buffer_type pdu_buffer_target_type;

    pdu_buffer_target_type &target;

    size_t pre_offset;

    pdu_buffer_slice( TargetType &t, size_t pre_offset_ =0 )
        : target(t),
          pre_offset( pre_offset_ )
    {
    }

    octet * at(size_t pos)
    {
        return target.at(pos+pre_offset);
    }

    octet const * at(size_t pos) const
    {
        return target.at(pos+pre_offset);
    }

    void set_len(size_t l)
    {
        target.set_len( l + pre_offset );
    }

    size_t get_len() const
    {
        return (target.get_len() > pre_offset) ? (target.get_len()-pre_offset) : 0;
    }

    size_t get_maxlen() const
    {
        return target.get_maxlen() - pre_offset;
    }

    octet operator [] ( size_t pos ) const
    {
        return target[pos];
    }

    octet & operator [] ( size_t pos )
    {
        return target[pos];
    }

};

template <typename TargetType>
struct const_pdu_buffer_slice
{
    typedef void pdu_buffer_void_type;
    typedef void const_pdu_buffer_void_type;
	    
    typedef std::istream pdu_buffer_istream_type;
    typedef std::ostream pdu_buffer_ostream_type;
    typedef const_pdu_buffer_slice<TargetType> pdu_buffer_type;
    typedef typename TargetType::pdu_buffer_type pdu_buffer_target_type;

    pdu_buffer_target_type const &target;

    size_t pre_offset;

    const_pdu_buffer_slice( TargetType const &t, size_t pre_offset_ )
        : target(t),
          pre_offset( pre_offset_ )
    {
    }

    octet const * at(size_t pos) const
    {
        return target.at(pos+pre_offset);
    }

    size_t get_len() const
    {
        return (target.get_len() > pre_offset) ? (target.get_len()-pre_offset) : 0;
    }

    size_t get_maxlen() const
    {
        return target.get_maxlen() - pre_offset;
    }

    octet operator [] ( size_t pos ) const
    {
        return target[pos];
    }

    octet & operator [] ( size_t pos )
    {
        return target[pos];
    }
};



template <typename TargetType>
inline typename pdu_buffer_slice<TargetType>::pdu_buffer_type make_slice( TargetType &target, size_t pre_offset )
{
    return pdu_buffer_slice<TargetType>(target,pre_offset);
}


template <typename PduBuffer>
inline typename PduBuffer::pdu_buffer_ostream_type & operator << ( std::ostream &s, PduBuffer const &v )
{
    ostream_state_save flags(s);
    s << labelfmt("MaxLen") << hexfmt(v.get_maxlen()) << std::endl;
    s << labelfmt("Len") << hexfmt(v.get_len()) << std::endl;
    s << labelfmt("Data");
    for( size_t i=0; i<v.get_len(); ++i )
    {
        s << octetfmt(*v.at(i)) << ' ';
    }
    return s;
}


template <typename PduBuffer>
inline typename PduBuffer::pdu_buffer_istream_type &operator >> (std::istream &i, PduBuffer &v )
{
    istream_state_save flags(i);
    i >> std::hex;
    size_t len=0;
    i >> hexref(len);
    if( len>v.get_maxlen() )
    {
        i.clear( std::ios_base::failbit );
        len=v.get_maxlen();
    }
    for( size_t n=0; n<len; ++n )
    {
        i >> octetref(*v.at(n));
    }
    v.set_len(len);
    return i;
}

/* @} */

/** \addtogroup octetblock Octet Block object, holds a data type that is comprised of an array of octets
 *
 * @{
 */

/// Octet Block
template <size_t N, char Separator=':' >
struct octet_block
{
    typedef void octet_block_void;
    typedef octet_block<N,Separator> octet_block_type;

    static const size_t size = N;
    static const char separator = Separator;

    octet_block()
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i]=0;
        }
    }

    template <char S1>
    octet_block( octet_block<N,S1> const &o )
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i]=o.b[i];
        }
    }

    octet_block( octet const v[size] )
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i]=v[i];
        }
    }

    octet_block_type const & operator = ( octet const v[size] )
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i]=v[i];
        }

        return *this;
    }

    template <char S1>
    octet_block_type operator = ( octet_block<N,S1> const &o )
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i]=o.b[i];
        }
        return *this;
    }

    void store( uint8_t *dest ) const
    {
        for( size_t i=0; i<size; ++i )
        {
            dest[i] = b[i];
        }
    }

    void retrieve( uint8_t const *src )
    {
        for( size_t i=0; i<size; ++i )
        {
            b[i] = src[i];
        }
    }

    void set(size_t n, octet v )
    {
        b[n] = v;
    }

    octet get(size_t n) const
    {
        return b[n];
    }

    size_t get_len() const
    {
        return size;
    }

    char get_separator() const
    {
        return separator;
    }

    octet operator [] ( size_t pos ) const
    {
        return b[pos];
    }

    octet & operator [] ( size_t pos )
    {
        return b[pos];
    }
    octet b[N];
};


template <size_t N, char Separator>
inline std::ostream & operator << ( std::ostream &s, octet_block<N,Separator> const &v )
{
    ostream_state_save flags(s);

    for( size_t i=0; i<v.size; ++i )
    {
        s << octetfmt( v.b[i] );
        if( i!=v.size-1 && Separator!='\0')
        {
            s << Separator;
        }
    }
    return s;
}

template <size_t N, char Separator>
inline std::istream & operator >> (std::istream &i, octet_block<N,Separator> &v )
{
    istream_state_save flags(i);
    i >> std::hex;
    for( size_t n=0; n<N; ++n )
    {
        i >> octetref(v.b[n]);
        if( n!=N-1 && Separator!='\0')
        {
            char c;
            i >> c;
            if( c!=Separator )
            {
                i.clear( std::ios_base::failbit );
                break;
            }
        }
    }
    
    return i;
}


/* @} */

/** \addtogroup ieee_types IEEE octet block based data types
 * @{
 */

typedef octet_block<3,'-'> oui24;
typedef octet_block<4,'-'> eui32;
typedef octet_block<5,'-'> oui36;
typedef octet_block<6,'-'> eui48;
typedef octet_block<8,'-'> eui64;


/* @} */

/** \addtogroup storage_traits storage_traits to provide bit information for fundamental types
 *
 * @{
 */
template <typename StorageType>
struct storage_traits
{
};


template <>
struct storage_traits<octet>
{
    typedef octet type;
    static const char * name() { return "octet"; }
    static const size_t bits=8;
    static const type msb_value=0x80U;
    static const type allbits=~(type(0));
    static const size_t size=1;
    static type value_for_bit(size_t bit) { return msb_value >> bit; }
};

template <>
struct storage_traits<doublet>
{
    typedef doublet type;
    static const char * name() { return "doublet"; }
    static const size_t bits=16;
    static const type msb_value=0x8000U;
    static const type allbits=~(type(0));
    static const size_t size=2;
    static type value_for_bit(size_t bit) { return msb_value >> bit; }
};


template <>
struct storage_traits<quadlet>
{
    typedef quadlet type;
    static const char * name() { return "quadlet"; }
    static const size_t bits=32;
    static const type msb_value=0x80000000UL;
    static const type allbits=~(type(0));
    static const size_t size=4;
    static type value_for_bit(size_t bit) { return msb_value >> bit; }
};


template <>
struct storage_traits<octlet>
{
    typedef octlet type;
    static const char * name() { return "octlet"; }
    static const size_t bits=64;
    static const type msb_value=0x8000000000000000ULL;
    static const type allbits=~(type(0));
    static const size_t size=8;
    static type value_for_bit(size_t bit) { return msb_value >> bit; }

};

/* @} */


/** \addtogroup endian Endian Utilities
 *
 * @{
 */

inline void endian_reverse( octet const &vin, octet &vout )
{
    vout = vin;
}

inline void endian_reverse( doublet const &vin, doublet &vout )
{
    octet const *p = reinterpret_cast< octet const * >(&vin);
    vout =
            ((doublet)(p[1])<<0) +
            ((doublet)(p[0])<<8);

}

inline void endian_reverse( quadlet const &vin, quadlet &vout )
{
    octet const *p = reinterpret_cast< octet const * >(&vin);
    vout =
            ((quadlet)(p[3])<<0) +
            ((quadlet)(p[2])<<8) +
            ((quadlet)(p[1])<<16) +
            ((quadlet)(p[0])<<24);
}

inline void endian_reverse( octlet const &vin, octlet &vout )
{
    octet const *p = reinterpret_cast< octet const * >(&vin);
    vout =
            ((octlet)(p[7])<<0) +
            ((octlet)(p[6])<<8) +
            ((octlet)(p[5])<<16) +
            ((octlet)(p[4])<<24) +
            ((octlet)(p[3])<<32) +
            ((octlet)(p[2])<<40) +
            ((octlet)(p[1])<<48) +
            ((octlet)(p[0])<<56);
}


inline void endian_big_to_native( octet const &vin, octet &vout )
{
    vout = vin;
}

inline void endian_big_to_native( doublet const &vin, doublet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}

inline void endian_big_to_native( quadlet const &vin, quadlet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}

inline void endian_big_to_native( octlet const &vin, octlet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}


inline void endian_little_to_native( octet const &vin, octet &vout )
{
    vout = vin;
}

inline void endian_little_to_native( doublet const &vin, doublet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}

inline void endian_little_to_native( quadlet const &vin, quadlet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}

inline void endian_little_to_native( octlet const &vin, octlet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}


inline void native_to_big_endian( octet const &vin, octet &vout )
{
    vout = vin;
}

inline void native_to_big_endian( doublet const &vin, doublet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}

inline void native_to_big_endian( quadlet const &vin, quadlet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}

inline void native_to_big_endian( octlet const &vin, octlet &vout )
{
#if BYTE_ORDER == LITTLE_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == BIG_ENDIAN
    vout = vin;
#endif
}


inline void native_to_little_endian( octet const &vin, octet &vout )
{
    vout = vin;
}

inline void native_to_little_endian( doublet const &vin, doublet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}

inline void native_to_little_endian( quadlet const &vin, quadlet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}

inline void native_to_little_endian( octlet const &vin, octlet &vout )
{
#if BYTE_ORDER == BIG_ENDIAN
    endian_reverse(vin,vout);
#elif BYTE_ORDER == LITTLE_ENDIAN
    vout = vin;
#endif
}

/* @} */




template <typename PduType, typename PduBuffer>
inline typename PduType::pdu_type * operator << ( PduType &pdu, PduBuffer const &v )
{
    pdu.retrieve(v);
    return 0;
}

template <typename PduType, typename PduBuffer>
inline typename PduType::pdu_type * operator >> ( PduType &pdu, pdu_buffer_slice<PduBuffer> v )
{
    pdu.store(v);
    return 0;
}

template <typename PduBuffer>
inline pdu_buffer_slice<PduBuffer> payload( PduBuffer &pdu, size_t offset=0)
{
    return make_slice(pdu,offset);
}

template <typename PduType, typename PduBuffer>
inline pdu_buffer_slice<PduBuffer> payload( PduType &pdu, PduBuffer &buf, typename PduType::pdu_type * = 0)
{
    return make_slice(buf,pdu.get_total_offset_to_payload());
}

/** \addtogroup field field - ield in a PDU
 *
 * @{
 */

/// field - field in a PDU.
template <typename FieldType, size_t Offset, typename StorageType=FieldType, int MsbBit=-1, int LsbBit=-1>
struct field
{
    typedef void field_type_void;

    typedef field<FieldType,Offset,StorageType,MsbBit,LsbBit> pdu_type;
    typedef StorageType storage_type;
    typedef FieldType field_type;
    const static int msb_bit = MsbBit;
    const static int lsb_bit = LsbBit;
    const static int shift = storage_traits<StorageType>::bits - LsbBit - 1;
    const static int width = (1 + LsbBit - MsbBit);
    const static storage_type mask = ((storage_traits<StorageType>::allbits) >> (storage_traits<StorageType>::bits - width)) << shift;
    const static storage_type inverse_mask = storage_type(~mask);

    StorageType flatten( StorageType orig = 0 ) const
    {
        storage_type s= storage_type(value);
        s = s << shift;
        s = (s & mask) | (orig & inverse_mask);
        return s;
    }

    void unflatten( StorageType s )
    {
        s = s & mask;
        s = s >> shift;
        value = FieldType(s);
    }

    field() : value()
    {
    }

    field( StorageType v )
    {
        unflatten(v);
    }


    template <size_t N>
    field( pdu_buffer<N> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType *>(buf.at( Offset ));
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename TargetType>
    field( pdu_buffer_slice<TargetType> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename TargetType>
    field( const_pdu_buffer_slice<TargetType> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <size_t N>
    field( pdu_buffer_ref<N> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <size_t N>
    field( const_pdu_buffer_ref<N> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename PduBuffer>
    void store( PduBuffer &buf ) const
    {
        StorageType *s = reinterpret_cast<StorageType *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        orig = flatten(orig);
        native_to_big_endian(orig,*s);
    }

    template <typename PduBuffer>
    void retrieve( PduBuffer const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }


    operator FieldType() const
    {
        return value;
    }

    FieldType operator = ( FieldType f )
    {
        value = f;
        return f;
    }

    FieldType value;

    void operator << ( StorageType const &v )
    {
        unflatten(v);
    }

    void operator >> ( StorageType &v ) const
    {
        v=flatten(v);
    }
};

template <size_t Offset, int Bit, typename StorageType>
struct field<bool,Offset,StorageType,Bit,-1>
{
    typedef void field_type_void;

    typedef bool FieldType;    
    typedef field<FieldType,Offset,StorageType,Bit,-1> pdu_type;
    typedef StorageType storage_type;
    typedef FieldType field_type;
    const static int msb_bit = Bit;
    const static int lsb_bit = Bit;
    const static int shift = storage_traits<StorageType>::bits - Bit - 1;
    const static int width = 1;
    const static storage_type mask = storage_type(1) << shift;
    const static storage_type inverse_mask = storage_type(~mask);

    StorageType flatten( StorageType orig = 0 ) const
    {
        storage_type s= storage_type(value ? 1 : 0);
        s = s << shift;
        s = (s & mask) | (orig & inverse_mask);
        return s;
    }

    void unflatten( StorageType s )
    {
        s = s & mask;
        value = FieldType(s!=0);
    }


    field() : value()
    {
    }

    field( StorageType v )
    {
        unflatten(v);
    }


    template <size_t N>
    field( pdu_buffer<N> const &buf )
    {
        StorageType *s = reinterpret_cast<StorageType *>(buf.at( Offset ));
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename TargetType>
    field( pdu_buffer_slice<TargetType> const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename TargetType>
    field( const_pdu_buffer_slice<TargetType> const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <size_t N>
    field( pdu_buffer_ref<N> const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <size_t N>
    field( const_pdu_buffer_ref<N> const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }

    template <typename PduBuffer>
    void store( PduBuffer &buf ) const
    {
        StorageType *s = reinterpret_cast<StorageType *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        orig = flatten(orig);
        native_to_big_endian(orig,*s);
    }

    template <typename PduBuffer>
    void retrieve( PduBuffer const &buf )
    {
        StorageType const *s = reinterpret_cast<StorageType const *>(buf.at( Offset ) );
        StorageType orig;
        endian_big_to_native(*s,orig);
        unflatten(orig);
    }


    operator FieldType() const
    {
        return value;
    }

    FieldType operator = ( FieldType f )
    {
        value = f;
        return f;
    }

    FieldType value;

    void operator << ( StorageType const &v )
    {
        unflatten(v);
    }

    void operator >> ( StorageType &v ) const
    {
        v=flatten(v);
    }
};

template <typename FieldType, size_t Offset, typename StorageType, int MsbBit, int LsbBit>
inline std::ostream & operator << ( std::ostream &s, field<FieldType,Offset,StorageType,MsbBit,LsbBit> const &v )
{
    s << v.value;
    return s;
}

template <size_t Offset, typename StorageType, int Bit>
inline std::ostream & operator << ( std::ostream &s, field<bool,Offset,StorageType,Bit> const &v )
{
    s << boolfmt(v.value);
    return s;
}

/* @} */

/** \addtogroup field field - a fundamental type field at an octet offset in a PDU
 *
 * @{
 */

template <typename FieldType, size_t Offset, typename StorageType >
struct field<FieldType,Offset,StorageType,-1,-1>
{
    FieldType value;

    typedef void field_type_void;
    typedef field<FieldType,Offset,StorageType,-1,-1> pdu_type;
    typedef StorageType storage_type;
    typedef FieldType field_type;

    const static size_t msb_bit = 0;
    const static size_t lsb_bit = storage_traits<StorageType>::size*8-1;
    const static size_t shift = 0;
    const static size_t width = storage_traits<StorageType>::size*8;
    const static size_t len = storage_traits<StorageType>::size;

    field() : value()
    {
    }

    field( storage_type const &v )
        : value(v)
    {
    }


    template <size_t N>
    field( pdu_buffer<N> const &buf )
    {
        retrieve(buf);
    }

    template <typename TargetType>
    field( pdu_buffer_slice<TargetType> const &buf )
    {
        retrieve(buf);
    }


    template <typename PduBuffer>
    void store( PduBuffer &buf ) const
    {
        storage_type *s = reinterpret_cast<storage_type *>(buf.at( Offset ) );        
        storage_type v=value;
        native_to_big_endian(v,*s);
    }

    template <typename PduBuffer>
    void retrieve( PduBuffer const &buf )
    {
        storage_type const *s = reinterpret_cast<storage_type const *>(buf.at( Offset ) );
        storage_type v;
        endian_big_to_native(*s,v);
        value=v;
    }

    operator FieldType () const
    {
        return value;
    }

    FieldType operator = ( FieldType const &f )
    {
        value = f;
        return f;
    }
};


/* @} */

/** \addtogroup octet_block_field octet block field - octet_block in a PDU
 *
 * @{
 */

template <size_t N, char Separator, size_t Offset >
struct field< octet_block<N,Separator>, Offset, octet_block<N,Separator>, -1, -1 >
{
    typedef void field_type_void;
    typedef octet_block<N,Separator> FieldType;
    FieldType value;

    typedef field< octet_block<N,Separator>, Offset, octet_block<N,Separator>, -1, -1 > pdu_type;
    typedef typename FieldType::octet_block_type octet_block_type;

    typedef FieldType storage_type;
    typedef FieldType field_type;

    const static size_t msb_bit = 0;
    const static size_t lsb_bit = FieldType::size*8-1;
    const static size_t shift = 0;
    const static size_t width = FieldType::size*8;
    const static size_t len = FieldType::size;

    field() : value()
    {
    }

    field( storage_type const &v )
        : value(v)
    {
    }


    template <size_t M>
    field( pdu_buffer<M> const &buf )
    {
        retrieve(buf);
    }

    template <typename TargetType>
    field( pdu_buffer_slice<TargetType> const &buf )
    {
        retrieve(buf);
    }

    template <typename TargetType>
    field( const_pdu_buffer_slice<TargetType> const &buf )
    {
        retrieve(buf);
    }

    template <size_t M>
    field( pdu_buffer_ref<M> const &buf )
    {
        retrieve(buf);
    }

    template <size_t M>
    field( const_pdu_buffer_ref<M> const &buf )
    {
        retrieve(buf);
    }

    template <typename PduBuffer>
    void store( PduBuffer &buf ) const
    {
        if( len+Offset <= buf.get_maxlen() )
        {
            value.store(buf.at(Offset));
        }
    }

    template <typename PduBuffer>
    void retrieve( PduBuffer const &buf )
    {
        if( len+Offset <= buf.get_maxlen() )
        {
            value.retrieve(buf.at( Offset ));
        }
    }

    operator FieldType &() const
    {
        return value;
    }

    FieldType & operator = ( FieldType const &f )
    {
        value = f;
        return f;
    }

};


/* @} */

/** \addtogroup to_from_string to_string and from_string helper functions
 * @{
 */

inline void to_string( std::string &outstr, std::string const &v )
{
    outstr = v;
}

inline void from_string( std::string const &instr, std::string &v )
{
    v=instr;
}


template <typename T>
inline typename T::boolfmt_void to_string( std::string &outstr, T v )
{
    std::stringstream s;
    s << v;
    outstr = s.str();
}

template <typename T>
inline typename T::boolref_void from_string( std::string const &instr, T v )
{
    std::stringstream s(instr);
    s >> v;
}

template <typename T>
inline typename T::octetfmt_void to_string( std::string &outstr, T v )
{
    std::stringstream s;
    s << v;
    outstr = s.str();
}

template <typename T>
inline typename T::octetref_void from_string( std::string const &instr, T v )
{
    std::stringstream s(instr);
    s >> v;
}


template <typename T>
inline typename T::hexfmt_obj_void to_string( std::string &outstr, T v )
{
    std::stringstream s;
    s << v;
    outstr = s.str();
}

template <typename T>
inline typename T::hexref_obj_void from_string( std::string const &instr, T v )
{
    std::stringstream s(instr);
    s >> v;
}

template <typename T>
inline typename T::field_type_void to_string( std::string &outstr, T const &v )
{
    std::stringstream s;
    s << v;
    outstr = s.str();
}

template <typename T>
inline typename T::field_type_void from_string( std::string const &instr, T &v )
{
    std::stringstream s(instr);
    s >> v;
}


template <typename T>
inline typename T::octet_block_void to_string( std::string &outstr, T const &v )
{
    std::stringstream s;
    s << v;
    outstr = s.str();
}

template <typename T>
inline typename T::octet_block_void from_string( std::string const &instr, T &v )
{
    std::stringstream s(instr);
    s >> v;
}

/* @} */

}

#endif
