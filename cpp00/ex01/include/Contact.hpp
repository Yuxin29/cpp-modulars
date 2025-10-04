/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:36:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 15:29:24 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ Stands for a phonebook contact.

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string     FirstName;
    std::string     LastName;
    std::string     Number;

public:
    void        setFirstName(std::string &name);
    void        setLastName(std::string &name);
    void        setNumber(std::string &number);

    std::string getFirstName();
    std::string getLastName();
    std::string getNumber();
}; //seems I need this ;

#endif