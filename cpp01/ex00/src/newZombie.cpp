#include "Zombie.hpp"

// It creates a zombie, name it, and return it so you can use it outside of the functionscope.
// "use it outside of the functionscope". -> exists and use independently
// heap memory, needs to delete it manully
Zombie* newZombie(std::string name){
    return (new Zombie(name));
}