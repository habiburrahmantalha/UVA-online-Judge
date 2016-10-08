#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 200000000
#define N 111
int n,g[N+5][N+5];

void floyed_warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
void reset()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        g[i][j]=inf;

        //g[i][i]=0;

    }
}
bool equal(int i)
{
    int x=g[1][i],j;
    for(j=1;j<=5;j++)
    {
        if(g[j][i]!=x)
        return false;
    }
    return true;
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        printf("%d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int tc,i,j,l,mn,fd,t=1,a,b,c,d;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d",&n,&l);
        reset();
        for(i=0;i<l;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c<g[a][b])
            g[a][b]=g[b][a]=c;
        }
        floyed_warshal();
        //print();
        mn=inf;
        d=inf;
        for(i=6;i<=n;i++)
        {
            if(equal(i))
            {
                //printf("%d*",i);
                if(d==g[1][i] || d==inf)
                {
                    fd=0;
                    for(j=1;j<=n;j++)
                        if(fd<g[i][j] && i!=j)
                            fd=g[i][j];
                            //printf("%d ",fd);
                    if(mn>fd)
                        mn=fd;
                }
                else if(d>g[1][i])
                d=g[1][i];

            }
        }
        if(mn==inf)
        printf("Map %d: -1\n",t++);
        else
        printf("Map %d: %d\n",t++,mn);
    }
    return 0;
}
