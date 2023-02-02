/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |          Memory Exception         |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include "mxpc_exception.hpp"


namespace mxpc65C02::exception
{
    class memory_exception : public mxpc_exception
    {
    public:
        explicit memory_exception(std::string what) noexcept;
    };
}