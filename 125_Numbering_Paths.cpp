#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
#define N 112
#define inf 1<<20
#define REP(i,a,b) for(int i=a;i<=b;i++)

int g[N+5][N+5],n,m;

void Floyed_warshal()
{
    REP(k,0,n)
        REP(i,0,n)
            REP(j,0,n)
            if(g[i][k]!=0 && g[k][j]!=0)
                g[i][j]=(g[i][j] + (g[i][k] * g[k][j]));

}
void Floyed_warshal_remove_cycle()
{
    REP(k,0,n)
    if(g[k][k])
        REP(i,0,n)
            REP(j,0,n)
            if(g[i][k]!=0 && g[k][j]!=0)
                g[i][j]=-1;


}

void print()
{
    REP(i,0,n)
    {

        printf("%d",g[i][0]);
        REP(j,1,n)
            printf(" %d",g[i][j]);
        printf("\n");
    }
}

int main()
{
    int a,b,c,t=0;
    while(scanf("%d",&m)==1 && m)
    {

        memset(g,0,sizeof(g));
        n=0;
        REP(i,0,m-1)
        {
            scanf("%d %d",&a,&b);
            n=max(n,max(a,b));
            g[a][b]=1;
        }

        Floyed_warshal();
        Floyed_warshal_remove_cycle();
        printf("matrix for city %d\n",t++);
        print();
    }
    return 0;
}
