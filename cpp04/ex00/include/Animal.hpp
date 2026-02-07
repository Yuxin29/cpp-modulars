#pragma once

#include <string>
#include <iostream>

// 4 Features of all OOP including C++
// Encapsulation    Hide data, control access
// Abstraction      Show result, hide how
// Inheritance      Reuse and extend
// Polymorphism     One interface, many behaviors
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
    //virtual enables polymorphilism
	std::string getType() const;           
};
