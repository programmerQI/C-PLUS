#include<iostream>
using namespace std;
void printDiamond(int n)
{
    int i,j,p;
    for(i=0;i<n;i++) // print the first half of diagram
    {
        for(j=0;j<n-1-i;j++) //print the space of each line
        {
            printf(" ");
        }
        for(p=0;p<2*i+1;p++) //print the "*" of each line
        {
            printf("*");
        }
        printf("\n"); // create a new line after printing each line.
    }
    for( i = 0 ; i < n-1; i ++) // print the second half of diagram
    {
        for( j = 0; j <= i ; j++) // print the space of each line
        {
            printf(" ");
        }
        for( p = 0; p < (n-2-i)*2+1; p++) //print * of each line
        {
            printf("*");
        }
        printf("\n"); // create a new line
    }
}
int main()
{
    printDiamond(4); //test data 1
    printDiamond(3); //test data 2
    return 0;
}
