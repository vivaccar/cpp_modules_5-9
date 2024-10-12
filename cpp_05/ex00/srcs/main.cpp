#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat Trump("Trump", 1000);

    std::cout << Trump.getName() << " " << Trump.getGrade() << std::endl;
/*     Trump.setGrade(1000);
    Trump.setGrade(101);
    std::cout << Trump.getName() << " " << Trump.getGrade() << std::endl; */

}