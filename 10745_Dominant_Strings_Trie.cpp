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
string str;
int len;
vector<string>strs;
struct Trie
{
    int next;
    int word;
    Trie *edge[N];
};
void initialize(Trie *head)
{
    int i;
    head->next=0;
    head->word=0;
    for(i=0;i<N;i++)
        head->edge[i]=NULL;
}
void add(Trie *head,int i,int j)
{
    if(i==len)
        head->word=j;
    else
    {
        int k=str[0]-'a';
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }
        head->edge[k]->next++;
        add(head->edge[k],i+1,j);
    }
}

void dfs_travarse(Trie *head,string a)
{
    if(head->next==0)
        printf("%s\n",strs[head->word].c_str());
    else
    {
        for(int i=0;i<N;i++)
        {
            if(head->edge[i]!=NULL)
            {
                char ch=i+'a';
                dfs_travarse(head->edge[i],a+ch);
            }
        }
    }
}
int main()
{
    Trie *head;
    head=(Trie *)malloc(sizeof(Trie));
    initialize(head);

    int n=0;
    while(cin>>str)
    {
        strs.push_back(str);
        sort(str.begin(),str.end());
        len=str.size();
        add(head,0,n);
        n++;
    }
    dfs_travarse(head,"");

    return 0;
}
