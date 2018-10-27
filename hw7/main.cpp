#include "book.h"
#include "book.cpp"
#include "user.h"
#include "user.cpp"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int findC(string str, char c)
{
    int len_str = str.length();
    if(len_str==0)
    {
        return -2;
    }

    for(int i = 0 ; i < len_str ;i++)
    {
        if(str[i]==c)
        {
            return i;
        }
    }
    return -1;
}

int split(string str, string *str1, string *str2)
{
    int len_str = str.length();
    if( len_str == 0 || str1 == NULL || str2 == NULL )
    {
        return -1;
    }
    int mark = findC(str,',');
    *str1 = str.substr(0,mark);
    *str2 = str.substr(mark+1,len_str-mark-1);
    return 1;
}

int readBooks(string fn, Book books[], int bk_n, int cp)
{
    ifstream in;
    in.open(fn.c_str());
    if(!in.is_open())
    {
        in.close();
        return -1;
    }

    string str = "";
    string str_title;
    string str_author;
    int cnt = 0;

    while(getline(in,str))
    {
        split(str,&str_author,&str_title);
        books[cnt].setAuthor(str_author);
        books[cnt].setTitle(str_title);
        cnt++;
    }

    in.close();
    return cnt;

}

int readRatings(string fn, User users[], int us_u, int cp)
{

}



int main()
{
    Book books[100];
    User users[100];

    string filename = "book.txt";
    int numbooks = 0;


    return 0;
}
