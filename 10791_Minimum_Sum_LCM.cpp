//Problem Type :
//Time :    0.008
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)
#define N 47000

bool Prime[N+10];

vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (Prime, true, sizeof (Prime));
    Prime [0] = Prime [1] = false;

    for (i = 4; i < N; i += 2 )
        Prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( Prime [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                Prime [j] = false;
        }
    }

    prime.clear ();
    prime.push_back (2);
    for ( i = 3; i < N; i += 2 ) {
        if ( Prime [i] )
            {
                prime.push_back (i);
            }
    }

}
bool isprime(long long n)
{
    if(n<N)
    {
        if(Prime[n])
            return true;
        else
            return false;
    }
    int i;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
            return false;
    }
    return true;

}
long long MinLCM(long long n)
{
    int i;
    long long x,y,c=0;
    if(n==1)
    return 2;
    y=0;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {

            x=1;
            c++;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                x*=prime[i];
            }


            y+=x;

        }
    }
    if(n>1)
    {
        y+=n;
        c++;
    }
    if(c<=1)
    y+=1;



    return y;
}
int main()
{
    sieve();
    long long n,t=1;
    while(scanf("%lld",&n) && n)
    {
        if(isprime(n))
            printf("Case %lld: %lld\n",t++,n+1);
        else
            printf("Case %lld: %lld\n",t++,MinLCM(n));
    }
    return 0;
}
