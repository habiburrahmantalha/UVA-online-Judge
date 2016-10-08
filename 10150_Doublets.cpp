#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include<string>
#define N 26000
#include<iostream>
using namespace std;

int pi[N];
vector <string> word[N];
int sz;

bool doublets(int a,int b)
{
    int i,d=0;
    for(i=0;i<sz;i++)
    {
        if(word[sz][a][i]!=word[sz][b][i])
        d++;
        if(d>1)
        return false;
    }


    return true;

}
void bfs(int start,int end)
{
    memset(pi,-1,sizeof(pi));
    queue<int>q;
    int u,v;
    pi[start]=start;
    q.push(start);

    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<word[sz].size();v++)
        {
            if(pi[v]==-1 && doublets(u,v))
            {
                //cout<<v<<endl;
                pi[v]=u;
                q.push(v);
                if(v==end)
                return;
            }
        }
    }
}
void print_path(int i,int j)
{
    //cout<<i<<j<<endl;
    //cout<<word[sz][j]<<endl;
    if(i==j)
    {
        cout<<word[sz][i]<<endl;
        return;
    }
    else
    {

        print_path(i,pi[j]);
        cout<<word[sz][j]<<endl;

    }
}
int main()
{
    char s[20],e[20];
    int i,j,l;
    bool f=false;
    while(gets(s))
    {
        l=strlen(s);
        if(l==0)
        break;
        word[l].push_back(s);

    }
    while(scanf("%s %s",s,e)==2)
    {
        if(f)
        printf("\n");
        f=true;
        sz=strlen(s);
        for(i=0;i<word[sz].size();i++)
        if(strcmp(word[sz][i].c_str(),s)==0)
        break;

        if(sz==strlen(e))
        {
            for(j=0;j<word[sz].size();j++)
            if(strcmp(word[sz][j].c_str(),e)==0)
            break;

            if(i==word[sz].size() || j==word[sz].size())

            printf("No solution.\n");

            else
            {
                bfs(i,j);
                //for(int k=0;k<word[sz].size();k++)
                //cout<<word[sz][k]<<word[sz][pi[k]]<<endl;
                if(pi[j]==-1)
                printf("No solution.\n");
                else
                print_path(i,j);
            }
        }
        else
        printf("No solution.\n");
    }
    return 0;

}
