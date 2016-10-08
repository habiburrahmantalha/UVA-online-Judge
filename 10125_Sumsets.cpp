//Problem Type :
//Time :    0.576
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
long long b[1000010][2];

int main()
{
    long long n,a[1010],i,j,k;
    map<long long,int> m;

    bool f;
    while(scanf("%lld",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

        sort(a,a+n);
        k=1;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]!=a[j])
                {
                    b[k][0]=a[i];
                    b[k][1]=a[j];
                    m[a[i]+a[j]]=k++;

                }
            }
        }
        f=false;

        for(i=n-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==j || a[i]==a[j])
                continue;

                k=m[a[i]-a[j]];
                if(k>0)
                {

                    if((b[k][0]!=a[i] && b[k][1]!=a[i]) && (b[k][0]!=a[j] && b[k][1]!=a[j]))
                    {
                        //printf("%lld %lld %lld %lld\n",a[i],a[j],b[k][0],b[k][1]);
                        printf("%lld\n",a[i]);
                        f=true;
                        i=j=0;
                    }
                }
            }
        }
        if(!f)
        printf("no solution\n");

        m.clear();
    }
    return 0;
}
