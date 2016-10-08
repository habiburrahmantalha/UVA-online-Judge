#include<stdio.h>

int XLL[10001],XUR[10001],YLL[10001],YUR[10001];
int r;

bool no_overlap()
{
    int i;
    if(r==0)
        return true;
    for(i=0;i<r;i++)
    {
        if(YLL[i]>=YUR[r])
            continue;
        else if(YLL[r]>=YUR[i])
            continue;
        else if(XLL[i]>=XUR[r])
            continue;
        else if(XLL[r]>=XUR[i])
            continue;
        else
        return false;
    }
    return true;
}
int main()
{
    int tc,t,n,m,area;
    scanf("%d",&tc);

    for(t=1;t<=tc;t++)
    {
        scanf("%d",&n);
        r=0;
        area=0;
        for(m=0;m<n;m++)
        {
            scanf("%d %d %d %d",&XLL[r],&YLL[r],&XUR[r],&YUR[r]);
            XLL[r]+=100;YLL[r]+=100;XUR[r]+=100;YUR[r]+=100;
            if(no_overlap())
            {
                area+=(XUR[r]-XLL[r])*(YUR[r]-YLL[r]);
                r++;
            }
        }
        printf("Case %d: %d\n",t,area);
    }
    return 0;
}
