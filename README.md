# Pokémon Trading Card Game - C++ Simulation

Welcome to the **Pokémon Trading Card Game (TCG) Simulation**! 🃏✨  
This project brings the excitement of Pokémon battles to **C++**, allowing players to build decks, activate Pokémon, attach energy cards, and battle each other just like in the real TCG.

🔗 **Official Pokémon TCG reference**: [tcg.pokemon.com](https://tcg.pokemon.com/en-us/)

---

## 🚀 Features

✅ **Card System** – Base class `Card` with specialized Pokémon, Energy, and Trainer cards.  
✅ **Pokémon Mechanics** – Includes Pokémon types, evolutions, HP, and attacks.  
✅ **Energy System** – Attach energy to power Pokémon attacks.  
✅ **Trainer Cards** – Play trainers to apply special effects (like healing).  
✅ **Battle System** – Attack opponent’s Pokémon, reduce HP, and strategize!  
✅ **Healing Mechanism** – Trainer cards can restore a Pokémon’s health.

---

## 🎮 How It Works  

Players build their decks using **Pokémon, Energy, and Trainer Cards**.  
Pokémon Cards have unique **attacks, HP, and energy costs**. Energy Cards are required to use attacks.  
Trainer Cards provide strategic effects, like **healing Pokémon**. Players **activate Pokémon, attach energy, and battle** each other.  
The game displays each player's **bench, active Pokémon, and battle results**.

---

## 🛠 Implementation

### 🃏 Base Class: `Card`
Defines the core structure for all cards:
- `cardName` (string): Card name.
- `displayInfo()`: Virtual function to display card details.

### ⚡ Pokémon Cards: `PokemonCard`
Inherits from `Card`, with additional attributes:
- `pokemonType` (Electric, Grass, Fire, etc.)
- `familyName` (e.g., "Pikachu")
- `evolutionLevel`
- `maxHP` & `hp`
- **Attacks** – A vector of **two attacks**, each with:
  - **Energy Cost**
  - **Stored Energy**
  - **Attack Name**
  - **Damage Output**

---

## 🖥️ Example Code

```cpp
Player player1("Hadi");
player1.addCardToBench(new EnergyCard("Electric"));
player1.addCardToBench(new TrainerCard("Ash", "heal all your action Pokémon"));
player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "Thunderbolt", 20, 3, "Thunderstorm", 30));

player1.activatePokemonCard(2);
player1.attachEnergyCard(0, 0);
player1.attachEnergyCard(0, 0);
