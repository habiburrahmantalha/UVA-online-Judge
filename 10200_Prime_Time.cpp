#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
#define N 100000
#define M 10000
#include <iostream>
#include <iomanip>
#define eps 1e-9
using namespace std;


bool mark [N+10];
int eprime[M+5],p[N+5];
vector <int> prime;

void sieve ()
{
    int i,j;
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

    prime.clear ();
    prime.push_back (2);
    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
                prime.push_back (i);
    }
}
void euler_prime()
{
    int i;
    for(i=0;i<=M;i++)
    {
        eprime[i]=i*i+i+41;
    }
}
bool isprime(int x)
{
    int i;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)
            return false;
    }
    return true;
}
void primes()
{
    memset(p,0,sizeof(p));
    int i,c=1;
    for(i=0;i<=M;i++)
    {
        if(isprime(eprime[i]))
            p[i]=1;
    }

}

int main()
{
    sieve();
    euler_prime();
    primes();

    int a,b,i,j;
    double res,c,n;

    while(scanf("%d %d",&a,&b)==2)
    {
        c=n=0.0;
        for(i=a;i<=b;i++)
        {
            n++;
            if(p[i])
                c++;
        }

        res=c/n*100;
        printf("%.2lf\n",res+eps);
    }

    return 0;
}

