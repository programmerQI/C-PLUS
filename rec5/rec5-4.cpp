#include<iostream>
#include<string>
using namespace std;

int getLastIndex(char c, string str)
{
    int size_str = str.length(); // get the length of the string

    if(size_str==0) // if it's empty string, return -1
    {
        return -1;
    }

    int i;
    for(i=size_str-1 ; i>=0 ; i--) // search c from the last character of the string to the first, return the first location.
    {
        if(str[i]==c)
        {
            return i;
        }
    }
    return -2;
}

int main()
{
    printf("%d\n",getLastIndex('z',"zebra")); // test data 1
    printf("%d\n",getLastIndex('z',""));     //test data 2
    return 0;
}
