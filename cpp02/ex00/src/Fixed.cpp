
#include "Fixed_hpp"

Fix::Fix()
{
    std::cout << "Default constructor called" << std::endl;
}

//copy 
{
   //Fixed b( a );   //2 obj     -->>copy = first copy, then asigne????
    std::cout << "Copy constructor called " << std::endl;
    std::cout << "Copy assignment operator called " << std::endl;
    std::cout << "getRawBits member function called " << std::endl;
}

// copy asginer
{
    //c = b;
    std::cout << "Copy assignment operator called " << std::endl;
    std::cout << "getRawBits member function called " << std::endl;
}

Fix::~Fix()
{
   std::cout << "Destructor called" << std::endl;
}

void Fix::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    std::cout << "nbr" << std::endl;
    // 0
}