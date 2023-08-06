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
    virtual void addCost(const int cost);
    virtual int findCheapestRow(const std::shared_ptr<Playground> Field);
    virtual int pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field);
    void showCards() const;
    virtual int showPoints();
    int mPoints;

    
};
