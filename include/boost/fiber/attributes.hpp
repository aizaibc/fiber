
//          Copyright Oliver Kowalke 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FIBERS_ATTRIBUTES_H
#define BOOST_FIBERS_ATTRIBUTES_H

#include <cstddef>

#include <boost/config.hpp>

#include <boost/fiber/flags.hpp>
#include <boost/fiber/stack_allocator.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

namespace boost {
namespace fibers {

struct attributes
{
    std::size_t     size;
    flag_fpu_t      preserve_fpu;

    attributes() BOOST_NOEXCEPT :
        size( stack_allocator::default_stacksize() ),
        preserve_fpu( fpu_preserved)
    {}

    explicit attributes( std::size_t size_) BOOST_NOEXCEPT :
        size( size_),
        preserve_fpu( fpu_preserved)
    {}

    explicit attributes( flag_fpu_t preserve_fpu_) BOOST_NOEXCEPT :
        size( stack_allocator::default_stacksize() ),
        preserve_fpu( preserve_fpu_)
    {}

    explicit attributes(
            std::size_t size_,
            flag_fpu_t preserve_fpu_) BOOST_NOEXCEPT :
        size( size_),
        preserve_fpu( preserve_fpu_)
    {}
};

}}

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_FIBERS_ATTRIBUTES_H
