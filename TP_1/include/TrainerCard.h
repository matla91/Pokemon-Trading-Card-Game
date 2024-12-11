#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "Card.h"
#include <string>

class TrainerCard : public Card {
private:
    // Effet spécifique de la carte (ex. "heal all your action pokemon")
    std::string trainerEffect;

public:
    // Constructeur : initialise le nom du trainer et l'effet de la carte
    TrainerCard(const std::string &name, const std::string &effect);

    // Destructeur virtuel pour une destruction correcte dans un contexte polymorphique
    virtual ~TrainerCard() {}

    // Affiche les informations de la carte (nom et effet)
    void displayInfo() const override;

    // Retourne l'effet de la carte
    std::string getEffect() const { return trainerEffect; }
};

#endif
