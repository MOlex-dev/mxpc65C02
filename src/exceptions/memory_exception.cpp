/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |          Memory Exception         |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../../include/exceptions/memory_exception.hpp"

using namespace mxpc65C02;
using exception::mxpc_exception;
using exception::memory_exception;


memory_exception::
memory_exception(std::string what) noexcept
    : mxpc_exception(std::move(what))
{ exception_type("memory_exception"); }
