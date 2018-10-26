#include<iostream>
using namespace std;
int getDigitCount(string str)
{
    int cnt=0; // set a count variable
    for(int i=0;i<str.length();i++) // search from the first character of the string to the last
    {
        if(str.at(i)>='0' && str.at(i)<='9') // if the character is a number, count ++
        {
            cnt++;
        }
    }
    return cnt; // return the count variable
}
int main()
{
    cout << getDigitCount("my1234my") << endl;  //test data 1
    cout << getDigitCount("1m2m4m5m") << endl;  //test data 2
    return 0;
}
