//
//  gamelib.cpp
//  gamelib
//
//  Created by Marijan Buffi on 05.07.23.
//

#include <iostream>
#include "gamelib.hpp"
#include "gamelibPriv.hpp"

void gamelib::HelloWorld(const char * s)
{
    gamelibPriv *theObj = new gamelibPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void gamelibPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

