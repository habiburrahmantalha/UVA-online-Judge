#include<stdio.h>
#include<string.h>
#include<vector>
#include<ctype.h>
#include<algorithm>
using namespace std;

//vector<int>g[1000];
int g[50][500];
int visit[50],n;
char res[50],v[50];

bool check(int k,int x)
{
    for(int i=0;i<k;i++)
    if(g[x][res[i]-'a'])
    return false;

    return true;
}

void backtrack(int k)
{
    int i;
    if(k==n)
    {
        for(i=0;i<n;i++)
        printf("%c",res[i]);
        printf("\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        if(visit[i]==0 && check(k,v[i]-'a'))
        {
            res[k]=v[i];
            visit[i]=1;
            backtrack(k+1);
            visit[i]=0;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    char input[1000],a,b;
    int i;
    bool f=false;
    while(gets(input))
    {
        if(f)
        printf("\n");
        f=true;
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        n=0;
        for(i=0;input[i]!=0;i++)
        {
            if(isalpha(input[i]))
            v[n++]=input[i];
        }
        sort(v,v+n);
        gets(input);
        for(i=0;input[i]!=0;i++)
        {
            if(isalpha(input[i]))
            {
                a=input[i];
                i++;
                for(; ; i++)
                if(isalpha(input[i]))
                {
                    b=input[i];
                    break;
                }
                //g[a-'a'].push_back(b-'a');
                g[a-'a'][b-'a']=1;
            }
        }
        backtrack(0);

    }
    return 0;
}
