#include "Player.h"
#include <iostream>
#include <algorithm>

// Destructeur : libère la mémoire allouée pour les cartes du banc et les cartes en action
Player::~Player() {
    for (auto c : benchCards) {
        delete c;
    }
    benchCards.clear();

    for (auto p : actionCards) {
        delete p;
    }
    actionCards.clear();
}

// Ajoute une carte au banc du joueur
void Player::addCardToBench(Card* c) {
    benchCards.push_back(c);
}

// Affiche les cartes présentes sur le banc
void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << " :" << std::endl;
    for (auto c : benchCards) {
        // On affiche uniquement les cartes de type Trainer
        TrainerCard* tc = dynamic_cast<TrainerCard*>(c);
        if (tc) {
            tc->displayInfo();
        }
    }
}

// Affiche les cartes Pokémon en action
void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << " :" << std::endl;
    for (auto p : actionCards) {
        p->displayInfo();
    }
}

// Active une carte Pokémon du banc et la place en action
void Player::activatePokemonCard(int benchIndex) {
    Card* c = benchCards[benchIndex];
    PokemonCard* pc = dynamic_cast<PokemonCard*>(c);
    if (pc) {
        std::cout << playerName << " is activating a Pokemon Card : " << pc->getName() << std::endl;
        actionCards.push_back(pc);
        benchCards.erase(benchCards.begin() + benchIndex);
    } else {
        std::cout << "Not a PokemonCard at this index" << std::endl;
    }
}

// Attache une carte Énergie du banc à un Pokémon en action
void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    Card* c = benchCards[benchIndex];
    EnergyCard* ec = dynamic_cast<EnergyCard*>(c);
    if (!ec) {
        std::cout << "Only energy card can be attached." << std::endl;
        return;
    }

    if (actionIndex < 0 || actionIndex >= (int)actionCards.size()) {
        std::cout << "Invalid action index for attaching energy." << std::endl;
        return;
    }

    PokemonCard* pc = actionCards[actionIndex];
    std::cout << playerName << " is attaching Energy Card of type "
              << ec->getEnergyType() << " to the Pokemon " << pc->getName() << std::endl;

    pc->addEnergyToAttacks();
    benchCards.erase(benchCards.begin() + benchIndex);
    delete ec;
}

// Effectue une attaque d’un Pokémon en action contre un Pokémon cible d’un autre joueur
void Player::attack(int attackerIndex, int attackIndex, Player &other, int targetIndex) {
    if (attackerIndex < 0 || attackerIndex >= (int)actionCards.size()) {
        std::cout << "Invalid attacker index." << std::endl;
        return;
    }

    PokemonCard* attacker = actionCards[attackerIndex];
    if (!attacker->hasAttackIndex(attackIndex)) {
        std::cout << "Only 2 attacks exist." << std::endl;
        return;
    }

    if (targetIndex < 0 || targetIndex >= (int)other.actionCards.size()) {
        std::cout << "Invalid target index." << std::endl;
        return;
    }

    PokemonCard* target = other.actionCards[targetIndex];
    std::cout << playerName << " attacking " << other.getName()
              << "'s Pokemon " << target->getName() << " with the Pokemon "
              << attacker->getName() << " with its attack : "
              << attacker->getAttackDescription(attackIndex) << std::endl;

    int damage = attacker->getAttackDamage(attackIndex);
    std::cout << "Reducing " << damage << " from " << other.getName() << "'s Pokemon's HP" << std::endl;

    target->setHP(target->getHP() - damage);

    if (target->getHP() <= 0) {
        std::cout << "Pokemon " << target->getName() << " has fainted" << std::endl;
    } else {
        std::cout << "Pokemon " << target->getName() << " is still alive" << std::endl;
    }
}

// Utilise une carte Trainer du banc (effet : soin des Pokémon en action)
void Player::useTrainer(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= (int)benchCards.size()) {
        std::cout << "Invalid trainer index." << std::endl;
        return;
    }

    TrainerCard* tc = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
    if (!tc) {
        std::cout << "No trainer card at this index." << std::endl;
        return;
    }

    std::cout << playerName << " is using the Trainer Card to \"" << tc->getEffect() << "\"" << std::endl;

    for (auto p : actionCards) {
        p->setHP(p->getMaxHP());
    }
}
