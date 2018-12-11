#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define SIZE 10000
using namespace std;
typedef struct Vtree
{
    bool isword;
    bool msp;
    int index;
    Vtree** nexts;
}*Vtree_link, Vtree;
int getMax(int a, int b)
{
    return a > b ? a : b;
}
int getNum(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    if(c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    return 0;
}
int isChr(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return 1;
    }
    if(c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}
string getLower(string word)
{
    int len = word.length();
    string ans;
    for(int i = 0; i < len; i ++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            ans.push_back(word[i] - 'A' + 'a');
        }
        else
        {
            ans.push_back(word[i]);
        }
    }
    return ans;
}
int split(string str, char c, string strs[], int s)
{
    int len_str = str.length();
    if(len_str == 0 || s == 0)
    {
        return -1;
    }

    str.push_back(c);
    len_str ++;
    int cnt = 0;
    for(int i = 0; i < len_str; i ++)
    {
        if(str[i] != c)
        {
            strs[cnt].push_back(str[i]);
        }
        else if(strs[cnt].length() != 0)
        {
            cnt++;
            if(cnt >= s)
            {
                return -1;
            }
        }
    }
    return cnt;
}
Vtree_link initNode()
{
    Vtree_link node = NULL;
    node = (Vtree_link)malloc(sizeof(Vtree));
    node->isword = false;
    node->msp = false;
    node->index = -1;
    node->nexts = (Vtree_link*)malloc(26*sizeof(Vtree_link));
    for(int i = 0; i < 24; i ++)
    {
        node->nexts[i] = NULL;
    }
    return node;
}
int getDepth(Vtree_link node, int p)
{
    int depth = p;
    for(int i = 0; i < 26; i ++ )
    {
        if(node->nexts[i] != NULL)
        {
            depth = getMax(getDepth(node->nexts[i], p + 1), depth);
        }
    }
    return depth;
}
int insertVocab(Vtree_link r, string vocab, bool iw, bool m, int idx)
{
    if(r == NULL)
    {
        return -1;
    }

    //cout << "This is it" << endl;
    Vtree_link node = r;
    int len = vocab.length();
    int id;
    for(int i = 0; i < len; i ++ )
    {
        //cout << tmp[i];
        id = getNum(vocab[i]);
        if(node->nexts[id] == NULL)
        {
            node->nexts[id] = initNode();
        }
        node = node->nexts[id];
    }
    node->isword = iw;
    node->msp = m;
    node->index = idx;
    return 1;
}
int getVocab(string *l, int s, Vtree_link r)
{
    string fileName = "vocabulary.txt";

    ifstream in;
    in.open(fileName.c_str());
    if(!in.is_open())
    {
        cout << fileName << " does not exist" << endl;
        exit(EXIT_FAILURE);
        return 0;
    }

    int cnt = 0;
    string tmp;
    while(getline(in, tmp) && cnt < s)
    {
        l[cnt] = tmp;
        insertVocab(r, tmp, true, false, -1);
        cnt++;
    }

    in.close();
    cout << "Read "<< cnt <<" words from "<< fileName << endl;
    return  cnt;
}
int getMisspellings(string *l, int s, Vtree_link r)
{
    string fileName = "misspelling.csv";

    ifstream in;
    in.open(fileName.c_str());
    if(!in.is_open())
    {
        cout << fileName << " does not exist" << endl;
        exit(EXIT_FAILURE);
        return 0;
    }

    int cnt = 0;
    string tmp;
    while(getline(in, tmp) && cnt < s)
    {
        string strs1[30], strs2[30];
        int cnt1, cnt2;

        cnt1 = split(tmp, ',', strs1, 30);
        insertVocab(r, strs1[0], true, false, -1);
        l[cnt] = strs1[0];

        cnt2 = split(strs1[1], '|', strs2, 30);
        //cout << strs1[0] << ",";
        for(int i = 0; i < cnt2; i ++)
        {
            //cout << strs2[i] << "|";
            insertVocab(r, strs2[i], true, true, cnt);
        }
        //cout << endl;
        cnt++;
    }

    in.close();
    cout << "Read " << cnt << " lines from " << fileName << endl;
    return  cnt;
}
int isCorrect(string word, Vtree_link r)
{
    if(r == NULL)
    {
        return -3;
    }

    Vtree_link node = r;
    int i = 0;
    int id;
    while(word[i] != '\0')
    {
        //cout << "This is it" << endl;
        id = getNum(word[i]);
        if(node->nexts[id] == NULL)
        {
            return -2;
        }
        node = node->nexts[id];

        i ++;
    }
    if(node->isword && node->msp)
    {
        return node->index;
    }
    else if(node->isword)
    {
        return -1;
    }
    return -2;
}
string correct(string str, string *l, Vtree_link root)
{
    int i = 0;
    int status;
    string tmp;
    string unk = "unknown";

    while(!isChr(str[i]))
    {
        i++;
    }
    while(str[i] != '\0')
    {
        string word;
        while(isChr(str[i]))
        {
            word.push_back(str[i]);
            i ++;
        }
        status = isCorrect(word, root);
        if(status == -2)
        {
            word = unk;
        }
        else if(status != -1 && status != -3)
        {
            word = l[status];
        }
        else if(status == -1)
        {
            word = getLower(word);
        }
        tmp.append(word);

        while(!isChr(str[i]) && str[i] != '\0')
        {
            tmp.push_back(str[i]);
            i ++;
        }
    }
    return tmp;
}
int main()
{
    Vtree_link root = initNode();
    string vocabs[SIZE];
    string misspellings[SIZE];
    int vocab_count = 0;
    int mispel_count = 0;

    vocab_count = getVocab(vocabs, SIZE, root);
    //cout << vocab_count << endl;
    mispel_count = getMisspellings(misspellings, SIZE, root);
    //cout << mispel_count << endl;

    //cout << getDepth(root, 0) << endl;
    //cout << cnt << endl;
    string str, ans;
    cout << "Enter the phrase you would like to correct:" << endl;
    getline(cin, str);

    ans = correct(str, misspellings, root);
    cout << ans << endl;

    return 0;
}
