#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
#define N 111
#define inf 1<<29
#define REP(i,a,b) for(int i=a;i<=b;i++)

int g[N+5][N+5],n;

void Floyed_warshal()
{
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

            }
}
void reset()
{
    REP(i,0,N)
    {
        REP(j,0,N)
        {
            g[i][j]=inf;


        }
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
    int a,b,t=1;
    while(scanf("%d %d",&a,&b) && a+b)
    {
        n=0;
        reset();

        n=max(n,max(a,b));
        g[a][b]=1;
        //g[b][a]=1;
        while(scanf("%d %d",&a,&b) && a+b)
        {
            n=max(n,max(a,b));
            g[a][b]=1;
            //g[b][a]=1;
        }
        //print();
        Floyed_warshal();
        double cost=0;
        int c=0;
        REP(i,1,n)
        REP(j,1,n)
        if(i!=j && g[i][j]!=inf)
        {
            cost+=g[i][j];
            c++;
        }
        printf("Case %d: average length between pages = %.3lf clicks\n",t++,cost/c);
        //print();
    }
    return 0;
}
