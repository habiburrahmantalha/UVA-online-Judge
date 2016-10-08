//Problem Type : bfs,bruteforce
//Time :    .008
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
int X[]={0,0,-1,1};
int Y[]={-1,1,0,0};
char g[12][12];

bool valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=n)
    return false;
    return true;
}
bool valid_fill(int x,int y)
{
    int u,v,i;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v))
        {
            if(g[x][y]==g[u][v])
            return false;
        }
    }
    return true;
}
void bfs(int x,int y)
{
    int u,v,i;
    char ch;
    queue<int>q;

    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];

            if(valid(x,y) && g[x][y]=='.')
            {
                for(ch='A';ch<='Z';ch++)
                {
                    g[x][y]=ch;
                    if(valid_fill(x,y))
                    break;
                }
                q.push(x);
                q.push(y);

            }
        }


    }

}

int main()
{
    int tc,t=1,i,j;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        f=false;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            if(g[i][j]!='.')
            {
                bfs(i,j);
                f=true;
            }
        }
        if(!f)
        {
            g[0][0]='A';
            bfs(0,0);
        }

        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
        printf("%s\n",g[i]);
    }
    return 0;
}
