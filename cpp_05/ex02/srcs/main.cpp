#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        AForm   *a = new ShrubberyCreationForm("Lula");
        Bureaucrat *b = new Bureaucrat("Bolsonaro", 20);
        a->beSigned(*b);
        a->execute(*b);
        delete a;
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}