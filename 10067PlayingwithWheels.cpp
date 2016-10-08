#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

int a;

int visit[10000+10];

int even(int x,int i)
{
    int num [4];
    num [3] = x % 10;
    num [2] = (x % 100) / 10;
    num [1] = (x % 1000) / 100;
    num [0] = x / 1000;

    num[i]+=1;
    if(num[i]>9)
    num[i]=0;
    a=num[0]*1000+num[1]*100+num[2]*10+num[3];
    return a;
}

int odd(int x,int i)
{
    int num [4];
    num [3] = x % 10;
    num [2] = (x % 100) / 10;
    num [1] = (x % 1000) / 100;
    num [0] = x / 1000;

    num[i]-=1;
    if(num[i]<0)
    num[i]=9;
    a=num[0]*1000+num[1]*100+num[2]*10+num[3];
    return a;
}

int bfs (int start,int end)
{
    if(start==end)
    return 0;

    if(visit[start] || visit[end])
    return -1;

    int d[10000+10];
    memset(d,0,sizeof(d));

    queue<int> q;

    int u,v;
    int i,j;

    q.push(start);
    visit[start]=1;
    d[start]=0;

    while(!q.empty())
    {
        u=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            for(j=0;j<2;j++)
            {
                if(j==0)
                v=even(u,i);
                else
                v=odd(u,i);

                if(visit[v]==0)
                {
                    d[v]=d[u]+1;
                    visit[v]=1;

                    if(v==end)
                    return d[v];
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int main()
{

    int s[4],e[4],x[4],forbidden,start,end;
    int tc,f,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(visit,0,sizeof(visit));

        for(i=0;i<4;i++)
        scanf("%d",&s[i]);

        start=s[0]*1000+s[1]*100+s[2]*10+s[3];

        for(i=0;i<4;i++)
        scanf("%d",&e[i]);

        end=e[0]*1000+e[1]*100+e[2]*10+e[3];

        scanf("%d",&f);
        for(i=0;i<f;i++)
        {
            for(j=0;j<4;j++)
            scanf("%d",&x[j]);

            forbidden=x[0]*1000+x[1]*100+x[2]*10+x[3];
            visit[forbidden]=1;
        }
        printf("%d\n",bfs(start,end));
    }
    return 0;
}
