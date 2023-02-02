/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Memory              |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

#include "../include/util.hpp"
#include "../include/exceptions/memory_exception.hpp"


namespace mxpc65C02
{
    class memory
    {
    public:
        enum class segments : word_t
        {
            ZERO_PAGE_BEGIN = 0x00'00,
                FAST_ACCESS_STORAGE_BEGIN = 0x00'00,
                FAST_ACCESS_STORAGE_END   = 0x00'FD,

                ROM_VARIABLES_BEGIN = 0x00'F5,
                ROM_VARIABLES_END   = 0x00'FD,

                RANDOM_NUMBER    = 0x00'FE,

                LAST_PRESSED_KEY = 0x00'FF,
            ZERO_PAGE_END   = 0x00'FF,

            STACK_BOTTOM = 0x01'00,
            STACK_TOP    = 0x01'FF,

            BITMAP_DISPLAY_BEGIN = 0x02'00,
            BITMAP_DISPLAY_END   = 0x05'FF,

            PROGRAM_BEGIN = 0x06'00,
            PROGRAM_END   = 0xEF'FF,

            SYMBOL_DISPLAY_BEGIN = 0xF0'00,
            SYMBOL_DISPLAY_END   = 0xFC'FF,

            EXPANSIONS_BEGIN = 0xFD'00,
            EXPANSIONS_END   = 0xFD'FF,

            ROM_BEGIN = 0xFE'00,
                IO_CHAR_KEYBOARD_BEGIN = 0xFE'00,
                IO_CHAR_KEYBOARD_END   = 0xFF'80,

                ENTRY_POINT_TABLE_BEGIN = 0xFF'81,
                ENTRY_POINT_TABLE_END   = 0xFF'F9,

                VECTORS_BEGIN = 0xFF'FA,
                VECTORS_END   = 0xFF'FF,
            ROM_END   = 0xFF'FF,
        };

        memory() noexcept;

        void load_program(const std::vector<byte_t> &program);

        byte_t read_byte(const word_t address) const noexcept;
        word_t read_word(const word_t address) const;

        void   write_byte(const word_t address, const byte_t data);
        void   write_word(const word_t address, const word_t data);

    private:
        std::vector<byte_t> m_memory;

        static bool is_readonly_segment(const word_t address);

        static const std::size_t memory_size;
        static const std::size_t max_program_size;
        static const word_t      max_address;

        friend std::ostream& operator<<(std::ostream &os, const memory &mem);
    };

    std::ostream& operator<<(std::ostream &os, const memory &mem);
}