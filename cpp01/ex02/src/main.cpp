/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:24:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

// Subjects
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
// Notes
// &str → address of the original string variable
// stringPTR → holds the same address (pointer)
// stringREF → stringREF itself is not a pointer, but using it in &stringREF gives the same address as str.
int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string variable is " << &str << std::endl;
    std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << &stringREF << std::endl;

    std::cout << "The value of the string variable is " << str << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl; //stringPTR: dereference the ptr
    std::cout << "The value pointed to by stringREF is " << stringREF << std::endl;

    return 0;
}
