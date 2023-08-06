//
//  HighestCardBot.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "Player.hpp"
#include "Playground.hpp"

class HighestCardBot:public Player
{
public:
    HighestCardBot();
    ~HighestCardBot();
    int pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field) override;
    int findCheapestRow(const std::shared_ptr<Playground> Field) override;
};
