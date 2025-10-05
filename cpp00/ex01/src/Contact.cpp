/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 14:45:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
    
// set infos
// input is a mutable object: 
// thus it can you cleared, covered and reused
void	Contact::getContact()
{
    std::string input;
    //first name
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } 
    while (input.empty());
        FirstName = input;
    //last name
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);if (input.empty())
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    } 
    while (input.empty());
        LastName = input;
    //nickname
    do {
        std::cout << "Enter nick name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    }
    while (input.empty());
        Nickname = input;
    //number
    do {
        std::cout << "Enter number: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    }
    while (input.empty());
        PhoneNumber = input;
    //secrect
    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Input cannot be empty. Please try again.\n";
    }
    while (input.empty());
        DarkestSecret = input;
}

void        Contact::printContactsSummary()
{
    std::string fn = FirstName;
    std::string ln = LastName;
    std::string nn = Nickname;
    
    if (fn.length() > MAX_LENGTH)
	{
		fn.resize(MAX_LENGTH - 1);
		fn.append(".");
	}
    if (fn.length() > MAX_LENGTH)
	{
		fn.resize(MAX_LENGTH - 1);
		fn.append(".");
	}
    if (fn.length() > MAX_LENGTH)
	{
		fn.resize(MAX_LENGTH - 1);
		fn.append(".");
	}
    std::cout << std::setw(10) << 1 << "|"
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