#ifndef USER_CPP
#define USER_CPP
#include<string>
using namespace std;
User::User()
{
    this->username = "";
    this->numRatings = 0;
    for(int i = 0 ; i < this->SIZE ; i++)
    {
        this->ratings[i] = -1;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    if(numRatings>this->SIZE)
    {
        return;
    }
    for( int i = 0 ; i < numRatings ; i ++)
    {
        this->ratings[i] = ratings[i];
    }
    this->username = username;
    this->numRatings = numRatings;
}
string User::getUsername()
{
    return this->username;
}
void User::setUsername(string username)
{
    this->username = username;
}
int User::getRatingAt(int index)
{
    if(index<0||index >= this->numRatings)
    {
        return -1;
    }
    return this->ratings[index];
}
bool User::setRatingAt(int index, int value)
{
    if(value>5||value<0||index<0||index>=this->numRatings)
    {
        return false;
    }
    this->ratings[index]=value;
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

#endif // USER_CPP

















