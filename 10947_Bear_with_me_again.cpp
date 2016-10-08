#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 111
#define inf 1<<30
#define REP(i,a,b) for(long long  i=a;i<=b;i++)

long long g[N+5][N+5],limit;
long long n,x[N+5],y[N+5],r[N+5];

void Floyed_warshal()
{
    REP(k,1,n+2)
        REP(i,1,n+2)
            REP(j,1,n+2)
            if(g[i][j]<=(r[i]+r[j]+limit)*(r[i]+r[j]+limit) || (g[i][k]<=(r[i]+r[j]+limit) && g[k][j]<=(r[i]+r[j]+limit)))
            {
                //printf("%lf %lf\n",g[i][j]/m<=K , (g[i][k]+g[k][j])/m<=K);
                g[i][j]=0;

            }
}
void reset()
{
    REP(i,0,111)
    {
        REP(j,0,111)
            g[i][j]=inf;
        g[i][i]=0;
    }

}

void print()
{
    REP(i,1,n+2)
    {
        REP(j,1,n+2)
        printf("%lld ",g[i][j]);
        printf("\n");
    }
}
void make_graph()
{
    REP(i,1,n+2)
    REP(j,1,n+2)
    if(i!=j)
    g[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main()
{
    long long a,b,c,k,m;
    while(scanf("%lld %lld",&k,&m)==2)
    {
        limit=k*m;
        reset();
        //print();
        REP(i,1,2)
        {
            scanf("%lld %lld %lld",&x[i],&y[i],&r[i]);

        }
        scanf("%lld",&n);
        REP(i,3,n+2)
        {
            scanf("%lld %lld %lld",&x[i],&y[i],&r[i]);

        }

        make_graph();
        //print();
        Floyed_warshal();
        //print();
        if(g[1][2]==0)
        printf("Larry and Ryan will escape!\n");
        else
        printf("Larry and Ryan will be eaten to death.\n");


    }
    return 0;
}




