#include<iostream>
#include<string>
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
//#include "Library.h"
//#include "Library.cpp"
using namespace std;

int test(string str[])
{
    str[0] = "WOSHI";
    return 1;
}
int abs(int a)
{
    if(a<0)
    {
        return -a;
    }
    return a;
}
int compare(string str1,string str2)
{

        cout << "xxx" << endl;
    if(str1.length()!=str2.length())
    {
        cout << "xxx" << endl;
        return 0;
    }

    int i=0;
    while(str1[i]!='\0')
    {
        if(!(str1[i]==str2[i]||abs(str1[i]-str2[i])==32))
        {

            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    Book book;
    User user;
    //Library lib;
    /*string str = "asdf,12313,ppppp";
    string strs[10];
    split(str,',',strs,10);
    cout << strs[0] << endl;
    cout << strs[1] << endl;
    cout << strs[2] << endl;*/
    cout << 'A' - 'a' << endl;
    cout << 'B' - 'b' << endl;
    cout << compare("BEN","ben") << endl;
}
