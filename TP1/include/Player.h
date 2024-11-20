#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include <vector>
#include <string>

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    Player(const std::string& name) : playerName(name) {}

    ~Player() {
        for (auto card : benchCards) delete card;
        for (auto card : actionCards) delete card;
    }

    void addCardToBench(Card* card) {
        benchCards.push_back(card);
    }

    void activatePokemonCard(int index) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
        }
    }

    void attachEnergyCard(int benchIndex, int actionIndex) {
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energy) {
            // Attache l'énergie
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }

    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
        auto* attacker = actionCards[attackerIndex];
        auto* target = opponent.actionCards[targetIndex];
        target->takeDamage(attacker->getAttackDamage(attackIndex));
    }

    void useTrainer(int index) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainer) {
            trainer->applyEffect(actionCards);
            benchCards.erase(benchCards.begin() + index);
        }
    }

    void displayBench() const {
        std::cout << "Bench for " << playerName << ":" << std::endl;
        for (const auto& card : benchCards) {
            card->displayInfo();
        }
    }

    void displayAction() const {
        std::cout << "Active Pokemon for " << playerName << ":" << std::endl;
        for (const auto& card : actionCards) {
            card->displayInfo();
        }
    }
};

#endif // PLAYER_H
