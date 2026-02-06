#include <string>
#include <iostream>

// Notes
// &str → address of the original string variable
// stringPTR → holds the same address (pointer)
// stringREF → stringREF itself is not a pointer, but using it in &stringREF gives the same address as str.
int main()
{
    // • A string variable initialized to "HI THIS IS BRAIN".
    // • stringPTR: A pointer to the string.
    // • stringREF: A reference to the string.
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // • The memory address of the string variable.
    // • The memory address held by stringPTR.
    // • The memory address held by stringREF.
    std::cout << "The memory address of the string variable is " << &str << std::endl;
    std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << &stringREF << std::endl;

    // • The value of the string variable.
    // • The value pointed to by stringPTR.
    // • The value pointed to by stringREF.
    std::cout << "The value of the string variable is " << str << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl; //stringPTR: dereference the ptr
    std::cout << "The value pointed to by stringREF is " << stringREF << std::endl;

    return 0;
}
