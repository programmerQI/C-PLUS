#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Player.cpp"
#include "Bash.h"
#include "Bash.cpp"
#include <iostream>
#include <string>
class Game
{

private:

    char file1[100] = "notation.txt";

    Player player;
    Bash bash;
    //std::ifstream in;
    int count_passedMilage;
    int count_passedStore;

public:

    const static int MONEY = 1000;
    const static int DISTANCE = 2040;

    Game();
    int startGame();
    int initGameInfo();


};
#endif // GAME_H
