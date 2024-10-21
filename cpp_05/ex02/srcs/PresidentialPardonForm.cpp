#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm::AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

void PresidentialPardonForm::doExecution(Bureaucrat const &executor) const {
    (void) executor;
    std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
