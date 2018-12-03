#ifndef GAME_CPP
#define GAME_CPP
#include "BasicTool.cpp"
#include "Game.h"
#include "Store.h"
#include "Store.cpp"
#include "Hunt.h"
#include "Hunt.cpp"))
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

    do
    {
        bash.chose_departureTime();
        std::cin>> str1 >> str2;
    }
    while (time.setStart(stoi(str1),stoi(str2)) == time.NOTVALID);
    bash.print_notation(file1);
    shop();

    return 1;
}
int Game::takeTurn()
{
    std::string str1, str2, str3, str4, str5;
    bash.show_todoList();

    std::cin >> str1;
    switch(stoi(str1))
    {
    case 1:
        rest();
        break;
    case 2:
        go();
        break;
    case 3:
        hunt();
        break;
    case 4:
        break;
    default:
        break;
    }
}
int Game::consume()
{
    if(player.get_leaderStatus() != player.DEAD)
    {
        player.reduce_food(3);
    }
    if(player.get_member1Status() != player.DEAD)
    {
        player.reduce_food(3);
    }
    if(player.get_member2Status() != player.DEAD)
    {
        player.reduce_food(3);
    }
    if(player.get_member3Status() != player.DEAD)
    {
        player.reduce_food(3);
    }
    if(player.get_member4Status() != player.DEAD)
    {
        player.reduce_food(3);
    }
}
int Game::shop()
{

    std::string str1,str2;
    Store newStore(count_passedStore);

    while(true)
    {
        bash.show_storeInfo(newStore);
        bash.ask_shoppingItem();
        std::cin >> str1;
        if(stoi(str1) == 6)
        {
            return 1;
        }
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
            if(player.reduce_money(newStore.purchaseFood(stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_food(stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 3:
            if(player.reduce_money(newStore.purchaseBullets(stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_bullets(stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 4:
            if(player.reduce_money(newStore.purchaseWagonPart(stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_wagonPart(stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 5:
            if(player.reduce_money(newStore.purchaseMedicalKit(stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_medicalKit(stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        default:
            bash.show_playersMoney(player);
            break;
        }
    }
}
int Game::rest()
{
    time.rest();
    consume();
}
int Game::go()
{
    srand(std::time(NULL));
    count_passedMilage += (rand()%70 + 71);
}
int Game::hunt()
{
    std::string str1, str2;
    Hunt ht;
    int cnt;
    if(ht.encounter_rabbit())
    {
        bash.encounter_rabbit();
        std::cin >> str1;
        while(true)
        {
            if(stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(stoi(str2)) == puzzle.MATCH)
                    {
                        if(player.reduce_bullets(10) != player.NOENOUGH_BULLETS)
                        {
                            player.add_food(2);
                            bash.show_huntSuccess();
                        }
                        else
                        {
                            bash.no_enoughBullets();
                        }
                        break;
                    }
                    else
                    {
                        bash.show_puzzleNotMatch();
                    }
                }
                break;
            }
            else if(stoi(str2) == 2)
            {
                break;
            }
        }
    }
    if(ht.encounter_fox())
    {
        bash.encounter_fox();
        std::cin >> str1;
        while(true)
        {
            if(stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(stoi(str2)) == puzzle.MATCH)
                    {
                        if(player.reduce_bullets(8) != player.NOENOUGH_BULLETS)
                        {
                            player.add_food(5);
                            bash.show_huntSuccess();
                        }
                        else
                        {
                            bash.no_enoughBullets();
                        }
                        break;
                    }
                    else
                    {
                        bash.show_puzzleNotMatch();
                    }
                }
                break;
            }
            else if(stoi(str2) == 2)
            {
                break;
            }
        }
    }
    if(ht.encounter_deer())
    {
        bash.encounter_deer();
        std::cin >> str1;
        while(true)
        {
            if(stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(stoi(str2)) == puzzle.MATCH)
                    {
                        if(player.reduce_bullets(5) != player.NOENOUGH_BULLETS)
                        {
                            srand(std::time(NULL));
                            player.add_food(rand()%25+1+30);
                            bash.show_huntSuccess();
                        }
                        else
                        {
                            bash.no_enoughBullets();
                        }
                        break;
                    }
                    else
                    {
                        bash.show_puzzleNotMatch();
                    }
                }
                break;
            }
            else if(stoi(str2) == 2)
            {
                break;
            }
        }
    }
    if(ht.encounter_beer())
    {
        bash.encounter_beer();
        std::cin >> str1;
        while(true)
        {
            if(stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(stoi(str2)) == puzzle.MATCH)
                    {
                        if(player.reduce_bullets(10) != player.NOENOUGH_BULLETS)
                        {
                            srand(std::time(NULL));
                            player.add_food(rand()%250+1+100);
                            bash.show_huntSuccess();
                        }
                        else
                        {
                            bash.no_enoughBullets();
                        }
                        break;
                    }
                    else
                    {
                        bash.show_puzzleNotMatch();
                    }
                }
                break;
            }
            else if(stoi(str2) == 2)
            {
                break;
            }
        }
    }
    if(ht.encounter_moose())
    {
        bash.encounter_moose();
        std::cin >> str1;
        while(true)
        {
            if(stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(stoi(str2)) == puzzle.MATCH)
                    {
                        if(player.reduce_bullets(12) != player.NOENOUGH_BULLETS)
                        {
                            srand(std::time(NULL));
                            player.add_food(rand()%300+1+300);
                            bash.show_huntSuccess();
                        }
                        else
                        {
                            bash.no_enoughBullets();
                        }
                        break;
                    }
                    else
                    {
                        bash.show_puzzleNotMatch();
                    }
                }
                break;
            }
            else if(stoi(str2) == 2)
            {
                break;
            }
        }
    }
}
#endif // GAME_CPP
