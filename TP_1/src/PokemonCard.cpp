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
    // Ajoute les deux attaques avec une �nergie initiale � 0
    attacks.push_back(std::make_tuple(firstAttackCost, 0, firstAttackDesc, firstAttackDamage));
    attacks.push_back(std::make_tuple(secondAttackCost, 0, secondAttackDesc, secondAttackDamage));
}

// Affiche les informations principales de la carte Pok�mon
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name : " << cardName
              << " , Type : " << pokemonType
              << " , Evolution Level : " << evolutionLevel
              << " of the family \"" << familyName
              << " , HP : " << hp << "\"" << std::endl;
    std::cout << "Attacks :" << std::endl;
    displayAttacks();
}

// Affiche les d�tails des attaques
void PokemonCard::displayAttacks() const {
    for (size_t i = 0; i < attacks.size(); i++) {
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost : " << std::get<0>(attacks[i]) << std::endl;
        std::cout << "Attack current energy storage : " << std::get<1>(attacks[i]) << std::endl;
        std::cout << "Attack description : " << std::get<2>(attacks[i]) << std::endl;
        std::cout << "Attack damage : " << std::get<3>(attacks[i]) << std::endl;
    }
}

// Ajoute de l'�nergie aux attaques sans d�passer leur co�t
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

// D�finit les points de vie actuels, en s'assurant qu'ils ne d�passent pas le maximum
void PokemonCard::setHP(int newHP) {
    hp = newHP;
    if (hp > maxHP) hp = maxHP;
}

// Retourne le nom de la famille du Pok�mon
const std::string &PokemonCard::getFamilyName() const { return familyName; }

// Retourne le niveau d'�volution
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }

// Retourne le type du Pok�mon
const std::string &PokemonCard::getPokemonType() const { return pokemonType; }

// V�rifie si un index d'attaque est valide
bool PokemonCard::hasAttackIndex(int idx) const {
    return (idx >= 0 && idx < (int)attacks.size());
}

// Retourne les d�g�ts de l'attaque sp�cifi�e par son index
int PokemonCard::getAttackDamage(int idx) const {
    if (!hasAttackIndex(idx)) return 0;
    return std::get<3>(attacks[idx]);
}

// Retourne la description de l'attaque sp�cifi�e par son index
std::string PokemonCard::getAttackDescription(int idx) const {
    if (!hasAttackIndex(idx)) return "";
    return std::get<2>(attacks[idx]);
}
