#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // 1. Création de notre structure de test (sur la stack)
    Data myData;
    myData.id = 42;
    myData.name = "Marvin le Paranoid Android";
    myData.value = 42.42f;

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Adresse originale : " << &myData << std::endl;
    std::cout << "ID    : " << myData.id << std::endl;
    std::cout << "Name  : " << myData.name << std::endl;
    std::cout << "Value : " << myData.value << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;

    uintptr_t rawValue = Serializer::serialize(&myData);
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Valeur brute (en décimal) : " << rawValue << std::endl;
    std::cout << "Valeur brute (en hexa)    : 0x" << std::hex << rawValue << std::dec << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;

    Data* deserializedPtr = Serializer::deserialize(rawValue);
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Nouvelle adresse pointée  : " << deserializedPtr << std::endl;
    std::cout << "ID    : " << deserializedPtr->id << std::endl;
    std::cout << "Name  : " << deserializedPtr->name << std::endl;
    std::cout << "Value : " << deserializedPtr->value << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    if (deserializedPtr == &myData) {
        std::cout << "IDENDITIQUE" << std::endl;
    } else {
        std::cout << "DIFFERENT" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}