#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
public:
    Card(const std::string& cardName) : cardName(cardName) {}
    virtual ~Card() = default;

    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;

protected:
    std::string cardName;
};

#endif // CARD_H
