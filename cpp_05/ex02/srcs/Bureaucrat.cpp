#include "../includes/Bureaucrat.hpp"

// DEFAULT CONSTRUCTORS
Bureaucrat::Bureaucrat(): _name(""), _grade(150) {
    std::cout << GREEN << "DEFAULT BUREAUCRAT CONSTRUCTOR CALLED" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(150){
    this->setGrade(grade);
    std::cout << GREEN << "BUREAUCRAT " << name << " CONSTRUCTOR CALLED" << RESET << std::endl;
}


// COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName()), _grade(other.getGrade()) {
    std::cout << GREEN << "BUREAUCRAT " << this->_name << " COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}


// DESTRUCTOR
Bureaucrat::~Bureaucrat() {
    std::cout << RED << "BUREAUCRAT " << this->_name << " DESTROYED" << RESET << std::endl;
}


// COPY ASSIGNMENT OPERATOR
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "BUREAUCRAT " << this->_name << " CALEED A COPY FROM " << other.getName() << std::endl;
    if (this == &other)
        return *this;
    this->_grade = other.getGrade();
    return *this;
}


// GETTERS FOR NAME AND GRADE
const std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}


void Bureaucrat::setGrade(int grade) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too Low!");
}

void    Bureaucrat::incrementGrade() {
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << *this << std::endl;
}

void    Bureaucrat::decrementGrade() {
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << *this << std::endl;
}

void    Bureaucrat::signForm(AForm &Form) {
    try
    {
        Form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't sign " << Form.getName() << " because " << e.what() << '\n';
    }
}

void    Bureaucrat::executeForm(AForm const &form) const {
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
    }
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& Bureaucrat) {
    ostream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return ostream;
}