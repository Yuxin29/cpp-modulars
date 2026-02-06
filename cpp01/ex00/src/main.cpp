#include "Zombie.hpp"

int main()
{
    // zombies on heap memories
    std::cout << "------now here comes a heap Zombie------" << std::endl;
    Zombie* testZombie = newZombie("boy");
    testZombie->announce();
    delete (testZombie);
    Zombie* emptyZombie = newZombie("");
    emptyZombie->announce();
    delete (emptyZombie);
    std::cout << "------heap Zombie test done------" << std::endl << std::endl;

    // zombies on stack memories
    std::cout << "------now here comes a stack Zombie------" << std::endl;
    randomChump("girl z");
    randomChump("");
    std::cout << "------stack Zombie test done------" << std::endl;
    
    return 0;
}
