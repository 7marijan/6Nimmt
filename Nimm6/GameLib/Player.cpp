//
//  Player.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "Player.hpp"
#include "UI.hpp"
#include "Dealer.h"
#include "Playground.hpp"

Player::Player()
{
}

Player::~Player()
{
}

int Player::pickCard(std::vector<GameCard> cards)
{
    return 1;
}

void Player::addCost(int cost)
{
    mPoints += cost;
}

int Player::pickRow()
{
    return 0;
}

int Player::showPoints()
{
    return mPoints;
}

int Player::findCheapestRow(std::shared_ptr<Playground> Field)
{
    return 0;
}




