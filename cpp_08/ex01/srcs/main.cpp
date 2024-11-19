#include "../includes/Span.hpp"

int main(void)
{
    try
    {
        std::cout << GREEN << "TEST 0 --> Adding value to a empty class: \n" << RESET << std::endl;
        Span s;
        s.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
    
    try
    {
        std::cout << GREEN << "TEST 1 --> Adding values until Maximum Size: \n" << RESET << std::endl;
        Span s(5);
        s.addNumber(1);
        s.addNumber(5);
        s.addNumber(9);
        s.addNumber(12);
        s.addNumber(0);
        s.print();
        s.addNumber(-10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
    try
    {
        std::cout << GREEN << "\nTEST 2 --> LONGEST SPAN: \n" << RESET << std::endl;
        Span s(4);

        s.addNumber(-101);
        s.addNumber(INT_MAX);
        s.addNumber(INT_MIN);
        s.addNumber(21);
        std::cout << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
    try
    {
        std::cout << GREEN << "\nTEST 3 --> SHORTEST SPAN: \n" << RESET << std::endl;
        Span s(4);
        
        s.addNumber(-101);
        s.addNumber(INT_MIN);
        s.addNumber(3);
        s.addNumber(INT_MAX);
        std::cout << s.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
    try
    {
        std::cout << GREEN << "\nTEST 4 --> 1000000 VALUES: \n" << RESET << std::endl;
        std::vector<int> v(1000000);
        Span s(1000000);
        std::generate(v.begin(), v.end(), rand);
        s.addNumber(v.begin(), v.end());
        //s.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
}