#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int a[20],i,j,n,t;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        sort(a,a+n);
        printf("Case %d: %d\n",i+1,a[n/2]);
    }
    return 0;
}

