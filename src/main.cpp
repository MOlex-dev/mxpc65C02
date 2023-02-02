/*-----------------------------------*
 |     W65C02 Processor Simulator    |
 |         Author: MOlex-dev         |
 *-----------------------------------*/

#include <iostream>
#include <vector>

#include "../include/util.hpp"
#include "../include/memory.hpp"

#define PRINT_SETTINGS(settings) std::cout << settings << std::endl;
#define PRINT_ARGUMENTS(cmd_arguments) for (const auto &arg : cmd_arguments) std::cout << arg << std::endl;
#define PRINT_MEMORY(memory_instance) std::cout << memory_instance << std::endl;

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
        PRINT_SETTINGS(config)


        memory computer_memory;

        std::vector<byte_t> program(0x12ff);
        for (std::size_t i = 0; i < 0x12ff; ++i) {
            program[i] = i * 2;
        }
        computer_memory.load_program(program);


        //PRINT_MEMORY(computer_memory)










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
