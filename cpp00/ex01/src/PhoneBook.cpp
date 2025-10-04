/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:30:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 15:55:52 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// On program start-up, the phonebook is empty and the user is prompted to enter one
// of three commands. The program only accepts ADD, SEARCH and EXIT.

#include "PhoneBook.hpp"
#include "Contact.hpp"

//first constructor functinos
// it is special, it does not have a return value
PhoneBook::PhoneBook()
{
    total = 0;
    oldest_index = 0;   
}

//add a new contact to the phonebook
void    PhoneBook::addContact(Contact &c)
{
    Contact  new_contact  = getContact();
    
    
}

//get info from the keyboard
Contact    PhoneBook::getContact()
{
    std::string input;
    Contact     new_contact; //input is a mutable object: thus it can you cleared, covered and reused
    
    std::cout << "Enter first_name: ";
    std::getline(std::cin, input);
    new_contact.setFirstName(input);
    
    std::cout << "Enter last_name: ";
    std::getline(std::cin, input);
    new_contact.setLastName(input);
    
    std::cout << "Enter number: ";
    std::getline(std::cin, input);
    new_contact.Contact::setNumber(input);

    return new_contact;
}
