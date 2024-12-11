#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"

class Player {
private:
    // Nom du joueur
    std::string playerName;

    // Cartes en réserve (sur le banc)
    std::vector<Card*> benchCards;

    // Cartes Pokémon actuellement en action
    std::vector<PokemonCard*> actionCards;

public:
    // Constructeur : initialise le nom du joueur
    Player(const std::string &name) : playerName(name) {}

    // Destructeur : nettoie la mémoire allouée dynamiquement pour les cartes
    ~Player();

    // Ajoute une carte au banc du joueur
    void addCardToBench(Card* c);

    // Affiche les cartes présentes sur le banc
    void displayBench() const;

    // Affiche les cartes Pokémon en action
    void displayAction() const;

    // Active une carte Pokémon depuis le banc et la place en action
    void activatePokemonCard(int benchIndex);

    // Attache une carte Énergie depuis le banc à un Pokémon en action
    void attachEnergyCard(int benchIndex, int actionIndex);

    // Effectue une attaque avec un Pokémon en action contre un Pokémon d’un autre joueur
    void attack(int attackerIndex, int attackIndex, Player &other, int targetIndex);

    // Utilise une carte d’entraîneur (Trainer) depuis le banc
    void useTrainer(int benchIndex);

    // Retourne le nom du joueur
    const std::string &getName() const { return playerName; }
};

#endif
