#include<stdio.h>
int CountVowels(string str)
{
    int cnt = 0;

    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='I'||str[i]=='U')
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}
int main()
{
    return 0;
}
