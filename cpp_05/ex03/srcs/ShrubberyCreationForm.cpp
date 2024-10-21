#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm::AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    AForm::operator=(other);
    this->_target = other._target;
    return (*this);
}

void ShrubberyCreationForm::doExecution(Bureaucrat const &executor) const {
    std::string file_name_str = this->_target + "_shrubbery";
    const char *file_name = file_name_str.c_str();
    std::ofstream file;
    const char *tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n";
    
    file.open(file_name);
    if (file.is_open())
    {
        file << tree << std::endl;
        file.close();
    }
    else
        std::cerr << "Error while creating a file " << file_name;

    std::cout << executor.getName() << " is able to execute" << std::endl;
}  