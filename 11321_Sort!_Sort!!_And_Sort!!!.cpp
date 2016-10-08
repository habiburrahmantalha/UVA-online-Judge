#include<stdio.h>
#include<algorithm>
using namespace std;
struct NM
{
    int n,m;
};
bool comp(NM a,NM b)
{
    if(a.m==b.m)
    {
        if((a.n&1) && (b.n&1))
        return a.n>b.n;
        else if(!(a.n&1) && !(b.n&1))
        return a.n<b.n;
        else
        return  (a.n&1);
    }
    return a.m<b.m;
}
int main()
{
    int n,m,i;
    NM x[10010];
    while(scanf("%d %d",&n,&m) && n+m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i].n);
            x[i].m=x[i].n%m;
        }
        sort(x,x+n,comp);
        printf("%d %d\n",n,m);
        for(i=0;i<n;i++)
        printf("%d\n",x[i].n);
    }
    printf("0 0\n");
    return 0;
}
