/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 11:34:47 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int           _fixedPointValue;
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

    //The 4 arithmetic operators: +, -, *, and /.

    //The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
    // post-decrement) operators, that will increase or decrease the fixed-point value from
    // the smallest representable ϵ such as 1 + ϵ > 1.

    // • A static member function min that takes as parameters two references on fixed-point
    // numbers, and returns a reference to the smallest one.
    // • A static member function min that takes as parameters two references to constant
    // fixed-point numbers, and returns a reference to the smallest one.
    // • A static member function max that takes as parameters two references on fixed-point
    // numbers, and returns a reference to the greatest one.
    // • A static member function max that takes as parameters two references to constant
    // fixed-point numbers, and returns a reference to the greatest one
};

// LATER
// And add the following function 
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter
// Overload << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
