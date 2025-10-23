/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:08:53 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:28:07 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat
    : public Animal
{
private:
    Brain*      _brain;
	
public:
	Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat &other);
    ~Cat(); 

    void makeSound() const override;

    Brain &getBrain();
};
