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

    // Cartes en r�serve (sur le banc)
    std::vector<Card*> benchCards;

    // Cartes Pok�mon actuellement en action
    std::vector<PokemonCard*> actionCards;

public:
    // Constructeur : initialise le nom du joueur
    Player(const std::string &name) : playerName(name) {}

    // Destructeur : nettoie la m�moire allou�e dynamiquement pour les cartes
    ~Player();

    // Ajoute une carte au banc du joueur
    void addCardToBench(Card* c);

    // Affiche les cartes pr�sentes sur le banc
    void displayBench() const;

    // Affiche les cartes Pok�mon en action
    void displayAction() const;

    // Active une carte Pok�mon depuis le banc et la place en action
    void activatePokemonCard(int benchIndex);

    // Attache une carte �nergie depuis le banc � un Pok�mon en action
    void attachEnergyCard(int benchIndex, int actionIndex);

    // Effectue une attaque avec un Pok�mon en action contre un Pok�mon d�un autre joueur
    void attack(int attackerIndex, int attackIndex, Player &other, int targetIndex);

    // Utilise une carte d�entra�neur (Trainer) depuis le banc
    void useTrainer(int benchIndex);

    // Retourne le nom du joueur
    const std::string &getName() const { return playerName; }
};

#endif
