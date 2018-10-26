#include<iostream>
#include<string>
#include "user.h"
/*User();
User(std::string username, int rating[], int numRatings);
std::string getUsername();
void setUsername(std::string);
int getRatingAt(int index);
bool setRatingAt(int index, int value);
int getNumRatings();
void setNumRatings(int numRatings);
int getSize();*/
User::User()
{
    this->username = "";
    this->numRatings = 0;
    this->SIZE = 200;
    for(int i = 0 ; i < this->SIZE ; i ++)
    {
        ratings[i] = -1;
    }
}
User::User(std::string name, int rating[], int numRatings)
{
    this->name = name;
    this->numRatings = numRatings;
    for(int i = 0 ; i < this->numRatings ; i++)
    {
        this->rating[]
    }
}
