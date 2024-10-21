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


AForm   *Intern::makeForm(const std::string &fileName, const std::string &target) {
    return ();
}