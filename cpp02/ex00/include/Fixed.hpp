/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:52:25 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 10:52:29 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
