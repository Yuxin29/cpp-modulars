#include "Animal.hpp"

Animal::Animal(){
    _type = "Pet";
    std::cout << "Animal: " << _type << " constructed." << std::endl;
}

Animal::Animal(const Animal& other){
    this->_type = other._type;
    std::cout << "Copy animal " << _type << "." << std::endl;
}

Animal& Animal::operator=(const Animal &other){
    this->_type = other._type;
    std::cout << "Copy assign animal " << _type << "." << std::endl;
    return *this;
}

Animal::~Animal(){    
    std::cout << "Animal: " << _type << " deconstructed." << std::endl;
}

void Animal::makeSound() const{
    std::cout << "woaaa I am an animal." << std::endl;
}

std::string Animal::getType() const{
    return _type;
}
    
