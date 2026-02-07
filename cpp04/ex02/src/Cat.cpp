#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
    : Animal(){  
    _type = "Cat";
    std::cout << "Cat: " << _type << " constructed." << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& other)
    : Animal(other){
    _brain = new Brain(*other._brain);// deep copy
}

Cat& Cat::operator=(const Cat &other){
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain; //deepcopy
    }
    return *this;
}

Cat::~Cat(){    
    delete _brain;
    std::cout << "Cat: " << _type << " deconstructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaoooooo." << std::endl;
}

Brain &Cat::getBrain()
{
    return *_brain;
}