#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Player.cpp"
#include "Bash.h"
#include "Bash.cpp"
#include "Misfortunes.h"
#include "Misfortunes.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
struct Date
{
    int month;
    int date;
};
struct Stone
{
    std::string name;
    int mileage;
    int type;
};
class Time
{

private:

    int timeTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year;
    Date start;
    Date deadLine;

public:

    const static int NOTVALID = 0;
    const static int SUCCESS = 1;

    Time()
    {
        year = 1847;
        deadLine.month = 11;
        deadLine.date = 20;
    }

    int setStart(int month, int date)
    {

        //std::cout << month << "++" << date << std::endl;
        if(month < 3 || month > 5)
        {
            return NOTVALID;
        }
        if(date > timeTable[month] || date < 0)
        {
            return NOTVALID;
        }
        start.month = month;
        start.date = date;
        return 1;
    }

    int get_currentMonth()
    {
        return start.month;
    }

    int get_currentDate()
    {
        return start.date;
    }

    int rest()
    {
        srand(std::time(NULL));
        start.date += (rand()%3 + 1);

        if(start.date > timeTable[start.month])
        {
            start.date %= timeTable[start.month];
            start.month ++;
        }
        return 1;
    }

    int going()
    {
        start.date += 14;

        if(start.date > timeTable[start.month])
        {
            start.date %= timeTable[start.month];
            start.month ++;
        }
        return 1;
    }

    int hunt()
    {

        start.date += 1;

        if(start.date > timeTable[start.month])
        {
            start.date %= timeTable[start.month];
            start.month ++;
        }
        return 1;
    }

    int isBehindSchedule()
    {
        if(start.month > deadLine.month || start.month == deadLine.month && start.date > deadLine.date)
        {
            return 1;
        }
        return 0;
    }
};
class Puzzle
{
private:
    int number;
public:
    const static int MATCH = 1;
    const static int NOTMATCH = 0;

    Puzzle()
    {
        srand(std::time(NULL));
        number = rand()%10 + 1;
    }

    int solve(int n)
    {
        if( n == number )
        {
            return MATCH;
        }
        return NOTMATCH;
    }
};
class Game
{

private:

    char file1[100] = "notation.txt";
    char file2[100] = "fort-milestones.txt";
    char file3[100] = "river-milestones.txt";

    Time time;
    Bash bash;
    Player player;
    Misfortunes misfortunes;
    int count_stones;
    Stone stones[20];
    std::ifstream in;
    int count_passedMilage;
    int count_passedStore;

public:

    const static int MONEY = 1000;
    const static int DISTANCE = 2040;




    Game();
    int startGame();
    int initGameInfo();
    int takeTurn();
    int consume();
    int shop();
    int rest();
    int go();
    int hunt();
    int opt_negtiveEvent();
    int isGameOver();
    int sortStone();
};
#endif // GAME_H
