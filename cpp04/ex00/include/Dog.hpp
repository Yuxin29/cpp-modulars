/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:08:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:21:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog
    : public Animal
{
public:
	Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog &other);
    ~Dog(); 

    void makeSound() const override;
};
