#include<stdio.h>
#include<math.h>


int main()
{
    long long a,b,x,y,z,zz;


    while(scanf("%lld",&x) && x)
    {

        y=floor(sqrt(x));
        z=y*y;
        zz=(y+1)*(y+1);

        if(y&1)
        {
            if(z==x)
            {
                a=1;
                b=y;
            }
            else if(x-z<=y+1)
            {
                a=x-z;
                b=y+1;
            }
            else
            {
                a=y+1;
                b=zz-x+1;
            }


        }
        else
        {
            if(z==x)
            {
                a=y;
                b=1;
            }
            else if(x-z<=y+1)
            {
                a=y+1;
                b=x-z;
            }
            else
            {

                a=zz-x+1;
                b=y+1;
            }

        }
        printf("%lld %lld\n",a,b);
    }
    return 0;
}
