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

#define N 4
char str[1010];
int len,mx,mxr;
int current[1010];
vector<int>res;
struct Trie
{
    int Prefix;
    Trie *edge[N];
};
int to_int(char x)
{
    if(x=='A')
    return 0;
    else if(x=='C')
    return 1;
    else if(x=='G')
    return 2;
    else if(x=='T')
    return 3;
}
char to_char(int x)
{
    if(x==0)
    return 'A';
    else if(x==1)
    return 'C';
    else if(x==2)
    return 'G';
    else if(x==3)
    return 'T';
}
void initialize(Trie *head)
{
    int i;
    head->Prefix=0;
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
        int k=to_int(str[i]);
        if(head->edge[k]==NULL)
        {
            head->edge[k]=(Trie*)malloc(sizeof(Trie));
            initialize(head->edge[k]);
        }
        add(head->edge[k],i+1);
    }
}
void travers_trie(Trie *head,int k,int j)
{
    //cout<<a<<" "<<k<<" "<<head->Prefix<<endl;
    current[k]=j;

    if(k>mx)
    {
        mx=k;
        res.clear();
        for(int i=0;i<=k;i++)
            res.push_back(current[i]);
        mxr=head->Prefix;
    }
    for(int i=0;i<N;i++)
        if(head->edge[i]!=NULL && head->edge[i]->Prefix>=2)
            travers_trie(head->edge[i],k+1,i);


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

        mx=-1;
        res.clear();
        for(i=0;i<N;i++)
            if(head->edge[i]!=NULL && head->edge[i]->Prefix>=2)
                travers_trie(head->edge[i],0,i);



        if(res.size()==0)
            printf("No repetitions found!\n");
        else
        {
            for(i=0;i<res.size();i++)
            printf("%c",to_char(res[i]));
            printf(" %d\n",mxr);
        }

    }
    return 0;
}
