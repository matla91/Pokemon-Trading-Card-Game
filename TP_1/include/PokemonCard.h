#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "Card.h"
#include <tuple>
#include <vector>
#include <string>

class PokemonCard : public Card {
private:
    // Attributs sp�cifiques � une carte Pok�mon
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;

    // Liste des attaques : chaque attaque est un tuple contenant :
    // (co�t en �nergie, �nergie actuelle, description, d�g�ts)
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    // Constructeur initialisant tous les attributs
    PokemonCard(const std::string &name,
                const std::string &type,
                const std::string &family,
                int evoLevel,
                int maxHP,
                int firstAttackCost,
                const std::string &firstAttackDesc,
                int firstAttackDamage,
                int secondAttackCost,
                const std::string &secondAttackDesc,
                int secondAttackDamage);

    virtual ~PokemonCard() {}

    // Affiche les informations de la carte
    void displayInfo() const override;

    // Affiche les attaques de la carte
    void displayAttacks() const;

    // Ajoute de l'�nergie aux attaques (sans d�passer leur co�t)
    void addEnergyToAttacks();

    // Accesseurs et mutateurs pour les points de vie
    int getHP() const;
    int getMaxHP() const;
    void setHP(int newHP);

    // Accesseurs pour les informations sp�cifiques
    const std::string &getFamilyName() const;
    int getEvolutionLevel() const;
    const std::string &getPokemonType() const;

    // V�rifie la validit� d'un index d'attaque
    bool hasAttackIndex(int idx) const;

    // R�cup�re les d�g�ts ou la description d'une attaque via son index
    int getAttackDamage(int idx) const;
    std::string getAttackDescription(int idx) const;
};

#endif
