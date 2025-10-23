/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:05:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:11:34 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

//pure vitual class can only be called bu new or state directly, it can only be inharited,
// on child process, this pure vitual member function needs to be override.
class Animal
{
protected:
	std::string _type;
	
public:
	Animal();
    Animal(const Animal& other);               
    Animal& operator=(const Animal &other);
    virtual ~Animal();  //virtual makes sure when deconstruct/delete parent, child is also deconstructed/deleted

	virtual void makeSound() const = 0;        //pure vitual, so the Animal class it pure vitual, can only be inharited, not created direcly.
	virtual std::string getType() const;    //virtual enables polmorphilism
};
