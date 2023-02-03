/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |               Utils               |
 |                                   |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include "../include/util.hpp"

using namespace mxpc65C02;
using mxpc65C02::exception::cmd_exception;


byte_t                  mxpc65C02::
lower_word(const word_t word) noexcept
{ return word % 0x1'00; }

byte_t                  mxpc65C02::
higher_word(const word_t word) noexcept
{ return word / 0x1'00; }

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



    // TODO: WORK HERE


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