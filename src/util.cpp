/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Utils               |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/util.hpp"

using namespace mxpc65C02;


byte_t                  mxpc65C02::
lower_word(const word_t word) noexcept
{ return word % 0x1'00; }

byte_t                  mxpc65C02::
higher_word(const word_t word) noexcept
{ return word / 0x1'00; }
