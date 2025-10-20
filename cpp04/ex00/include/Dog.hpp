/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:08:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 20:13:19 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog
    : public Animal
{
protected:
	std::string type;
	
public:
	Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog &other);
    ~Dog(); 

    void makeSound() const;
	std::string getType() const;
};
