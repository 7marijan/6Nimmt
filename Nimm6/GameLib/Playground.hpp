//
//  Playground.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include <vector>
#include "GameCard.h"

class Playground
{
public:
    Playground();
    ~Playground();
    void printField();
    void placeCard(std::vector<GameCard> cards, int row, int column, int num);
    int getRightRow(const int value) const;
    int getRightColumn(const int row);
    int costOfRow(int row);
    void initField(const std::vector<GameCard> startCards);
    void clearRow(int row);
    int lowestCardOnField(int forbiddenCard) const;

private:
    std::vector<GameCard> mField[4];
    
};
