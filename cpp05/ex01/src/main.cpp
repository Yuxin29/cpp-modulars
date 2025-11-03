#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // can signed the for.
    try {
        Bureaucrat a("Alice", 1);
        Form fa("Form_Alice", 1, 1);
        std::cout << a << std::endl;
        std::cout << fa << std::endl;
        a.signForm(fa);
        std::cout << fa << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // cannot signed the for.
    try {
        Bureaucrat b("Boris", 150);
        std::cout << b << std::endl;
        Form fb("Form_Boris", 149, 149);
        std::cout << fb << std::endl;
        b.signForm(fb);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //can not sign first but can after increment grade for bureact
    try {
        Bureaucrat c("Colin", 76);
        std::cout << c << std::endl;
        Form fc("Form_Colin", 75, 75);
        std::cout << fc << std::endl;
        c.signForm(fc);
        c.incrementGrade();
        std::cout << c << std::endl;
        c.signForm(fc);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //trying to sign form repeatedlt
    try {
        Bureaucrat d("David", 10);
        std::cout << d << std::endl;
        Form fd("Form_Colin", 20, 20);
        std::cout << fd << std::endl;
        d.signForm(fd);
        std::cout << fd << std::endl;
        d.signForm(fd);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //trying to sign form repeatedlt
    try {
        Bureaucrat e("Emily", 10);
        std::cout << e << std::endl;
        Form fe("Form_Emily", 20, 200);
        std::cout << fe << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}