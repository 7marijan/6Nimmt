//
//  Human.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include "Human.hpp"
#include "Playground.hpp"
#include "UI.hpp"

Human::Human()
{
}

Human::~Human()
{
}

int Human::pickRow()
{
    UI UI;
    int row;
    
    UI.giveOutput("Die Ausgewählte Karte passt leider zu keiner Reihe.");
    UI.giveCostOfRow();
    row = UI.getPlayerRow();
    
    return row;
}

int Human::pickCard(std::vector<GameCard> cards)
{
    UI UI;
    int card;
    card = UI.getPlayerMove(cards);
    return card;
}

int Human::findCheapestRow(std::shared_ptr<Playground> Field)
{
    UI UI;
    int row = -1;
    std::string input;
    
    do
    {
        input = UI.getUserInput("Welche Reihe möchtest du einsammeln?: ");
        if(input == "1")
        {
            row = 0;
        }
        else if (input == "2")
        {
            row = 1;
        }
        else if (input == "3")
        {
            row = 2;
        }
        else if (input == "4")
        {
            row = 3;
        }
        else
        {
            UI.giveOutput("Bitte Reihe 1-4 auswählen.");
        }
    }
    while(row == -1);
        
    return row;
}
