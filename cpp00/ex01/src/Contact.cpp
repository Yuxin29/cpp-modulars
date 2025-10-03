/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 16:01:52 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    set_FirstName(std::string &name)
{
    FirstName = name;
}


void    set_LastName(std::string &name)
{
    LastName = name;
}

void    set_Number(std::string &number)
{
    Number = number;
}

std::string Get_FirstName()
{
    return FirstName;
}

std::string Get_LastName()
{
    return LastName;
}

std::string Get_Number()
{
    return Number;
}
    