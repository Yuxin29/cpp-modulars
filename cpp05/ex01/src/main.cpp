#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
        a.incre_grade();
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Boris", 150);
        std::cout << b << std::endl;
        b.decre_grade();
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Colin", 0);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

}