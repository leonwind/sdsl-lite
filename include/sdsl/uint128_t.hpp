/* sdsl - succinct data structures library
    Copyright (C) 2012 Simon Gog, Matthias Petri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see http://www.gnu.org/licenses/ .
*/
/*! \file uint128_t.hpp
   \brief uint128_t.hpp contains contains the definition of a 128-bit unsigned integer type.
   \author Simon Gog, Matthias Petri
*/
#ifndef INCLUDED_SDSL_UINT128
#define INCLUDED_SDSL_UINT128

#include <iostream>
#include "bitmagic.hpp"

namespace sdsl
{

typedef unsigned int uint128_t __attribute__((mode(TI)));

inline
std::ostream& operator<<(std::ostream& os, const uint128_t& x)
{
    uint64_t X[2] = {(uint64_t)(x >> 64), (uint64_t)x};
    for (int j=0; j < 2; ++j) {
        for (int i=0; i < 16; ++i) {
            os << std::hex << ((X[j]>>60)&0xFULL);
            X[j] <<= 4;
        }
    }
    return os;
};


} // end namespace

#endif
