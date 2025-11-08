#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* formInvalid;

    // Test creating valid forms
    form1 = someRandomIntern.makeForm("ShrubberyCreationForm request", "Home");
    form2 = someRandomIntern.makeForm("RobotomyRequestForm request", "Bender");
    form3 = someRandomIntern.makeForm("PresidentialPardonForm request", "Alice");

    // Test creating an invalid form
    formInvalid = someRandomIntern.makeForm("unknown form", "Target");

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;
    std::cout << formInvalid << std::endl;

    std::cout << "\n--- Clean up ---\n";
    // delete form1;
    // delete form2;
    // delete form3;
    // delete formInvalid; // safe even if nullptr

    return 0;
}