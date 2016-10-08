#include<stdio.h>
#include<string.h>

int g[20][20],n,sum,x,y;

void new_index()
{
    int a,b;
    a=x-1;
    if(a<0)
    a=n-1;

    b=y+1;
    if(b>=n)
    b=0;

    if(g[a][b])
    {
        a=x+1;
        if(x>=n)
        a=0;

        b=y;
    }
    x=a;
    y=b;
}
void magiq_squre()
{
    g[0][(n-1)/2]=1;
    int c=2;
    x=0;
    y=(n-1)/2;
    new_index();
    while(g[x][y]==0)
    {
        g[x][y]=c++;
        new_index();
    }
}
void print_3()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf(" %1d",g[i][j]);
        printf("\n");
    }
}

void print_9()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf(" %2d",g[i][j]);
        printf("\n");
    }
}

void print_15()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf(" %3d",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int i;
    bool f=false;
    while(scanf("%d",&n)==1)
    {
        if(f)
        printf("\n");
        f=true;

        memset(g,0,sizeof(g));
        magiq_squre();
        sum=0;
        for(i=0;i<n;i++)
        sum+=g[0][i];

        printf("n=%d, sum=%d\n",n,sum);
        if(n==3)
        print_3();
        else if(n>3 && n<=9)
        print_9();
        else
        print_15();

    }
    return 0;
}
