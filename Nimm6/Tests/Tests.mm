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
    
    int whoWon, one = 0, two = 0, draw = 0;
    
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
            one++;
        }
        else if(whoWon == 2)
        {
            two++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
        
    }
    
    std::cout << "Bot1: " << one << std::endl;
    std::cout << "Bot2: " << two << std::endl;
    std::cout << "Draw : " << draw << std::endl;
    
}

- (void)test2
{
    Control Control;
    
    int whoWon, one = 0, two = 0, draw = 0;
    
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
            one++;
        }
        else if(whoWon == 2)
        {
            two++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
        
    }
    
    std::cout << "LowestCardBot: " << one << std::endl;
    std::cout << "HighestCardBot: " << two << std::endl;
    std::cout << "Draw: " << draw << std::endl;
    
}

- (void)test3
{
    Control Control;
    
    int whoWon, one = 0, two = 0, draw = 0;
    
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
            one++;
        }
        else if(whoWon == 2)
        {
            two++;
        }
        else if(whoWon == 3)
        {
            draw++;
        }
        
    }
    
    std::cout << "LowestCardBot: " << one << std::endl;
    std::cout << "RandomBot: " << two << std::endl;
    std::cout << "Draw: " << draw << std::endl;
    
}

/*
- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}
*/
@end
