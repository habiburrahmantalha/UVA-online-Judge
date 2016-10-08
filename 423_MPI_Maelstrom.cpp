
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define N 111
#define inf 1000000000
#define REP(i,a,b) for(int i=a;i<=b;i++)

long long g[N+5][N+5],n;

void Floyed_warshal()
{
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

}
void reset()
{
    REP(i,0,n)
    {
        REP(j,0,n)
            g[i][j]=inf;
        g[i][i]=0;
    }

}

void print()
{
    REP(i,1,n)
    {
        REP(j,1,n)
        printf("%d ",g[i][j]);
        printf("\n");
    }
}

int main()
{


    char x[10];
    while(scanf("%lld",&n)==1 && n)
    {
        reset();
        //print();
        REP(i,1,n)
        REP(j,1,n)
        if(i>j)
        {
            scanf("%s",x);
            if(strcmp(x,"x")!=0)
            {
                g[i][j]=strtol(x,NULL,0);
                g[j][i]=strtol(x,NULL,0);
            }
        }
        //print();
        Floyed_warshal();
        //print();
        long long mx=0;
        REP(i,1,n)
        //REP(j,1,n)
        //if(i!=j)
        if(mx<g[1][i])
        mx=g[1][i];
        if(mx==inf)
        mx=0;
        printf("%lld\n",mx);
    }
    return 0;
}
