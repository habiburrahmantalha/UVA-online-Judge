#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
int m,n;
char g[102][102];

bool valid(int x,int y)
{
    if(x<0 && x>=n && y<0 && y<=m)
    return false;
    else return true;
}
bool star(int u,int v)
{
    int i,x,y;
    for(i=0;i<8;i++)
    {
        x=u+X[i];
        y=v+Y[i];
        if(valid(x,y) && g[x][y]=='*')
        return false;
    }
    return true;
}

int main()
{
    int i,j,count;
    while(scanf("%d %d",&n,&m) &&n &&m)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(g[i][j]=='*')
                if(star(i,j))
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

