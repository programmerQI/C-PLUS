#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int length(string str)
{
    int i=0;
    int cnt = 0;
    while(str[i]!='\0')
    {
        cnt ++;
        i++;
    }
    return cnt;
}


int split(string str, char c, string arr[], int n)
{
    int size_str = str.length();

    if(size_str == 0)
    {
        return 0;
    }

    int i,j;

    int p1, p2;

    p1 = p2 = 0;

    for(i=0; i<size_str; i++)
    {
        if(str[i]==c)
        {
            if(i-p2!=0)
            {
                for(j=0 ; j< i-p2 ; j++)
                {
                    arr[p1].insert(j,1,str.at(p2+j));
                }


                p1 ++;




            }
            p2 = i+1;

        }
    }

    if(str[size_str-1]!=c)
    {
        arr[p1]=str.substr(p2,size_str);
        p1++;
    }



    return p1;
}

int main()
{
    string str1 = "A,";
    char c = ',';
    string arr[6];
    int a = 3;

    printf("%d",split(str1,c,arr,6));


    return 0;
}
