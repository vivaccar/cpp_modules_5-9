#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            ScalarConverter::convert(av[1]);
        }
        catch (const std::invalid_argument& e) 
        {
            std::cerr << e.what() << std::endl;
        }
        return 0;
    }
    std::cout << "Impossible to convert" << std::endl << "Try: ./convert [string]" << std::endl;
    return 1;
}