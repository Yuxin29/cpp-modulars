/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 16:50:21 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

// Write a program that contains:
// • A string variable initialized to "HI THIS IS BRAIN".
// • stringPTR: A pointer to the string.
// • stringREF: A reference to the string.
// Your program has to print:
// • The memory address of the string variable.
// • The memory address held by stringPTR.
// • The memory address held by stringREF.
// And then:
// • The value of the string variable.
// • The value pointed to by stringPTR.
// • The value pointed to by stringREF.

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string variable is " << &str << std::endl;
    std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << stringREF << std::endl;

    std::cout << "The value of the string variable is " << str << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is " << stringREF << std::endl;

    return 0;
}
