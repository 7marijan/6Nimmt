//
//  Player.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "Player.hpp"
#include "UI.hpp"
#include "Dealer.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::pickCard()
{
    UI UI;
    UI.getPlayerMove(mCards);
}

void Player::addCost(int cost)
{
    mPoints += cost;
}

int Player::pickRow()
{
    UI UI;
    int row;
    
    UI.giveOutput("Die Ausgewählte Karte passt leider zu keiner Reihe.");
    UI.giveCostOfRow();
    row = UI.getPlayerRow();
    
    return row;
}

void Player::takeHand()
{
    Dealer Dealer;
    
    mCards = Dealer.Draw(10);
}

std::vector<GameCard> Player::showOwnCards()
{
    return mCards;
}


