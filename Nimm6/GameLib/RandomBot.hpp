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
    int pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field) override;
    int findCheapestRow(std::shared_ptr<Playground> Field) override;
};
