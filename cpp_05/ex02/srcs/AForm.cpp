#include "../includes/AForm.hpp"

//DEFAUL CONSTRUCTORS
AForm::AForm(): _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
    std::cout << GREEN << "DEFAULT FORM CONSTRUCTOR CALLED" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
    std::cout << GREEN << "FORM " << _name << " CONSTRUCTOR CALLED" << std::endl; 
    std::cout << *this << std:: endl;
}


//COPY CONSTRUCTOR
AForm::AForm(const AForm &other): 
_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {  
    std::cout << GREEN << "FORM " << this->_name << " COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}


//DESTRUCTOR
AForm::~AForm() {
    std::cout << RED << "FORM: " << _name << " DESTROYED" << RESET << std::endl;
}

//COPY OPERATOR
AForm& AForm::operator=(const AForm &other) {
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

//GETTER & SETTERS

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExec() const {
    return this->_gradeToExec;
}

bool    AForm::getSignStatus() const {
    return this->_isSigned;
}

const std::string AForm::getName() const {
    return this->_name;
}

void    AForm::setSignStatus(bool isSigned) {
    this->_isSigned = isSigned;
}

// EXCEPTIONS

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too Low!");
}

const char *AForm::FormNotSigned::what() const throw() {
    return ("This form is not signed!");
}

//OPERATOR <<

std::ostream& operator<<(std::ostream& ostream, const AForm& Form) {
    ostream << Form.getName() << " FORM, IS SIGNED: " << Form.getSignStatus() <<
    ", GRADE TO SIGN IS: " << Form.getGradeToSign() << ", AND GRADE TO EXEC IS: "
    << Form.getGradeToExec(); 
    return ostream;
}

void    AForm::beSigned(const Bureaucrat &Bureaucrat) {
    if (Bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    if (this->_isSigned)
    {
        std::cout << "This form has already been signed by someone" << std::endl;
        return ;
    }
    std::cout << GREEN << Bureaucrat.getName() << " signed " <<
    this->getName() << RESET << std::endl;
    this->_isSigned = true;
}

void    AForm::execute(const Bureaucrat &executer)
{
    if (!this->_isSigned)
        throw AForm::FormNotSigned();
    if (this->_gradeToExec > executer.getGrade())
        throw AForm::GradeTooLowException();
}