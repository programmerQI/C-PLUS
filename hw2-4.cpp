#include<iostream>
#include<cmath>
using namespace std;
int luminosity(double b, double d)
{
    double ans; // set a double to store the answer.

    ans = 4.0 * 3.14159 * b * pow(d, 2); // use the algorithm to get the answer.

    return ans; // return an integer.
}
int main()
{

    cout << luminosity (0.254, 1.97) << endl; // test data 1. input data (0.254, 1.97). expect result 12. correct result.

    cout << luminosity (9.16, 1.11) << endl; // test data 2. input data (9.16, 1.11). expect result 141. correct result.

    return 0;
}
