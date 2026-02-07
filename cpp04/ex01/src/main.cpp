#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* i = nullptr;
	const Animal* j = nullptr;
	try
	{
		std::cout << "============ TESTING SINGLE DOG AND CAT ============" << std::endl;
		std::cout << "testing constructor " << std::endl;
		i = new Dog();
		j = new Cat();
		
		std::cout << "testing get type" << std::endl;
		std::cout << "Dog type: " << i->getType() << std::endl;
		std::cout << "Cat type: " << j->getType() << std::endl;

		std::cout << "testing makeSound" << std::endl;
		i->makeSound();
		j->makeSound();

		std::cout << "Deleting objects " << std::endl;
		delete i;
		delete j;
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		delete i;
		delete j;
		return 1;
    }
	std::cout << std::endl;

	// in case of n is 5, there will be 3 cats and 2 dogs
	const int n = 4;
	Animal* animal_arr[n];
	for (int i = 0; i < n; ++i)
		animal_arr[i] = nullptr;
	try
	{
		std::cout << "============ TESTING ARRAY OF ANIMALS WITH BRAINS ============" << std::endl;
		std::cout << "n array construct" << std::endl;
		for (int i = 0; i < n / 2; i++)
			animal_arr[i] = new Dog();
		for (int i = n / 2; i < n; i++)
			animal_arr[i] = new Cat();
		std::cout << "get ideas " << std::endl;
		for (int i = 0; i < n / 2; i++){
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			dog->getBrain().get_idea(1);
		}
		for (int i = n / 2; i < n; i++){
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			cat->getBrain().get_idea(1);
		}

		std::cout << "set ideas" << std::endl;
		for (int i = 0; i < n / 2; i++){
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			dog->getBrain().set_idea(1, "I love human\n");
		}
		for (int i = n / 2; i < n; i++){
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			cat->getBrain().set_idea(1, "I hate human\n");
		}

		std::cout << "get ideas again" << std::endl;
		for (int i = 0; i < n / 2; i++){
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			std::cout << dog->getBrain().get_idea(1);
		}
		for (int i = n / 2; i < n; i++){
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			std::cout << cat->getBrain().get_idea(1);
		}
			
		std::cout << "n array deconstruct" << std::endl;
		for (int i = 0; i < n; i++)
			delete (animal_arr[i]);
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		for (int i = 0; i < n; i++)
			delete (animal_arr[i]);
		return 1;
    }
	std::cout << std::endl;
	
	try
	{
		std::cout << "============ TESTING DEEP COPY ============" << std::endl;
		Dog original;

		std::cout << "------------" << std::endl;
		Brain &brain1 = original.getBrain();
		brain1.set_idea(0, "Chase the mailman!");
		// calls deep copy constructor
		Dog copy = original;
		std::cout << "Original idea: " << original.getBrain().get_idea(0) << std::endl;
		std::cout << "Copy idea: " << copy.getBrain().get_idea(0) << std::endl;
		
		std::cout << "------------" << std::endl;
		Brain &brain2 = original.getBrain();
		brain2.set_idea(0, "Sleep on the couch.");
		std::cout << "After modifying original:" << std::endl;
		std::cout << "Original idea: " << original.getBrain().get_idea(0) << std::endl;
		std::cout << "Copy idea: " << copy.getBrain().get_idea(0) << std::endl;
		std::cout << std::endl;
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		return 1;
    }
	
	return 0;
}