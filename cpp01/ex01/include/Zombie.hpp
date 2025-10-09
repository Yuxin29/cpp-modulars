/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/09 13:00:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

// You have to determine in what case it’s better to allocate the zombies on the stack or heap.
// Zombies must be destroyed when you don’t need them anymore. 
// The destructor must print a message with the name of the zombie for debugging purposes.
class Zombie
{
private:
    std::string name;
    
public:
    Zombie();                   //Constructor: class method, eg.   Zombie z;            stack mem
    Zombie(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~Zombie();			        //deconstructer

    void announce(void);
    void setName(std::string name);
};

// It must allocate N Zombie objects in a single allocation. 
// Then, it has to initialize the zombies, 
// giving each one of them the name passed as parameter. 
Zombie* zombieHorde(int N, std::string name);

#endif
