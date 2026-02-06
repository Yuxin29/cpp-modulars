#include "Zombie.hpp"

//return 0; //return (nullptr); // return NULL;
Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
        return 0;
    Zombie *horde = new(std::nothrow) Zombie[N];
    if (!horde) //do I need to error check here??
    {
        std::cout << "Error: Failed to allocate mem for zombie horde." << std::endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}