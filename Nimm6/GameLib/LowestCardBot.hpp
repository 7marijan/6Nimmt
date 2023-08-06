//
//  LowestCardBot.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "Player.hpp"
#include "Playground.hpp"

class LowestCardBot:public Player
{
public:
    LowestCardBot();
    ~LowestCardBot();
    int pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field) override;
    int findCheapestRow(const std::shared_ptr<Playground> Field) override;
};
