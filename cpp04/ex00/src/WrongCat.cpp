#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal(){
    _type = "WrongCat";
    std::cout << "WrongCat: " << _type << " constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other){
    this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other){
    WrongAnimal::operator=(other);
    this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat(){    
    std::cout << "WrongCat: " << _type << " deconstructed." << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "niaoooooo." << std::endl;
}
