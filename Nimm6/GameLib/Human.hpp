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
    std::vector<GameCard> mCards;
    int findCheapestRow(const std::shared_ptr<Playground> Field) override;
    int pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field) override;};
