/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 15:30:18 by yuwu             ###   ########.fr       */
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
    // bool operator<(const Fixed &another) const;
    // bool operator>=(const Fixed &another) const;
    // bool operator<=(const Fixed &another) const; 
    // bool operator==(const Fixed &another) const; 
    // bool operator!=(const Fixed &another) const; 
    
    
    //The 4 arithmetic operators: +, -, *, and /.
    // Fixed const b(Fixed(5.05f) * Fixed(2));  Usage
    //return a new Fixed 
    Fixed operator+(const Fixed &another) const;
    // Fixed operator-(const Fixed &another) const;
    // Fixed operator*(const Fixed &another) const;
    // Fixed operator/(const Fixed &another) const;
    
    //The 4 increment/decrement (pre and post) operators, 
    // that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
    // ++i      pre increment
    // i++      post increment

    
    // • A static member function min that takes as parameters two references on fixed-point numbers, 
    // and returns a reference to the smallest one.
    // • A static member function min that takes as parameters two references to constant fixed-point numbers, 
    // and returns a reference to the smallest one.
    static Fixed &min(Fixed &a, Fixed& b);
    static const Fixed &min(const Fixed &a, const Fixed& b); //if input is const, return also const
    static Fixed &max(Fixed &a, Fixed& b);
    static const Fixed &max(const Fixed &a, const Fixed& b); //if input is const, return also const
};

// Overloads the insertion operator (<<) for Fixed objects.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
