// CSCI1300 Fall 2018
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Project1







///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining on how you are approaching the problem, step by step
///////////////////////////////////////////////////////////////////////////////////////////////////

/*

Your algorithm goes into here


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

//setting global variables of user's total points and computer's total points
const int player = 0;
const int comoputer = 1;

int points[3];

//this function is for initiating the game
int init()
{
    int i;
    for(i=0;i<sizeof(points)/sizeof(int);i++)
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

// your 3 + functions go in here

/**
 * game
 * driver function to play the game
 * the function does not return any value
 */

void game()
{
    char input[500];
    while(printf("Please decide Rolling or Hold!\n"),scanf("%s",input)!=EOF)
    {
        if(strcmp(input,"rolling")==0 || strcmp(input,"Rolling")==0)
        {
            printf("xxx\n");
        }
        else if(strcmp(input,"hold")==0 || strcmp(input,"Hold")==0)
        {
            printf("%d",sizeof(points)/sizeof(int));
            printf("yyyy\n");
        }
        else
        {
            printf("Please retype your decision.");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main.
// Once you finished please paste your code above this line
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game!
	game();
	return 0;
}
