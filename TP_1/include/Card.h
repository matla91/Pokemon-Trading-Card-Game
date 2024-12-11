#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
protected:
    // Nom de la carte
    std::string cardName;

public:
    // Constructeur initialisant le nom de la carte
    Card(const std::string &name) : cardName(name) {}

    // Destructeur virtuel pour permettre une destruction correcte des objets d�riv�s
    virtual ~Card() {}

    // M�thode virtuelle pure � impl�menter dans les classes d�riv�es
    virtual void displayInfo() const = 0;

    // Accesseur pour r�cup�rer le nom de la carte
    std::string getName() const { return cardName; }
};

#endif
