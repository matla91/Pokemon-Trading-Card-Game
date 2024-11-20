#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
private:
    int currentHp;
    int maxHp;
    std::vector<std::tuple<std::string, int, int>> attacks; // Nom, coût, dégâts

public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                int evolution, int maxHp, int currentHp,
                const std::string& attack1Name, int attack1Damage, int attack1Cost,
                const std::string& attack2Name, int attack2Damage, int attack2Cost)
        : Card(name), maxHp(maxHp), currentHp(currentHp) {
        attacks.push_back({attack1Name, attack1Damage, attack1Cost});
        attacks.push_back({attack2Name, attack2Damage, attack2Cost});
    }

    void heal() { currentHp = maxHp; }

    int getAttackDamage(int attackIndex) const {
        if (attackIndex >= 0 && attackIndex < attacks.size()) {
            return std::get<2>(attacks[attackIndex]); // Retourne les dégâts de l'attaque
        } else {
            throw std::out_of_range("Index d'attaque invalide.");
        }
    }


    void takeDamage(int damage) { currentHp -= damage; if (currentHp < 0) currentHp = 0; }

    void displayInfo() const override {
        std::cout << "Pokemon: " << cardName << ", HP: " << currentHp << "/" << maxHp << std::endl;
    }

    std::string getType() const override { return "PokemonCard"; }
};


#endif // POKEMONCARD_H
