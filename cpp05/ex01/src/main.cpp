#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat a("Alice", 1);
        Form fa("Form_Alice", 1, 1);
        a.signForm(fa);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Boris", 150);
        Form fb("Form_Boris", 149, 149);
        b.signForm(fb);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
    try {
        Bureaucrat c("Colin", 75);
        Form fc("Form_Colin", 75, 75);
        c.signForm(fc);
        c.decre_grade();
        c.signForm(fc);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    //what if trying to sign an already signed form??
}