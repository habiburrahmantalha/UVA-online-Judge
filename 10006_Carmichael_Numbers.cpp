#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 65000

long long n;
bool mark[N+5],C[N+5];

void sieve ()
{
    long long i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for (i = 4; i < N; i += 2 )
        mark [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( mark [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

}



long long fast_mod_pow(long long b,long long e,long long m)
{
    long long r = 1;
    while (e > 0) {
        if ((e & 1) == 1) {
	    r = (r * b) % m;
        }
        e >>= 1;
        b = (b * b) % m;
    }
    return r;
}
void Carmichael()
{
    memset (C,false, sizeof (C));
    long long i,j;
    for(i=9;i<=N;i+=2)
        C[i]=true;
    for(i=9;i<=N;i+=2)
    {
        if(mark[i])
            C[i]=false;
        else
        for(j=2;j<i;j++)
        if(fast_mod_pow(j,i,i)!=j)
        {
            C[i]=false;
            break;
        }
    }
    for(i=0;i<=N;i++)
        if(C[i])
        printf("%d ",i);
}
int main()
{
    long long car[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
    memset (C,false, sizeof (C));
    for(int i=0;i<15;i++)
        C[car[i]]=true;
    //sieve ();
    //Carmichael();
    while(scanf("%lld",&n) && n)
    {

        if(C[n])
            printf("The number %d is a Carmichael number.\n",n);
        else
            printf("%d is normal.\n",n);
    }
    return 0;
}
