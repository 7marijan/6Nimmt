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
    int findCheapestRow(std::shared_ptr<Playground> Field) override;
    int pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field) override;};
