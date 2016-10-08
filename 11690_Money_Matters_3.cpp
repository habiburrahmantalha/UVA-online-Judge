#include<stdio.h>
#include<string.h>

int n,P[10010];

void reset()
{
    int i;
    for(i=0;i<n;i++)
    P[i]=i;
}

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];
}

void unionset(int x ,int y)
{
    int px=findset(x);
    int py=findset(y);
    P[py]=P[px];
}

int main()
{
    int tc,i,j,a,b,m,x[10010],f[10010];

    bool impossible;

    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d",&n,&m);
        reset();
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            f[i]=0;
        }

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            unionset(a,b);
        }

        for(i=0;i<n;i++)
        {
            findset(i);
            f[P[i]]+=x[i];
        }
        impossible=false;
        for(i=0;i<n;i++)
        {
            if(f[i]!=0)
            {
                impossible=true;
                break;
            }
        }
        if(impossible)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");

    }
    return 0;
}
