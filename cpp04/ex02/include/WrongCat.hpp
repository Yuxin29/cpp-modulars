/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:29:19 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:55:59 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat
    : public WrongAnimal
{   
public:
	WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat &other);
    ~WrongCat(); 

    void makeSound() const;
};
