/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:12:20 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 19:45:02 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Constructors ===\n";
    ClapTrap ct("CL4P-TP");
    ScavTrap st("SC4V-TP");
    ClapTrap copy(ct);
    ClapTrap assigned; assigned = ct;

    std::cout << "\n=== Virtual attack (polymorphism) ===\n";
    ct.attack("Skag");                // ClapTrap::attack
    ClapTrap& baseRef = st;
    baseRef.attack("Bandit");         // calls ScavTrap::attack via virtual dispatch

    std::cout << "\n=== Basic durability and repair on ScavTrap ===\n";
    st.takeDamage(30);
    st.beRepaired(10);
    st.attack("Psycho");              // accessible via base ref if needed

    std::cout << "\n=== Drain ScavTrap energy with attacks ===\n";
    for (int i = 0; i < 55; ++i) {
        baseRef.attack("Dummy");      // consumes energy (ScavTrap starts with 50 EP)
    }

    std::cout << "\n=== Lethal damage and attempts afterward ===\n";
    st.takeDamage(200);               // kill it
    baseRef.attack("Afterlife");      // should refuse due to 0 HP
    st.beRepaired(5);                 // should refuse due to 0 HP

    std::cout << "\n=== Delete via Base* (checks virtual destructor) ===\n";
    ClapTrap* poly = new ScavTrap("Poly");
    poly->attack("Target");
    delete poly;                      // must call ~ScavTrap then ~ClapTrap

    std::cout << "\n=== End of test ===\n";
    return 0;
}