/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:32:03 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 16:57:41 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ◦ It has an array of contacts.
// ◦ It can store a maximum of 8 contacts. 
//     If the user tries to add a 9th contact, replace the oldest one by the new one.
// ◦ Please note that dynamic allocation is forbidden.

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact     persons[8];
    int         total; //could be 0 to 8
    int         oldest_index;

public:
    PhoneBook(); //constructor funcsion, executed when callinng the class, initiatem the Class pb
    Contact getContact();
    void    addContact();
    void    showContacts();
    void    showoneContact(int i);
    void    searchContact();
    //search contact
    //maybe cleanning up this phonebook ?
};

#endif