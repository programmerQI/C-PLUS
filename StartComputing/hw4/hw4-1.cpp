#include<iostream>
using namespace std;
void printEvenNums(int a)
{
    int i;
    for(i = 1 ; i <= a ; i ++) //print all the number that meet the requirement
    {
        if(i%2==0)
        {
            cout << i << endl;
        }
    }
}
int main()
{
    printEvenNums(10);
    printEvenNums(8);
    return 0;
}
