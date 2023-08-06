//
//  RandomBot.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "RandomBot.hpp"
#include <random>
#include <iostream>
#include <cassert>

RandomBot::RandomBot()
{
}

RandomBot::~RandomBot()
{
}

int RandomBot::pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field)
{
    return 0;
}

int RandomBot::findCheapestRow(const std::shared_ptr<Playground> Field)
{
    std::random_device randomDevice;
    std::mt19937 rng(randomDevice());
    std::uniform_int_distribution<std::mt19937::result_type> randomRange(0, 3);
    
    return randomRange(rng);
}
