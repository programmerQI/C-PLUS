#include<iostream>
using namespace std;
void printSquares(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0; j<2*n; j++) // print each line
        {
            if(i>0&&i<n-1&&j>n&&j<2*n-1) //print the space
            {
                printf(" ");
            }
            else
            {
                printf("*"); // print the "*"
            }
            if(j==n-1) //print the space between two rectangular
            {
                printf(" ");
            }
        }
        if(i<n-1) // print
        {
            printf("\n");
        }
    }
}
int main()
{
    printSquares(5); //test data 1
    printSquares(4); //test data 2
    return 0;
}
