#include<stdio.h>

int sum,i,j,x[20][20];

void oddsquare(int n,int r,int c)
{
    if(n==r+c+1)
    {
        printf(" %d\n",x[r][c]);
        return;
    }
    for(i=c;i<n-c;i++)
    {
        sum+=x[r][i]+x[n-1-r][i];
    }
    //printf("%d*\n",sum);
    //sum=0;
    for(i=r+1;i<n-1-r;i++)
    {
        sum+=x[i][c]+x[i][n-1-c];
    }
    printf(" %d",sum);
    sum=0;
    oddsquare(n,r+1,c+1);
}

void evensquare(int n,int r,int c)
{
    if(n==r+c)
    {
        printf("\n");
        return;
    }
    for(i=c;i<n-c;i++)
    {
        sum+=x[r][i]+x[n-1-r][i];
    }
    //printf("%d*\n",sum);
    //sum=0;
    for(i=r+1;i<n-1-r;i++)
    {
        sum+=x[i][c]+x[i][n-1-c];
    }
    printf(" %d",sum);
    sum=0;
    evensquare(n,r+1,c+1);
}

int main()
{
    int n,tc=1;
    while(scanf("%d",&n) && n)
    {

        if(n==0)
        break;

        if(n==1)
        {
            scanf("%d",&x[0][0]);
            printf("Case %d: %d\n",tc++,x[0][0]);
            continue;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {

                scanf("%d",&x[i][j]);
            }
        }
        sum=0;
        printf("Case %d:",tc++);
        if(n&1)
        oddsquare(n,0,0);
        else
        evensquare(n,0,0);
    }
    return 0;
}
