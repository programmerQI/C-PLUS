#include<iostream>
using namespace std;
void numberSign(int a)
{
    if(a>0) // when a is a positive number
    {
        cout << "positive" << endl; // print "positive"
    }
    else if (a==0) // when a is equal to zero
    {
        cout << "zero" << endl; // print "zero
    }
    else // otherwise it must be a negative number
    {
        cout << "negative" << endl; // print "negative"
    }
}
int main()
{
    numberSign(10); // test data 10, expect "positive"
    numberSign(0); // test data 10, expect "zero"
    numberSign(-10); // test data 10, expect "negative"
    return 0;
}
