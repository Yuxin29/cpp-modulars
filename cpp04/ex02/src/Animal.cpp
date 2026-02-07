#include "Animal.hpp"

Animal::Animal(){
    _type = "Pet";
    std::cout << "Animal: " << _type << " constructed." << std::endl;
}

Animal::Animal(const Animal& other){
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal &other){
    this->_type = other._type;
    return *this;
}

Animal::~Animal(){    
    std::cout << "Animal: " << _type << " deconstructed." << std::endl;
}

//this is not necessary, because pure abstract function never needs to be called
void Animal::makeSound() const
{
    std::cout << "woaaa I am an animal." << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}
    
