#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
        return 0;
    }
    std::cout << "Impossible to convert" << std::endl << "Try: ./convert [string]" << std::endl;
}