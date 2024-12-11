#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
private:
    // Type d'énergie représentée par cette carte (par ex. "Electric", "Grass", etc.)
    std::string energyType;

public:
    // Constructeur : initialise le type d'énergie et le nom de la carte par défaut ("Energy")
    EnergyCard(const std::string &etype);

    // Destructeur virtuel (rien à détruire explicitement ici, mais nécessaire pour des objets polymorphiques)
    virtual ~EnergyCard() {}

    // Affiche les informations de la carte (type d'énergie)
    void displayInfo() const override;

    // Retourne le type d'énergie de la carte
    std::string getEnergyType() const { return energyType; }
};

#endif
