//
//  Control.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "Control.hpp"
#include "Human.hpp"
#include "LowestCardBot.hpp"
#include "HighestCardBot.hpp"
#include "RandomBot.hpp"
#include "UI.hpp"
#include <memory>
#include "Dealer.h"
//UI UI;


Control::Control()
{
}

Control::~Control()
{
}

void Control::preGame()
{
    UI UI;
    Dealer Dealer;
    std::vector<GameCard> playingCards;
    
    UI.giveOutput("Spiel wird gestartet.");
    
    UI.giveOutput("Wer soll gegen wen spielen?");
    UI.giveOutput("Human Player [1]");
    UI.giveOutput("Lowest-Card Bot [2]");
    UI.giveOutput("Highest-Card Bot [3]");
    UI.giveOutput("Random Bot [4]");
    UI.giveOutput("Intelligent Bot [5]");

    std::shared_ptr<Player> P1 = choosePlayer("1");
    std::shared_ptr<Player> P2 = choosePlayer("2");
    std::shared_ptr<Playground> Field (new Playground);
    
    playingCards = Dealer.Draw(4);
    Field->initField(playingCards);
    
    startGame(P1, P2, Field);
}

int Control::startGame(std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, std::shared_ptr<Playground> Field)
{
    
    UI UI;
    int card1, card2 = 0, row1, row2 = 0;
    
    while(true)
    {
        
        card2 = 1;
        row2 = 1;
        
        card1 = UI.getPlayerMove(P1->showOwnCards());

        row1 = Field->getRightRow(P1->mCards[card1].value);
        if(row1 != -1)
        {
            Field->placeCard(P1->mCards, row1, Field->getRightColumn(P1->mCards[card1].value, row1), card1);
        }
        else
        {
            UI.giveOutput("TEST BESTANDEN");
        }
        Field->printField();
    
        P1->mCards.erase(P1->mCards.begin()+card1);
    }
    
    
    return 3;
}


std::shared_ptr<Player> Control::choosePlayer(std::string number)
{
    
    UI UI;
    std::string output, input;
    
    do
    {
        output = "Wähle Spieler " + number + ":";
        
        input = UI.getUserInput(output);
    
        if(input == "1")
        {
            std::shared_ptr<Player> P (new Human);
            return P;
        }
        else if(input == "2")
        {
            std::shared_ptr<Player> P (new LowestCardBot);
            return P;
        }
        else if(input == "3")
        {
            std::shared_ptr<Player> P (new HighestCardBot);
            return P;
        }
        else if(input == "4")
        {
            std::shared_ptr<Player> P (new RandomBot);
            return P;
        }
        else
        {
            UI.giveOutput("Falsche Eingabe. Versuch es doch noch einmal!");
        }
    }while(true);
    
}


