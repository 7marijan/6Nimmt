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
   
private:
    int startGame(std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, std::shared_ptr<Playground> Field);
    std::shared_ptr<Player> choosePlayer(std::string number);
    
};
