#include "Zombie.hpp"

int main()
{
    //heap zombie
    std::cout << "------now here comes heap Zombie arrays------" << std::endl;
    Zombie* boy_horde = zombieHorde(4, "boy");
    for (int i = 0; i < 4; i++){
        std::cout << "this is Zombie index: " << i << std::endl;
        boy_horde[i].announce();
    }
    delete[] boy_horde;
    std::cout << std::endl;

    std::cout << "------now here comes 0-Zombie arrays------" << std::endl;
    Zombie* none_horde = zombieHorde(0, "none");
    for (int i = 0; i < 0; i++){
        std::cout << "this is Zombie index: " << i << std::endl;
        none_horde[i].announce();
    }
    delete[] none_horde;
    std::cout << std::endl;

    std::cout << "------now here comes empty-Zombie arrays------" << std::endl;
    Zombie* empty_horde = zombieHorde(3, "");
    for (int i = 0; i < 3; i++){
        std::cout << "this is Zombie index: " << i << std::endl;
        empty_horde[i].announce();
    }
    delete[] empty_horde;
    std::cout << std::endl;

    return 0;
}