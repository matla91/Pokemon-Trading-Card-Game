#include "card.h"
#include "pokemonCard.h"
#include "energyCard.h"
#include "trainerCard.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Création du premier joueur
    Player player1("Hadi");

    // Ajout de cartes sur le banc du joueur 1
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard(
        "Pikachu", "Electric", "Pikachu", 2, 100, 2,
        "thunder bolt", 20, 3, "thunder storm", 30));

    // Activation et association d'énergie pour le joueur 1
    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    // Création du deuxième joueur
    Player player2("Germain");

    // Ajout de cartes sur le banc du joueur 2
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard(
        "Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2,
        "Seed", 15, 3, "Vine Whip", 25));

    // Activation et association d'énergie pour le joueur 2
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);

    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    // Joueur 1 attaque le joueur 2
    player1.attack(0, 0, player2, 0);

    cout << endl;
    player2.displayAction();

    // Joueur 2 utilise une carte dresseur
    player2.useTrainer(0);

    cout << endl;
    player2.displayAction();

    return 0;
}
