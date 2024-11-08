#include "../includes/Array.hpp"

int main(void)
{
    std::cout << RED << "CONSTRUCTORS TESTS\n" << RESET << std::endl;
    
    Array<int> empty;
    Array<float> noEmpty(10);
    Array<float> floatArray(noEmpty);
    
    std::cout << "SIZE: " << noEmpty.size() << std::endl;
    std::cout << "SIZE: " << empty.size() << std::endl;
    std::cout << "SIZE: " << floatArray.size() << std::endl;

    std::cout << RED << "\n[] OPERATOR TESTS" << RESET << std::endl;
    for (unsigned int i = 0; i < noEmpty.size(); i++)
    {
        try
        {
            noEmpty[i] = static_cast<float>(i) + 0.5f;
            std::cout << noEmpty[i] << " ";
        }
        catch(const std::exception& e)
        {
            std::cerr << "\nInvalid index!" << std::endl;
        }
    }

    std::cout << RED << "\n\n= OPERATOR TESTS" << RESET << std::endl;
    std::cout << "\nArray before copy: ";
    for (unsigned int i = 0; i < floatArray.size(); i++)
    {
        try
        {
            std::cout << floatArray[i] << " ";
        }
        catch(const std::exception& e)
        {
            std::cerr << "\nInvalid index!" << std::endl;
        }
    }

    floatArray = noEmpty;

    std::cout << "\n\nArray after copy: ";
    for (unsigned int i = 0; i < floatArray.size(); i++)
    {
        try
        {
            std::cout << floatArray[i] << " ";
        }
        catch(const std::exception& e)
        {
            std::cerr << "\nInvalid index!" << std::endl;
        }
    }
    std::cout << std::endl;
}
