/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:55:32 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/09 22:13:30 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <string>
#include <iomanip>
#include <sstream>

class Zombie
{
    private:
    std :: string name;
    public :
    void announce(void);
    Zombie(std :: string name);
    Zombie(void);
    ~Zombie();
    void setname(std :: string name);
};

Zombie* zombieHorde( int N, std::string name );