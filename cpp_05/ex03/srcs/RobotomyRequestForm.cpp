#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm::AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

void RobotomyRequestForm::doExecution(Bureaucrat const &executor) const {
    (void) executor;
    
    static int x = 1;
    std::cout << "TRRRRRRRRRRRR ... ";
    if (x % 2 == 0)
        std::cout << BLUE << this->_target << " has been robotomized sucessfully" << RESET << std::endl;
    else
        std::cout << BLUE << this->_target << " robotomy failed" << RESET << std::endl;
    x++;
}