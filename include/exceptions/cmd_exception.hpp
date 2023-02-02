/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |           CMD Exception           |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include "mxpc_exception.hpp"


namespace mxpc65C02::exception
{
    class cmd_exception : public mxpc_exception
    {
    public:
        explicit cmd_exception(std::string what) noexcept;
    };
}