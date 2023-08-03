//
//  main.cpp
//  Nimm6
//
//  Created by Marijan Buffi on 05.07.23.
//

//#include <memory>
//#include <iostream>
#include "gamelib.hpp"
#include "Control.hpp"
//#include <vector>
//#include "UI.hpp"
//#include "Dealer.h"
//Dealer Dealer;
//Playground Playground;

int main(int argc, const char * argv[])
{
    Control Control;
/*
    std::shared_ptr<UI> UI;
    
    std::vector<GameCard> test(24);
    test = Dealer.Draw(24);
 
    Playground.initField(test);
    
    for(int i = 0; i < test.size(); i++){
        std::cout << (int)test[i].value << "|" << (int)test[i].cost << std::endl;
    }
    
    Playground.printField();
    
    do
    {
        int jons = UI->getPlayerMove(test);
        
        int row = Playground.getRightRow(test[jons].value);
        if(row != -1)
        {
            Playground.placeCard(test, row, Playground.getRightColumn(test[jons].value, row), jons);
        }
        else
        {
            UI->giveOutput("TEST BESTANDEN");
        }
        Playground.printField();
    
        test.erase(test.begin()+jons);
    }
    while(true);
*/
    
    Control.preGame();
    
    return 0;
}
