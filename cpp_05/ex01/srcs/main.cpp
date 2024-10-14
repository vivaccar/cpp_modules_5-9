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
    // SIGN FORM TESTS
    std::cout << GREEN << "------ TESTS FOR SIGN FORMS --------" << RESET << std::endl;
    {
        try
        {
            Bureaucrat Hamilton("Hamilton", 100);
            Form       driversForm("Drivers", 50, 50);
            driversForm.beSigned(Hamilton);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}