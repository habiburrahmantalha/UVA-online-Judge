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
#define  N 26

string name;
int len,cnt;

struct Trie
{
    int prefix;
    Trie *E[N];
};

void initialize(Trie *head)
{
    head->prefix=0;
    for(int i=0;i<N;i++)
    head->E[i]=NULL;
}

void add(Trie *head,int i)
{
    head->prefix++;

    if(i==len)
        return;
    else
    {

        int k=name[i]-'a';
        if(head->E[k]==NULL)
        {
            head->E[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->E[k]);
        }

        add(head->E[k],i+1);
    }
}
void dfs(Trie *head)
{
    cnt+=head->prefix;
    for(int i=0;i<N;i++)
    {
        if(head->E[i]!=NULL)
        {

            if(head->prefix>1)
            {
                dfs(head->E[i]);
            }
        }
    }
}

int main()
{
    int tc,n,i;
    scanf("%d",&tc);
    while(tc--)
    {
        Trie *head;
        head=(Trie*)malloc(sizeof(Trie));
        initialize(head);

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>name;
            len=name.length();
            add(head,0);
        }
        cnt=0;
        for(i=0;i<N;i++)
        if(head->E[i]!=NULL)
            dfs(head->E[i]);

        printf("%d\n",cnt);
    }
    return 0;
}
