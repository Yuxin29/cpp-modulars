/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:53:37 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 15:50:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void )
{
    std::cout << "------------------" << std::endl;
    Fixed a;
   
    std::cout << "------------------" << std::endl;
    Fixed b(a);
    
    std::cout << "------------------" << std::endl;
    Fixed c;   
    c = b;
    
    std::cout << "------------------"<< std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    std::cout << "------------------"<< std::endl;
    a.setRawBits(1);
    b.setRawBits(2);
    c.setRawBits(3);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
