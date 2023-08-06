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
    int findCheapestRow(const std::shared_ptr<Playground> Field) override;
    int pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field)override;};
