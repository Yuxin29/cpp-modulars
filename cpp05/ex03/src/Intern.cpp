#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern&) {
}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string& name, const std::string& tar)
{
    static const std::string requestNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
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