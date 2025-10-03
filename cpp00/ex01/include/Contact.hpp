/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:36:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 15:57:27 by yuwu             ###   ########.fr       */
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
    void        set_FirstName(std::string &name);
    void        set_LastName(std::string &name);
    void        set_Number(std::string &number);

    std::string get_FirstName();
    std::string get_LastName();
    std::string sget_Number();
}; //seems I need this ;

#endif