/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:46:38 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 15:17:43 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// On program start-up, the phonebook is empty and the user is prompted to enter one
// of three commands. The program only accepts ADD, SEARCH and EXIT.
int main()
{
    PhoneBook   book;
    std::string cmd;
    while (true)
    {
        std::cout << "Enter command please (ADD / SEARCH / EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            std::cout << "now we are adding" << std::endl;
            book.addContact();
        }
        else if (cmd == "SEARCH")
        {
            std::cout << "now we are searching" << std::endl;
            book.searchContact();
        }
        else if (cmd == "EXIT")
        {
            std::cout << "now we are quiting the program" << std::endl;
            break;
        }
    }
	return (0);
}
