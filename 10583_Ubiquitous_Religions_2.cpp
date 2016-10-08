#include<stdio.h>
#include<string.h>

int P[50010],R[50010];
int n,m,size;

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];

}
void reset()
{
    size=n;
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
    if(py!=px)
        size--;

    if(R[px]>R[py])
        P[py]=px;
    else
        P[px]=py;
    if(R[px]==R[py])
        R[py]=R[px]+1;
}
int main()
{
    int a,b,i,t=1;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;

        reset();

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            unionset(a,b);
        }

        printf("Case %d: %d\n",t++,size);
    }
    return 0;
}


