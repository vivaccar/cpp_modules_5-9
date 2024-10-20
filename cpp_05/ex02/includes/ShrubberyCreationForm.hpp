#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    
    public :
        // Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

        void    doExecution(Bureaucrat const &executor);
};