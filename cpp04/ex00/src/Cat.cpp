#include "Cat.hpp"

Cat::Cat()
    : Animal(){
    _type = "Cat";
    std::cout << "Cat: " << _type << " constructed." << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other){
}

Cat& Cat::operator=(const Cat &other){
    Animal::operator=(other);
    return *this;
}

Cat::~Cat(){    
    std::cout << "Cat: " << _type << " deconstructed." << std::endl;
}

void Cat::makeSound() const{
    std::cout << "miaoooooo." << std::endl;
}
