#include "Zombie.hpp"

// It creates a zombie, name it, and the zombie announces itself.
// stack memory
void    randomChump(std::string name){
    Zombie z(name);
    z.announce();
}
