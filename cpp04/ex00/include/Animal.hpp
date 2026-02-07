#pragma once

#include <string>
#include <iostream>

// 4 Features of all OOP including C++
// Encapsulation   Hide data, control access
// Abstraction     Show result, hide how
// Inheritance     Reuse and extend
// Polymorphism	One interface, many behaviors
class Animal
{
protected:
	std::string _type;
	
public:
	Animal();
    //Animal(std::string type); No need because the tyep is by defualt;
    Animal(const Animal& other);               
    Animal& operator=(const Animal &other);
    virtual ~Animal();  //virtual makes sure when deconstruct/delete parent, child is also deconstructed/deleted

	virtual void makeSound() const;         //virtual  enables polmorphilism
	std::string getType() const;            //not neccassarilye virtual 
};
