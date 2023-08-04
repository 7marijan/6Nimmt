//
//  IntelligentBot.cpp
//  gamelib
//
//  Created by Marijan Buffi on 04.08.23.
//

#include "IntelligentBot.hpp"
#include "Playground.hpp"

IntelligentBot::IntelligentBot()
{
    mCount = 0;
}

IntelligentBot::~IntelligentBot()
{
}

int IntelligentBot::pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field)
{
    int lowestCard, dif = 0, tempSize = 104, spot = 0;
    bool found = false;
    lowestCard = Field->lowestCardOnField();
    
    for(int i = 0; i < cards.size(); i++)
    {
        dif = cards[i].value - lowestCard;
        
        if(dif > 0)
        {
            if(tempSize > dif)
            {
                tempSize = cards[i].value;
                spot = i;
                found = true;
            }
        }
    }
    
    if(found != true)
    {
        for(int i = 0; i < cards.size(); i++)
        {
            if(cards[i].value < tempSize)
            {
                tempSize = cards[i].value;
                spot = i;
            }
        }
    }
    
    return spot;
}

int IntelligentBot::findCheapestRow(std::shared_ptr<Playground> Field)
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
