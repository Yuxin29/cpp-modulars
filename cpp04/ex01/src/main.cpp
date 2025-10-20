/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:49 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 20:57:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "------------ testing single ------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete(j);
	delete(i);
	
	return 0;
}

