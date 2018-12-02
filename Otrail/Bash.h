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

    char askShoppingItem[100][100] = {"buy what? :"};

    char askShoppingAmount[100][100] = {"buy how many? :"};

    char noEnoughMoney[100][100] = {"you don't have enough money!"};

    char todoList[100][100] = {"chose your action:",
                               "1. rest.",
                               "2. go.",
                               "3. hunt.",
                               "3. quit."};

public:

    const static int SUCCESS = 1;
    const static int FAIL_TO_OPEN_FILE = -1;

    Bash();

    void show_startGameMenu();

    void say_goodBye();

    void ask_leaderName();

    void ask_memberName();

    void ask_shoppingItem();

    void ask_shoppingAmount();

    void no_enoughMoney();

    void show_todoList();

    void plyerCurrent_info();

    void show_storeInfo(Store store);

    void show_playersMoney(Player player);

    int print_notation(const char *path);
};
#endif // BASH_H
