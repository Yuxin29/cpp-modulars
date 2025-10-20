/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:44:05 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 21:06:04 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
    //Animal(std::string type); No need because the tyep is by defualt;
    Brain(const Brain& other);               
    Brain& operator=(const Brain &other);
    ~Brain();
};
