#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
    public:
        //constructors
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        void doExecution(Bureaucrat const &executor) const;
};