#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

bool comp(long double a,long double b)
{
    return a>b;
}

int main()
{
    int tc,n,i;
    long double a[10010],s,area,max;
    bool f;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%Lf",&a[i]);
        }
        sort(a,a+n,comp);
        max=0;
        for(i=0;i<n-2;i++)
        {
            if(a[i]<a[i+1]+a[i+2])
            {
                s=a[i]+a[i+1]+a[i+2];
                s/=2;
                area=sqrt(s)*sqrt(s-a[i])*sqrt(s-a[i+1])*sqrt(s-a[i+2]);
                if(max<area)
                max=area;
            }
        }

        printf("%.2Lf\n",max);

    }
    return 0;
}
