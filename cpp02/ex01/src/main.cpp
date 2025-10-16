/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:34 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 14:18:04 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    std::cout << "---------test default constructor---------" << std::endl << std::endl;
    
    Fixed const b(10);
    std::cout << "---------test int constructor---------" << std::endl << std::endl;

    Fixed const c(42.42f);
    std::cout << "---------test float constructor---------" << std::endl << std::endl;

    Fixed const d(b);
    std::cout << "---------test copy constructor---------" << std::endl << std::endl;
    
    a = Fixed( 1234.4321f );
    std::cout << "---------test copy assign constructor---------" << std::endl << std::endl;
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "---------print whole number values---------" << std::endl << std::endl;
    // a is 1234.43
    // b is 10
    // c is 42.4219
    // d is 10
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "---------print whole number values---------" << std::endl << std::endl;
    // a is 1234 as integer
    // b is 10 as integer
    // c is 42 as integer
    // d is 10 as integer

    return 0;
}
