//
//  Player.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "GameCard.h"
#include <vector>

class Player
{
public:
    Player();
    ~Player();
    std::vector<GameCard> mCards;
    virtual int findCheapestRow();
    virtual void pickCard();
    virtual int pickRow();
    virtual void takeHand();
    virtual std::vector<GameCard> showOwnCards();

private:
    
    int mPoints;
    void addCost(int cost);
};
