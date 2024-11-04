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
    std::cout << "Invalid input" << std::endl << "Try: ./convert [string]" << std::endl;
    return 1;
}


// float max 3.402823466 E + 38

// double max 1.7976931348623158 E + 308

// int max 2147483647