/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:46:38 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 16:42:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook   book;
    std::string cmd;
    while (true)
    {
        std::cout << "Enter command please (ADD / SEARCH / EXIT): ";
        std::getline(std::cin, cmd); /// I dont know how to write this one yet: but use getline to get the cmd
        if (cmd == "ADD")
        {
            std::cout << "now we are adding" << std::endl;
            book.addContact();
        }
        else if (cmd == "SEARCH")
        {
            std::cout << "now we are searching" << std::endl;
            book.showContacts();
            //do search
        }
        else if (cmd == "EXIT")
        {
            std::cout << "now we are quiting the program" << std::endl;
            //quit the program
            break; // do I have some thing to free ??
        }
    }
	return (0);
}
