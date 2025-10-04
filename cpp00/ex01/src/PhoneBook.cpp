/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:30:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 17:17:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//first: constructor functinos
// it is special, it does not have a return value
// executed when callinng the class, initiatem the Class pb
PhoneBook::PhoneBook()
{
    total = 0;
    oldest_index = 0;   
}

void    PhoneBook::showoneContact(int i)
{
    std::cout << "First name: " << persons[i].getFirstName() << std::endl;
    std::cout << "Last name: " << persons[i].getFirstName() << std::endl;
    std::cout << "Nick ame: " << persons[i].getNickname() << std::endl;
    std::cout << "Phone number: " << persons[i].getFirstName() << std::endl;
    std::cout << "Darkest secrect: " << persons[i].getDarkestSecret() << std::endl;
}

void    PhoneBook::showContacts()
{
    std::string info;
    for (int i = 0; i < total; ++i)
    {
        showoneContact(i);
    }
}

void    PhoneBook::searchContact()
{
    std::string index;
    int    i;
    
    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, index);
    i = std::atoi(index.c_str());
    if (i < total)
    {
        showoneContact(i);
        return;
    }
    std::cout << "Invalid index" << std::endl;
    return;
}

//add a new contact to the phonebook
void    PhoneBook::addContact()
{
    Contact  new_contact  = getContact();
    if (total < 8)
    {
        persons[total] = new_contact; 
        total++;
        return;
    }
    persons[oldest_index] =  new_contact;
    return;
}

//get info from the keyboard
Contact    PhoneBook::getContact()
{
    std::string input;//input is a mutable object: thus it can you cleared, covered and reused
    Contact     new_contact;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    new_contact.setFirstName(input);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    new_contact.setLastName(input);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, input);
    new_contact.setNickname(input);
    
    std::cout << "Enter number: ";
    std::getline(std::cin, input);
    new_contact.Contact::setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    new_contact.Contact::setDarkestSecret(input);

    return new_contact;
}
