#include<stdio.h>
#include<iostream>
#include "Game.h"
#include "Game.cpp"
#include "Misfortunes.h"
#include "Misfortunes.cpp"
using namespace std;
int main()
{
    Misfortunes m;
    Game game;
    while(game.startGame())
    {
        //cout << "Game is running" << endl;
        game.initGameInfo();
        while(game.isGameOver())
        {
            game.takeTurn();
        }
    }
}
