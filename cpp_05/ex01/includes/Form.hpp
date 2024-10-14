#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form &other);
        ~Form();

        Form& operator=(const Form &other);

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

        void    beSigned(const Bureaucrat &Bureaucrat);
};

std::ostream& operator<<(std::ostream& ostream, const Form& Form);