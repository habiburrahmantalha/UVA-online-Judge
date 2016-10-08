#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

int X[]={0,-1,0};
int Y[]={-1,0,1};
char path[]={'I','E','H','O','V','A','#'};
int move[10];
int n,m;
char g[10][10];

bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}

void print(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(move[i]==0)
        printf("forth");
        else if(move[i]==-1)
        printf("left");
        else if(move[i]==1)
        printf("right");
        if(i!=x-1)
        printf(" ");
    }
    printf("\n");
}
bool find_path(char c)
{
    int i;
    for(i=0;i<7;i++)
    if(path[i]==c)
    return true;

    return false;
}
void bfs(int x,int y)
{
    queue<int> q;
    int u,v,i,in;
    int visit[10][10];
    memset(visit,0,sizeof(visit));
    q.push(x);
    q.push(y);
    in=0;
    visit[x][y]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<3;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && find_path(g[x][y]) && visit[x][y]==0)
            {
                move[in++]=Y[i];
                q.push(x);
                q.push(y);
                visit[x][y]=1;
            }
        }

    }
    print(in);
}

int main()
{
    int tc,i,x,y;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(g,0,sizeof(g));

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++)
        scanf("%s",g[i]);

        for(i=0;i<m;i++)
        if(g[n-1][i]=='@')
        {
            x=n-1;
            y=i;
        }
        bfs(x,y);
    }
    return 0;
}
