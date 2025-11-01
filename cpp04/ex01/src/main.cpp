/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 14:29:32 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
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
		std::cout << "------------ testing constructor ------------" << std::endl;
		i = new Dog();
		j = new Cat();
		
		std::cout << "------------ testing get type ------------" << std::endl;
		std::cout << "Dog type: " << i->getType() << std::endl;
		std::cout << "Cat type: " << j->getType() << std::endl;

		std::cout << "------------ testing makeSound  ------------" << std::endl;
		i->makeSound();
		j->makeSound();

		std::cout << "------------ Deleting objects  ------------" << std::endl;
		delete i;
		delete j;
		std::cout << "============ TESTING SINGLE DOG AND CAT DONE ============" << std::endl << std::endl;
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		delete i;
		delete j;
		return 1;
    }
	
	int n = 4;  // in case of n is 5, there will be 3 cats and 2 dogs
	Animal* animal_arr[n] = {nullptr};
	try
	{
		std::cout << "============ TESTING ARRAY OF ANIMALS WITH BRAINS ============" << std::endl;
		std::cout << "------------ n array construct ------------" << std::endl;
		for (int i = 0; i < n / 2; i++)
			animal_arr[i] = new Dog();
		for (int i = n / 2; i < n; i++)
			animal_arr[i] = new Cat();
		std::cout << "------------ get ideas ------------" << std::endl;
		for (int i = 0; i < n / 2; i++)
		{
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			dog->getBrain().get_idea(1);
		}
		for (int i = n / 2; i < n; i++)
		{
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			cat->getBrain().get_idea(1);
		}

		std::cout << "------------ set ideas ------------" << std::endl;
		for (int i = 0; i < n / 2; i++)
		{
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			dog->getBrain().set_idea(1, "I love human\n");
		}
		for (int i = n / 2; i < n; i++)
		{
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			cat->getBrain().set_idea(1, "I hate human\n");
		}

		std::cout << "------------ get ideas again------------" << std::endl;
		for (int i = 0; i < n / 2; i++)
		{
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			std::cout << dog->getBrain().get_idea(1);
		}
		for (int i = n / 2; i < n; i++)
		{
			Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
			std::cout << cat->getBrain().get_idea(1);
		}
			
		std::cout << "------------ n array deconstruct ------------" << std::endl;
		for (int i = 0; i < n; i++)
			delete (animal_arr[i]);
		std::cout << "============ TESTING ARRAY OF ANIMALS WITH BRAINS DONE ============" << std::endl << std::endl;
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		for (int i = 0; i < n; i++)
			delete (animal_arr[i]);
		return 1;
    }
	
	try
	{
		std::cout << "============ TESTING DEEP COPY ============" << std::endl;
		Dog original;
		Brain &brain1 = original.getBrain();
		brain1.set_idea(0, "Chase the mailman!");
		std::cout << "------------" << std::endl;
		Dog copy = original; // calls deep copy constructor
		std::cout << "Original idea: " << original.getBrain().get_idea(0) << std::endl;
		std::cout << "Copy idea: " << copy.getBrain().get_idea(0) << std::endl;
		std::cout << "------------" << std::endl;
		Brain &brain2 = original.getBrain();
		brain2.set_idea(0, "Sleep on the couch.");
		std::cout << "After modifying original:" << std::endl;
		std::cout << "Original idea: " << original.getBrain().get_idea(0) << std::endl;
		std::cout << "Copy idea: " << copy.getBrain().get_idea(0) << std::endl;
		std::cout << "============ TESTING DEEP COPY DONE ============" << std::endl << std::endl;
	}
	catch (const std::bad_alloc &e)
    {
        std::cout << "Error: Allocation failed in SINGLE DOG/CAT test: " << e.what() << std::endl;
		return 1;
    }
	
	return 0;
}