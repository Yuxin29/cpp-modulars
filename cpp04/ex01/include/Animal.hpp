#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string _type;
	
public:
	Animal();
    Animal(const Animal& other);               
    Animal& operator=(const Animal &other);
    virtual ~Animal();  
	//virtual makes sure when deconstruct/delete parent, child is also deconstructed/deleted

	virtual void makeSound() const;         
	//virtual enables polmorphilism
	std::string getType() const;        
};
