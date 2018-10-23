#include<iostream>
using namespace std;
void population(int a)
{
    int s = 365 * 24 * 3600; // get how many seconds does 365 days have.

    a += (s / 8); // plus how many people birth.

    a -= (s / 12); // mines how many people dead.

    a += (s / 27); // plus immigration.

    cout << a << endl; // print the answer.
}
int main()
{

    population(0); // input 0, expect 248200. answer is correct.

    population(1000000); // input 1000000, expect 3482000. answer is correct.

    return 0;
}
