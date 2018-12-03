#ifndef BASH_H
#define BASH_H
#include "Store.h"
#include "Store.cpp"
#include "Player.h"
#include "Player.cpp"
class Bash
{

private:

    char startGameMenu[100][100] = {"***Oregon Trail***",
                                    "1. Start the game.",
                                    "2. Exit.",
                                    "select:"};

    char sayGoodBye[100][100] = {"Good Bye!"};

    char askLeaderName[100][100] = {"please entering the leader's name:"};

    char askMemberName[100][100] = {"please entering the four members' name:"};

    char choseDepartureTime[100][100] = {"You are going to travel from Independence, Missouri to Oregon City (2040 miles)",
                                         "by the end of fall(November 30th, 1847).",
                                         "Please select a time(between 03/01/1847 and 05/01/1847) you want to depart.",
                                         "month(3~5):",
                                         "date(0~31):"};

    char askShoppingItem[100][100] = {"buy what? :"};

    char askShoppingAmount[100][100] = {"buy how many? :"};

    char noEnoughMoney[100][100] = {"you don't have enough money!"};

    char todoList[100][100] = {"chose your action:",
                               "1. rest.",
                               "2. go.",
                               "3. hunt.",
                               "4. quit."};

    char encounterRabbit[100][100] = {"you got lucky!",
                                      "you encountered a rabbit!",
                                      "take 10 bullets, get 2 food",
                                      "do you want to hunt?",
                                      "1. yes.",
                                      "2. no."};

    char encounterFox[100][100] = {"you got lucky!",
                                      "you encountered a fox!",
                                      "",
                                      "do you want to hunt?",
                                      "1. yes.",
                                      "2. no."};

    char encounterDeer[100][100] = {"you got lucky!",
                                      "you encountered a deer!",
                                      "do you want to hunt?",
                                      "1. yes.",
                                      "2. no."};

    char encounterBeer[100][100] = {"you got lucky!",
                                      "you encountered a beer!",
                                      "do you want to hunt?",
                                      "1. yes.",
                                      "2. no."};

    char encounterMoose[100][100] = {"you got lucky!",
                                      "you encountered a moose!",
                                      "do you want to hunt?",
                                      "1. yes.",
                                      "2. no."};

    char showHuntSuccess[100][100] = {"Success!"};

    char noEnoughBullets[100][100] = {"you don't have enough bullets!"};

    char showPuzzle[100][100] = {"please guess a number between 1~10.",
                                  "you have three chances:"};

    char showPuzzleMatch[100][100] = {"right"};

    char showPuzzleNotMatch[100][100] = {"wrong"};



public:

    const static int SUCCESS = 1;
    const static int FAIL_TO_OPEN_FILE = -1;

    Bash();

    void show_startGameMenu();

    void say_goodBye();

    void ask_leaderName();

    void ask_memberName();

    void chose_departureTime();

    void ask_shoppingItem();

    void ask_shoppingAmount();

    void no_enoughMoney();

    void show_todoList();

    void encounter_rabbit();

    void encounter_fox();

    void encounter_deer();

    void encounter_beer();

    void encounter_moose();

    void show_huntSuccess();

    void no_enoughBullets();

    void show_puzzle();

    void show_puzzleMatch();

    void show_puzzleNotMatch();

    void plyerCurrent_info();

    void show_storeInfo(Store store);

    void show_playersMoney(Player player);

    int print_notation(const char *path);
};
#endif // BASH_H
