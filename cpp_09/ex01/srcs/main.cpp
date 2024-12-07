#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            RPN rpn(av[1]);
            std::cout << rpn.getTop() << std::endl;
            return 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    std::cout << "Error" << std::endl;
    return 1;
}