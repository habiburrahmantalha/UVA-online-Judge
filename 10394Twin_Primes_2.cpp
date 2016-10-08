#include<stdio.h>
#include<string.h>


#define MAXSIEVE 18409210//20000000//100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 2150 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

int twin[100030];

void yarins_sieve()
{
    int i,j;
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
    if (a[i>>3]&(1<<(i&7)))
    for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
    a[j>>3]&=~(1<<(j&7));

    int in=1;
    for(i=3;in<100010 ;i+=2)
	{
	    if(isprime(i) && isprime(i+2))
	    twin[in++]=i;
	}
}

int main()
{
    yarins_sieve();
    int x;
    while(scanf("%d",&x)==1)
    {

        printf("(%d, %d)\n",twin[x],twin[x]+2);
    }
    return 0;
}
