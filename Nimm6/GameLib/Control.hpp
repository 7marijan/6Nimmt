//
//  Control.hpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#pragma once
#include "Playground.hpp"
#include <memory>
#include "Player.hpp"
#include "UI.hpp"

class Control
{
public:
    Control();
    ~Control();
    void preGame();
    int startGame(std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, std::shared_ptr<Playground> Field);

private:
    std::shared_ptr<Player> choosePlayer(std::string number);
    void clearFieldAddCost(const std::shared_ptr<Playground> &Field, const std::shared_ptr<Player> &P, int card, int column, int row);
    void makeMove(const std::shared_ptr<Playground> &Field, const std::shared_ptr<Player> &P1, int card1, int &column1, int &row1);
    void systemSleep();
};
