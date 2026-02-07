#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    _type = "WrongPet";
    std::cout << "WrongAnimal: " << _type << " constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
    this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal(){    
    std::cout << "WrongAnimal: " << _type << " deconstructed." << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "woaaa I am a Wrong animal." << std::endl;
}

std::string WrongAnimal::getType() const{
    return _type;
}
    