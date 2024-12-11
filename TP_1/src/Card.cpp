#include "Card.h"

// Le constructeur et le destructeur de base sont inclus uniquement si des op�rations sp�cifiques sont n�cessaires.
Card::Card(const std::string &name) : cardName(name) {
    // Initialisation ou message de d�bogage si n�cessaire
    // Exemple : std::cout << "Carte cr��e : " << cardName << std::endl;
}

Card::~Card() {
    // Nettoyage ou message de d�bogage si n�cessaire
    // Exemple : std::cout << "Carte supprim�e : " << cardName << std::endl;
}
