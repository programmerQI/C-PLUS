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
    return this->ratings[index];
}
void User::setRatingAt(int index, int value)
{
    this->ratings[index]=value;
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

















