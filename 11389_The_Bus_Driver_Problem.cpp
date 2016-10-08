#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int n,r,d,m[110],e[110],i,sum;
    while(scanf("%d %d %d",&n,&d,&r)==3 && r+d+n)
    {
        for(i=0;i<n;i++)
        scanf("%d",&m[i]);

        for(i=0;i<n;i++)
        scanf("%d",&e[i]);

        sort(m,m+n);
        sort(e,e+n);

        sum=0;
        for(i=0;i<n;i++)
        if(d<m[i]+e[n-1-i])
        sum+=(m[i]+e[n-1-i]-d);

        printf("%d\n",sum*r);
    }
    return 0;
}
