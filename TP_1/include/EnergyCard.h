#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
private:
    // Type d'�nergie repr�sent�e par cette carte (par ex. "Electric", "Grass", etc.)
    std::string energyType;

public:
    // Constructeur : initialise le type d'�nergie et le nom de la carte par d�faut ("Energy")
    EnergyCard(const std::string &etype);

    // Destructeur virtuel (rien � d�truire explicitement ici, mais n�cessaire pour des objets polymorphiques)
    virtual ~EnergyCard() {}

    // Affiche les informations de la carte (type d'�nergie)
    void displayInfo() const override;

    // Retourne le type d'�nergie de la carte
    std::string getEnergyType() const { return energyType; }
};

#endif
