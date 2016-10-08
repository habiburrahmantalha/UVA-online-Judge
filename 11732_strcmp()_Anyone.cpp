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
#include<ctype.h>
using namespace std;
#define PI 2 * acos (0.0)

char str[1010];
int l;
long long res;
struct Trie
{
    int Prefix;
    int postfix;
    Trie *edge[62];
};
void initialize(Trie *a)
{
    int i;
    a->Prefix=0;
    a->postfix=0;
    for(i=0;i<62;i++)
        a->edge[i]=NULL;
}
int to_int(char x)
{
    if(isupper(x))
        return x-'A'+26;
    else if(islower(x))
        return x-'a';
    else
        return x-'0'+52;
}
void add(Trie *head,int i)
{

    if(i==l)
        return;
    head->postfix++;
    int k=to_int(str[i]);
    if(head->edge[k]==NULL)
    {
        head->edge[k]=(Trie*)malloc(sizeof(Trie));
        initialize(head->edge[k]);
        res+=head->postfix-1;
    }
    res+=head->edge[k]->Prefix;
    head->edge[k]->Prefix++;
    add(head->edge[k],i+1);
}

int main()
{
    printf("%lf\n",2*4960*4960*(1-cos(30)));
    int n,i,t=1,k;
    long long x;

    while(scanf("%d",&n) && n)
    {
        Trie *head;
        head=(Trie *)malloc(sizeof(Trie));
        initialize(head);
        res=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            l=strlen(str);
            add(head,0);
        }
        printf("Case %d: %lld\n",t++,res);
    }

    return 0;
}

