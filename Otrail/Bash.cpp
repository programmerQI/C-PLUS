#ifndef BASH_CPP
#define BASH_CPP
#include "Bash.h"
#include "Player.h"
#include "Player.cpp"
#include "Store.h"
#include "Store.cpp"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
Bash::Bash()
{

}
void Bash::show_startGameMenu()
{
    int i = 0;
    while(strlen(startGameMenu[i])!=0)
    {
        printf("%s\n",startGameMenu[i++]);
    }
}
void Bash::say_goodBye()
{
    int i = 0;
    while(strlen(sayGoodBye[i])!=0)
    {
        printf("%s\n",sayGoodBye[i++]);
    }
}
void Bash::game_over()
{
    int i = 0;
    while(strlen(gameOver[i])!=0)
    {
        printf("%s\n",gameOver[i++]);
    }
}
void Bash::ask_leaderName()
{
    int i = 0;
    while(strlen(askLeaderName[i])!=0)
    {
        printf("%s\n",askLeaderName[i++]);
    }
}
void Bash::ask_memberName()
{
    int i = 0;
    while(strlen(askMemberName[i])!=0)
    {
        printf("%s\n",askMemberName[i++]);
    }
}
void Bash::chose_departureTime()
{
    int i = 0;
    while(strlen(choseDepartureTime[i])!=0)
    {
        printf("%s\n",choseDepartureTime[i++]);
    }
}
void Bash::ask_shoppingItem()
{
    int i = 0;
    while(strlen(askShoppingItem[i])!=0)
    {
        printf("%s\n",askShoppingItem[i++]);
    }
}
void Bash::ask_shoppingAmount()
{
    int i = 0;
    while(strlen(askShoppingAmount[i])!=0)
    {
        printf("%s\n",askShoppingAmount[i++]);
    }
}
void Bash::no_enoughMoney()
{
    int i = 0;
    while(strlen(noEnoughMoney[i])!=0)
    {
        printf("%s\n",noEnoughMoney[i++]);
    }
}
void Bash::show_todoList()
{
    int i = 0;
    while(strlen(todoList[i])!=0)
    {
        printf("%s\n",todoList[i++]);
    }
}
void Bash::encounter_rabbit()
{
    int i = 0;
    while(strlen(encounterRabbit[i])!=0)
    {
        printf("%s\n",encounterRabbit[i++]);
    }
}
void Bash::encounter_fox()
{
    int i = 0;
    while(strlen(encounterFox[i])!=0)
    {
        printf("%s\n",encounterFox[i++]);
    }
}
void Bash::encounter_deer()
{
    int i = 0;
    while(strlen(encounterDeer[i])!=0)
    {
        printf("%s\n",encounterDeer[i++]);
    }
}
void Bash::encounter_beer()
{
    int i = 0;
    while(strlen(encounterBeer[i])!=0)
    {
        printf("%s\n",encounterBeer[i++]);
    }
}
void Bash::encounter_moose()
{
    int i = 0;
    while(strlen(encounterMoose[i])!=0)
    {
        printf("%s\n",encounterMoose[i++]);
    }
}
void Bash::show_huntSuccess()
{
    int i = 0;
    while(strlen(showHuntSuccess[i])!=0)
    {
        printf("%s\n",showHuntSuccess[i++]);
    }
}
void Bash::no_enoughBullets()
{
    int i = 0;
    while(strlen(noEnoughBullets[i])!=0)
    {
        printf("%s\n",noEnoughBullets[i++]);
    }
}
void Bash::show_puzzle()
{
    int i = 0;
    while(strlen(showPuzzle[i])!=0)
    {
        printf("%s\n",showPuzzle[i++]);
    }
}
void Bash::show_puzzleMatch()
{
    int i = 0;
    while(strlen(showPuzzleMatch[i])!=0)
    {
        printf("%s\n",showPuzzleMatch[i++]);
    }
}
void Bash::show_puzzleNotMatch()
{
    int i = 0;
    while(strlen(showPuzzleNotMatch[i])!=0)
    {
        printf("%s\n",showPuzzleNotMatch[i++]);
    }
}
void Bash::show_playerCurrentInfo(Player player)
{

}
void Bash::show_travelInfo(int month, int date, int mileage)
{
    std::cout << "--Month : " << month << " Date : " << date << "--" << std::endl;
    std::cout << "--Mileage : " << mileage << std::endl;
}
void Bash::pop_memberDead(std::string name)
{
    std::cout << name << " " << "dead!" << std::endl;
}
void Bash::pop_memberSick(std::string name)
{
    std::cout << name << " " << "sick!" << std::endl;
}
void Bash::pop_stoneInfo(std::string name)
{
    std::cout << "Cross " << name << "!" << std::endl;
}
void Bash::show_storeInfo(Store store)
{
    std::cout << "**Store**" << std::endl;
    std::cout << "1. oxen " << store.get_oxenPrice() << std::endl;
    std::cout << "2. food " << store.get_foodPrice() << std::endl;
    std::cout << "3. bullets " << store.get_bulletsPrice() << std::endl;
    std::cout << "4. wagonPart " << store.get_wagonPartPrice() << std::endl;
    std::cout << "5. medicalKit " << store.get_medicalKitPrice() << std::endl;
    std::cout << "6. done " << std::endl;
}
void Bash::show_playersMoney(Player player)
{
    std::cout << "your money: " << player.get_money() << std::endl;
}
int Bash::print_notation(const char *path)
{
    std::cout << "there it is" << std::endl;

    std::ifstream file;
    file.open(path);
    if(!file.is_open())
    {
        file.close();
        return FAIL_TO_OPEN_FILE;
    }

    char str[1000];
    while(file.getline(str,1000))
    {
        printf("%s\n",str);
    }

    file.close();
    return SUCCESS;
}
#endif // BASH_CPP
