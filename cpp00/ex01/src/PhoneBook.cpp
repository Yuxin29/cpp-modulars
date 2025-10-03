/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:30:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 16:19:32 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// On program start-up, the phonebook is empty and the user is prompted to enter one
// of three commands. The program only accepts ADD, SEARCH and EXIT.

#include "PhoneBook.hpp"

void add_Contact()
{
    std::string name_f;
    std::string name_l;
    std::string nbr;
    //Contact     new;
    
    std::cout << "Enter first_name: ";
    std::getline(std::cin, name_f);
    //set_first_name
    
    std::cout << "Enter first_name: ";
    std::getline(std::cin, name_f);
    //set_first_name
    
    std::cout << "Enter first_name: ";
    std::getline(std::cin, name_f);
    //set_first_name
}
