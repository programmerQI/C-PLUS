#ifndef USER_CPP
#define USER_CPP
#include<string>
using namespace std;
User::User()
{
    this->username = "";
    this->numRating = 0;
    for(int i = 0 ; i < this->SIZE ; i++)
    {
        this->ratings[i] = -1;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    if(numRatings>this->SIZE)
    {
        return -1;
    }
    this->username = username;
    this->ratings = ratings;
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
int getRatingAt(int index)
{
    return this->ratings[index];
}


#endif // USER_CPP
