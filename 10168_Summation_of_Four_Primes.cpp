#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

#define MAXSIEVE 10000001//100000000//61474836//47//10000000//20000000//100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT sqrt(MAXSIEVE)/2 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd
bool isp(int x)
{
    if(x==2)
    return true;
    if(x&1 && isprime(x))
    return true;
    return false;
}
void yarins_sieve()
{
    int i,j;
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
    if (a[i>>3]&(1<<(i&7)))
    for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
    a[j>>3]&=~(1<<(j&7));
    /*
    int c=0;
    for(i=3;i<100000;i++)
    if(i&1 && isprime(i))
    c++;
    //printf("%d ",i);
    printf("%d\n",c);
    */
}
int main()
{
    yarins_sieve();
    int x,i;
    while(scanf("%d",&x)==1)
    {
        //if(prime[x])
        //printf("x");
        //continue;
        if(x>=8)
        {
            if(x&1)
            printf("2 3 ");
            else
            printf("2 2 ");
            x-=(4+(x&1));
            if(isp(x-2))
                    printf("%d %d\n",2,x-2);
            else
            for(i=3; ;i+=2)
            {
                if(isp(i) && isp(x-i))
                {
                    printf("%d %d\n",i,x-i);
                    break;
                }
            }
        }
        else
        printf("Impossible.\n");

    }
    return 0;
}
