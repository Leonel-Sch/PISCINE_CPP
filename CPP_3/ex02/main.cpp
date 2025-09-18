/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:12:20 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 20:37:39 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== ex02: ClapTrap / ScavTrap / FragTrap ===\n";

    std::cout << "\n--- Constructeurs ---\n";
    ClapTrap ct("CL4P-TP");
    ScavTrap st("SC4V-TP");
    FragTrap ft("FR4G-TP");

    std::cout << "\n--- Actions de base (ClapTrap) ---\n";
    ct.attack("Skag");
    ct.beRepaired(3);
    ct.takeDamage(5);
    ct.attack("Bandit");

    std::cout << "\n--- ScavTrap specifics + polymorphisme ---\n";
    st.guardGate();
    st.attack("Psycho");
    st.takeDamage(30);
    st.beRepaired(10);
    ClapTrap& baseRefToScav = st;         // polymorphisme par référence
    baseRefToScav.attack("Marauder");     // appelle ScavTrap::attack via virtual

    std::cout << "\n--- FragTrap specifics ---\n";
    ft.attack("Bruiser");
    ft.highFivesGuys();                    // ASCII high-five
    ft.takeDamage(40);
    ft.beRepaired(20);

    std::cout << "\n--- Vider l'energie de ScavTrap ---\n";
    for (int i = 0; i < 55; ++i) {
        baseRefToScav.attack("Dummy");    // ScavTrap commence à 50 EP
    }

    std::cout << "\n--- Tuer FragTrap et retester ---\n";
    ft.takeDamage(200);                    // mort
    ft.attack("Afterlife");                // doit refuser (0 HP)
    ft.highFivesGuys();                    // message avec check HP

    std::cout << "\n--- Destruction via Base* (vérifie destructeur virtuel) ---\n";
    ClapTrap* poly1 = new ScavTrap("Poly-Scav");
    ClapTrap* poly2 = new FragTrap("Poly-Frag");
    poly1->attack("Target-1");
    poly2->attack("Target-2");
    delete poly1;                          // ~ScavTrap puis ~ClapTrap
    delete poly2;                          // ~FragTrap puis ~ClapTrap

    std::cout << "\n=== Fin des tests ===\n";
    return 0;
}