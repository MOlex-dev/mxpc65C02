/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |         Computer Settings         |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/settings.hpp"

using namespace mxpc65C02;
using screen_mode = mxpc65C02::settings::screen_mode;


settings::
settings(const std::string src_file_path, const frequency freq, const screen_mode scr_mode) noexcept
    : m_prg_file_path {std::move(src_file_path)}, m_frequency {freq}, m_screen_mode {scr_mode} {}


std::string             settings::
program_file_path() const noexcept
{ return m_prg_file_path; }

screen_mode             settings::
monitor_mode() const noexcept
{ return m_screen_mode; }

frequency               settings::
frequency_cpu() const noexcept
{ return m_frequency; }

void                    settings::
program_file_path(std::string file_path) noexcept
{ m_prg_file_path = std::move(file_path); }

void                    settings::
monitor_mode(const screen_mode mode) noexcept
{ m_screen_mode = mode; }

void                    settings::
frequency_cpu(const frequency freq) noexcept
{ m_frequency = freq; }


std::string             settings::
screen_mode_to_str(const screen_mode &mode) noexcept
{ return screen_mode_str.at(mode);}


const std::map<screen_mode, std::string>    settings::
screen_mode_str
{
    { screen_mode::BITMAP_DISPLAY,   "BITMAP DISPLAY" },
    { screen_mode::SYMBOLIC_DISPLAY, "SYMBOLIC DISPLAY"}
};


std::ostream&           mxpc65C02::
operator<<(std::ostream &os, const settings::screen_mode &st)
{
    os << settings::screen_mode_to_str(st);
    return os;
}

std::ostream&           mxpc65C02::
operator<<(std::ostream &os, const settings &st)
{
    os << '\n' << std::setw(15) << "Source file: " << st.m_prg_file_path;
    os << '\n' << std::setw(15) << "Frequency: "   << st.m_frequency;
    os << '\n' << std::setw(15) << "Screen mode: " << st.m_screen_mode;
    return os;
}