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
#include "UI.hpp"
#include <chrono>
#include <thread>

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
    
    P1->mCards = Dealer.Draw(10);
    P2->mCards = Dealer.Draw(10);
    playingCards = Dealer.Draw(4);
    
    
    Field->initField(playingCards);
    
    startGame(P1, P2, Field);
}





int Control::startGame(std::shared_ptr<Player> P1, std::shared_ptr<Player> P2, std::shared_ptr<Playground> Field)
{
    
    UI UI;
    int card1, card2, column1, column2, row1, row2;
    
    for(int i = 0; i < 10; i ++)
    {
        Field->printField();
        
        card1 = P1->pickCard(P1->mCards);
        card2 = P2->pickCard(P2->mCards);
        
        if(P1->mCards[card1] < P2->mCards[card2])
        {
            makeMove(Field, P1, card1, column1, row1);
            systemSleep();
            
            Field->printField();
            
            systemSleep();
            makeMove(Field, P2, card2, column2, row2);
        }
        else
        {
            makeMove(Field, P2, card2, column2, row2);
            systemSleep();
            
            Field->printField();
            
            systemSleep();
            makeMove(Field, P1, card1, column1, row1);
        }
        Field->printField();
    }
    
    std::cout << "Player 1: " << P1->showPoints() << std::endl;
    std::cout << "Player 2: " << P2->showPoints() << std::endl;
    
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

void Control::clearFieldAddCost(const std::shared_ptr<Playground> &Field, const std::shared_ptr<Player> &P, int card, int column, int row)
{
    P->addCost(Field->costOfRow(row));
    Field->clearRow(row);
    Field->placeCard(P->mCards, row, column, card);
}

void Control::makeMove(const std::shared_ptr<Playground> &Field, const std::shared_ptr<Player> &P, int card, int &column, int &row)
{
    row = Field->getRightRow(P->mCards[card].value);
    
    if(row == -1)
    {
        row = P->findCheapestRow(Field);
        clearFieldAddCost(Field, P, card, 0, row);
    }
    else
    {
        column = Field->getRightColumn(P->mCards[card].value, row);
        
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

void Control::systemSleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
