/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 16:20:55 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::set_FirstName(std::string &name)
{
    FirstName = name;
}


void    Contact::set_LastName(std::string &name)
{
    LastName = name;
}

void    Contact::set_Number(std::string &number)
{
    Number = number;
}

std::string Contact::get_FirstName()
{
    return FirstName;
}

std::string Contact::get_LastName()
{
    return LastName;
}

std::string Contact::get_Number()
{
    return Number;
}
