#pragma once
#ifndef IEEE802_3_HPP
#define IEEE802_3_HPP

#include "ieee.hpp"

namespace IEEE802_3
{
using namespace IEEE;


typedef octet_block<6,'-'> mac48;
typedef octet_block<8,'-'> mac64;

struct vlan_tci
{
    field<octet,0,doublet,0,2> pcp;
    field<bool,0,doublet,3> cfi;
    field<doublet,0,doublet,4,15> vid;

    vlan_tci( doublet v=0 )
    {
        unflatten(v);
    }

    operator doublet() const
    {
        return flatten();
    }

    doublet operator = ( doublet v )
    {
        unflatten(v);
        return v;
    }

    void unflatten( doublet v )
    {
        pcp << v;
        cfi << v;
        vid << v;
    }

    doublet flatten() const
    {
        doublet v=0;
        pcp >> v;
        cfi >> v;
        vid >> v;
        return v;
    }

};

inline std::ostream & operator << (std::ostream &s, vlan_tci const &v )
{
    ostream_state_save flags(s);
    s << labelfmt("pcp") << hexfmt(v.pcp) << std::endl;
    s << labelfmt("cfi") << boolfmt(v.cfi) << std::endl;
    s << labelfmt("vid") << hexfmt(v.vid);
    return s;
}


struct ethernet_header
{
    typedef ethernet_header pdu_type;

    typedef field<mac48,0> destination_address_field;
    typedef field<mac48,6> source_address_field;
    typedef field<vlan_tci,14,doublet> vlan_tci_field;
    typedef field<doublet,12> untagged_ethertype_field;
    typedef field<doublet,16> tagged_ethertype_field;

    destination_address_field destination_address;
    source_address_field source_address;
    bool tagged;
    vlan_tci_field vlan;
    doublet ethertype;
    size_t offset_to_payload;

    template <typename PduBuffer>
    void store( PduBuffer &buf ) const
    {
        destination_address >> buf;
        source_address >> buf;
        if( tagged )
        {
            untagged_ethertype_field tag=0x8100;
            tag >> buf;
            vlan >> buf;
            tagged_ethertype_field e=ethertype;
            e >> buf;
        }
        else
        {
            untagged_ethertype_field e=ethertype;
            e >> buf;
        }
    }

    template <typename PduBuffer>
    void retrieve( PduBuffer &buf )
    {
        destination_address << buf;
        source_address << buf;
        untagged_ethertype_field e;
        e << buf;
        if( e==0x8100)
        {
            tagged = true;
            vlan << buf;
            tagged_ethertype_field te;
            te << buf;
            ethertype = te;
            offset_to_payload = 18;
        }
        else
        {
            tagged = false;
            ethertype = e;
            offset_to_payload = 14;
        }
    }

    size_t get_total_offset_to_payload() const
    {
        return offset_to_payload;
    }
};



inline std::ostream & operator << (std::ostream &s, ethernet_header const &v )
{
    ostream_state_save flags(s);
    s << labelfmt("DA") << v.destination_address << std::endl;
    s << labelfmt("SA") << v.source_address << std::endl;
    if( v.tagged )
    {
        s << titlefmt("VLAN Tag") << v.vlan << std::endl;
    }
    s << labelfmt("EtherType") << hexfmt(v.ethertype) << std::endl;
    s << labelfmt("PayloadOffset") << hexfmt(v.offset_to_payload) << std::endl;
    return s;
}

}

#endif // IEEE802_3_HPP
