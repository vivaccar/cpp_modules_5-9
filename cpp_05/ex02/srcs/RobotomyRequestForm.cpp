#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm::AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

void RobotomyRequestForm::doExecution(Bureaucrat const &executor) {
    
}