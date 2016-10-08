#include<cstdio>
#include<vector>
#include<cstring>

#define N 10000000

using namespace std;

bool Prime[N+10];

vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (Prime, true, sizeof (Prime));
    Prime [0] = Prime [1] = false;

    for (i = 4; i <= N; i += 2 )
        Prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( Prime [i] )
        {
            for (j = i * i; j <= N; j += 2 * i )
                Prime [j] = false;
        }
    }

    prime.clear ();
    prime.push_back (2);
    //int count=0;
    for ( i = 3; i <= N; i += 2 ) {
        if ( Prime [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }

}
void prime_factor(long long x)
{
    int i;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        while(x%prime[i]==0)
        {
            printf("    %lld\n",prime[i]);
            x/=prime[i];
        }
    }
    if(x!=1)
    printf("    %lld\n",x);
}
int main()
{
    sieve();
    long long x;
    while(scanf("%lld",&x) && x>=0)
    {
        prime_factor(x);
        printf("\n");
    }
    return 0;
}
