#ifndef LOX_HPP
#define LOX_HPP

#include <string_view>      

namespace tree_walk
{
    class Lox
    {
        public:
            Lox() = delete;
            static int main(int argc, char* argv[]);
        private:
            static int runFile(std::string_view path);
            static int run(std::string_view source);
            static int repl();
    };
}
#endif // LOX_HPP