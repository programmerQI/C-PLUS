#include<iostream>
#include<stdio.h>
using namespace std;

int split(string str, char c, string strs[], int size)
{

    int size_str = str.length();

    int i,j;

    int p , cnt;

    p = cnt = 0;

    for(i=0;i<size_str;i++)
    {
        if(str[i]==c)
        {
            if(i!=p)
            {
                strs[cnt++] = str.substr(p,i-p);
            }
            p = i + 1;
        }
    }

    if(str[size_str - 1]!=c)
    {
        strs[cnt++] = str.substr(p,size_str-1);
    }

    for(i=0;i<cnt;i++)
    {
        cout << strs[i] << "\n" << endl;
    }

    return cnt;
}

int main()
{
    string str = "ASD ASB YSB";
    char c = ' ';
    string strs[6];
    int size = 6;

    printf("%d\n",split(str,c,strs,6));

    return 0;
}
