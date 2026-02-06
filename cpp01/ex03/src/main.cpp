#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    // Weapon testing
    std::cout << "------------------------" << std::endl;
    Weapon test = Weapon("cold weapon");
    std::cout << "the original type is " << test.getType() << std::endl;
    test.setType("hot weapon");
    std::cout << "the new type is " << test.getType() << std::endl;
    std::cout << std::endl;
    
    // HumanA testing
    {
    std::cout << "------------------------" << std::endl;
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    std::cout << std::endl;
    }
    
    // HumanB testing
    {
    std::cout << "------------------------" << std::endl;
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    std::cout << std::endl;
    }

    return 0;
}
