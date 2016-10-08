#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long

LL fact(LL n)
{
    LL f=1,i;
    for(i=1;i<=n;i++)
    f*=i;
    return f;
}

int main()
{
    LL t=1,tc,i,j,n,m,p,l,a,k;
    char str[35],res[35];
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%s %lld",str,&n);
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            m=fact(l-i);
            p=m/(l-i);
            a=n%m;

            for(k=p,j=0;k<=a;j++)
            k+=p;

            printf("%lld %lld %lld %lld\n",m,p,a,j);


            res[j+i]=str[i];
        }
        res[l]=0;
        printf("Case %lld: %s\n",t++,res);
    }
    return 0;
}
