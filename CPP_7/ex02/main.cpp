#include "Array.hpp"

int main() {
    std::cout << "-------------------------------------------" << std::endl;
    Array<int> emptyArray;
    std::cout << "Taille de emptyArray : " << emptyArray.size() << " (attendu: 0)" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    Array<int> intArray(5);
    std::cout << "Taille de intArray : " << intArray.size() << " (attendu: 5)" << std::endl;
    
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    Array<int> copyArray(intArray);
    
    intArray[0] = 4242; 
    
    std::cout << "Original intArray[0] : " << intArray[0] << " (attendu: 4242)" << std::endl;
    std::cout << "Copie copyArray[0]   : " << copyArray[0] << " (attendu: 0 -> PREUVE DE LA DEEP COPY)" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    Array<int> assignedArray;
    assignedArray = copyArray;
    
    copyArray[1] = 999;
    std::cout << "Source copyArray[1]  : " << copyArray[1] << " (attendu: 999)" << std::endl;
    std::cout << "Dest assignedArray[1]: " << assignedArray[1] << " (attendu: 10 -> PREUVE DE LA DEEP COPY)" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    try {
        std::cout << "Tentative d'accès à intArray[10]..." << std::endl;
        std::cout << intArray[10] << std::endl;
        std::cout << "ERREUR : Cette ligne ne devrait pas s'afficher !" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée avec succès : " << e.what() << std::endl;
    }

    try {
        std::cout << "Tentative d'accès à intArray[-1]..." << std::endl;
        std::cout << intArray[-1] << std::endl; // -1 va underflow et devenir un énorme entier non signé
        std::cout << "ERREUR : Cette ligne ne devrait pas s'afficher !" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée avec succès : " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Bonjour";
    strArray[1] = "le";
    strArray[2] = "monde";
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    
    return 0;
}