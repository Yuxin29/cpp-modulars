#pragma once 

#include <string>
#include <iostream>
#include <cmath>

constexpr int INT_MAX = 2147483647;
constexpr int INT_MIN = -2147483648;

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBitsNumber = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& another);
    Fixed& operator=(const Fixed &other);
    ~Fixed(); 

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

// from the sub
// An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter
// Overloads the insertion operator (<<) for Fixed objects.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
