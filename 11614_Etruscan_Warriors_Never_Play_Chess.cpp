#include<stdio.h>
#include<math.h>
#define LL long long

LL precal(LL x)
{
    LL y,mid,p=0;
    LL low=1;
    LL high=x;
    x*=2;
    while(1)
    {
        p=mid;
        mid=(low+high)/2;
        if(p==mid)
            return mid;
        y=x/(mid+1);
        if(y==mid)
            return mid;
        if(mid<y)
            low=mid-1;
        else
            high=mid+1;
    }

}
int main()
{

    LL res,x;
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%lld",&x);
        //res=log2(x);
        //printf("%lld\n",res);
        res=precal(x);
        printf("%lld\n",res);
    }
    return 0;
}
