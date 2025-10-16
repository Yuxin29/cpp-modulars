/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:34 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 10:54:36 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    //Default constructor called
    Fixed const b(0);
    // Int constructor called
    Fixed const c(42.42f);
    // Float constructor called
    Fixed const d( b );
    // Copy constructor called
    a = Fixed( 1234.4321f );
    // Copy assignment operator called
    // Float constructor called
    // Copy assignment operator called
    // Destructor called
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // a is 1234.43
    // b is 10
    // c is 42.4219
    // d is 10
    // a is 1234 as integer
    // b is 10 as integer
    // c is 42 as integer
    // d is 10 as integer

    return 0;
}
