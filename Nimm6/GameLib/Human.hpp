//
//  Human.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "Player.hpp"

class Human:public Player
{
public:
    Human();
    ~Human();
    int findCheapestRow() override;
    void pickCard() override;
    int pickRow() override;
    void takeHand() override;
    std::vector<GameCard> showOwnCards() override;
};
