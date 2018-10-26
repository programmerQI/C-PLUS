#include<iostream>
#include<string>
#include "book.h"
std::string Book::getTitle()
{
    return this->title;
}
void Book::setTitle(std::string title)
{
    this->title = title;
}
std::string Book::getAuthor()
{
    return this->author;
}
void Book::setAuthor(std::string author)
{
    this->author = author;
}
