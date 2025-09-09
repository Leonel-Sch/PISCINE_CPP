/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:58:11 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/09 20:17:18 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie :: announce()
{
    std :: cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie :: Zombie(std :: string name) : name(name) {}

Zombie :: ~Zombie()
{
    std :: cout << name << " has been deleted\n";
}