#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<queue>
#define POP(q) q.front();q.pop();
using namespace std;
int n,g[1001][1001],pi[1001],visit[1001];
map<int,char>mp2;
void bfs(int s,int e)
{
    int u,v;
    queue<int>q;
    memset(visit,0,sizeof(visit));
    memset(pi,0,sizeof(pi));
    visit[s]=1;
    q.push(s);
    while(!q.empty())
    {
        u=POP(q);
        for(v=1;v<n;v++)
        {
            if(g[u][v] && visit[v]==0)
            {
                visit[v]=1;
                q.push(v);
                pi[v]=u;
                if(v==e)
                    return;
            }
        }
    }
}
void printpath(int s,int e)
{
    if(s==e)
        printf("%c",mp2[s]);
    else
    {
        printpath(s,pi[e]);
        printf("%c",mp2[e]);
    }
}
int main()
{
    int tc,i,x,y,m,q;
    char a[100],b[100];
    map<string,int>mp;
    bool f=false;

    scanf("%d",&tc);
    while(tc--)
    {
        if(f)
            printf("\n");
        f=true;
        memset(g,0,sizeof(g));
        scanf("%d %d",&m,&q);
        n=1;
        for(i=1;i<=m;i++)
        {
            scanf("%s %s",a,b);
            if(!mp[a])
            {
                x=n;
                mp2[n]=a[0];
                mp[a]=n++;
            }
            else
                x=mp[a];
            if(!mp[b])
            {
                mp2[n]=b[0];
                mp[b]=n++;
                y=mp[b];
            }
            else
                y=mp[b];
            g[x][y]=g[y][x]=1;
        }
        for(i=0;i<q;i++)
        {

            scanf("%s %s",a,b);
            x=mp[a];
            y=mp[b];
            bfs(x,y);
            printpath(x,y);
            printf("\n");

        }
        mp.clear();
        mp2.clear();
    }
    return 0;
}
