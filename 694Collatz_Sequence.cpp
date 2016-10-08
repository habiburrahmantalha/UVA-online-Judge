#include<stdio.h>

int main()
{
    long long a,l,tc=1,count,n;
    while(scanf("%lld %lld",&a,&l))
    {
        if(a<0 && l<0)
        break;
        count=0;
        n=a;
        while(1)
        {
            if(n>l)
            break;
            if(n==1)
            {
                count++;
                break;
            }
            if(n%2==0)
            n/=2;
            else
            n=3*n+1;

            count++;

        }
       printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",tc++,a,l,count);
    }
    return 0;

}
