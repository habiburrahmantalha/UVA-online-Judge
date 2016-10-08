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
char s[210];
int len,mx;
struct Trie
{
    int prefix;
    Trie *edge[2];

};
void initialize(Trie *head)
{
    head->prefix=0;
    head->edge[0]=head->edge[1]=NULL;
}
void add(Trie *head,int i)
{
    if(i==len)
        head->prefix++;
    else
    {
        head->prefix++;
        int k=s[i]-'0';
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }
        add(head->edge[k],i+1);
    }

}

void goodness(Trie *head,int k)
{
    if(k*head->prefix > mx)
        mx=head->prefix*k;

    if(head->edge[0]!=NULL)
        goodness(head->edge[0],k+1);
    if(head->edge[1]!=NULL)
        goodness(head->edge[1],k+1);


}
int main()
{
    int tc,n,i;
    scanf("%d",&tc);
    while(tc--)
    {
        Trie *head;
        head=(Trie *)malloc(sizeof(Trie));
        initialize(head);

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            len=strlen(s);
            add(head,0);
        }
        mx=0;
        goodness(head,0);
        printf("%d\n",mx);
    }
    return 0;
}
