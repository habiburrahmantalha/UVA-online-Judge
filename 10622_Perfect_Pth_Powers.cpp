#include<stdio.h>
#include<string.h>
#include<math.h>

long long POW(long long x,long long y)
{
    long long z=x;
    for(int i=1;i<y;i++)
    z*=x;

    return z;
}
int main()
{
    double y;
    long long i,z,x;
    while(scanf("%lld",&x) && x)
    {
        if(x<0)
        {
            x=-x;
            for(i=31;i>=1;i-=2)
            {
                y=pow((double)x,1/(double)i);
                y+=0.0000001;
                z=(long long)y;
                //printf("%lld %lld %lld\n",i,z,POW(z,i));
                if(x==POW(z,i))
                break;
            }
        }
        else
        {
            long long len=sqrt(x);
            for(i=32;i>=1;i--)
            {
                y=pow((double)x,1/(double)i);
                y+=0.0000001;
                z=(long long)y;
                //printf("%lld %lld %lld\n",i,z,POW(z,i));
                if(x==POW(z,i))
                break;
            }
        }


        printf("%lld\n",i);
    }
    return 0;
}

