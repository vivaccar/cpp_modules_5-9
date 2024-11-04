#include "../includes/Serializer.hpp"

int main(void) 
{
    Data playerOne;
    playerOne.name = "Vinicius";
    playerOne.number = 10;

    uintptr_t raw = Serializer::serialize(&playerOne);

    Data *ptr = Serializer::deserialize(raw);
    
    if (ptr == &playerOne)
    {
        std::cout << "NAME: " << ptr->name << std::endl;
        std::cout << "NUMBER: " << ptr->number << std::endl;
        std::cout << GREEN << "Serialization sucess!" << RESET << std::endl;
    }
    else
        std::cout << RED << "Something went wrong!" << RESET << std::endl;

    // CREATING NEW POINTER

    Data *newPtr = Serializer::deserialize(raw);
    std::cout << "\nNew pointer Data" << std::endl;
    std::cout << "NAME: " << newPtr->name << std::endl;
    std::cout << "NUMBER: " << newPtr->number << std::endl;
}