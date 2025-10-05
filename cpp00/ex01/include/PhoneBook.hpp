/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:32:03 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 14:58:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>

// ◦ It has an array of contacts.
// ◦ It can store a maximum of 8 contacts. 
//     If the user tries to add a 9th contact, replace the oldest one by the new one.
class PhoneBook
{
private:
	Contact	persons[8];
	int		total;
	int		oldest_index;

public:
	PhoneBook(); 
	void	addContact();
	void	searchContact();
};

#endif