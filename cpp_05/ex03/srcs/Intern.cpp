#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


Intern::Intern() {
    std::cout << GREEN << "INTERN CONSTRUCTOR CALLED" << RESET << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << GREEN << "INTERN COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &other) {
    (void) other;
    return *this;
}


AForm   *makePresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *makeRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *makeShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm   *Intern::makeForm(const std::string &fileName, const std::string &target) {
    AForm (*members_ptr[3])(const std::string &target) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
}

