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
#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}

int Player::pickCard(std::vector<GameCard> cards, int num, std::shared_ptr<Playground> Field)
{
    return 1;
}

int Player::showPoints()
{
    return mPoints;
}

void Player::addCost(const int cost)
{
    mPoints += cost;
}

int Player::findCheapestRow(const std::shared_ptr<Playground> Field)
{
    return 0;
}

void Player::showCards() const
{
    for(int i = 0; i < mCards.size(); i++)
    {
        std::cout << "| " << (int)mCards[i].value;
    }
    std::cout << " |" << std::endl;
}


