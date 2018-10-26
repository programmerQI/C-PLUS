#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int getScores(string str, int scores[], int size)
{
    char c = ' ';
    int size_str = str.length();

    int i,j;
    int p,cnt;
    p = cnt = 0;

    string tmp;
    for(i=0;i<size_str; i++)
    {
        if(str[i]==c)
        {
            if(i!=p)
            {
                tmp = str.substr(p,i-p);
                scores[cnt++] = atoi(tmp.c_str());
            }

            p = i + 1;
        }
    }

    if(str[size_str-1]!= c)
    {
        tmp = str.substr(p,size_str);
        scores[cnt++] = atoi(tmp.c_str());
    }

    for(i=0;i<cnt;i++)
    {
        cout << scores[i] << "\n" << endl;
    }

    return cnt;
}

int main()
{
    string str = "   ";
    char c = ' ';
    int scores[100];

    printf("%d",getScores(str,scores,100));

    return 0;
}
