#include<iostream>
using namespace std;
void printMultiples(int a, int m)
{
    int i = 1;
    while( a * i <= m ) // print all the multiples of "a" that less than the given number "m"
    {
        cout << a * i << endl;
        i++;
    }
}
int main()
{
    printMultiples(3,10); //test data 1
    printMultiples(2,10); //test data 2
    return 0;
}
