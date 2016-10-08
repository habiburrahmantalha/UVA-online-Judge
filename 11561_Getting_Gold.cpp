#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

char g[55][55];
int d[55][55],m,n,visit[55][55];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;

    return true;
}

int getting_gold(int x,int y)
{
    queue<int>q;

    int i,u,v,c=0;
    memset(visit,0,sizeof(visit));
    if(g[x][y]=='T')
        return 0;

    q.push(x);
    q.push(y);
    visit[x][y]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        if(g[u][v]=='G')
        c++;
        if(d[u][v])
        continue;
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && visit[x][y]==0 && (g[x][y]=='.' || g[x][y]=='G'))
            {
                q.push(x);
                q.push(y);
                visit[x][y]=1;
            }
        }
    }
    return c;

}
void find_draft()
{
    int i,j,k;
    memset(d,0,sizeof(d));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(g[i][j]=='T')
            for(k=0;k<4;k++)
                if(valid(i+X[k],j+Y[k]))
                {
                    //cout<<i+X[k]<<j+Y[k]<<endl;
                    d[i+X[k]][j+Y[k]]=1;
                }
}
int main()
{
    int i,j;
    while(scanf("%d %d",&m,&n)==2)
    {
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        find_draft();
        //*
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(g[i][j]=='P')
                    printf("%d\n",getting_gold(i,j));
                    //*/
    }
    return 0;
}
