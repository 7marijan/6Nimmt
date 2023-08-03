//
//  LowestCardBot.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//
#include "LowestCardBot.hpp"
#include "Playground.hpp"
#include <chrono>
#include <thread>

LowestCardBot::LowestCardBot()
{
}

LowestCardBot::~LowestCardBot()
{
}

int LowestCardBot::pickRow()
{
    return 0;
}

int LowestCardBot::pickCard(std::vector<GameCard> cards)
{
    int spot = 0, tempSize = 104;
    
    for(int i = 0; i < cards.size(); i++)
    {
        if(cards[i].value < tempSize)
        {
            tempSize = cards[i].value;
            spot = i;
        }
    }
    
    return spot;
}

int LowestCardBot::findCheapestRow(std::shared_ptr<Playground> Field)
{
    int cheapestRow = 28, row = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if((int)Field->costOfRow(i) < cheapestRow)
        {
            cheapestRow = Field->costOfRow(i);
            row = i;
        }
    }
    
    
    return row;
}
