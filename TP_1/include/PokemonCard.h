#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "Card.h"
#include <tuple>
#include <vector>
#include <string>

class PokemonCard : public Card {
private:
    // Attributs spécifiques à une carte Pokémon
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;

    // Liste des attaques : chaque attaque est un tuple contenant :
    // (coût en énergie, énergie actuelle, description, dégâts)
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

    // Ajoute de l'énergie aux attaques (sans dépasser leur coût)
    void addEnergyToAttacks();

    // Accesseurs et mutateurs pour les points de vie
    int getHP() const;
    int getMaxHP() const;
    void setHP(int newHP);

    // Accesseurs pour les informations spécifiques
    const std::string &getFamilyName() const;
    int getEvolutionLevel() const;
    const std::string &getPokemonType() const;

    // Vérifie la validité d'un index d'attaque
    bool hasAttackIndex(int idx) const;

    // Récupère les dégâts ou la description d'une attaque via son index
    int getAttackDamage(int idx) const;
    std::string getAttackDescription(int idx) const;
};

#endif
