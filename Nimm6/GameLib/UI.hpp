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
    std::string getUserInput(std::string message);
    void giveOutput(std::string output);
    int getPlayerMove(std::vector<GameCard> cards, int num);
    int getPlayerRow();
    void giveCostOfRow(std::shared_ptr<Playground> Field);
    
private:
    void showCards(std::vector<GameCard> cards);
};
