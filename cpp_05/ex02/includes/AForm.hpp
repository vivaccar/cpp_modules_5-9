#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream> 
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm &other);
        virtual ~AForm();

        AForm& operator=(const AForm &other);

        int getGradeToSign() const;
        int getGradeToExec() const;
        bool      getSignStatus() const;
        const std::string getName() const;
        void    setSignStatus(bool isSigned);


        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSigned: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        void    beSigned(const Bureaucrat &Bureaucrat);
        void    execute(Bureaucrat const &executor);
        virtual void    doExecution(Bureaucrat const &executor) = 0;
};

std::ostream& operator<<(std::ostream& ostream, const AForm& Form);

#endif