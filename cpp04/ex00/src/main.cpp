/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 12:01:08 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
	
int main()
{
	std::cout << "------------ testing copy & copy assign on dog ------------" << std::endl;
	Dog a;
	std::cout << "------------" << std::endl;
	Dog b = a;   
	std::cout << "------------" << std::endl;           
	Dog c;
	std::cout << "------------" << std::endl;  
	c = Dog();
	
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
	i->makeSound();
	j->makeSound();
	
	std::cout << "------------ testing make wrong sound ------------" << std::endl;
	wrong_meta->makeSound();
	k->makeSound(); // will output WrongAnimal sound due to missing virtual
	
	std::cout << "------------ Manually delete ------------" << std::endl;
	delete(meta);
	delete(wrong_meta);
	delete(j);
	delete(i);
	delete(k);
	return 0;
}
