/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:53:37 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 10:53:39 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void )
{
    Fixed a;        //1 obj
    //Default constructor called
    Fixed b( a );   //2 obj     -->>copy = first copy, then asigne????
    //Copy constructor called  
    //Copy assignment operator called 
    //getRawBits member function called
    Fixed c;        //3 obj
    //Default constructor called
    c = b;
    //Copy assignment operator called
    //getRawBits member function called
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    // getRawBits member function called
    // 0
    // getRawBits member function called
    // 0
    // getRawBits member function called
    // 0
    //Destructor called
    // Destructor called
    // Destructor called
    return 0;
}
