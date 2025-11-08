#include "Intern.hpp"

AForm* Intern::makeForm(const std::string& name, const std::string& tar)
{
    static const std::string requestNames[] = {
        "ShrubberyCreationForm request",
        "RobotomyRequestForm request",
        "PresidentialPardonForm request"
    };
    AForm *res = nullptr;
    for (int i = 0; i < 3; i++){
        if (requestNames[i] == name){
            switch (i) {
                case 0: res = new ShrubberyCreationForm(tar); break;
                case 1: res = new RobotomyRequestForm(tar); break;
                case 2: res = new PresidentialPardonForm(tar); break;
            }
            break;
        }
    }

    if (res)
        std::cout << "Intern creates " << *res << "\n";
    else
        std::cout << "Intern could not create " << name << "\n";
    return res;
}