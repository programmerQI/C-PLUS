#ifndef BOOK_CPP
#define BOOK_CPP
#include<string>
using namespace std;
Book::Book()
{
    this->title = "";
    this->author = "";
}
Book::Book(string title, string author)
{
    this->title = title;
    this->author = author;
}
string Book::getTitle()
{
    return this->title;
}
void Book::setTitle(string title)
{
    this->title = title;
}
string Book::getAuthor()
{
    return this->author;
}
void Book::setAuthor(string author)
{
    this->author = author;
}
#endif // BOOK_CPP
