/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:29:09 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 20:17:27 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain :: Brain()
{
    for (int i = 0;i < 100;i++)
    {
        ideas[i] = "ideas";
    }
    std :: cout << "Brain default constructor full of ideas\n";
}

Brain :: Brain(Brain &other)
{
    for (int i = 0;i < 100;i++)
    {
        ideas[i] = other.ideas[i];
    }
    std :: cout << "Brain Copy constructor full of ideas\n";
}

Brain &Brain :: operator=(Brain &other)
{
    if (this != &other)
    {
        for (int i = 0;i < 100;i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    std :: cout << "Brain Assignement Copy full of ideas\n";
    return (*this);
}

Brain :: ~Brain()
{
    std :: cout << "Brain Destructor\n";
}

void	Brain::displayIdeasFirstAddress(void) const {
	std::cout << &ideas[0] << std::endl;
}