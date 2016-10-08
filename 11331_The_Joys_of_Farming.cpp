//Problem Type :    bicoloring,knapsack/coin change//joy of farming
//Time :    0.124
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

bool g[2010][2010],visit[2010],f[2010],impossible;
int white,black,bull,cow,D[2010],p,field;

void bi_color(int u)
{
    queue<int>q;
    int v;


    q.push(u);
    visit[u]=true;
    f[u]=true;

    white=1;
    black=0;

    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=1;v<=bull+cow;v++)
        {
            if(g[u][v] && !visit[v])
            {
                if(!f[u])
                {
                    f[v]=true;
                    white++;
                }
                else
                    black++;

                visit[v]=true;
                q.push(v);
            }
            else if(g[u][v] && visit[v] && u!=v)
            {
                if(f[u]==f[v])
                {
                    impossible=true;
                    return;
                }
            }
        }
    }
}
bool peace_setup()
{
    int i,j,x,y;
    x=max(cow,bull);
    y=x-field;

    int T[y+10];
    memset(T,0,sizeof(T));
    T[0]=1;
    for(i=0;i<p;i++)
    {
        for(j=y;j>=0;j--)
        {
            if(T[j] && j+D[i]<=y)
            T[j+D[i]]=1;
        }
    }

    if(T[y] && y+field==x)
        return true;
    return false;
}

int main()
{
    int tc,i,x,y,m;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&bull,&cow,&m);

        memset(g,false,sizeof(g));
        memset(visit,false,sizeof(visit));
        memset(f,false,sizeof(f));

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            g[x][y]=g[y][x]=true;
        }

        impossible=false;
        field=0;
        for(i=1,p=0;i<=bull+cow;i++)
        {
            if(!visit[i])
            {
                bi_color(i);
                field+=min(white,black);
                D[p++]=abs(white-black);
            }
            if(impossible)
                break;
        }

        if(impossible)
            printf("no\n");
        else
        {
            if(peace_setup())
                printf("yes\n");
            else
                printf("no\n");
        }

    }
    return 0;
}
