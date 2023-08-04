//
//  Playground.cpp
//  gamelib
//
//  Created by Marijan Buffi on 31.07.23.
//

#include <iostream>
#include <vector>
#include "Playground.hpp"
#include "UI.hpp"

UI UI;
GameCard initCard;

Playground::Playground()
{
}

Playground::~Playground()
{
}

void Playground::initField(std::vector<GameCard> startCards)
{
    initCard = {0, 0};
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
                mField[i].push_back(initCard);
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        mField[i][0] = startCards.at(i);
    }
}

void Playground::printField()
{
    std::cout << "------------------- Cost:" << std::endl;
    
    for(int i = 0; i < 4; i++)
    {
        for(GameCard j: mField[i])
        {
            if((int)j.value == initCard.value)
            {
                std::cout << "|  ";
            }
            else
            {
                std::cout << '|' << (int)j.value;
            }
        }
        std::cout << "|  " << costOfRow(i) << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void Playground::placeCard(std::vector<GameCard> cards, int row, int column, int num)
{
    mField[row][column] = cards[num];
}

int Playground::getRightRow(int value)
{
    int row = -1, temp = 104, dif = 0;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 5; j >= 0; j--)
        {
            if(mField[i][j].value != initCard.value)
            {
                dif = value - mField[i][j].value;
                if(dif > 0 && dif < temp)
                {
                    temp = dif;
                    row = i;
                    break;
                }
                break;
            }
        }
    }
    
    return row;
}

int Playground::getRightColumn(int value, int row)
{
    int column = 5;
    
    for(int j = 5; j >= 0; j--)
    {
        
        if(mField[row][j].value != initCard.value)
        {
            column = j + 1;
            break;
        }
        
    }
    
    if(column == 5)
    {
        clearRow(row);
        column = 0;
    }
    
    return column;
}

int Playground::clearRow(int row)
{
    int cost = 0;
    
    for(int i = 0; i < 6; i++)
    {
        cost += mField[row][i].cost;
        mField[row][i] = initCard;
    }
    
    return cost;
}

int Playground::costOfRow(int row)
{
    int cost = 0, temp;
    
    for(int i = 0; i < 6; i ++)
    {   temp = (int)mField[row][i].cost;
        cost += temp;
    }
    
    return cost;
}

int Playground::lowestCardOnField()
{
    int value = 104, temp;
    bool found = false;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 5; j >= 0; j--)
        {
            if(mField[i][j].value != initCard.value && j < 4)
            {
                temp = mField[i][j].value;
                if(temp < value)
                {
                    value = temp;
                    found = true;
                    break;
                }
                break;
            }
            
        }
    }
    
    if(found == false)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 5; j >= 0; j--)
            {
                if(mField[i][j].value != initCard.value)
                {
                    temp = mField[i][j].value;
                    if(temp < value)
                    {
                        value = temp;
                        break;
                    }
                    break;
                }
                
            }
        }
    }
    
    return value;
}
