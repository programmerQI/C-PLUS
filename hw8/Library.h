#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
#include <string>
using namespace std;
class Library
{
private:
    const static int SIZE_BOOK = 200;
    const static int SIZE_USER = 200;
    Book books[SIZE_BOOK];
    User users[SIZE_USER];
    int numBooks;
    int numUsers;
public:
    Library();
    int readBooks(string filename);
    int readRatings(string filename);
    void printAllBooks();
    int getCountReadBooks(string uname);
    double calcAvgRating(string title);
    bool addUser(string uname);
    bool checkOutBook(string uname,string title,int rating);
    void viewRatings(string uname);
    void getRecommendations(string uname);
};

#endif // LIBRARY_H
