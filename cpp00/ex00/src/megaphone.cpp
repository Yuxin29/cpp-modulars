/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:56:09 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 12:11:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *
// $>

// the aim of ex00: capitalize and print out a string.

#include <iostream>

int main()
{
    std::string name = "Summer";
    int number = 5;
    std::cout << "hello " << name << ", you are " << number << " years old." << std::endl;
    return 0;
}