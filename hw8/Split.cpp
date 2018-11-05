#ifndef SPLIT_CPP
#define SPLIT_CPP
#include<string>
using namespace std;
int split(string str, char c, string strs[], int siz)
{
    int len_str = str.length();
    if(len_str==0||siz==0)
    {
        return -1;
    }

    str.push_back(c);
    len_str++;

    char tmp[200];
    int t = 0;
    int cnt = 0;

    for(int i = 0 ; i < len_str ; i ++ )
    {
        if(str[i]==c)
        {
            if(t==0)
            {
                continue;
            }
            tmp[t++]='\0';
            strs[cnt++].assign(tmp);
            t=0;
        }
        else
        {
            tmp[t++]=str[i];
        }
    }

    return cnt;
}

#endif // SPLIT_CPP
