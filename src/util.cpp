/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Utils               |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/util.hpp"
#include "../include/settings.hpp"

using namespace mxpc65C02;
using mxpc65C02::exception::cmd_exception;


byte_t                  mxpc65C02::
lower_word(const word_t word) noexcept
{ return word % 0x1'00; }

byte_t                  mxpc65C02::
higher_word(const word_t word) noexcept
{ return word / 0x1'00; }


std::string             mxpc65C02::
to_lower(const std::string &input) noexcept
{
    std::string res = input;
    std::for_each(res.begin(), res.end(), [](auto &c) { c = std::tolower(c); });
    return res;
}

std::string             mxpc65C02::
to_upper(const std::string &input) noexcept
{
    std::string res = input;
    std::for_each(res.begin(), res.end(), [](auto &c) { c = std::toupper(c); });
    return res;
}


settings                mxpc65C02::
cmd_to_settings(const std::vector<std::string> &cmd_args)
{
    // Parse cmd arguments
    if (cmd_args.size() == 1) {
        throw cmd_exception("No program (*.bin) and settings (*.cfg) files");
    }
    if (cmd_args.size() > 3) {
        throw cmd_exception("Too many command line arguments");
    }
    std::string path_to_program, path_to_settings;

    for (std::size_t i = 1; i < cmd_args.size(); ++i) {
        if (cmd_args[i].length() < 4) {
            throw cmd_exception("Unexpected file \'" + cmd_args[i]
                                + "\'. Should be program file (*.bin) or settings file (*.cfg)");
        }

        auto arg_ext = cmd_args[i].substr(cmd_args[i].length() - 4, 4);
        if (arg_ext == ".cfg") {
            path_to_settings = cmd_args[i];
        } else if (arg_ext == ".bin") {
            path_to_program = cmd_args[i];
        } else {
            throw cmd_exception("Unexpected file \'" + cmd_args[i]
                                + "\'. Should be program file (*.bin) or settings file (*.cfg)");
        }
    }

    if (path_to_program.empty()) {
        throw cmd_exception("No program file path (*.bin). Multiply declaration of a settings file");
    }
    if (path_to_settings.empty()) {
        throw cmd_exception("No settings file path (*.cfg). Multiply declaration of a program file");
    }

    settings config;
    config.program_file_path(path_to_program);

    // Parse settings
    std::ifstream config_file(path_to_settings);
    if (not config_file.is_open()) {
        throw cmd_exception("Can't open configuration file: " + path_to_settings);
    }

    std::string input_string;
    std::size_t line = 1;

    while (std::getline(config_file, input_string)) {
        std::string proc_str = input_string;

        auto rem_beg = std::remove(proc_str.begin(), proc_str.end(), ' ');
        proc_str.erase(rem_beg, proc_str.end());

        if (proc_str.empty()) {
            ++line;
            continue;
        }

        auto eq_pos = proc_str.find('=');
        if (eq_pos == std::string::npos) {
            throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line)
                                + ": " + input_string + R"(: no '=' sign)");
        }

        std::string property, value;
        property = proc_str.substr(0, eq_pos);
        value = proc_str.substr(eq_pos + 1, proc_str.length() - 1);

        if (property.empty()) {
            throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line) + ": "
                                + "No property");
        }
        if (value.empty()) {
            throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line) + ": "
                                + "No value");
        }

        if (property ==  "FREQUENCY") {
            hertz_t property_freq;
            if (std::find_if(value.begin(), value.end(), [](const auto &c) {
                return not std::isdigit(c);
            }) != value.end()) {
                throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line) + ": "
                                    + "Can't parse to number: " + value);
            }
            config.frequency_cpu(std::strtoull(value.c_str(), nullptr, 10));
        } else if ( property == "SCREEN_MODE") {
            if (value == "BITMAP_DISPLAY") {
                config.monitor_mode(settings::screen_mode::BITMAP_DISPLAY);
            } else if (value == "SYMBOLIC_DISPLAY") {
                config.monitor_mode(settings::screen_mode::SYMBOLIC_DISPLAY);
            } else {
                throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line) + ": "
                                    + "Unknown value: " + value);
            }
        } else {
            throw cmd_exception("Settings file parsing error:\nAt line: " + std::to_string(line) + ": "
                                + "Unknown property: " + property);
        }
        ++line;
    }
    config_file.close();

    return config;
}

std::vector<byte_t>     mxpc65C02::
read_program_from_file(const std::string path)
{
    std::ifstream source_code_reader(path, std::ios::binary);
    if (not source_code_reader.is_open()) {
        throw cmd_exception("Can't open source code file at: " + path);
    }

    std::vector<byte_t> program_code;
    char byte;
    while (source_code_reader.get(byte)) {
        program_code.push_back(static_cast<byte_t>(byte));
    }
    source_code_reader.close();

    return program_code;
}