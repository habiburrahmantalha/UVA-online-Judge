#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int t,n,p,q,x[50],j,i,sum;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(j=0;j<n;j++)
        {
            scanf("%d",&x[j]);
        }
        sort(x,x+n);
        sum=0;
        for(j=0;j<p && j<n;j++)
        {
            sum+=x[j];
            if(sum>q)
            break;
        }

        printf("Case %d: %d\n",i+1,j);
    }
    return 0;
}

