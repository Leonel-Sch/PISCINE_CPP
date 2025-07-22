/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:23:46 by lscheupl          #+#    #+#             */
/*   Updated: 2025/07/22 15:11:09 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int main()
{
    Contact first;
    first.SetName("Leonel", 0);
    first.SetName("SCHEUPLEIN", 1);
    
    std :: cout << first.getFullName() << std :: endl;
}