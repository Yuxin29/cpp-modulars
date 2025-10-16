/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:53:37 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 11:14:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void )
{
    Fixed a;        //1st obj
    std::cout << "---------test default constructor---------" << std::endl << std::endl;
   
    Fixed b( a );   //2nd obj     -->>copy = first copy, then asigne????
    std::cout << "---------test copy constructor---------" << std::endl << std::endl;
    
    Fixed c;        //3rd obj       copy & assign
    c = b;
    std::cout << "---------test copy assigning---------" << std::endl << std::endl;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << "--------test getter----------" << std::endl << std::endl;
    
    a.setRawBits(1);
    b.setRawBits(2);
    c.setRawBits(3);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << "---------test setter---------" << std::endl << std::endl;

    return 0;
}
