//Problem Type : Sufix Trie
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
char str[5010];
int len,mx;
struct Trie
{
    int Prefix;
    int word;
    Trie *edge[N];
};
void initialize(Trie *head)
{
    int i;
    head->Prefix=0;
    head->word=0;
    for(i=0;i<N;i++)
        head->edge[i]=NULL;
}
void add(Trie *head,int i)
{
    if(i==len)
        head->Prefix++;
    else
    {
        head->Prefix++;
        int k=str[i]-'a';
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }

        add(head->edge[k],i+1);
    }
}
void travers_trie(Trie *head,int k)
{
    //cout<<head->Prefix;
    if(head->Prefix<2)
    {
        return;
            //mx=max(mx,k-1);
    }
    else
    {
        if(head->Prefix>=2)
            mx=max(mx,k);
        for(int i=0;i<N;i++)
        {
            if(head->edge[i]!=NULL)
            {
                travers_trie(head->edge[i],k+1);
            }
        }
    }

}

int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        Trie *head;
        head=(Trie *)malloc(sizeof(Trie));
        initialize(head);

        scanf("%s",str);
        len=strlen(str);
        for(i=0;i<len;i++)
        add(head,i);
        mx=0;
        //travers_trie(head,0);
        printf("%d\n",mx);

    }
    return 0;
}
