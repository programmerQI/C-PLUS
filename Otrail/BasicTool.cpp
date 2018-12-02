#ifndef BASIC_TOOL
#define BASIC_TOOL
#include <string>
int isNum(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0 ;
}
int getNum(char c)
{
    return c - '0';
}
int stoi(std::string str)
{
    int ans = 0;
    int i;
    while(str[i]!='\0')
    {
        if(!isNum(str[i]))
        {
            return -1;
        }
        ans = ans * 10 + getNum(str[i]);
        i++;
    }
    return ans;
}
#endif // BASIC_TOOL
