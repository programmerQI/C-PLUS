#include<iostream>
using namespace std;
void convertSeconds(int sec)
{
    int h;//set an integer for storing the number of hours.

    h = sec/3600;//get hours.

    int m;//set an integer for storing the number of minutes.

    m = sec%3600/60;//get minutes.

    int s;//set an integer for storing the number of seconds that has be converted.

    s = sec%60;// get seconds.

    cout << h << " hour(s) " << m << " minute(s) " << s << " second(s) "<< endl;// print the answer.

}
int main()
{
    convertSeconds(3600); // test data 1. input data 3600. expect result "1 hour(s) 0 minute(s) 0 second(s)". correct result.

    convertSeconds(60); //test data 2. input data 60. expect result "0 hour(s) 0 minute(s) 0 second(s)". correct result.

    return 0;
}
