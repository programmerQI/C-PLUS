#include<iostream>
#include<stdio.h>
using namespace std;
int IsAllAlpha(string str)
{
    if(str.length()==0)
    {
        return -1;
    }

    int i,j;
    i= 0;

    while(str[i]!='\0')
    {
        if(!(str[i]>='a'&&str[i]<='z')&&!(str[i]>='A'&&str[i]<='Z'))
        {
            return 0;
        }
    }
    i++;
    return 1;
}
int main()
{
    int i;
    for(i=0;i<26;i++)
    {
        printf("%c",'A'+i);
    }
    return 0;
}
