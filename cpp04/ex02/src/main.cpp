#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* i = nullptr;
	const Animal* j = nullptr;
	try
	{	
		std::cout << "------------ Testing Abstract Animal ------------" << std::endl;
		//Animal a = Animal(); 
		std::cout << std::endl;

		std::cout << "------------ testing constructor ------------" << std::endl;
		i = new Dog();
		j = new Cat();
		std::cout << std::endl;
		
		std::cout << "------------ testing get type ------------" << std::endl;
		std::cout << "Dog type: " << i->getType() << std::endl;
		std::cout << "Cat type: " << j->getType() << std::endl;
		std::cout << std::endl;
		
		std::cout << "------------ testing makeSound  ------------" << std::endl;
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;

		std::cout << "------------ Deleting objects  ------------" << std::endl;
		delete i;
		delete j;
		std::cout << std::endl;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Error: Allocation failed: " << e.what() << std::endl;
		delete i;
		delete j;
		return 1;
	}
	
	return 0;
}
