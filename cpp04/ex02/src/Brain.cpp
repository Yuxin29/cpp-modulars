/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:45:51 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:30:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain begin constructed." << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";    
}

Brain::Brain(const Brain& other)
{
    //do I need to check identical case here ???
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = other._ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other)
{
    //do I need to check identical case here ???
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = other._ideas[i];
    }
    return *this;
}
    
Brain::~Brain()
{
    std::cout << "Brain begin deconstructed." << std::endl;
}

void Brain::set_idea(int index, std::string idea)
{
    if (index < 100 && index >= 0)
        _ideas[index] = idea;
    return ;
}

std::string Brain::get_idea(int index) const
{
    if (index < 100 && index >= 0)
        return (_ideas[index]);
    return "";
}