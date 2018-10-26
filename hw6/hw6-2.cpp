#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

char* getC()
{
    char *str;
    str = (char*)malloc(sizeof(char)*4);
    str[0] = '1';
    str[1] = '2';
    str[2] = '\0';
    return str;
}
int main()
{
    string str = "abcdef";

    int n = find(str,0);
    cout << n << endl;
    return 0;
}
