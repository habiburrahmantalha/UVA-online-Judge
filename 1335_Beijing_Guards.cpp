#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

int a[100010];
int main()
{
    int n,i,mx,x,y;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[n];
        a[n+1]=a[1];
        mx=0;

        if(n&1)
        {
            if(n==3)
                mx=a[1]+a[2]+a[3];
            else
            for(i=1;i<=n;i++)
            {
                x=a[i]+a[i+1];
                y=a[i]+a[i-1];
                if(x==y)
                    mx=max(mx,x+1);
                else if(x>y)
                    mx=max(mx,x);
                else
                    mx=max(mx,y);
            }

        }
        else
        {
            for(i=0;i<=n;i++)
            {
                mx=max(mx,a[i]+a[i+1]);

            }

        }
        printf("%d\n",mx);
    }
    return 0;
}
