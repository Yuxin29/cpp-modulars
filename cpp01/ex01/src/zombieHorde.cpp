#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
        return 0;
    Zombie *horde = new(std::nothrow) Zombie[N];
    // in case of std::bad_alloc, it will return nullptr
    // can as well do try catch
    if (!horde){
        std::cout << "Error: Failed to allocate mem for zombie horde." << std::endl;
        return nullptr;
    }
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}