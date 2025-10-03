/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:56:09 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/03 14:25:36 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << " LOUD AND UNBEARABLE FEEDBACK NOISE " << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++)
    {
        std::string temp(av[i]);
        for (std::string::size_type j = 0; j < temp.size(); j++)
        {
            temp[j] = std::toupper(temp[j]);
        }
        std::cout << temp;
        if (i < ac -1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}