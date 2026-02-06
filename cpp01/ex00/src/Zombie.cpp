#include "Zombie.hpp"

Zombie::Zombie(){ 
}

//Constructor: class method, object level op, stack mem
Zombie::Zombie(std::string name)
: name(name) {
}

//deconstructer
// The destructor must print a msg with the name of the zombie for debugging.
Zombie::~Zombie(){
    std::cout << this->name << " is now destroyed." << std::endl;
}
    
void Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}