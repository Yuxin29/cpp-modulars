#pragma once

#include <string>
#include <iostream>
#include <cmath>

constexpr int MY_INT_MAX = 2147483647;
constexpr int MY_INT_MIN = -2147483648;

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

    //The 6 comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed &another) const;  //the  const at the end make sure that this is not modified
    bool operator<(const Fixed &another) const;
    bool operator>=(const Fixed &another) const;
    bool operator<=(const Fixed &another) const; 
    bool operator==(const Fixed &another) const; 
    bool operator!=(const Fixed &another) const; 
    
    //The 4 arithmetic operators: +, -, *, and /. return a new Fixed 
    Fixed operator+(const Fixed &another) const;
    Fixed operator-(const Fixed &another) const;
    Fixed operator*(const Fixed &another) const;
    Fixed operator/(const Fixed &another) const;
    
    //The 4 increment/decrement (pre and post) operators, 
    Fixed &operator++();        //pre  ++i
    Fixed operator++(int);      //post i++, int no use, just to differentia.
    Fixed &operator--();
    Fixed operator--(int);      
    
    // min & max
    static Fixed &min(Fixed &a, Fixed& b);
    static const Fixed &min(const Fixed &a, const Fixed& b); //if input is const, return also const
    static Fixed &max(Fixed &a, Fixed& b);
    static const Fixed &max(const Fixed &a, const Fixed& b); //if input is const, return also const
};

// Overloads the insertion operator (<<) for Fixed objects.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);