#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

char g[110][110],op[1000010];
int N,M,S,c;
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

bool valid(int x,int y)
{
    if(x<0 || x>= N || y<0 || y>=M)
    return false;
    return true;
}
int dir(char ch,int i)
{
    if(ch=='F')
    return i;
    else if(ch=='D')
    return (i+1)%4;
    else if(ch=='E')
    return (i+3)%4;
    else
    return -1;
}
void traverse(int x,int y,int d)
{
    g[x][y]='.';
    int i,u,v,w;
    int len=strlen(op);
    for(i=0;i<len;i++)
    {
        w=dir(op[i],d);
        if(w==-1)
        continue;
        if(w==d)
        {
            u=x+X[w];
            v=y+Y[w];
            if(valid(u,v) && g[u][v]!='#')
            {
                if(g[u][v]=='*')
                {
                    c++;
                    g[u][v]='.';
                    x=u;
                    y=v;
                }
                else if(g[u][v]=='.')
                {
                    x=u;
                    y=v;
                }

            }

        }
        else
        {
            u=x;
            v=y;
            d=w;
        }
        //printf("%d %d %d\n",u,v,w);
    }
}
int main()
{
    int i,j;
    while(scanf("%d %d %d",&N,&M,&S) && N+M+S)
    {
        for(i=0;i<N;i++)
        scanf("%s",&g[i]);
        gets(op);
        gets(op);

        c=0;

        for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        if(g[i][j]=='N')
        traverse(i,j,0);
        else if(g[i][j]=='L')
        traverse(i,j,1);
        else if(g[i][j]=='S')
        traverse(i,j,2);
        else if(g[i][j]=='O')
        traverse(i,j,3);

        printf("%d\n",c);
    }
    return 0;
}
