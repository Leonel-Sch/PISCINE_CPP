/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:43:57 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/11 23:58:31 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl :: debug()
{
    std :: cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std :: flush;
}
void Harl :: info()
{
    std :: cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std :: flush;
}

void Harl :: warning()
{
    std :: cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std :: flush;
}

void Harl :: error()
{
    std :: cout << "This is unacceptable! I want to speak to the manager now.\n" << std :: flush;
}

void Harl :: complain(std::string level) 
{
    void (Harl :: *functions[])(void) = 
    {
        &Harl :: debug,
        &Harl :: info,
        &Harl :: warning,
        &Harl :: error
    };
    std :: string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) 
    {
        if (levels[i] == level) 
        {
            (this->*functions[i])();
            break;
        }
    }
}