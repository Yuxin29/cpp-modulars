/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:08:53 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 20:51:02 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat
    : public Animal
{
private:
	std::string type;
    
public:
	Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat &other);
    ~Cat(); 

    void makeSound() const;
	std::string getType() const;
};

