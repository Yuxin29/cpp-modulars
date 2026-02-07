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
    virtual ~WrongAnimal();  //still virtual, for mem safety

	void makeSound() const;         //not virtual, so polymorphism won't apply
	std::string getType() const;   
};
