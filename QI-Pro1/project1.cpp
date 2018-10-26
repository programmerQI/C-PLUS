// CSCI1300 Fall 2018
// Author: <QI WANG>
// Recitation: <200> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/qiwa3476/csci1300>
// Project 1







///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// 1. create variables to store players' points.
// 2. create a function that change players' points base on the rule.
// 3. create a function that interact with players.
// 4. make a visual player.
// 5. check if the points get to 100.
///////////////////////////////////////////////////////////////////////////////////////////////////

/*
use if/else to decide how the points change.
*/


///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up!
// After finishing up your pseudocode, translate them into c++
// IMPORTANT: rollDice() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const int TOTALPLAYERS = 2;//How many players in the game

const int ID_COMPUTER = 0;//the computer's id
const int ID_PLATER = 1;//the player 1 's id

int points[TOTALPLAYERS];//storage all the players' points.


int initGame()//initiate the game.
{
    int i;
    for(i=0;i<TOTALPLAYERS;i++)//all the players points change to 0.
    {
        points[i]=0;
    }
    return 1;
}
/**
 * rollDice
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDice()
{
	return random() % 6 + 1;
}


int changePoints(int id, int d) //change the player's points base on player's id and the dice he rolled.
{
    if(d==2 || d==4 || d==5)//get points
    {
        points[id]+=d;
    }
    else if(d==1 || d==6)//points change to 0
    {
        points[id] = 0;
    }
    else if(d == 3)//points change to 15
    {
        points[id] = 15;
    }

    printf("%d",points[id]);//print

    return 1;
}

int checkPoint(int id) //check if the player gets win base on player's ID.
{
    if(points[id]>=100)
        return 1;
    else
        return 0;
}

/**
 * game
 * driver function to play the game
 * the function does not return any value
 */

void game()
{

    char input[500];
    int d;

    while(printf("**Please decide Rolling or Hold!\n-"),scanf("%s",input)!=EOF)
    {

        if(strcmp(input,"Rolling")==0)
        {
            d=rollDice();
            printf("->You rolled %d.\n",d);

            printf("  Your points now are ");
            changePoints(ID_PLATER,d);
            printf("!\n");

            if(checkPoint(ID_PLATER))
            {
                printf("***********************************");
                printf("***Congrats! You get 100 Points!***");
                printf("***********************************");
                break;
            }
        }
        else if (strcmp(input,"Hold")==0)
        {

        }
        else
        {
            printf("!!Please type it again!");
            continue;
        }

        d=rollDice();
        printf("->>Computer rolled %d.\n",d);

        printf("   Computer's points now are ");
        changePoints(ID_COMPUTER,d);
        printf("!\n");

        if(checkPoint(ID_COMPUTER))
        {
            printf("+++++++++++++++++++++++++++++++++++");
            printf("+++++Computer gets 100 Points!+++++");
            printf("+++++++++++++++++++++++++++++++++++");
            break;
        }

    }
}


int main()
{
    char input[500];
    while((printf("Type Ready starting the game.\n"),scanf("%s",input)!=EOF)&&strcmp(input,"Ready")==0)
    {
        initGame();
        game();
    }
	return 0;
}
