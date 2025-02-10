#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    std::cout << rpn.calculate() << std::endl;
    return 0;
}