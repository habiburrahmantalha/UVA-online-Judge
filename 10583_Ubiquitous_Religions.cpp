#include<stdio.h>
#include<string.h>

int R[50010],P[50010];
int n,m;

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];

}
void reset()
{
    for(int i=1;i<=n;i++)
    {
        P[i]=i;
        R[i]=0;
    }
}
void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);

    if(R[px]>R[py])
        P[py]=px;
    else
        P[px]=py;
    if(R[px]==R[py])
        R[py]=R[px]+1;
}
int main()
{
    int a,b,i,mx,f[50010],t=1;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;

        reset();
        memset(f,0,sizeof(f));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            unionset(a,b);
        }
        for(i=1;i<=n;i++)
        {
            findset(i);
            f[P[i]]++;
        }
        mx=0;
        for(i=1;i<=n;i++)
        {
            //printf("%d %d\n",i,f[i]);
            if(f[i])
            mx++;
        }
        printf("Case %d: %d\n",t++,mx);
    }
    return 0;
}


