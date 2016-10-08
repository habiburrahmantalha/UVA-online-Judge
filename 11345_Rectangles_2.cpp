#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    long long t=1,tc,x1,x2,y1,y2,a,b,i,j,n,x[20010],y[20010];
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        memset(y,0,sizeof(y));
        memset(x,0,sizeof(x));
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);


            a=min(x1+10000,x2+10000);
            b=max(x1+10000,x2+10000);
            a=x1+10000;
            b=x2+10000;
            //printf("%d %d",a,b);
            for(j=a;j<=b;j++)
            x[j]++;


            a=min(y1+10000,y2+10000);
            b=max(y1+10000,y2+10000);
            //printf("%d %d",a,b);
            a=y1+10000;
            b=y2+10000;
            for(j=a;j<=b;j++)
            y[j]++;
        }

        a=0;
        for(i=0;i<=20000;i++)
        if(x[i]==n)
        a++;

        b=0;
        for(i=0;i<=20000;i++)
        if(y[i]==n)
        b++;
        if(a && b)
        printf("Case %lld: %lld\n",t++,(a-1)*(b-1));
        else
        printf("Case %lld: 0\n",t++);
    }
    return 0;
}
