#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include "PokemonCard.h"
#include <string>
#include <vector>

class TrainerCard : public Card {
public:
    TrainerCard(const std::string& cardName, const std::string& trainerEffect)
        : Card(cardName), trainerEffect(trainerEffect) {}

    virtual ~TrainerCard() = default;

    void displayInfo() const override {
        std::cout << "Nom du dresseur : " << cardName << std::endl;
        std::cout << "Effet : " << trainerEffect << std::endl;
    }

    void applyEffect(std::vector<PokemonCard*>& activePokemon) {
        if (trainerEffect == "heal all your action pokemon") {
            for (auto& pokemon : activePokemon) {
                pokemon->heal();
            }
            std::cout << "Tous les Pokémon en action ont été soignés au maximum !" << std::endl;
        }
    }

    std::string getType() const override { return "TrainerCard"; }

private:
    std::string trainerEffect;
};

#endif // TRAINERCARD_H
