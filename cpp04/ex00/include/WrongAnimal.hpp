/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:25:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 11:51:26 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
    WrongAnimal(const WrongAnimal& other);               
    WrongAnimal& operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();  //still virtual, for mem safety

	void makeSound() const;         //not virtual, so polymorphism won't apply
	std::string getType() const;   
};
