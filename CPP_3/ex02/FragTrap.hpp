/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:25:49 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 20:31:49 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Claptrap.hpp"
#include <string>
#include <iomanip>
#include <iostream>

class FragTrap : public ClapTrap
{
public :
    FragTrap();
    FragTrap(std :: string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    
    void attack(const std :: string &target);
    void highFivesGuys(void);
};

