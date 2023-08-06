//
//  HighestCardBot.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "HighestCardBot.hpp"
#include <chrono>
#include <thread>

HighestCardBot::HighestCardBot()
{
}

HighestCardBot::~HighestCardBot()
{
}

int HighestCardBot::pickCard(const std::vector<GameCard> cards, const int num, const std::shared_ptr<Playground> Field)
{
    int spot = 0, tempSize = 0;
    
    for(int i = 0; i < cards.size(); i++)
    {
        if(cards[i].value > tempSize)
        {
            tempSize = cards[i].value;
            spot = i;
        }
    }
    
    return spot;
}

int HighestCardBot::findCheapestRow(const std::shared_ptr<Playground> Field)
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
