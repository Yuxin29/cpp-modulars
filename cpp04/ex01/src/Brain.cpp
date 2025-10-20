/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:45:51 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 21:07:09 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain begin constructed." << std::endl;
}

Brain::Brain(const Brain& other)
{
    this->_ideas = other->_ideas;
}

Brain& Brain::operator=(const Brain &other)
{
    this->_ideas = other->_ideas;
    return *this;
}
    
Brain::~Brain()
{
    std::cout << "Brain begin deconstructed." << std::endl;
}