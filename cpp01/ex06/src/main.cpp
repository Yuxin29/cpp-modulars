/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 14:40:18 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Give the name harlFilter to your executable.

int main(int ac, char **av)
{
    Harl harl;
     
    if (ac != 2)
    {
        std::cout << "Wrong av number." << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}
