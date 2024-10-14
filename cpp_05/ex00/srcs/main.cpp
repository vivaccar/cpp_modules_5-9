#include "../includes/Bureaucrat.hpp"

int main()
{
    // CONSTRUCTORS TESTS FOR HIGHEST THAN 1 AND LOWEST THAN 150
    {
        std::cout << GREEN << "------ TESTS FOR CONSTRUCTORS RANGE 1-150 --------" << std::endl;
        try
        {
            Bureaucrat Trump("Trump", 100);
            Bureaucrat Messi("Messi", 1);
            Bureaucrat Romario("Romario", 151);
            Bureaucrat Vinicius("Vini", -1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl << std:: endl;

    // TEST FOR INCREMENTATION HIGHEST THAN 1
    {
        std::cout << GREEN << "------ TESTS FOR INCREMENTATIONS --------" << std::endl;
        try
        {
            Bureaucrat Ronaldinho("ronaldinho", 20);
            for (int i = 0; i < 150; i++)
                Ronaldinho.incrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }

    std::cout << std::endl << std:: endl;
    // TEST FOR DECREMENTATION LOWEST THAN 150
    {
        std::cout << GREEN << "------ TESTS FOR DECREMENTATIONS --------" << std::endl;
        try
        {
            Bureaucrat Ronaldinho("ronaldinho", 135);
            for (int i = 0; i < 150; i++)
                Ronaldinho.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }

    std::cout << std::endl << std:: endl;
    // COPY CONSTRUCTOR AND COPY OPERATOR TESTS
    {
        std::cout << GREEN << "------ TESTS FOR COPY CONSTRUCTOR AND COPY OPERATOR --------" << std::endl;

        Bureaucrat  Neymar("Ney", 120);
        Bureaucrat  b1(Neymar);

        std::cout << Neymar << std::endl;
        std::cout << b1 << std::endl;

        Bureaucrat  b2("b2", 20);
        b2 = Neymar;
        b2 = Neymar;
        std::cout << b2 << std::endl;
    }    
}