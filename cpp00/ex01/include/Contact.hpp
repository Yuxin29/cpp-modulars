/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:36:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 16:36:07 by yuwu             ###   ########.fr       */
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
    std::string     Nickname;
    std::string     PhoneNumber;
    std::string     DarkestSecret;

public:
    void        setFirstName(std::string &name);
    void        setLastName(std::string &name);
    void        setNickname(std::string &name);
    void        setPhoneNumber(std::string &number);
    void        setDarkestSecret(std::string &secrect);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
}; 
//seems I need this ;

#endif