#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User
{
private:
    const static int SIZE = 200;
    string username;
    int ratings[SIZE];
    int numRatings;
public:
    User();
    User(string username, int ratings[], int numRatings);
    string getUsername();
    void setUsername(string username);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatings);
    int getSize();
};
#endif // USER_H
