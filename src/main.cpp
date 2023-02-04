/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include <iostream>
#include <vector>

#include "../include/util.hpp"
#include "../include/memory.hpp"

//#define DEBUG_SETTINGS
//#define DEBUG_PROGRAM_LOADING
//#define DEBUG_MEMORY

using namespace mxpc65C02;
using namespace mxpc65C02::exception;


int main(int argc, char **argv)
{
    std::vector<std::string> cmd_arguments(argc);
    for (int i = 0; i < argc; ++i) {
        cmd_arguments[i] = std::string(argv[i]);
    }

    try {
        auto config = cmd_to_settings(cmd_arguments);

#ifdef DEBUG_SETTINGS
        std::cout << config << std::endl;
#endif

        const auto program = read_program_from_file(config.program_file_path());

#ifdef DEBUG_PROGRAM_LOADING
        for (std::size_t i = 0; i < program.size(); ++i) {
            if (i % 0x10 == 0) { std::cout << '\n'; }
            std::cout << std::right << std::hex << std::setfill('0') << std::setw(2) << +program.at(i) << ' ';
        }
#endif

        memory computer_memory;
        computer_memory.load_program(program);

#ifdef DEBUG_MEMORY
        std::cout << computer_memory << std::endl;
#endif


        //TODO: Continue here









    } catch (const mxpc_exception &except) {
        std::cout << "ERROR!" << '\n';
        std::cout << except.type() << ": " << except.message() << '\n' << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}















//#include <iostream>
//#include <vector>
//#include <fstream>

//
//std::vector<byte> read_program_from_file(std::string program_file_path);
//class monitor
//{
//public:
//    void write(std::vector<byte> &mem) {
//        for (int i = 0; i < 32; ++i) {
//            for (int j = 0; j < 32; ++j) {
//
//            }
//        }
//    }
//
//};
//struct registers
//{
//    byte a, x, y, sp;
//    word ip;
//};
//
//int main()
//{
//    registers rgs;
//    rgs.sp = 0x2000;
//
//    std::vector<byte> memory(0x1'00'00);
//    memory[0x2000] = { 0xA9 };
//    memory[0x2001] = { 0x33 };
//
//    monitor mntr;
//    mntr.write(memory);
//
//
//
//
//    return 0;
//}
//
//std::vector<byte> read_program_from_file(std::string program_file_path)
//{
//    std::ifstream source_reader(program_file_path, std::ios_base::binary);
//
//    if (not source_reader.is_open())
//        throw std::ios_base::failure("Source code file opening error!\n");
//
//    std::vector<byte> result;
//    while (not source_reader.eof())
//        result.push_back(source_reader.get());
//
//    source_reader.close();
//    result.erase(--result.end());
//
//    return result;
//}
