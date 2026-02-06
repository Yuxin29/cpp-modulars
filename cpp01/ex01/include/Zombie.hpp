#pragma once 

#include <string>
#include <iostream>
#include <new>       // defines std::nothrow

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
// Then, it has to initialize the zombies,  giving each one of them the name passed as parameter. 
Zombie* zombieHorde(int N, std::string name);
