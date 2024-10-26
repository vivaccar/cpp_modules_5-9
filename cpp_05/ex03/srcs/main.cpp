#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
    {
        try
        {
            std::cout << GREEN << "------ TESTS FOR DIFFERENT FORMS CREATION --------\n" << RESET << std::endl;
            Intern  estagiario;
            AForm   *cur;

            cur = estagiario.makeForm("Anyone", "Manager");
            if (cur)
                delete cur;
            cur = estagiario.makeForm("Robotomy", "Manager");
            if (cur)
                delete cur;
            cur = estagiario.makeForm("shrubbery creation", "Director");
            if (cur)
                delete cur;
            cur = estagiario.makeForm("robotomy request", "Manager");
            if (cur)
                delete cur;
            cur = estagiario.makeForm("presidential pardon", "Vice president");
            if (cur)
                delete cur;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}