#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

    std::cout << "-------------------------------------------" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::cout << "Recherche de la valeur 30..." << std::endl;
        std::vector<int>::iterator itVec = ::easyfind(vec, 30);
        std::cout << "Succès ! Valeur trouvée : " << *itVec << std::endl;

        std::cout << "Recherche de la valeur 99 (n'existe pas)..." << std::endl;
        ::easyfind(vec, 99);
        std::cout << "ERREUR : Cette ligne ne devrait pas s'afficher." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée avec succès : " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(84);
    lst.push_back(21);
    lst.push_back(0);

    try {
        std::cout << "Recherche de la valeur 42..." << std::endl;
        std::list<int>::iterator itLst = ::easyfind(lst, 42);
        std::cout << "Succès ! Valeur trouvée : " << *itLst << std::endl;

        std::cout << "Recherche de la valeur -5 (n'existe pas)..." << std::endl;
        ::easyfind(lst, -5);
        std::cout << "ERREUR : Cette ligne ne devrait pas s'afficher." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée avec succès : " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}