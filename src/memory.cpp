/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Memory              |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/memory.hpp"

using namespace mxpc65C02;
using mxpc65C02::exception::memory_exception;


memory::
memory() noexcept
    : m_memory(memory_size) {}


void                    memory::
load_program(const std::vector<byte_t> &program)
{
    if (program.size() > max_program_size) {
        throw memory_exception("Program size is too big! Maximal program size: " + std::to_string(max_program_size)
                               + " bytes!");
    }
    std::memcpy(m_memory.data() + (word_t)segments::PROGRAM_BEGIN, program.data(), program.size());
}


byte_t                  memory::
read_byte(const word_t address) const noexcept
{ return m_memory[address]; }

word_t                  memory::
read_word(const word_t address) const
{
    if (address == max_address) {
        throw memory_exception("Can't read WORD from 0xFFFF address!");
    }
    return m_memory[address] + m_memory[address + 1] * 0x1'00;
}

void                    memory::
write_byte(const word_t address, const byte_t data)
{
    if (is_readonly_segment(address)) {
        throw memory_exception("Can't write to READONLY segment!");
    }
    m_memory[address] = data;
}

void                    memory::
write_word(const word_t address, const word_t data)
{
    if (address == max_address) {
        throw memory_exception("Can't write WORD to 0xFFFF address!");
    }
    if (is_readonly_segment(address) or is_readonly_segment(address + 1)) {
        throw memory_exception("Can't write to READONLY segment!");
    }

    m_memory[address] = lower_word(data);
    m_memory[address + 1] = higher_word(data);
}


bool                    memory::
is_readonly_segment(const word_t address)
{ return address >= (word_t)segments::ROM_BEGIN and address <= (word_t)segments::ROM_END; }


const std::size_t       memory::
memory_size = 0x1'00'00;

const std::size_t       memory::
max_program_size = (word_t)segments::PROGRAM_END - (word_t)segments::PROGRAM_BEGIN + 1;

const word_t            memory::
max_address = 0xFF'FF;


std::ostream&           mxpc65C02::
operator<<(std::ostream &os, const memory &mem)
{
    os << '\n' << std::hex << std::uppercase << std::setw(5) << ' ' << '|';
    for (uint8_t i = 0; i < 0x10; ++i) {
        os << ' ' << std::setfill('0') << std::setw(2) << +i;
    }

    os << '\n' << std::setfill('-') << std::setw(54) << '-';
    for (std::size_t i = 0; i < memory::memory_size; ) {
        if (i % 0x10 == 0) {
            os << '\n';
            os << std::setfill('0') << std::setw(4) << i << " |";
        }
        os << ' ' << std::setfill('0') << std::setw(2) << +mem.m_memory[i];
        ++i;
    }
    os << std::endl;
    return os;
}