//
//  Player.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "GameCard.h"
#include "Playground.hpp"
#include <vector>

class Player
{
public:
    Player();
    ~Player();
    std::vector<GameCard> mCards;
    void addCost(int cost);
    virtual int findCheapestRow(std::shared_ptr<Playground> Field);
    virtual int pickCard(std::vector<GameCard> cards);
    virtual int pickRow();
    virtual int showPoints();

private:
    int mPoints;
    
};
