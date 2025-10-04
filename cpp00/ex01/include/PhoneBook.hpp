/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:32:03 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 18:04:35 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

// ◦ It has an array of contacts.
// ◦ It can store a maximum of 8 contacts. 
//     If the user tries to add a 9th contact, replace the oldest one by the new one.
// ◦ Please note that dynamic allocation is forbidden.
class PhoneBook
{
private:
	Contact	persons[8];
	int		total; //could be 0 to 8
	int		oldest_index;

public:
	PhoneBook(); 
	void	addContact();
	void	searchContact();
};

#endif