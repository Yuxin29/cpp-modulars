#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat fa("Form_Alice", 1, 1);
        a.signForm(fa);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}