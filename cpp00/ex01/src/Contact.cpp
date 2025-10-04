/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 18:04:45 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
    
// //set infos
void	Contact::fillFromInput()
{
    std::string input;//input is a mutable object: thus it can you cleared, covered and reused
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    FirstName = input;
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    LastName = input;

    std::cout << "Enter nick name: ";
    std::getline(std::cin, input);
    Nickname = input;
    
    std::cout << "Enter number: ";
    std::getline(std::cin, input);
    PhoneNumber = input;

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    DarkestSecret = input;
}

void        Contact::printContact()
{
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nick ame: " << Nickname << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secrect: " << DarkestSecret << std::endl;
}