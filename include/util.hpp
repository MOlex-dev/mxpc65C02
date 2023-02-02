/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Utils               |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <fstream>


namespace mxpc65C02
{
    typedef uint8_t  byte_t;
    typedef uint16_t word_t;

    byte_t lower_word(const word_t word) noexcept;
    byte_t higher_word(const word_t word) noexcept;
}