#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* formInvalid;

    // Test creating valid forms
    form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    form3 = someRandomIntern.makeForm("presidential pardon", "Alice");

    // Test creating an invalid form
    formInvalid = someRandomIntern.makeForm("unknown form", "Target");

    if (form1){
        std::cout << *form1 << std::endl;
        delete form1;
    }
    if (form2){
        std::cout << *form2 << std::endl;
        delete form2;
    }
    if (form3){
        std::cout << *form3 << std::endl;
        delete form3;
    }
    if (formInvalid){
        std::cout << *formInvalid << std::endl;
        delete formInvalid;
    }

    return 0;
}