#include<iostream>
#include<iomanip> // need to use the setprecision() function to format the printing of float or double.
using namespace std;
void celsiusToFahrenheit(double cel)
{
    double fa; // set a double to store the fahrenheit value.

    fa = cel * (9.0/5.0) + 32; // using the algorithm to get cel.

    cout << "The temperature of "<< cel << " in fahrenheit is " << fixed <<setprecision(2) << fa << endl; // formatting fa and output.

}
int main()
{

    celsiusToFahrenheit(0); //test data 1. input value 0. expect result "The temperature of 0 in fahrenheit is 32". result is correct.

    celsiusToFahrenheit(35) //test data 2. input value 35. expect result "The temperature of 0 in fahrenheit is 95". result is correct.

    return 0;
}
