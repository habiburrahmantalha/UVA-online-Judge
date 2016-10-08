#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <queue>

using namespace std;

int n,m,count,visit[101][101];
char g[101][101];

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    else
        return false;
}

void bfs(int x,int y)
{
    int i,u,v;
    queue<int>q;

    q.push(x);
    q.push(y);
    if(g[x][y]=='W')
    {
        count++;
        visit[x][y]=1;
    }
    else
    return;

    while(!q.empty())
    {

        x=q.front();
        q.pop();
        y=q.front();
        q.pop();

        for(i=0;i<8;i++)
        {
            u=x+X[i];
            v=y+Y[i];
            if(valid(u,v) && g[u][v]=='W' && visit[u][v]==0)
            {
                    count++;
                    visit[u][v]=1;
                    q.push(u);
                    q.push(v);
            }

        }
    }
}


int main ()
{
    //freopen("in.txt","r",stdin);
    int tc,i,j;
    char ch,num[10];
    bool f=false;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        if(f==true)
        printf("\n");
        n=0;
        memset(g,0,sizeof(g));

        while(1)
        {
            scanf("%s",g[n++]);
            if(isdigit(g[n-1][0]))
            {
                //for(i=0;i<n;i++)
                //printf("%s\n",g[i]);
                i=atoi(g[n-1]);
                m=strlen(g[0]);
                scanf("%d",&j);
                count=0;
                //printf("%d %d",n,m);
                memset(visit,0,sizeof(visit));
                //printf("%d %d\n",i,j);
                bfs(i-1,j-1);
                printf("%d\n",count);

                break;
            }
        }
        getchar();
        while(1)
        {
            ch=getchar();
            if(ch=='\n' ||ch==EOF)
            break;
            else
            {
                int in=0;
                memset(num,0,sizeof(num));
                while(ch!=' ')
                {
                    num[in++]=ch;
                    ch=getchar();
                }
                i=atoi(num);
                scanf("%d",&j);
                getchar();
                count=0;
                memset(visit,0,sizeof(visit));
                //printf("%d %d\n",i,j);
                bfs(i-1,j-1);
                printf("%d\n",count);

            }
        }
        f=true;
    }

    return 0;
}
