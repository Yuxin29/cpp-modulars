/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:51:31 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "------------ testing parent ------------" << std::endl;
	const Animal* meta = new Animal();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	
	std::cout << "------------ testing child ------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << "------------ testing getter ------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	
	std::cout << "------------ testing make sound ------------" << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	
	std::cout << "------------ testing make wrong sound ------------" << std::endl;
	wrong_meta->makeSound();
	k->makeSound();

	std::cout << "------------ Manually delete ------------" << std::endl;
	delete(meta);
	delete(wrong_meta);
	delete(j);
	delete(i);
	delete(k);
	return 0;
}

