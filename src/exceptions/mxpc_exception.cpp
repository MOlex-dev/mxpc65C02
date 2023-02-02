/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |           MXPC Exception          |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../../include/exceptions/mxpc_exception.hpp"

using namespace mxpc65C02;
using exception::mxpc_exception;


mxpc_exception::
mxpc_exception(std::string what) noexcept
    : m_except_message {std::move(what)}, m_except_type {"mxpc_exception"} {}


void                    mxpc_exception::
exception_type(std::string type) noexcept
{ m_except_type = std::move(type); }


std::string             mxpc_exception::
message() const noexcept
{ return m_except_message; }

std::string             mxpc_exception::
type() const noexcept
{ return m_except_type; }