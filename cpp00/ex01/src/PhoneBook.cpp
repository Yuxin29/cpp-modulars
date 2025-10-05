/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:30:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 15:15:39 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

// constructor functinos: it does not have a return value
// executed when callinng the class, initiatem the Class pb
PhoneBook::PhoneBook()
{
    total = 0;
    oldest_index = 0;   
}

//add a new contact to the phonebook
void    PhoneBook::addContact()
{
    Contact  new_contact;
    new_contact.getContact();
    if (total < 8)
    {
        persons[total] = new_contact; 
        total++;
        return;
    }
    persons[oldest_index] =  new_contact;
    return;
}

bool isPositiveDigit(std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void    PhoneBook::searchContact()
{
    std::string index;
    int    i = -1;
    
    //empty phonebook
    if (total < 1)
    {
        std::cout << "The phonebook is empty. " << std::endl;
        return ;
    }
    //print all phonebook contacts summary
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "firstname" << "|"
              << std::setw(10) << "lastname" << "|"
              << std::setw(10) << "nickname" << std::endl;
    for (int d = 0; d < total; ++d)
    {
        persons[d].printContactsSummary();
    }
    //select the index of the contact
    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, index);
    do {
        std::cout << "Enter the index of the contact you want to display: ";
        std::getline(std::cin, index);
        if (!isPositiveDigit(index))
        {
            std::cout << "invalid index. Please try again.\n";
            continue;
        }
        i = std::atoi(index.c_str());
        if (i > total)
            std::cout << "Index out of range" << std::endl;
    }
    while (i == -1);
        persons[i].printContact();
    return;
}
