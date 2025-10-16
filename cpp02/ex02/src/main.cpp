/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:27 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 16:02:52 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void )
{
    std::cout << "---------othdox / getter_setter / toInt_toFloat tested before ---------" << std::endl << std::endl;

    //code
    std::cout << "---------testing comparison operaters---------" << std::endl << std::endl;

    Fixed const pl(Fixed(2.4f) + Fixed(2));
    Fixed const mi(Fixed(2.4f) - Fixed(2));
    Fixed const mu(Fixed(2.4f) * Fixed(2));  // 1228 resulte wrong
    Fixed const de(Fixed(2.4f) / Fixed(2));  //0.00390625 resulte wrong
    std::cout << pl << std::endl;
    std::cout << mi << std::endl;
    std::cout << mu << std::endl;
    std::cout << de << std::endl;
    std::cout << "---------testing arithmetic operaters---------" << std::endl << std::endl;

    Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "---------testing increment / decrement ---------" << std::endl << std::endl;
    
    //code
    std::cout << "---------testing max / min operaters---------" << std::endl << std::endl;
    
    return 0;
}

// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// $>
