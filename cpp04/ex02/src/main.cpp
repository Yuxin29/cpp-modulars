/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 14:28:10 by yuwu             ###   ########.fr       */
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
		std::cout << "------------ Testing Abstract Animal ------------" << std::endl;
		//Animal a = Animal(); 

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
