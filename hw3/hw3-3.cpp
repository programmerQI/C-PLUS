#include<iostream>
using namespace std;
int checkLeapYear(int y)
{
    if ( y <= 1582 && y%4 == 0 )
    {
        return 1;
    }
    else if( y%4 == 0 && y%100 != 0 || y%400 == 0 ) // After 1582, when the year can be divide by 4 and not by 100 or by 400, it must be leap year.
    {
        return 1; //return 1
    }
    return 0;
}
int main()
{
    printf("%d",checkLeapYear(1500)); // input 1500, expect 1;
    printf("%d",checkLeapYear(1616)); // input 1616, expect 1;
    printf("%d",checkLeapYear(1501)); // input 1616, expect 0;
    printf("%d",checkLeapYear(1600)); // input 1616, expect 1;
    return 0;
}
