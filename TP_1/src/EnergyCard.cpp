#include "EnergyCard.h"
#include <iostream>

// Constructeur : Initialise le type d'énergie et fixe le nom de la carte à "Energy"
EnergyCard::EnergyCard(const std::string &etype)
    : Card("Energy"), energyType(etype) {}

// Affiche les informations de la carte : affiche le type d'énergie
void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type : " << energyType << std::endl;
}
