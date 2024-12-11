#include "Card.h"

// Le constructeur et le destructeur de base sont inclus uniquement si des opérations spécifiques sont nécessaires.
Card::Card(const std::string &name) : cardName(name) {
    // Initialisation ou message de débogage si nécessaire
    // Exemple : std::cout << "Carte créée : " << cardName << std::endl;
}

Card::~Card() {
    // Nettoyage ou message de débogage si nécessaire
    // Exemple : std::cout << "Carte supprimée : " << cardName << std::endl;
}
