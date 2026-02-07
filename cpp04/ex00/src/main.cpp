
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
	
int main()
{
	{
		std::cout << "------------ testing copy & copy assign on dog ------------" << std::endl;
		Dog a;
		Dog b = a;              
		Dog c; 
		c = Dog();
	}
	std::cout << std::endl;
	
	const Animal* meta = nullptr;
	const WrongAnimal* wrong_meta = nullptr;
	const Animal* j = nullptr;
	const Animal* i = nullptr;
	const WrongAnimal* k = nullptr;
	try
	{
		std::cout << "------------ testing parent and child ------------" << std::endl;
		meta = new Animal();
		wrong_meta = new WrongAnimal();
		j = new Dog();
		i = new Cat();
		k = new WrongCat();
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Error: Allocation failed: " << e.what() << std::endl;
		delete(meta);
		delete(wrong_meta);
		delete(j);
		delete(i);
		delete(k);
		return 1;
	}
	std::cout << std::endl;

	std::cout << "------------ testing getter ------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------ testing make sound ------------" << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	
	std::cout << "------------ testing make wrong sound ------------" << std::endl;
	wrong_meta->makeSound();
	k->makeSound(); // will output WrongAnimal sound due to missing virtual
	std::cout << std::endl;
	
	std::cout << "------------ Manually delete ------------" << std::endl;
	delete(meta);
	delete(wrong_meta);
	delete(j);
	delete(i);
	delete(k);
	std::cout << std::endl;

	return 0;
}
