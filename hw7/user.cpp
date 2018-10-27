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
    for(int i = 0 ; i < this->SIZE ; i ++)
    {
        this->ratings[i] = -1;
    }
}

User::User(std::string name, int ratings[], int numRatings)
{
    this->username = name;
    this->numRatings = numRatings;
    if(numRatings<=SIZE)
    {
        for(int i = 0 ; i < this->numRatings ; i++)
        {
            this->ratings[i] = ratings[i];
        }

    }
}

std::string User::getUsername()
{
    return this->username;
}

void User::setUsername(std::string username)
{
    this->username = username;
}

int User::getRatingAt(int index)
{
    if(index>=SIZE)
    {
        return -1;
    }
    return this->ratings[index];
}

bool User::setRatingAt(int index, int value)
{
    if(value<0 || value>5)
    {
        return false;
    }
    this->ratings[index] = value;
    return true;
}

int User::getNumRatings()
{
    return this->numRatings;
}

void User::setNumRatings(int numRatings)
{
    this->numRatings = numRatings;
}

int User::getSize()
{
    return this->SIZE;
}
