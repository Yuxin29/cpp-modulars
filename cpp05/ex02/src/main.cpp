#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    // can signed the for.
    try {
        Bureaucrat a("Alice", 1);
        AForm fa("AForm_Alice", 1, 1);
        std::cout << a << std::endl;
        std::cout << fa << std::endl;
        a.signAForm(fa);
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
        AForm fb("AForm_Boris", 149, 149);
        std::cout << fb << std::endl;
        b.signAForm(fb);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //can not sign first but can after increment grade for bureact
    try {
        Bureaucrat c("Colin", 76);
        std::cout << c << std::endl;
        AForm fc("AForm_Colin", 75, 75);
        std::cout << fc << std::endl;
        c.signAForm(fc);
        c.incrementGrade();
        std::cout << c << std::endl;
        c.signAForm(fc);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //trying to sign AForm repeatedlt
    try {
        Bureaucrat d("David", 10);
        std::cout << d << std::endl;
        AForm fd("AForm_Colin", 20, 20);
        std::cout << fd << std::endl;
        d.signAForm(fd);
        std::cout << fd << std::endl;
        d.signAForm(fd);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //trying to sign AForm repeatedlt
    try {
        Bureaucrat e("Emily", 10);
        std::cout << e << std::endl;
        AForm fe("AForm_Emily", 20, 200);
        std::cout << fe << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}