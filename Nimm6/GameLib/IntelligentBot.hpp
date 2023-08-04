//
//  IntelligentBot.hpp
//  gamelib
//
//  Created by Marijan Buffi on 04.08.23.
//

#pragma once
#include "GameCard.h"
#include "Playground.hpp"
#include "Player.hpp"

class IntelligentBot:public Player
{
public:
    IntelligentBot();
    ~IntelligentBot();
    int findCheapestRow(std::shared_ptr<Playground> Field) override;
    int pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field)override;

private:
    int mCount;
};
