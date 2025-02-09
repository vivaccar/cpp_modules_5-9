#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);
        
        const std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);

        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        void    incrementGrade();
        void    decrementGrade();
} ;

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& Bureaucrat);

#endif 
