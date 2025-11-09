#include "Bureaucrat.hpp"

int main(void)
{
    //upper limit
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //lower limit
    try {
        Bureaucrat b("Boris", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //illegal construction
    try {
        Bureaucrat c("Colin", 0);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //normal functioning
    try {
        Bureaucrat d("David", 15);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}