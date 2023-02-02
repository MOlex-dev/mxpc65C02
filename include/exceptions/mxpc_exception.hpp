/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |           MXPC Exception          |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#pragma once

#include <stdexcept>


namespace mxpc65C02::exception
{
    class mxpc_exception
    {
    public:
        explicit mxpc_exception(std::string what) noexcept;

        virtual std::string message() const noexcept;
        virtual std::string type() const noexcept;

    protected:
        void exception_type(std::string type) noexcept;

    private:
        std::string m_except_message;
        std::string m_except_type;
    };
}