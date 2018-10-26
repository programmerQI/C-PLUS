#ifndef BOOK_H
#define BOOK_H
#include<string>
class Book
{
private:
    std::string title;
    std::string author;
public:
    std::string getTitle();
    void setTitle(std::string title);
    std::string getAuthor();
    void setAuthor(std::string author);
};
#endif // BOOK_H
