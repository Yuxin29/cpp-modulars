/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 20:39:53 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
	
public:
	Animal();
    //Animal(std::string type); No need because the tyep is by defualt;
    Animal(const Animal& other);               
    Animal& operator=(const Animal &other);
    virtual ~Animal();  //virtual makes sure when deconstruct/delete parent, child is also deconstructed/deleted

	virtual void makeSound() const;         //virtual
	virtual std::string getType() const;    //virtual enables polmorphilism
};
