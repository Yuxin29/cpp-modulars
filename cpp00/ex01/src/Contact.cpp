/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 16:37:44 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
    
//set infos
void    Contact::setFirstName(std::string &name)
{
    FirstName = name;
}


void    Contact::setLastName(std::string &name)
{
    LastName = name;
}

void    Contact::setNickname(std::string &name)
{
    Nickname = name;
}

void    Contact::setPhoneNumber(std::string &number)
{
    PhoneNumber = number;
}
void    Contact::setDarkestSecret(std::string &secrect)
{
    DarkestSecret = secrect;
}

//get infos
std::string Contact::getFirstName()
{
    return FirstName;
}

std::string Contact::getLastName()
{
    return LastName;
}

std::string    Contact::getNickname()
{
    return Nickname;
}

std::string Contact::getPhoneNumber()
{
    return PhoneNumber;
}

std::string    Contact::getDarkestSecret()
{
    return DarkestSecret;
}
