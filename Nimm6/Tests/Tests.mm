//
//  Tests.m
//  Tests
//
//  Created by Marijan Buffi on 05.07.23.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "Control.hpp"
#include "Player.hpp"
#include "LowestCardBot.hpp"
#include "HighestCardBot.hpp"
#include "RandomBot.hpp"
#include "IntelligentBot.hpp"
#include "Dealer.h"

@interface Tests : XCTestCase

@end

@implementation Tests

- (void)test1
{
    Control Control;
    
    int whoWon;
    float intelligent = 0, lowest = 0, draw = 0;
    
    for(int i = 0; i < 1000; i++)
    {
        Dealer Dealer;
        std::shared_ptr<Player> P1(new IntelligentBot);
        std::shared_ptr<Player> P2(new LowestCardBot);
        std::shared_ptr<Playground> Field (new Playground);
        std::vector<GameCard> playingCards;
        
        P1->mCards = Dealer.Draw(10);
        P2->mCards = Dealer.Draw(10);
        playingCards = Dealer.Draw(4);
        
        
        Field->initField(playingCards);
        
        
        whoWon = Control.startGame(P1, P2, Field);
        
        if(whoWon == 1)
        {
            intelligent++;
        }
        else if(whoWon == 2)
        {
            lowest++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
    }
    
    intelligent = intelligent / 10;
    lowest = lowest / 10;
    draw = draw / 10;
    
    std::cout << "\nIntelligentBot: " << intelligent << "%" << std::endl;
    std::cout << "LowestCardBot: " << lowest << "%" << std::endl;
    std::cout << "Unentschieden: " << draw << "%\n" << std::endl;
    
}

- (void)test2
{
    Control Control;
    
    int whoWon;
    float intelligent = 0, highest = 0, draw = 0;
    
    for(int i = 0; i < 1000; i++)
    {
        Dealer Dealer;
        std::shared_ptr<Player> P1(new IntelligentBot);
        std::shared_ptr<Player> P2(new HighestCardBot);
        std::shared_ptr<Playground> Field (new Playground);
        std::vector<GameCard> playingCards;
        
        P1->mCards = Dealer.Draw(10);
        P2->mCards = Dealer.Draw(10);
        playingCards = Dealer.Draw(4);
        
        
        Field->initField(playingCards);
        
        
        whoWon = Control.startGame(P1, P2, Field);
        
        if(whoWon == 1)
        {
            intelligent++;
        }
        else if(whoWon == 2)
        {
            highest++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
    }
    
    intelligent = intelligent / 10;
    highest = highest / 10;
    draw = draw / 10;
    
    std::cout << "\nIntelligentBot: " << intelligent << "%" << std::endl;
    std::cout << "HighestCardBot: " << highest << "%" << std::endl;
    std::cout << "Unentschieden: " << draw << "%\n" << std::endl;
    
}

- (void)test3
{
    Control Control;
    
    int whoWon;
    float intelligent = 0, randombot = 0, draw = 0;
    
    for(int i = 0; i < 1000; i++)
    {
        Dealer Dealer;
        std::shared_ptr<Player> P1(new IntelligentBot);
        std::shared_ptr<Player> P2(new RandomBot);
        std::shared_ptr<Playground> Field (new Playground);
        std::vector<GameCard> playingCards;
        
        P1->mCards = Dealer.Draw(10);
        P2->mCards = Dealer.Draw(10);
        playingCards = Dealer.Draw(4);
        
        
        Field->initField(playingCards);
        
        
        whoWon = Control.startGame(P1, P2, Field);
        
        if(whoWon == 1)
        {
            intelligent++;
        }
        else if(whoWon == 2)
        {
            randombot++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
    }
    
    intelligent = intelligent / 10;
    randombot = randombot / 10;
    draw = draw / 10;
    
    std::cout << "\nIntelligentBot: " << intelligent << "%" << std::endl;
    std::cout << "RandomBot: " << randombot << "%" << std::endl;
    std::cout << "Unentschieden: " << draw << "%\n" << std::endl;
    
}

@end
