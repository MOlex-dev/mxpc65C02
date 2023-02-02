/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |             Frequency             |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <iostream>

namespace mxpc65C02
{
    typedef std::size_t hertz_t;

    class frequency
    {
    public:
        frequency() noexcept;
        frequency(const hertz_t freq) noexcept;

        hertz_t value() const noexcept;
        void    value(const hertz_t freq) noexcept;

        static hertz_t from_kilo(const std::uint32_t kilohertz) noexcept;
        static hertz_t from_mega(const std::uint32_t megahertz) noexcept;
        static hertz_t from_giga(const std::uint32_t gigahertz) noexcept;

    private:
        hertz_t m_frequency;

        friend std::ostream& operator<<(std::ostream &os, const frequency &frq);
    };

    std::ostream& operator<<(std::ostream &os, const frequency &frq);
};
