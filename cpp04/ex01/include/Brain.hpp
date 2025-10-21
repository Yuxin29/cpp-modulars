/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:44:05 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/21 18:49:56 by yuwu             ###   ########.fr       */
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
    
    Brain(const Brain& other);               
    Brain& operator=(const Brain &other);
    ~Brain();

    void set_idea(int index, std::string idea);
    std::string get_idea(int index);
};
