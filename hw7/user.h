#ifndef USER_H
#define USER_H
#include<string>
class User
{
private:

    const static int SIZE = 200;

    std::string username;
    int ratings[SIZE];
    int numRatings;

public:
    User();
    User(std::string username, int rating[], int numRatings);
    std::string getUsername();
    void setUsername(std::string);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatings);
    int getSize();
};
#endif // USER_H
