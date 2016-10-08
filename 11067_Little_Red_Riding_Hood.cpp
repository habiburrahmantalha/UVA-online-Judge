#include<stdio.h>
#include<string.h>
long long g[110][110],n,h,w;
bool v[110][110];

void count_path()
{
    long long i,j;
    g[0][0]=1;
    for(i=0;i<=w;i++)
    for(j=0;j<=h;j++)
    {
        if(!v[i][j])
        {
            if(i>0)
            g[i][j]+=g[i-1][j];
            if(j>0)
            g[i][j]+=g[i][j-1];
        }
    }
}
int main()
{
    long long a,b;


    while(scanf("%lld %lld",&w,&h)==2 && w && h)
    {
        scanf("%lld",&n);
        memset(g,0,sizeof(g));
        memset(v,0,sizeof(v));

        while(n--)
        {
            scanf("%lld %lld",&a,&b);
            v[a][b]=true;
        }
        count_path();
        /*
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            printf("%d ",g[i][j]);
            printf("\n");
        }
        */
        if(g[w][h]==1)
        printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else if(g[w][h])
        printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",g[w][h]);
        else
        printf("There is no path.\n");
    }
    return 0;
}
