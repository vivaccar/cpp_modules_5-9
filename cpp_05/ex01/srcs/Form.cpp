#include "../includes/Form.hpp"

//DEFAUL CONSTRUCTORS
Form::Form(): _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
    std::cout << GREEN << "DEFAULT FORM CONSTRUCTOR CALLED" << RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    std::cout << GREEN << "FORM " << _name << " CONSTRUCTOR CALLED" << std::endl; 
    std::cout << *this << std:: endl;
}


//COPY CONSTRUCTOR
Form::Form(const Form &other): 
_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {  
    std::cout << GREEN << "FORM " << this->_name << " COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}


//DESTRUCTOR
Form::~Form() {
    std::cout << RED << "FORM: " << _name << " DESTROYED" << RESET << std::endl;
}

//COPY OPERATOR
Form& Form::operator=(const Form &other) {
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

//GETTER & SETTERS

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExec() const {
    return this->_gradeToExec;
}

bool    Form::getSignStatus() const {
    return this->_isSigned;
}

const std::string Form::getName() const {
    return this->_name;
}

void    Form::setSignStatus(bool isSigned) {
    this->_isSigned = isSigned;
}

// EXCEPTIONS

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too Low!");
}

//OPERATOR <<

std::ostream& operator<<(std::ostream& ostream, const Form& Form) {
    ostream << Form.getName() << " FORM, IS SIGNED: " << Form.getSignStatus() <<
    ", GRADE TO SIGN IS: " << Form.getGradeToSign() << ", AND GRADE TO EXEC IS: "
    << Form.getGradeToExec(); 
    return ostream;
}

void    Form::beSigned(const Bureaucrat &Bureaucrat) {
    if (Bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "This form has already been signed by someone" << std::endl;
        return ;
    }
    std::cout << "The Bureaucrat: " << Bureaucrat.getName() << " signed the form " <<
    this->getName() << std::endl;
    this->_isSigned = true;
}