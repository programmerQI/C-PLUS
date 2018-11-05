#ifndef LIBRARY_CPP
#define LIBRARY_CPP
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
#include "Library.h"
#include "Split.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

inline int square(int a)
{
    return a*a;
}

int compare(string str1,string str2)
{
    if(str1.length()!=str2.length())
    {
        return 0;
    }

    int i;
    while(str1[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }

    return 1;
}

Library::Library()
{
    this->numBooks = 0;
    this->numUsers = 0;
}

int Library::readBooks(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        fin.close();
        return -1;
    }


    string strs[10];
    string line = "";
    int cnt = 0;
    while(getline(fin,line) && this->numBooks < this->SIZE_BOOK)
    {
        split(line,',',strs,5);
        this->books[this->numBooks].setAuthor(strs[0]);
        this->books[this->numBooks].setTitle(strs[1]);
        this->numBooks++;
        cnt ++;
    }

    fin.close();
    return cnt;
}

int Library::readRatings(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        fin.close();
        return -1;
    }

    string strs[10];
    string line = "";
    int cnt = 0;
    int cnt_rt,i;
    char c;
    while( getline(fin,line) && this->numUsers < this->SIZE_USER)
    {
        cnt_rt = i = 0;
        split(line,',',strs,5);
        this->users[this->numUsers].setUsername(strs[0]);
        while(strs[0][i]!='\0')
        {
            c = strs[0][i];
            if(c >= '0' && c <= '9')
            {
                this->users[this->numUsers].setRatingAt(cnt_rt,c-'0');
                cnt_rt++;
            }
            i++;
        }
        users[this->numUsers].setNumRatings(cnt_rt);
        this->numUsers++;
        cnt++;
    }

    fin.close();
    return cnt;
}

void Library::printAllBooks()
{
    if(this->numBooks==0)
    {
        cout << "" << endl;
        return;
    }

    cout << "" << endl;

    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        cout << "" << endl;
    }

    return;
}

int Library::getCountReadBooks(string uname)
{
    int cnt = 0;

    User tmp;
    int n;
    for( int i = 0 ; i < this->numUsers ; i ++)
    {
        tmp = users[i];
        if(uname.compare(tmp.getUsername())==0)
        {
            n = tmp.getNumRatings();
            for(int j = 0 ; j < n ; j ++ )
            {
                if(tmp.getRatingAt(j)>0)
                {
                    cnt++;
                }
            }
            return cnt;
        }
    }

    return -1;
}

double Library::calcAvgRating(string title)
{
    int sum = 0;
    int cnt = 0;

    int rt;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        if(title.compare(books[i].getTitle())==0)
        {
            for(int j = 0 ; j < this->numUsers ; j++ )
            {
                rt = users[j].getRatingAt(i);
                if(rt>0)
                {
                    sum += rt;
                    cnt ++;
                }
            }
            return 1.0*sum/cnt;
        }
    }

    return -1;
}

bool Library::addUser(string uname)
{
    if(this->numUsers < this->SIZE_USER)
    {
        cout << "" << endl;
        return false;
    }

    for(int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            cout << "" << endl;
            return false;
        }
    }

    users[this->numUsers].setUsername(uname);
    users[this->numUsers].setNumRatings(0);

    return true;
}

bool Library::checkOutBook(string uname, string title, int rating)
{
    if(this->numBooks==0)
    {
        cout << ""  << endl;
        return false;
    }

    int u_id = -1;;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        cout << "" << endl;
        return false;
    }

    for( int i = 0 ; i < this->numBooks ; i++ )
    {
        if(compare(title,books[i].getTitle()))
        {
            users[u_id].setRatingAt(i,rating);
            return true;
        }
    }

    cout << "" << endl;
    return false;
}

void Library::viewRatings(string uname)
{
    if(this->numBooks==0)
    {
        cout << ""  << endl;
        return;
    }

    int u_id = -1;;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        cout << "" << endl;
        return;
    }

    User tmp = users[u_id];
    if(tmp.getNumRatings()==0)
    {
        cout << "" << endl;
        return;
    }

    int rt;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        rt = tmp.getRatingAt(i);
        if(rt != 0)
        {
            cout << "" << endl;
            cout << "" << endl;
        }
    }

    return;
}

void Library::getRecommendations(string uname)
{
    if(this->numBooks==0)
    {
        cout << ""  << endl;
        return;
    }

    int u_id = -1;;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        cout << "" << endl;
        return;
    }

    int m = 0x7fffffff;
    int simuser_id = 0;
    User tmp = users[u_id];
    int sum;
    for(int i = 0 ; i < this->numUsers ; i++)
    {
        if(i == u_id || users[i].getNumRatings() == 0)
        {
            continue;
        }
        sum = 0;
        for(int j = 0 ; j < this->numBooks ; j ++)
        {
            sum = sum + square(tmp.getRatingAt(j)-users[i].getRatingAt(j));
        }
        if(m>sum)
        {
            m = sum;
            simuser_id = i;
        }
    }

    User simuser = users[simuser_id];
    int cnt = 0;
    int tur,sur;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        tur = tmp.getRatingAt(i);
        sur = simuser.getRatingAt(i);
        if(tur==0 && (sur==3||sur==4||sur==5))
        {
            if(cnt!=0)
            {
                cout << ",";
            }
            cout << "" << endl;
        }
        if(cnt == 5)
        {
            return;
        }
    }

    return;
}

#endif // LIBRARY_CPP



















