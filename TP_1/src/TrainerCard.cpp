#include "TrainerCard.h"
#include <iostream>

// Constructeur : Initialise le nom de la carte et l'effet du trainer
TrainerCard::TrainerCard(const std::string &name, const std::string &effect)
    : Card(name), trainerEffect(effect) {}

// Affiche les informations de la carte : nom et effet
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name : " << getName()
              << " , Effect : " << trainerEffect << std::endl;
}
