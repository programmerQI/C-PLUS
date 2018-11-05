#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;
class Book
{
private:
    string title;
    string author;
public:
    Book();
    Book(string title, string author);
    string getTitle();
    void setTitle(string title);
    string getAuthor();
    void setAuthor(string author);
};
#endif // BOOK_H
