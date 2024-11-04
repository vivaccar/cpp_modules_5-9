#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int rnd = std::rand();

    if (rnd % 3 == 0)
        return new A;
    else if (rnd % 3 == 1)
        return new B;
    return new C;
}

void    identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout  << GREEN << "indentify(Base* p) functions identified an object of type A\n" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout  << GREEN << "indentify(Base* p) functions identified an object of type B\n" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout  << GREEN << "indentify(Base* p) functions identified an object of type C\n" << RESET << std::endl;
    else
        std::cout << "Unknow type" << std::endl;
}

void    identify(Base& p) {
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout  << GREEN << "indentify(Base& p) functions identified an object of type A\n" << RESET << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout  << GREEN << "indentify(Base& p) functions identified an object of type B\n" << RESET << std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout  << GREEN << "indentify(Base& p) functions identified an object of type C\n" << RESET << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "Unknown Type." << std::endl;
            }
        }
    }
}

int main(void)
{
    Base *a = generate();
    identify(a);
    identify(*a);
    delete a;
}