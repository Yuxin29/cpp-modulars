/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/21 19:13:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "------------ testing construct ------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "------------ testing deconstruct ------------" << std::endl;
	delete(j);
	delete(i);
	
	std::cout << "------------ n array construct ------------" << std::endl;
	int n = 4;
	Animal *animal_arr[n];
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			animal_arr[i] = new Dog();
		else	
			animal_arr[i] = new Cat();
	}
	
	std::cout << "------------ get ideas ------------" << std::endl;
	for (int i = 0; i < n / 2; i++)
	{
		if (i < n / 2)
		{
			Dog *dog = dynamic_cast<Dog*>(animal_arr[i]);
			Brain br = dog->getBrain();
			br.get_idea(1);
		}
		// else
		// {
		// 	Cat *cat = dynamic_cast<Cat*>(animal_arr[i]);
		// 	Brain br = cat->getBrain();
		// 	br.get_idea(1);
		// }	
	}

	// std::cout << "------------ set ideas ------------" << std::endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	if (i < n / 2)
	// 		animal_arr[i]->_brain.set_idea(1, "I love human\n");

	// 	else	
	// 		animal_arr[i]->_brain.set_idea(1, "I hate human\n");
	// }

	// std::cout << "------------ get ideas ------------" << std::endl;
	// for (int i = 0; i < n; i++)
	// 	animal_arr[i]->_brain->get_idea(1);
		
	std::cout << "------------ n array deconstruct ------------" << std::endl;
	for (int i = 0; i < n; i++)
		delete (animal_arr[i]);
	
	return 0;
}

