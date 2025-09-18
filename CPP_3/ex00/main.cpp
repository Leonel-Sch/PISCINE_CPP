/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:12:20 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 18:36:49 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main() {
    std::cout << "=== Constructors ===\n";
    ClapTrap a;                 // default
    ClapTrap b("Bender");       // named
    ClapTrap c(b);              // copy
    ClapTrap d; d = b;          // assignment

    std::cout << "\n=== Basic actions ===\n";
    b.attack("Target-1");
    b.beRepaired(3);
    b.takeDamage(4);
    b.attack("Target-2");

    std::cout << "\n=== Drain energy ===\n";
    for (int i = 0; i < 12; ++i) {
        b.attack("EnergyDummy");
    }

    std::cout << "\n=== Take fatal damage and try to act ===\n";
    a.takeDamage(15);      // should die
    a.attack("Nobody");    // should refuse (dead)
    a.beRepaired(5);       // should refuse if energy check happens after death

    std::cout << "\n=== Exact lethal and small repairs ===\n";
    c.takeDamage(10);      // exactly current HP
    c.attack("Afterlife"); // should refuse (dead)
    c.beRepaired(2);       // consumes energy, message prints

    std::cout << "\n=== End of test ===\n";
    return 0;
}