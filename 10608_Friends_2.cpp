#include<stdio.h>
#include<string.h>

int P[30010];
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
        P[i]=i;


}
void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);
    P[py]=P[px];
}
int main()
{
    int a,b,i,mx,tc,f[30010];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);

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
        if(mx<f[i])
            mx=f[i];
        printf("%d\n",mx);
    }
    return 0;
}

