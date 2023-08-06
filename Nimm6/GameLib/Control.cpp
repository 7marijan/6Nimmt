//
//  Control.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include <iostream>
#include <memory>
#include "Control.hpp"
#include "Human.hpp"
#include "LowestCardBot.hpp"
#include "HighestCardBot.hpp"
#include "RandomBot.hpp"
#include "IntelligentBot.hpp"
#include "UI.hpp"
#include <chrono>
#include <thread>
#include <unistd.h>
#include <term.h>

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
    
    UI.giveOutput("---------------------------");
    UI.giveOutput("Wer soll gegen wen spielen?\n");
    UI.giveOutput("Human Player [1]");
    UI.giveOutput("Lowest-Card Bot [2]");
    UI.giveOutput("Highest-Card Bot [3]");
    UI.giveOutput("Random Bot [4]");
    UI.giveOutput("Intelligent Bot [5]");
    UI.giveOutput("---------------------------");

    std::shared_ptr<Player> P1 = choosePlayer("1");
    std::shared_ptr<Player> P2 = choosePlayer("2");
    std::shared_ptr<Playground> Field (new Playground);
    std::vector<GameCard> playingCards;
    
    P1->mCards = Dealer.Draw(10);
    P2->mCards = Dealer.Draw(10);
    playingCards = Dealer.Draw(4);
    
    
    Field->initField(playingCards);
    
    startGame(P1, P2, Field);
}

int Control::startGame( std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, const std::shared_ptr<Playground> Field)
{
    
    UI UI;
    int card1 = 0, card2 = 0;
    
    UI.giveOutput("\n\nSpiel wird gestartet!");
    
    Field->printField();
    
    for(int i = 0; i < 10; i ++)
    {
        card1 = P1->pickCard(P1->mCards, 1, Field);
        card2 = P2->pickCard(P2->mCards, 2, Field);
            
        if(P1->mCards[card1] < P2->mCards[card2])
        {
            
            systemSleep();
            std::cout << "\nPlayer 1: " << (int)P1->mCards[card1].value << std::endl;
            makeMove(Field, P1, card1);
            
            Field->printField();
            
            systemSleep();
            std::cout << "\nPlayer 2: " << (int)P2->mCards[card2].value << std::endl;
            makeMove(Field, P2, card2);
        }
        else
        {
            systemSleep();
            std::cout << "\nPlayer 2: " << (int)P2->mCards[card2].value << std::endl;
            makeMove(Field, P2, card2);
            
            Field->printField();
            
            systemSleep();
            std::cout << "\nPlayer 1: " << (int)P1->mCards[card1].value << std::endl;
            makeMove(Field, P1, card1);
        }
        Field->printField();
    }

    std::cout << "\nPlayer 1: " << P1->showPoints() << std::endl;
    std::cout << "Player 2: " << P2->showPoints() << std::endl;
    
    if(P1->showPoints() < P2->showPoints())
    {
        UI.giveOutput("\nPlayer 1 hat gewonnen!");
        return 1;
    }
    else if(P1->showPoints() > P2->showPoints())
    {
        UI.giveOutput("\nPlayer 2 hat gewonnen!");
        return 2;
    }
    else
    {
        UI.giveOutput("\nDas Spiel ist unentschieden ausgegangen!");
        return 3;
    }
}

std::shared_ptr<Player> Control::choosePlayer(const std::string number) const
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
        else if(input == "5")
        {
            std::shared_ptr<Player> P (new IntelligentBot);
            return P;
        }
        else
        {
            UI.giveOutput("Falsche Eingabe. Versuch es doch noch einmal!");
        }
    }while(true);
    
}

void Control::clearFieldAddCost(const std::shared_ptr<Playground> Field, std::shared_ptr<Player> P, const int card, const int column, const int row)
{
    P->addCost(Field->costOfRow(row));
    Field->clearRow(row);
    Field->placeCard(P->mCards, row, column, card);
}

void Control::makeMove(const std::shared_ptr<Playground> Field, std::shared_ptr<Player> P, int card)
{
    int row, column;
    
    row = Field->getRightRow(P->mCards[card].value);
    
    if(row == -1)
    {
        row = P->findCheapestRow(Field);
        clearFieldAddCost(Field, P, card, 0, row);
    }
    else
    {
        column = Field->getRightColumn(row);
        
        if(column == 5)
        {
            clearFieldAddCost(Field, P, card, 0, row);
        }
        else
        {
            Field->placeCard(P->mCards, row, column, card);
        }
    }
    
    P->mCards.erase(P->mCards.begin()+card);
}

void Control::systemSleep() const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
