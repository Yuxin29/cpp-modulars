/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/07 19:04:10 by yuwu             ###   ########.fr       */
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
    //Zombie();                   //Constructor: class method, eg.   Zombie z;            stack mem
    Zombie(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~Zombie();			        //deconstructer

    void announce(void);
};

// It creates a zombie, name it, and return it so you can use it outside of the functionscope.
Zombie* newZombie( std::string name );
//It creates a zombie, name it, and the zombie announces itself.
void    randomChump( std::string name );

#endif
