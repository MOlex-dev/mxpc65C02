/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |           CMD Exception           |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../../include/exceptions/cmd_exception.hpp"

using namespace mxpc65C02;
using exception::mxpc_exception;
using exception::cmd_exception;


cmd_exception::
cmd_exception(std::string what) noexcept
        : mxpc_exception(std::move(what))
{ exception_type("cmd_exception"); }
