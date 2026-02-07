#include "Cat.hpp"
#include "Brain.hpp"

//Shallow copy copies pointers, deep copy copies the data they point to.

Cat::Cat()
    : Animal(){
    _type = "Cat";
    std::cout << "Cat: " << _type << " constructed." << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& other)
    : Animal(other){
    // deep copy
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat &other){
    if (this != &other) {
        Animal::operator=(other);
         //deepcopy
        *_brain = *other._brain;
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