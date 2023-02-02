/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |         Computer Settings         |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <map>

#include "frequency.hpp"


namespace mxpc65C02
{
    class settings
    {
    public:
        enum class screen_mode { BITMAP_DISPLAY, SYMBOLIC_DISPLAY };

        settings(const std::string src_file_path = "program.bin", const frequency freq = 10,
                 const screen_mode scr_mode = screen_mode::SYMBOLIC_DISPLAY) noexcept;

        std::string program_file_path() const noexcept;
        screen_mode monitor_mode() const noexcept;
        frequency   frequency_cpu() const noexcept;

        void program_file_path(std::string file_path) noexcept;
        void monitor_mode(const screen_mode mode) noexcept;
        void frequency_cpu(const frequency freq) noexcept;

        static std::string screen_mode_to_str(const screen_mode &mode) noexcept;

    private:
        std::string  m_prg_file_path {};
        screen_mode  m_screen_mode   {};
        frequency    m_frequency     {};

        const static std::map<screen_mode, std::string> screen_mode_str;

        friend std::ostream& operator<<(std::ostream &os, const settings &st);
        friend std::ostream& operator<<(std::ostream &os, const screen_mode &st);
    };
    std::ostream& operator<<(std::ostream &os, const settings::screen_mode &st);
    std::ostream& operator<<(std::ostream &os, const settings &st);
}