#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"
#include "Store.h"
#include "Store.cpp"
#include <iostream>
#include <string>
Game::Game()
{
    //std::cout << "This is it!" << std::endl;
}
int Game::startGame()
{
    std::string str1;

    while(true)
    {
        bash.show_startGameMenu();
        std::cin >> str1;

        if(str1.compare("1") == 0)
        {
            return 1;
        }
        else if(str1.compare("2") == 0)
        {
            bash.say_goodBye();
            return 0;
        }
    }

}
int Game::initGameInfo()
{

    count_passedMilage = 0;
    count_passedStore = 0;

    std::string str1, str2, str3, str4, str5;

    bash.ask_leaderName();
    std::cin >> str1;
    bash.ask_memberName();
    std::cin >> str2 >> str3 >> str4 >> str5;
    player.init(str1,str2,str3,str4,str5);
    //player.show_playerStatus();

    bash.print_notation(file1);

    Store newStore;
    while(true)
    {
        bash.show_storeInfo(newStore);
        bash.ask_shoppingItem();
        std::cin >> str1;
        bash.ask_shoppingAmount();
        std::cin >> str2;
        switch (stoi(str1))
        {
        case 1:
            if(player.reduce_money(newStore.purchaseOxen(stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_oxen(stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }


    }
    return 1;
}
#endif // GAME_CPP
