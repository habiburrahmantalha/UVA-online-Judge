#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd



void yarins_sieve()
{
    int i,j;
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
    if (a[i>>3]&(1<<(i&7)))
    for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
    a[j>>3]&=~(1<<(j&7));


}
int main()
{

	yarins_sieve();

	int x,y,i,z,zz;
	bool f;

    while(scanf("%d",&x)==1)
    {
        f=false;
        if(x%2!=0)
        {
            if(isprime(x-2))
            {
                z=2;
                zz=x-2;
                f=true;
            }
        }
        else
        {

            y=x/2;
            if(y%2==0)
                y++;
            for(i=y;i>=3;i-=2)
            {
                if(isprime(i)&& isprime(x-i))
                {
                    z=i;
                    zz=x-z;
                    if(z==zz)
                        continue;
                    f=true;
                    break;
                }

            }
        }
        if(z>zz)
            swap(z,zz);
        if(f==false)
        printf("%d is not the sum of two primes!\n",x);
        else
        printf("%d is the sum of %d and %d.\n",x,z,zz);
    }

    return 0;
}

