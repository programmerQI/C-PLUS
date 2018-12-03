#ifndef GAME_CPP
#define GAME_CPP
#include "BasicTool.cpp"
#include "Game.h"
#include "Store.h"
#include "Store.cpp"
#include "Hunt.h"
#include "Hunt.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
int Game::sortStone()
{
    Stone tmp;
    for(int i = 1 ; i < count_stones ; i++)
    {
        tmp = stones[i];
        for(int j = i - 1 ; j >= 0 && stones[j].mileage > tmp.mileage; j -- )
        {
            stones[j+1] =  stones[j];
            stones[j] = tmp;
        }
    }
    return 1;
}
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
    std::string str;
    int num;
    count_stones = 0;
    std::ifstream in;
    in.open(file2);
    if(in.is_open())
    {
        while(in>>str>>num&&count_stones < 20)
        {
            stones[count_stones].mileage = num;
            stones[count_stones].name = str;
            stones[count_stones].type = 1;
            count_stones ++;
        }
    }
    in.close();
    in.open(file3);
    if(in.is_open())
    {
        while(in>>str>>num&&count_stones < 20)
        {
            stones[count_stones].mileage = num;
            stones[count_stones].name = str;
            stones[count_stones].type = 2;
            count_stones ++;
        }
    }
    in.close();
    sortStone();

    misfortunes.setPlayer(&player);
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
        //std::cout << "this is it" << std::endl;
    }
    while (time.setStart(basic_tool::stoi(str1),basic_tool::stoi(str2)) == time.NOTVALID);
    bash.print_notation(file1);

    shop();

    return 1;
}
int Game::takeTurn()
{

    bash.show_travelInfo(time.get_currentMonth(),time.get_currentDate(),count_passedMilage);

    opt_negtiveEvent();

    std::string str1, str2, str3, str4, str5;
    bash.show_todoList();

    std::cin >> str1;
    switch(basic_tool::stoi(str1))
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
        if(basic_tool::stoi(str1) == 6)
        {
            return 1;
        }
        bash.ask_shoppingAmount();
        std::cin >> str2;
        switch (basic_tool::stoi(str1))
        {
        case 1:
            if(player.reduce_money(newStore.purchaseOxen(basic_tool::stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_oxen(basic_tool::stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 2:
            if(player.reduce_money(newStore.purchaseFood(basic_tool::stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_food(basic_tool::stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 3:
            if(player.reduce_money(newStore.purchaseBullets(basic_tool::stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_bullets(basic_tool::stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 4:
            if(player.reduce_money(newStore.purchaseWagonPart(basic_tool::stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_wagonPart(basic_tool::stoi(str2));
                bash.show_playersMoney(player);
            }
            break;
        case 5:
            if(player.reduce_money(newStore.purchaseMedicalKit(basic_tool::stoi(str2))) == player.NOENOUGH_MONEY)
            {
                bash.no_enoughMoney();
            }
            else
            {
                player.add_medicalKit(basic_tool::stoi(str2));
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
    misfortunes.rest();
    consume();
}
int Game::go()
{
    time.going();

    srand(std::time(NULL));

    int mile = rand()%70 + 71;
    count_passedMilage += mile;
    for(int i = 0 ; i < count_stones ; i++)
    {
        if(stones[i].mileage > count_passedMilage - mile && stones[i].mileage < count_passedMilage )
        {
            bash.show_storeInfo(stones[i].mileage);
            count_passedStore = stones[i].mileage;
            break;
        }
    }
}
int Game::hunt()
{
    //std::cout << "asdfasdf" << std::endl;
    time.hunt();

    std::string str1, str2;
    Hunt ht;
    int cnt;
    if(ht.encounter_rabbit())
    {
        bash.encounter_rabbit();
        std::cin >> str1;
        while(true)
        {
            if(basic_tool::stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(basic_tool::stoi(str2)) == puzzle.MATCH)
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
            if(basic_tool::stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(basic_tool::stoi(str2)) == puzzle.MATCH)
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
            else if(basic_tool::stoi(str2) == 2)
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
            if(basic_tool::stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(basic_tool::stoi(str2)) == puzzle.MATCH)
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
            else if(basic_tool::stoi(str2) == 2)
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
            if(basic_tool::stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(basic_tool::stoi(str2)) == puzzle.MATCH)
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
            else if(basic_tool::stoi(str2) == 2)
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
            if(basic_tool::stoi(str1) == 1)
            {
                Puzzle puzzle;
                bash.show_puzzle();
                cnt = 3;
                while(cnt--)
                {
                    std::cin >> str2;
                    if(puzzle.solve(basic_tool::stoi(str2)) == puzzle.MATCH)
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
            else if(basic_tool::stoi(str2) == 2)
            {
                break;
            }
        }
    }
}
int Game::opt_negtiveEvent()
{

    switch(misfortunes.continue_sickEvent())
    {
    case 0:
        bash.pop_memberDead(player.get_leaderName());
        break;
    case 1:
        bash.pop_memberDead(player.get_member1Name());
        break;
    case 2:
        bash.pop_memberDead(player.get_member2Name());
        break;
    case 3:
        bash.pop_memberDead(player.get_member3Name());
        break;
    case 4:
        bash.pop_memberDead(player.get_member4Name());
        break;
    default:
        break;
    }

    if(misfortunes.get_misfortunes() == misfortunes.NOTHAPPENED)
    {
        return 0;
    }

    switch(misfortunes.get_eventType())
    {
    case misfortunes.EVENT_SOMEBODY_SICK:
        switch(misfortunes.eventGenerate_somebodyGetSick())
        {
        case 0:
            bash.pop_memberSick(player.get_leaderName());
            break;
        case 1:
            bash.pop_memberSick(player.get_member1Name());
            break;
        case 2:
            bash.pop_memberSick(player.get_member2Name());
            break;
        case 3:
            bash.pop_memberSick(player.get_member3Name());
            break;
        case 4:
            bash.pop_memberSick(player.get_member4Name());
            break;
        default:
            break;
        }
        break;
    default:
            break;
    }
}
int Game::isGameOver()
{
    if(player.get_food() <= 0 || player.get_oxen() <= 0 || time.isBehindSchedule())
    {
        bash.game_over();
        return 0;
    }
    return 1;
}
#endif // GAME_CPP
