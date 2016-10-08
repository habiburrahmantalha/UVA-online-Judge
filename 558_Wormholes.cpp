#include<stdio.h>
#include<string.h>


int g[1001][1001],n,d[1001];

bool check()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(d[j]>d[i]+g[i][j])
            return true;
    return false;

}

bool check_bellmanford()
{
    int i,j;
    d[0]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(d[j]>d[i]+g[i][j])
            d[j]=d[i]+g[i][j];

    return check();

}

int main()
{
    int tc,m,a,b,c,i;

    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,0x7F,sizeof(g));
        memset(d,0x7F,sizeof(d));
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=c;
        }

        if(check_bellmanford())
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}
