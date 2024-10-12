#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150) {
    std::cout << "DEFAULT BUREAUCRAT CUNSTRUCTOR CALLED" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(150){
    this->setGrade(grade);
    std::cout << "BUREAUCRAT " << name << " CONSTRUCTOR CALLED" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "BUREAUCRAT " << this->_name << " DESTROYED" << std::endl;
}

const std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::setGrade(int grade) {
    try
    {
        if (grade > 0 && grade < 151)
        {
            this->_grade = grade;
            std::cout << this->getName() << " new grade is " << this->getGrade() << std::endl;
        }
        else
            throw (grade);
    }
    catch(int grade)
    {
        std::cout << grade << " is out of the range 1-150" << std::endl;
    }
}