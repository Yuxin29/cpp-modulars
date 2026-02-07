#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
    WrongAnimal(const WrongAnimal& other);               
    WrongAnimal& operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();  
	//still virtual, for mem safety

	void makeSound() const;         
	//not virtual, so the WrongCat should output the WrongAnimal sound.
	std::string getType() const;   
};
