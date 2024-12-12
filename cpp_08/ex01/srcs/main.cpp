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
        std::cout << GREEN << "\nTEST 2 --> COPY OPERATOR: \n" << RESET << std::endl;
        Span s1(5);
        Span s2(2);
        std::vector<int> v(5);
        std::generate(v.begin(), v.end(), rand);

        s1.addNumber(v.begin(), v.end());
        s2 = s1;
        std::cout << "STACK 1"<< std::endl;
        s2.print();
        std::cout << "\nSTACK 2"<< std::endl;
        s1.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << GREEN << "\nTEST 3 --> LONGEST SPAN: \n" << RESET << std::endl;
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
        std::cout << GREEN << "\nTEST 4 --> SHORTEST SPAN: \n" << RESET << std::endl;
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
        std::cout << GREEN << "\nTEST 5 --> 1000000 VALUES: \n" << RESET << std::endl;
        std::vector<int> v(100000);
        Span s(100000);
        std::generate(v.begin(), v.end(), rand);
        s.addNumber(v.begin(), v.end());
        s.print();
        std::cout << "Size: " << s.getSize() << std::endl;

        std::cout << "Longest Span: " << s.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;

    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
    try
    {
        std::cout << GREEN << "\nTEST 5 --> COPY CONSTRUCTOR: \n" << RESET << std::endl;
        std::vector<int> v(100000);
        Span s(100000);
        std::generate(v.begin(), v.end(), rand);
        s.addNumber(v.begin(), v.end());
        //s.print();
        Span sCopy(s);
        std::cout << "Size s: " << s.getSize() << std::endl;
        std::cout << "Size sCopy: " << sCopy.getSize() << std::endl;

        std::cout << "Longest Span: " << s.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n--------------------------------------\n" << RESET << std::endl;
}