#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

double simScore(string str1, string str2)
{
    int size_str1=str1.length();
    int size_str2=str2.length();

    if(size_str1 != size_str2 || size_str1 == 0)
    {
        return 0;
    }

    double ss;

    int i;
    int cnt=0;

    for(i=0;i<size_str1;i++)
    {
        if(str1[i]!=str2[i])
        {
            cnt++;
        }
    }

    return (size_str1-cnt)*1.0/size_str1;
}

int main()
{
    printf("%.2f\n",simScore("ACCT","ACCG"));
    return 0;
}
