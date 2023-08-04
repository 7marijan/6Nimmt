//
//  UI.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "UI.hpp"
#include <iostream>
#include <cstdlib>
#include "GameCard.h"
#include "Playground.hpp"

UI::UI()
{
}

UI::~UI()
{
}

std::string UI::getUserInput(std::string message)
{
    std::string i;
    
    std::cout << message << std::endl;
    std::cin >> i;
    
    return i;
}

void UI::giveOutput(std::string output)
{
    std::cout << output << std::endl;
}

int UI::getPlayerMove(std::vector<GameCard> cards, int num)
{
    char input[5], *ptr;
    long temp;
    int pickedCard;
    bool found = false;
    
    std::cout << "\nPlayer " << num << ": ";
    
    showCards(cards);
    
    do
    {
        std::cout << "Welche Karte möchtest du als nächstes Spielen?: ";
        std::cin >> input;
        
        temp = strtol(input, &ptr, 10);
        pickedCard = (int)temp;
        
        std::cin.clear();
        
        for(int i = 0; i < cards.size(); i++)
        {
            if(pickedCard == cards[i].value)
            {
                found = true;
                pickedCard = i;
                break;
            }
        }
        if(found == false)
        {
            std::cout << "Karte nicht gefunden, versuche es erneut!" << std::endl;
        }
    }
    while(found == false);
    
    return pickedCard;
}

void UI::showCards(std::vector<GameCard> cards)
{
    std::cout << "\nDeine Verfügbaren Karten:";
    
    std::cout << "| ";
    
    for(int i = 0; i < cards.size(); i++)
    {
        std::cout << (int)cards[i].value << " | ";
    }
    
    std::cout << "\n";
}


int UI::getPlayerRow()
{
    char input[5], *ptr;
    long temp;
    int pickedRow;
    bool done = false;
    
    do
    {
        std::cout << "Welche Reihe möchtest du Räumen: ";
        std::cin >> input;
        
        temp = strtol(input, &ptr, 10);
        pickedRow = (int)temp;
        
        std::cin.clear();
        
        if(pickedRow > 4 || pickedRow < 1)
        {
            std::cout << "Diese Reihe existiert nicht!" << std::endl;
        }
        else
        {
            done = true;
        }
    }
    while(done == false);
    
    return pickedRow;
    
}

void UI::giveCostOfRow(std::shared_ptr<Playground> Field)
{
    std::cout << " Reihe 1: " << Field->costOfRow(0) << std::endl;
    std::cout << " Reihe 2: " << Field->costOfRow(1) << std::endl;
    std::cout << " Reihe 3: " << Field->costOfRow(2) << std::endl;
    std::cout << " Reihe 4: " << Field->costOfRow(3) << std::endl;
}
