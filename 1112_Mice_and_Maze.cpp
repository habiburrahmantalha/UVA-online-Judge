#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int N,g[110][110];

void warshal()
{
    int i,j,k;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
            g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
}
void reset()
{
    int i,j;
    for(i=0;i<=N;i++)
    {
        for(j=0;j<=N;j++)
        {
            g[i][j]=100000;
        }
        //g[i][i]=0;
    }
}
int main()
{
    int tc,M,E,T,a,b,t,i,c;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        f=true;
        scanf("%d %d %d %d",&N,&E,&T,&M);
        reset();
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&t);
            g[a][b]=t;
        }
        warshal();
        g[E][E]=0;

        c=0;
        for(i=1;i<=N;i++)
        {
            if(g[i][E]<=T)
                c++;
        }
        printf("%d\n",c);

    }
    return 0;
}
