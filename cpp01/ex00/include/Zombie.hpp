#pragma once 

#include <string>
#include <iostream>

// Zombies must be destroyed when you don’t need them anymore. 
// stack or heap memory?
class Zombie
{
private:
    std::string name;

public:
    Zombie();                   //Constructor: class method, eg.   Zombie z;            stack mem
    Zombie(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~Zombie();			        //deconstructer

    void announce(void);
};

// heap memory
Zombie* newZombie( std::string name );
// stack memory
void    randomChump( std::string name );
