//
//  RandomBot.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "Player.hpp"

class RandomBot:public Player
{
public:
    RandomBot();
    ~RandomBot();
    int pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field) override;
    int findCheapestRow(const std::shared_ptr<Playground> Field) override;
};
