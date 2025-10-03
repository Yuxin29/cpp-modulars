/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:46:38 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 15:19:07 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
    //PhoneBook   book;
    std::string cmd;
    while (true)
    {
        std::cout << "Enter command please (ADD, SEARCH / EXIT): ";
        std::getline(std::cin, cmd); /// I dont know how to write this one yet: but use getline to get the cmd
        return 1; //test run
        if (cmd == "ADD")
        {
            //do add
        }
        else if (cmd == "SEARCH")
        {
            //do search
            
        }
        else if (cmd == "EXIT")
        {
            //quit the program
            break; // do I have some thing to free ??
        }
    }
	return (0);
}
