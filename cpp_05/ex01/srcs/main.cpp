#include "../includes/Form.hpp"

int main(void)
{
    // FORM CONSTRUCTORS TESTS
    std::cout << GREEN << "------ TESTS FOR CONSTRUCTORS RANGE 1-150 --------" << RESET << std::endl;
    {
        try
        {
            Form studentForm("Students", 10, 120);
            Form directorForm("Director", 20, 220);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }

    std::cout << std::endl << std::endl;
    // SIGN FORM TEST "beSigned"
    std::cout << GREEN << "------ TESTS FOR SIGN FORMS \"beSigned\" --------" << RESET << std::endl;
    {
        try
        {
            Bureaucrat Hamilton("Hamilton", 12);
            Form       driversForm("Drivers", 50, 50);
            driversForm.beSigned(Hamilton);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    // SIGN FORM TEST "beSigned"
    std::cout << GREEN << "------ TESTS FOR SIGN FORMS \"signForm\" --------" << RESET << std::endl;

    {
        try
        {
            Bureaucrat studentX("Student X", 50);
            Bureaucrat studentY("Student Y", 80);
            Form       studentsForm("Students", 50, 20);

            studentX.signForm(studentsForm);
            studentY.signForm(studentsForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
}