#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,i,x[10010],t=1,mn;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;

        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        for(i=0;i<m;i++)
            scanf("%*d");

        if(n>m)
        {
            mn=100;
            for(i=0;i<n;i++)
            if(mn>x[i])
                mn=x[i];
            printf("Case %d: %d %d\n",t++,n-m,mn);

        }
        else
            printf("Case %d: 0\n",t++);
    }
    return 0;
}
