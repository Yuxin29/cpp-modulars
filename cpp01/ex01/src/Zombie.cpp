#include "Zombie.hpp"

//Constructor: class method, class level op, eg.   Zombie z;            stack mem
Zombie::Zombie(){
}

//Constructor: class method, object level op, eg.   Zombie z("Manday")   stack mem
Zombie::Zombie(std::string name)
:name(name){
}

//deconstructer
Zombie::~Zombie(){
    std::cout << this->name << " is now destroyed." << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
}

void Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
