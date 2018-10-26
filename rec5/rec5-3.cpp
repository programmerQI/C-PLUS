#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int getMatchCount(string sub, string str)
{
    int size_sub = sub.length();
    int size_str = str.length();

    if(size_sub==0||size_str==0)
    {
        return -1;
    }

    if(size_sub>size_str)
    {
        return -2;
    }

    int cnt=0;
    int i,j;
    int flag;

    for(i=0;i<size_str;i++)
    {
        if(str[i]==sub[0])
        {
            flag=1;
            for(j=0;j<size_sub;j++)
            {
                if(str[i+j]!=sub[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    string str1="asdfqiqiqasdfqiqasdf";
    string str2="qiq";
    printf("%d\n",getMatchCount(str2,str1));
    return 0;
}
