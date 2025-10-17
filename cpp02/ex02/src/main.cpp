/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:27 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 12:14:18 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void )
{
    std::cout << "---------othdox / getter_setter / toInt_toFloat tested before ---------" << std::endl << std::endl;

    {
        std::cout << "---------testing comparison operaters begins---------" << std::endl;
        Fixed a = Fixed(1);
        Fixed b = Fixed(2);
        Fixed c = Fixed(2);
        std::cout << "value of a is " << a << std::endl;
        std::cout << "value of b is " << b << std::endl;
        std::cout << "value of c is " << c << std::endl;
        std::cout << "----nomal testing ----" << std::endl;
        std::cout << "bool a > than b: " << a.operator>(b) << std::endl;
        std::cout << "bool a < than b: " << a.operator<(b) << std::endl;
        std::cout << "bool a >= than b: " << a.operator>=(b) << std::endl;
        std::cout << "bool a <= than b: " << a.operator<=(b) << std::endl;
        std::cout << "bool a == than b: " << a.operator==(b) << std::endl;
        std::cout << "bool a != than b: " << a.operator!=(b) << std::endl;
        std::cout << "----stress testing ----" << std::endl;
        std::cout << "bool c > than b: " << a.operator>(b) << std::endl;
        std::cout << "bool c < than b: " << a.operator<(b) << std::endl;
        std::cout << "bool c >= than b: " << a.operator>=(b) << std::endl;
        std::cout << "bool c <= than b: " << a.operator<=(b) << std::endl;
        std::cout << "bool c == than b: " << a.operator==(b) << std::endl;
        std::cout << "bool c != than b: " << a.operator!=(b) << std::endl;
    }
    std::cout << "---------testing comparison operaters ends---------" << std::endl  << std::endl;

    {
        std::cout << "---------testing arithmetic operaters begins---------" << std::endl;
        Fixed a = Fixed(2.4f);
        Fixed b = Fixed(2);
        Fixed c = Fixed(0);
        Fixed d = Fixed(__INT32_MAX__);
        std::cout << "----nomal caculations ----" << std::endl;
        Fixed const pl(a + b);
        Fixed const mi(a - b);
        Fixed const mu(a * b);
        Fixed const de(a / b);
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "the sum is " << pl << std::endl;
        std::cout << "the minus is " << mi << std::endl;
        std::cout << "the multi is " << mu << std::endl;
        std::cout << "the devision is " << de << std::endl;
        std::cout << "----a bit edge test ----" << std::endl;
        Fixed const m(a / c);
        Fixed const n(d * d);
        std::cout << "testing deividing by 0: " << m << std::endl;
        std::cout << "testing overflow:  " << n << std::endl;
    }
    std::cout << "---------testing arithmetic operaters ends---------" << std::endl << std::endl;

    {
        std::cout << "---------testing increment / decrement begings---------" << std::endl;
        Fixed a; //a initiated to 0, increment test
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;       // 0.00390625
        std::cout << a << std::endl;         // 0.00390625
        std::cout << a++ << std::endl;       // 0.00390625
        std::cout << a << std::endl;         // 0.0078125
        Fixed b; //a initiated to 0, decrement test
        std::cout << b << std::endl;
        std::cout << --b << std::endl;
        std::cout << b << std::endl;
        std::cout << b-- << std::endl;
        std::cout << b << std::endl;
        std::cout << "----a bit hybrid test ----" << std::endl;
        Fixed const c(a * b);
        std::cout << c << std::endl;
        std::cout << Fixed::max(a, c) << std::endl;
    }
    std::cout << "---------testing increment / decrement ends---------" << std::endl << std::endl;
    
    {
        std::cout << "---------testing max / min operaters begins---------" << std::endl;
        Fixed a = Fixed(1);
        Fixed b = Fixed(2);
        std::cout << "value of a is " << a << std::endl;
        std::cout << "value of b is " << b << std::endl;
        std::cout << "the min of a and b is(returning non_const) " << Fixed::min(a, b) << std::endl;
        std::cout << "the min of a and b is(returning const) " << Fixed::min(a, b) << std::endl;
        std::cout << "the max of a and b is(returning non_const) " << Fixed::max(a, b) << std::endl;
        std::cout << "the max of a and b is(returning const) " << Fixed::max(a, b) << std::endl;
    }
    std::cout << "---------testing max / min operaters ends---------" << std::endl << std::endl;

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
