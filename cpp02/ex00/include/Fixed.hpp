/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:52:25 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 15:36:48 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>

// Orthodox Canonical Form as below:
// Default constructor
// Copy constructor
// Copy assignment operator
// Destructor
class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBitsNumber = 8;

public:
    Fixed();
    Fixed(const Fixed& another);
    Fixed& operator=(const Fixed &other);
    ~Fixed(); 

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
