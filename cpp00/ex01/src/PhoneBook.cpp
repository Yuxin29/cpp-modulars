/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:30:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 14:47:00 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

//first: constructor functinos
// it is special, it does not have a return value
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

void    PhoneBook::searchContact()
{
    std::string index;
    int    i;
    
    if (total < 1)
    {
        std::cout << "The phonebook is empty. " << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "fistname" << "|"
              << std::setw(10) << "lastname" << "|"
              << std::setw(10) << "nickname" << std::endl;
    for (int d = 0; d < total; ++d)
    {
        persons[d].printContactsSummary();
    }
    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, index);
    //first need to make sure index is all digits
    i = std::atoi(index.c_str());
    if (i < total)
    {
        persons[i].printContact();
        return;
    }
    std::cout << "Invalid index" << std::endl;
    return;
}
