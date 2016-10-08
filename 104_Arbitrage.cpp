#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
#define N 111
#define inf 1<<17
#define REP(i,a,b) for(int i=a;i<=b;i++)

double g[N+5][N+5];
int p[N+5][N+5],n;

void Floyed_warshal()
{
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n)
            {
                if(g[i][j]<g[i][k]*g[k][j])
                {
                    g[i][j]=g[i][k]*g[k][j];

                    p[i][j]=p[k][j];
                }
            }
}
void reset()
{
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            g[i][j]=0;
            p[i][j]=i;

        }
        g[i][i]=1.0;
    }

}

void print_path(int a,int b)
{
    if(a==b)
    {
        printf("%d",a);
        return;
    }
    else
    {
        print_path(a,p[a][b]);
        printf("-->%d",b);
    }
}
void print()
{
    REP(i,1,n)
    {
        REP(j,1,n)
        printf("%lf ",g[i][j]);
        printf("\n");
    }
}

int main()
{
    int a,b,c;
    while(scanf("%d",&n)==1 && n)
    {
        reset();
        //print();
        REP(i,1,n)
        REP(j,1,n)
        {
            if(i==j)
            continue;
            scanf("%lf",&g[i][j]);

        }
        Floyed_warshal();
        print();
        REP(i,1,n)

        {
            print_path(1,i);
            printf("\n");
        }
    }
    return 0;
}
/*
sample i/o


*/
