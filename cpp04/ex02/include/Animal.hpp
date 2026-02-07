
#pragma once

#include <string>
#include <iostream>

// pure vitual class can only be called by new or state directly, it can only be inheritated,
// on child process, this pure vitual member function needs to be override.
class Animal
{
protected:
	std::string _type;
	
public:
	Animal();
    Animal(const Animal& other);               
    Animal& operator=(const Animal &other);
	//virtual makes sure when deconstruct/delete parent, child is also deconstructed/deleted
    virtual ~Animal();  

	//pure vitual, so the Animal class it pure abstact, can only be inharited, not created direcly.
	virtual void makeSound() const = 0;    
	std::string getType() const;
};
