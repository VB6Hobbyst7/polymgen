#pragma once
#include "polytope.h"

namespace spt {

template <std::size_t Dim = 3, typename Real = typename spt::vec<Dim>::real_type>
using vertex = polytope<0, Dim, Real>;


template <std::size_t Dim, typename Real>
struct polytope<0, Dim, Real>
{
    static constexpr auto n = 0;
    static constexpr auto dim = Dim;
    using real_type = Real;

    spt::vec<Dim, Real> pos;

    polytope() = delete;
    polytope(const spt::vec<Dim, Real>& pos)
        : pos(pos) {}
    polytope(const polytope& other)
        : pos(other.pos) {}
};

} // namespace spt
