/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 17:03:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    // Weapon testing
    std::cout << "------------------------" << std::endl;
    Weapon test = Weapon("cold weapon");
    std::cout << "the original type is " << test.getType() << std::endl;
    test.setType("hot weapon");
    std::cout << "the new type is " << test.getType() << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;
    
    // HumanA testing
    {
    std::cout << "------------------------" << std::endl;
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    std::cout << "------------------------" << std::endl << std::endl;
    }
    
    // HumanB testing
    {
    std::cout << "------------------------" << std::endl;
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    std::cout << "------------------------" << std::endl << std::endl;
    }
    return 0;
}
