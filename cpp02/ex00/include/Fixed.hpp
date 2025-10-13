
#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>

// Orthodox Canonical Form as below:
// • Default constructor
// • Copy constructor
// • Copy assignment operator
// • Destructor
class Fixed
{
private:
    int                 _FixedPointValue;
    static const int    _FractionalBitsNumber = 8;

public:
    Fixed();
    Fixed(const Fixed& another);
    Fixed& operator=(const Fixed &other);
    ~Fixed(); 

    int getRawBits(void) const;
    void setRawBits( int const raw );
};

#endif
