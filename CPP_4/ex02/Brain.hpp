/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:18:07 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 20:18:06 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class Brain
{
private :
    std::string	ideas[100];
public :
    Brain();
    Brain(Brain &other);
    Brain &operator=(Brain &other);
    ~Brain();
    
    void			displayIdeasFirstAddress(void) const;
};