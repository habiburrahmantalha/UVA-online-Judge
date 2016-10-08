//who will do the rotation :P ?
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;
int g[510][510][5],visit[510][510],d[510][510],R,C;
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};


bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}
int dir(char c)
{
    if(c=='N')
        return 0;
    if(c=='E')
        return 1;
    if(c=='S')
        return 2;
    if(c=='W')
        return 3;

}
int get_dir(int i)
{
    if(i==0)
        return 2;
    if(i==1)
        return 3;
    if(i==2)
        return 0;
    if(i==3)
        return 1;
}
void bfs(int x,int y)
{
    int u,v,i;
    queue<int> q;

    visit[x][y]=1;
    d[x][y]=0;
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

            if(valid(x,y) && g[u][v][i] && g[x][y][get_dir(i)] && visit[x][y]==0)
            {
                d[x][y]=d[u][v]+1;
                visit[x][y]=1;
                if(x==R-1 && y==C-1)
                    return;
                q.push(x);
                q.push(y);
            }
        }
    }
}



int main()
{
    int i,j,k;
    char s[6];
    while(scanf("%d %d",&R,&C)==2)
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        memset(d,0,sizeof(d));

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(i==R-1 && j==C-1)
                    break;
                scanf("%s",s);
                for(k=0;s[k]!=0;k++)
                {
                    int x=dir(s[k]);
                    //printf("%c %d\n",s[k],x);

                    g[i][j][dir(s[k])]=1;
                    //printf("%d %d %d\n",i,j,g[i][j][dir(s[k])]);
                }
            }
        for(k=0;k<4;k++)
            g[i-1][j][k]=1;
            ///*
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                for(k=0;k<4;k++)
                    printf("%d ",g[i][j][k]);
                printf("\n");
            }
        }//*/
        bfs(0,0);
        if(visit[R-1][C-1])
        printf("%d\n",d[R-1][C-1]);
        else
            printf("no path to exit\n");
    }
    return 0;
}
