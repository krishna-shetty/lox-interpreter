#include "lox.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace tree_walk
{
    int Lox::main(int argc, char* argv[])
    {
        if(argc > 2)
        {
            std::cerr << "Usage: lox [script]\n";

        }
        else if (argc == 2)
        {
            runFile(argv[1]);
        }
        else
        {
            repl();
        }

        return 0;
    }

    int Lox::runFile(std::string_view path)
    {
        std::ifstream file(std::string(path), std::ios::binary);

        if(!file.is_open())
        {
            std::cerr << "Could not open file: " << path << "\n";
            return 74;
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();
        return run(buffer.str());
    }

    int Lox::repl()
    {
        std::string line;

        for(;;)
        {
            std::cout << "> " << std::flush;
            if(!std::getline(std::cin, line)) break;
            run(line);
        }
        return 0;
    }
}