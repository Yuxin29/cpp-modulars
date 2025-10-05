/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 15:49:00 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
    
// set infos: input is a mutable object: 
void	Contact::getContact()
{
    std::string input;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } while (input.empty());
    FirstName = input;

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } while (input.empty());
    LastName = input;

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } while (input.empty());
    Nickname = input;

    do {
        std::cout << "Enter number: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } while (input.empty());
    PhoneNumber = input;

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } while (input.empty());
    DarkestSecret = input;
}

void        Contact::printContactNames(int i)
{
    std::string fn = FirstName;
    std::string ln = LastName;
    std::string nn = Nickname;
    
    if (fn.length() > MAX_LENGTH)
	{
		fn.resize(MAX_LENGTH - 1);
		fn.append(".");
	}
    if (ln.length() > MAX_LENGTH)
	{
		ln.resize(MAX_LENGTH - 1);
		ln.append(".");
	}
    if (nn.length() > MAX_LENGTH)
	{
		nn.resize(MAX_LENGTH - 1);
		nn.append(".");
	}
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << fn << "|"
              << std::setw(10) << ln << "|"
              << std::setw(10) << nn << std::endl;
}
    
void        Contact::printContact()
{
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nickname: " << Nickname << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secrect: " << DarkestSecret << std::endl;
}