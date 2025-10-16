/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:03 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 10:54:05 by yuwu             ###   ########.fr       */
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
    int           _FixedPointValue;
    static const int    _FractionalBitsNumber = 8;

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


// LATER
// And add the following function 
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter
// Overload << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
