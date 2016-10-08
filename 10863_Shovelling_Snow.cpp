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

int n,m;
char G[25][25];
int D[4][25][25],P[4][25][25];
bool V[4][25][25];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;

    return true;
}
void bfs(int x,int y,int z)
{
    queue<int>q;
    int u,v,i;
    memset(V,false,sizeof(V));
    memset(P,-1,sizeof(P));
    memset(D,127,sizeof(D));


    D[z][x][y]=0;
    P[z][x][y]=z;
    V[z][x][y]=true;

    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        x=q.front();
        y=q.front();
        for(i=0;i<4;i++)
        {
            u=x+X[i];
            v=y+Y[i];
            if(valid(u,v) && G[u][v]!='#' && !V[u][v])
            {
                D[z][u][v]=D[z][x][y]+1;
                P[z][u][v]=i;
                V[z][u][v]=true;
                q.push(u);
                q.push(v);

            }
        }

    }


}
int main()
{

    int i,j,Cx[25],Cy[25];
    while(scanf("%d %d",&m,&n)==2 && n+m)
    {
        for(i=0;i<n;i++)
        scanf("%s",G[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(G[i][j]=='A')
                {
                    bfs(i,j,0);
                    Cx[0]=i;
                    Cy[0]=j;
                }
                else if(G[i][j]=='B')
                {
                    bfs(i,j,1);
                    Cx[1]=i;
                    Cy[1]=j;

                }
                else if(G[i][j]=='C')
                {
                    bfs(i,j,2);
                    Cx[2]=i;
                    Cy[2]=j;


                }
                else if(G[i][j]=='D')
                {
                    bfs(i,j,3);
                    Cx[3]=i;
                    Cy[3]=j;

                }
            }
        }

    }
    return 0;
}
