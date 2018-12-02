#include<stdio.h>
#include<iostream>
#include "Game.h"
#include "Game.cpp"
using namespace std;
int main()
{
    Game game;
    while(game.startGame())
    {
        cout << "Game is running" << endl;
        game.initGameInfo();
    }
}
