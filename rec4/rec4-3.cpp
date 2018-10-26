#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
int getMatchCount(string sub, string str)
{
    int size_sub = sub.length(); // get the length of the substring and the string;
    int size_str = str.length();

    if(size_sub==0||size_str==0) // if either string is empty, return -1;
    {
        return -1;
    }

    if(size_sub>size_str) // if the length of substring if longer than the target string, return -2;
    {
        return -2;
    }

    int cnt=0; // count how many times the substring shows

    int i,j;
    int flag;

    for(i=0;i<size_str;i++) // search from the first character of target string.
    {
        if(str[i]==sub[0]) // if found a character that is same as the first character of the substring, continue to compare the following character.
        {
            flag=1;
            for(j=0;j<size_sub;j++)
            {
                if(str[i+j]!=sub[j]) // if the any following character is not matched, mark flag as '0'.
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1) // if all the following character is matched, count variable plus one;
            {
                cnt++;
            }
        }
    }
    return cnt; // return the count.
}
int main()
{
    string str1="asdfqiqiqasdfqiqasdf";
    string str2="qiq";
    printf("%d\n",getMatchCount(str2,str1)); //test data1
    return 0;
}
