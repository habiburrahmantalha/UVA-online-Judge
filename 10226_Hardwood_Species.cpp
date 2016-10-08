//Problem Type : Trie
//Time :    .232
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

int n;
char tree[50];
int len;

struct Trie
{
    int word;
    Trie *edge[130];
};
void initialize(Trie *a)
{
    int i;
    a->word=0;
    for(i=0;i<130;i++)
        a->edge[i]=NULL;
}
bool add(Trie *head,int i)
{
    if(i==len)
    {
        head->word++;

    }
    else
    {
        int k=tree[i];
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }
        add(head->edge[k],i+1);
    }

}
void dfs(Trie *head)
{

	int i;
	if(head->word!=0)
	{
        tree[len]=0;
		printf("%s %.4lf\n",tree,( (double)head->word*100.0)/(double)n);
	}
	for(i=0;i<130;i++)
	{
		if(head->edge[i]!=NULL)
		{
			tree[len++]=i;
			dfs(head->edge[i]);
			len--;
		}
	}

}
int main()
{
    int tc,i;

    scanf("%d\n",&tc);
    while(tc--)
    {
        Trie *head;
        head=(Trie *)malloc(sizeof(Trie));
        initialize(head);
        n=0;

        while(gets(tree))
        {

            len=strlen(tree);
            if(len==0)
                break;
            add(head,0);
            n++;
        }
        len=0;
        dfs(head);
        if(tc)
        printf("\n");

    }

    return 0;
}
