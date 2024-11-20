#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
public:
    EnergyCard(const std::string& energyType)
        : Card("Energy"), energyType(energyType) {}

    virtual ~EnergyCard() = default;

    void displayInfo() const override {
        std::cout << "Nom de la carte : " << cardName << std::endl;
        std::cout << "Type d'énergie : " << energyType << std::endl;
    }

    std::string getType() const override { return "EnergyCard"; }

private:
    std::string energyType;
};

#endif // ENERGYCARD_H
