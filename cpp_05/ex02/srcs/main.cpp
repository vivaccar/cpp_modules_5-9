#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
    {
        std::cout << GREEN << "------ TESTS FOR SHRUBBERYFORM --------\n" << RESET << std::endl;
        AForm       *formA = new ShrubberyCreationForm("tree1");
        
        try
        {
            Bureaucrat  student("Student", 150);
            Bureaucrat  teacher("Teacher", 137);
            teacher.executeForm(*formA);
            teacher.signForm(*formA);
            student.executeForm(*formA);
            teacher.executeForm(*formA);
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete formA;
    }

    std::cout << std::endl << std::endl;
    
    {
        std::cout << GREEN << "------ TESTS FOR ROBOTOMYFORM --------\n" << RESET << std::endl;
        AForm   *formB = new RobotomyRequestForm("Printer");

        try
        {
            Bureaucrat  emploeyee("Employeer", 120);
            Bureaucrat  manager("Manager", 45);
            manager.signForm(*formB);
            manager.executeForm(*formB);
            manager.executeForm(*formB);

            emploeyee.signForm(*formB);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete formB;
    }

    std::cout << std::endl << std::endl;

    {
        std::cout << GREEN << "------ TESTS FOR PRESIDENTIALFORM --------\n" << RESET << std::endl;
        AForm *formC = new PresidentialPardonForm("Prisioner");
        try
        {
            Bureaucrat  secretary("Secretary", 60);
            Bureaucrat  president("President", 5);
            president.signForm(*formC);
            secretary.executeForm(*formC);
            president.executeForm(*formC);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete formC;
    }

    std::cout << std::endl << std::endl;
}