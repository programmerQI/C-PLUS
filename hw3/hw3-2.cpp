#include<iostream>
using namespace std;
int error = -1; // set value -1 as the sign of unexpected output
double calcPay(double h, double s)
{
    if( h<0 || s <0 ) // when the input is illegal , return -1 which is an imposble output, which means error.
    {
        return -1;
    }
    if(h<=40) // when the total worked hours is less than or equal to 40 hours.
    {
        return h*s; // return the total pay
    }
    else // when it more than 40 hours
    {
        return 40*s+(h-40)*1.5*s; // return total pay.
    }
}
int main()
{
    printf("%.2f\n",calcPay(41,10)); //input 41 hours and 10 per hour, expect 415.00
    printf("%.2f\n",calcPay(40,10)); //input 41 hours and 10 per hour, expect 400.00
    printf("%.2f\n",calcPay(30,10)); //input 41 hours and 10 per hour, expect 300.00
    printf("%.2f\n",calcPay(-1,-1)); //input 41 hours and 10 per hour, expect -1.00
    return 0;
}
