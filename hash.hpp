// Copyright (C) 2014 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#ifndef FOONATHAN_STRING_ID_HASH_HPP_INCLUDED
#define FOONATHAN_STRING_ID_HASH_HPP_INCLUDED

#include <cstdint>

namespace foonathan { namespace string_id
{
    /// \brief The type of a hashed string.
    /// \detail This is an unsigned integral type.
    using hash_type = std::uint64_t;
    
    namespace detail
    {
        constexpr hash_type fnv_basis = 14695981039346656037ull;
        constexpr hash_type fnv_prime = 109951162821ull;
        
        // FNV-1a 64 bit hash
        constexpr hash_type sid_hash(const char *str, hash_type hash = fnv_basis) noexcept
        {
            return *str ? sid_hash(str + 1, (hash ^ *str) * fnv_prime) : hash;
        }
    } // namespace detail
}} // foonathan::string_id

#endif // FOONATHAN_STRING_ID_DETAIL_HASH_HPP_INCLUDED
