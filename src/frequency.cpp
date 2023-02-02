/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |             Frequency             |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/frequency.hpp"

using namespace mxpc65C02;


frequency::
frequency() noexcept
    : frequency(1) {}

frequency::
frequency(const hertz_t freq) noexcept
{ m_frequency = freq; }


hertz_t                 frequency::
value() const noexcept
{ return m_frequency; }

void                    frequency::
value(const hertz_t freq) noexcept
{ m_frequency = freq; }


hertz_t                 frequency::
from_kilo(const std::uint32_t kilohertz) noexcept
{ return (hertz_t)kilohertz * 1'000; }

hertz_t                 frequency::
from_mega(const std::uint32_t megahertz) noexcept
{ return (hertz_t)megahertz * 1'000'000; }

hertz_t                 frequency::
from_giga(const std::uint32_t gigahertz) noexcept
{ return (hertz_t)gigahertz * 1'000'000'000; }


std::ostream&           mxpc65C02::
operator<<(std::ostream &os, const frequency &frq)
{
    os << frq.m_frequency;
    return os;
}
