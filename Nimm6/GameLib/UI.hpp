//
//  UI.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include <string>
#include "GameCard.h"
#include "Playground.hpp"
#include <memory>

class UI
{
public:
    UI();
    ~UI();
    std::string getUserInput(const std::string message) const;
    void giveOutput(const std::string output) const;
    int getPlayerMove(const std::vector<GameCard> cards, const int num) const;
    int getPlayerRow() const;
    void giveCostOfRow(const std::shared_ptr<Playground> Field) const;
    
private:
    void showCards(const std::vector<GameCard> cards) const;
};
