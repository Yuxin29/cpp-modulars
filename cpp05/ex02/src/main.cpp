#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // can sign and exect the ShrubberyCreationForm.
    // ShrubberyCreationForm: Required grades: sign 145, exec 137
    try {
        Bureaucrat a("Alice", 1);
        ShrubberyCreationForm scf("scf_Alice");
        a.signAForm(scf);
        a.executeForm(scf);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // can signed but cannot exect the RobotomyRequestForm.
    // RobotomyRequestForm: Required grades: sign 72, exec 45
    try {
        Bureaucrat b("Boris", 70);
        std::cout << b << std::endl;
        RobotomyRequestForm rrf("rrf_Boris");
        std::cout << rrf << std::endl;
        b.signAForm(rrf);
        std::cout << rrf << std::endl;
        b.executeForm(rrf);
        std::cout << rrf << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // cannot sign or exect the PresidentialPardonForm.
    // PresidentialPardonForm: Required grades: sign 25, exec 5
    try {
        Bureaucrat c("Colin", 30);
        std::cout << c << std::endl;
        PresidentialPardonForm ppf("ppf_Colin");
        std::cout << ppf << std::endl;
        c.signAForm(ppf);
        std::cout << ppf << std::endl;
        c.executeForm(ppf);
        std::cout << ppf << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // cannot exect when not signed the PresidentialPardonForm.
    try {
        Bureaucrat d("David", 5);
        std::cout << d << std::endl;
        PresidentialPardonForm ppf_2("ppf_2_David");
        std::cout << ppf_2 << std::endl;
        d.executeForm(ppf_2);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //trying to exect AForm repeatedlt
    try {
        Bureaucrat d("David", 5);
        std::cout << d << std::endl;
        PresidentialPardonForm ppf_2("ppf_2_David");
        std::cout << ppf_2 << std::endl;
        d.signAForm(ppf_2);
        std::cout << ppf_2 << std::endl;
        d.executeForm(ppf_2);
        d.executeForm(ppf_2);
        std::cout << ppf_2 << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}