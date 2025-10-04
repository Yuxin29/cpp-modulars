/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 15:29:12 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(std::string &name)
{
    FirstName = name;
}


void    Contact::setLastName(std::string &name)
{
    LastName = name;
}

void    Contact::setNumber(std::string &number)
{
    Number = number;
}

std::string Contact::getFirstName()
{
    return FirstName;
}

std::string Contact::getLastName()
{
    return LastName;
}

std::string Contact::getNumber()
{
    return Number;
}
