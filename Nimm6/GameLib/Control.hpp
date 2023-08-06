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
    int startGame( std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, const std::shared_ptr<Playground> Field);

private:
    std::shared_ptr<Player> choosePlayer(const std::string number) const;
    void clearFieldAddCost(const std::shared_ptr<Playground> &Field, std::shared_ptr<Player> &P, const int card, const int column, const int row);
    void makeMove(const std::shared_ptr<Playground> &Field, std::shared_ptr<Player> &P, int card);
    void systemSleep() const;
};
