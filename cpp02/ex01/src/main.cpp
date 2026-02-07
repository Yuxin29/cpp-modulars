#include "Fixed.hpp"

int main( void ) 
{
    std::cout << "---------test Orthodox Form---------" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << std::endl;

    std::cout << "---------print actual number values, int / float---------" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << std::endl;
    
    std::cout << "---------print whole number values---------" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << std::endl;

    std::cout << "---------stress testing ---------" << std::endl;
    Fixed const m(MY_INT_MAX);
    std::cout << "m is " << m << std::endl;
    std::cout << std::endl;

    return 0;
}
