/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:00:18 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

// stack or heap?
// Zombies must be destroyed when you don’t need them anymore. 
class Zombie
{
private:
    std::string name;
    
public:
    Zombie();                 //Constructor: class method, eg.   Zombie z;            stack mem
    Zombie(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~Zombie();			        //deconstructer

    void announce(void);
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
