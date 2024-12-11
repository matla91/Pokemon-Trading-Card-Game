#include "PokemonCard.h"
#include <iostream>

// Constructeur : Initialise les attributs et configure les attaques
PokemonCard::PokemonCard(const std::string &name,
                         const std::string &type,
                         const std::string &family,
                         int evoLevel,
                         int maxHPVal,
                         int firstAttackCost,
                         const std::string &firstAttackDesc,
                         int firstAttackDamage,
                         int secondAttackCost,
                         const std::string &secondAttackDesc,
                         int secondAttackDamage)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evoLevel), maxHP(maxHPVal), hp(maxHPVal)
{
    // Ajoute les deux attaques avec une énergie initiale à 0
    attacks.push_back(std::make_tuple(firstAttackCost, 0, firstAttackDesc, firstAttackDamage));
    attacks.push_back(std::make_tuple(secondAttackCost, 0, secondAttackDesc, secondAttackDamage));
}

// Affiche les informations principales de la carte Pokémon
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name : " << cardName
              << " , Type : " << pokemonType
              << " , Evolution Level : " << evolutionLevel
              << " of the family \"" << familyName
              << " , HP : " << hp << "\"" << std::endl;
    std::cout << "Attacks :" << std::endl;
    displayAttacks();
}

// Affiche les détails des attaques
void PokemonCard::displayAttacks() const {
    for (size_t i = 0; i < attacks.size(); i++) {
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost : " << std::get<0>(attacks[i]) << std::endl;
        std::cout << "Attack current energy storage : " << std::get<1>(attacks[i]) << std::endl;
        std::cout << "Attack description : " << std::get<2>(attacks[i]) << std::endl;
        std::cout << "Attack damage : " << std::get<3>(attacks[i]) << std::endl;
    }
}

// Ajoute de l'énergie aux attaques sans dépasser leur coût
void PokemonCard::addEnergyToAttacks() {
    for (auto &atk : attacks) {
        int cost = std::get<0>(atk);
        int curr = std::get<1>(atk);
        if (curr < cost) {
            std::get<1>(atk) = curr + 1;
        }
    }
}

// Retourne les points de vie actuels
int PokemonCard::getHP() const { return hp; }

// Retourne les points de vie maximum
int PokemonCard::getMaxHP() const { return maxHP; }

// Définit les points de vie actuels, en s'assurant qu'ils ne dépassent pas le maximum
void PokemonCard::setHP(int newHP) {
    hp = newHP;
    if (hp > maxHP) hp = maxHP;
}

// Retourne le nom de la famille du Pokémon
const std::string &PokemonCard::getFamilyName() const { return familyName; }

// Retourne le niveau d'évolution
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }

// Retourne le type du Pokémon
const std::string &PokemonCard::getPokemonType() const { return pokemonType; }

// Vérifie si un index d'attaque est valide
bool PokemonCard::hasAttackIndex(int idx) const {
    return (idx >= 0 && idx < (int)attacks.size());
}

// Retourne les dégâts de l'attaque spécifiée par son index
int PokemonCard::getAttackDamage(int idx) const {
    if (!hasAttackIndex(idx)) return 0;
    return std::get<3>(attacks[idx]);
}

// Retourne la description de l'attaque spécifiée par son index
std::string PokemonCard::getAttackDescription(int idx) const {
    if (!hasAttackIndex(idx)) return "";
    return std::get<2>(attacks[idx]);
}
