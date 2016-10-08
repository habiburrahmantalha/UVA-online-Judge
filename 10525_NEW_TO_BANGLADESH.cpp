#include<stdio.h>
#include<string.h>
#define inf 10000000

struct d_t
{
    int t,d;
};
d_t g1[101][101];
int n;
void warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(g1[i][j].t>g1[i][k].t+g1[k][j].t)
                    g1[i][j].t=g1[i][k].t+g1[k][j].t;

                if(g1[i][j].d>g1[i][k].d+g1[k][j].d)
                    g1[i][j].d=g1[i][k].d+g1[k][j].d;



            }
}

void reset()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            g1[i][j].t=g1[i][j].d=inf;
        }
}
int main()
{
    int T,t,d,a,b,q,m,i;
    bool f=false;
    scanf("%d",&T);

    while(T--)
    {
        if(f)printf("\n");
        scanf("%d %d",&n,&m);
        reset();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&t,&d);
            //if(g1[a][b].t>t)
            {
                g1[a][b].t=g1[b][a].t=t;
                g1[a][b].d=g1[b][a].d=d;
            }
            //else if(g1[a][b].t==t && g1[a][b].d>d)
            {
                //g1[a][b].t=g1[b][a].t=t;
                //g1[a][b].d=g1[b][a].d=d;
            }

        }
        warshal();

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(g1[a][b].d==inf)
                printf("No Path.\n");
            else
                printf("Distance and time to reach destination is %d & %d.\n",g1[a][b].d,g1[a][b].t);
        }
        f=true;
    }
    return 0;
}
