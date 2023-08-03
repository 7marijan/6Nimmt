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
    std::vector<GameCard> startCards;
    void printField();
    void placeCard(std::vector<GameCard> cards, int row, int column, int num);
    int getRightRow(int value);
    int getRightColumn(int value, int row);
    int costOfRow(int row);
    void initField(std::vector<GameCard> startCards);

private:
    std::vector<GameCard> mField[4];
    int clearRow(int row);
};
