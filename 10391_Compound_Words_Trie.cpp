//Problem Type : Trie
//Time :
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


#define N 26
char str[20];
int len,cnt;
vector<string>v;
struct Trie
{

    int word;
    Trie *edge[N];
};
void initialize(Trie *head)
{
    int i;

    head->word=0;
    for(i=0;i<N;i++)
        head->edge[i]=NULL;
}
void add(Trie *head,int i)
{
    if(i==len)
        head->word++;
    else
    {
        int k=str[i]-'a';
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }
        add(head->edge[k],i+1);
    }
}
string getword2(Trie *head,string a)
{
    if(head->word!=0)
    {
        return a;

    }
    else{
    int k=a[0]-'a';
    if(head->edge[k]!=NULL)
        getword2(head->edge[k],a.substr(1));
    }


}
string getword(Trie *head,string a)
{
    if(head->word!=0)
    {
        return a;
    }
    int k=a[0]-'a';
    if(head->edge[k]!=NULL)
        getword(head->edge[k],a.substr(1));


}
int main()
{
    Trie *head;
    head=(Trie *)malloc(sizeof(Trie));
    initialize(head);

    int i;
    v.clear();
    while(scanf("%s",str)==1)
    {
        len=strlen(str);
        add(head,0);
        v.push_back(str);
    }
    for(i=0;i<v.size();i++)
    {
        string fuck=getword(head,v[i]);
        if(fuck.size() > 0)
            fuck=getword(head,v[i]);

    }

    return 0;
}
