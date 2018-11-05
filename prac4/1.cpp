#include<iostream>
#include<cmath>
using namespace std;
int getNum(string str)
{
    int str_l = str.length();

    int res = 0;
    int i = 0;
    int e;

    while(str[i]!='\0')
    {
        str_l--;
        e = pow(10,str_l);
        res = res + (str[i]-'0')*e;
        i++;
    }

    return res;
}
int main()
{
    cout << getNum("98") << endl;
    return 0;
}
