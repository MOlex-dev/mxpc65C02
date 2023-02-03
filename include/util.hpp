/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Utils               |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <fstream>
#include <vector>
#include <string>

#include "settings.hpp"
#include "exceptions/cmd_exception.hpp"


namespace mxpc65C02
{
    typedef uint8_t  byte_t;
    typedef uint16_t word_t;

    byte_t lower_word(const word_t word) noexcept;
    byte_t higher_word(const word_t word) noexcept;

    settings    cmd_to_settings(const std::vector<std::string> &cmd_args);
    std::vector<byte_t> read_program_from_file(const std::string path);
}