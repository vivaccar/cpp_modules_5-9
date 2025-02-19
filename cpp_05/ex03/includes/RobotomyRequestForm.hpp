#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
    
    public:
        //constructors
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

        void doExecution(Bureaucrat const &executor) const;
};