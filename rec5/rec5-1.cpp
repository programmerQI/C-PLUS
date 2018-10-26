#include<iostream>
#include<string>
using namespace std;

int getWordCount(string str)
{

    if(str.length()==0) // if it is an empty string return 0;
    {
        return 0;
    }

    int i,cnt=0;
    for(i=0;i<str.length();i++) //search from the first character to the last
    {
        if(str.at(i)==' ') // count how many times the space character shows
        {
            cnt++;
        }
    }

    return cnt+1; // the cnt + 1 would be the total words counts.
}
int main()
{

    cout << getWordCount("I am QI WANG") << endl; // test data 1
    cout << getWordCount(""); // test data 2

    return 0;
}
