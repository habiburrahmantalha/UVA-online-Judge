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

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
char g[210][210];
int n,m,visit[210][210];


bool valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    return false;

    return true;
}
void conquaring_city(int x,int y)
{
    int i,u,v;
    visit[x][y]=1;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && visit[u][v]==0 && g[u][v]==g[x][y])
        conquaring_city(u,v);
    }
}

void surrounding_capital(int x,int y)
{
    int a[]={-1,-1,-1,0,1,1,1,0};
    int b[]={-1,0,1,1,1,0,-1,-1};

    int i,j,frontier,city,c,u,v;

    city=0;
    memset(visit,0,sizeof(visit));
    for(i=0;i<8;i++)
    {
        u=x+a[i];
        v=y+b[i];
        if(visit[u][v]==0)
        {
            city++;
            conquaring_city(u,v);
        }
    }
    frontier=0;
    for(i=0;i<4;i++)
    {
        c=0;
        for(j=1; ;j++)
        {
            u=x+X[i]*j;
            v=y+Y[i]*j;

            if(valid(u,v))
            {
                if(visit[u][v]==0)
                {
                    c++;
                    conquaring_city(u,v);
                }
            }
            else
            break;
        }
        frontier=max(frontier,c);
    }
    printf("%d\n",city+frontier);
}
int main()
{
    int i,j;
    while(scanf("%d %d",&n,&m)==2 && n && m)
    {
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(g[i][j]=='A')
                surrounding_capital(i,j);
            }
        }

    }
    return 0;
}
