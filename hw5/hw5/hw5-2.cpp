#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int getMax(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

/*int match(string str1, string str2)
{
    int size_str1= str1.length();
    int size_str2= str2.length();

    if(size_str1==0 || size_str2==0)
    {
        return -1;
    }

    int i,j;
    int cnt = 0;
    int maxcnt = 0;

    for(i=0;i<size_str1;i++)
    {
        if(str1[i]==str2[0])
        {
            cnt = 0;
            for(j=0;j<size_str2;j++)
            {
                if(str1[i+j]==str2[j])
                {
                    cnt++;
                }
            }
            maxcnt = getMax(cnt,maxcnt);
        }
    }

    return maxcnt;
}*/


double simScore(string str1, string str2)
{
    int size_str1=str1.length();
    int size_str2=str2.length();

    if(size_str1 != size_str2 || size_str1 == 0)
    {
        printf("xxx");
        return 0;
    }

    double ss;

    int i;
    int cnt=0;

    for(i=0;i<size_str1;i++)
    {
        if(str1[i]!=str2[i])
        {
            cnt++;
        }
    }

    return (size_str1-cnt)*1.0/size_str1;
}


void analyzer(string g1, string g2, string g3, string seq)
{
    int size_g1 = g1.length();
    int size_g2 = g2.length();
    int size_g3 = g3.length();
    int size_seq = seq.length();

    if(size_g1!=size_g2||size_g2!=size_g3||size_g1!=size_g3)
    {
        cout << "Genome length does not match." << endl;
        return;
    }

    if(size_g1 == 0)
    {
        cout << "Genome and sequence cannot be empty." << endl;
        return;
    }

    if(size_seq>size_g1)
    {
        cout << "Sequence length must be smaller than genome​ length." << endl;
        return;
    }



    double g1_s, g2_s, g3_s;
    g1_s=g2_s=g3_s=-1;

    int i , j;
    for(int i=0;i<size_g1-size_seq;i++)
    {
        string tmp1 = g1.substr(i,size_seq);
        string tmp2 = g2.substr(i,size_seq);
        string tmp3 = g3.substr(i,size_seq);
        g1_s = getMax(g1_s,simScore(tmp1,seq));
        printf("g1:%d\n",g1_s);
        g2_s = getMax(g2_s,simScore(tmp2,seq));
        printf("g2:%d\n",g2_s);
        g3_s = getMax(g3_s,simScore(tmp3,seq));
        printf("g3:%d\n",g3_s);

    }

    if(g1_s >= g2_s && g1_s >=g3_s)
    {
        cout << "Genome 1 is the best match." << endl;
    }
    if(g2_s >= g1_s && g2_s >= g3_s)
    {
        cout << "Genome 2 is the best match." << endl;
    }
    if(g3_s >= g1_s && g3_s >=g2_s)
    {
        cout << "Genome 3 is the best match." << endl;
    }

}
int main()
{
    analyzer("TAAGGCA","TACCTAC","AGCCAGA","TCT");
    return 0;
}
