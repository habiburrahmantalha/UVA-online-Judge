#include<stdio.h>
#include<string.h>
long long g[35][35],xe,ye,xs,ys,n,vi[35][35][2];
/*
bool valid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n)
    return false;
    return true;
}

int X[]={1,0};
int Y[]={0,1};

void count_path(int x,int y)
{
    int u,v,i;
    if(x==xe && y==ye)
    {
        path++;
        return;
    }
    for(i=0;i<2;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]!=i)
        {
            //printf("%d %d %d %d\n",u,v,i,g[u][v]);
            count_path(u,v);
        }
    }
}
*/
void count_path()
{
    long long i,j;
    g[xs][ys]=1;
    for(i=xs;i<=xe;i++)
    for(j=ys;j<=ye;j++)
    {
        if(vi[i][j-1][1])
        g[i][j]+=g[i][j-1];
        if(vi[i-1][j][0])
        g[i][j]+=g[i-1][j];
    }
}
int main()
{
    long long tc,w,a,b;
    char c[10];
    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld",&n);
        scanf("%lld %lld",&xs,&ys);
        scanf("%lld %lld",&xe,&ye);

        scanf("%lld",&w);
        memset(g,0,sizeof(g));
        memset(vi,-1,sizeof(vi));

        while(w--)
        {
            scanf("%lld %lld %s",&a,&b,c);
            if(c[0]=='W')
            vi[a-1][b][0]=0;
            else if(c[0]=='E')
            vi[a][b][0]=0;
            else if(c[0]=='S')
            vi[a][b-1][1]=0;
            else if(c[0]=='N')
            vi[a][b][1]=0;
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

        printf("%lld\n",g[xe][ye]);
    }
    return 0;
}
