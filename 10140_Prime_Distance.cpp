#include<cstdio>
#include<vector>
#include<cstring>

#define N 47000

using namespace std;

struct PRIME
{
    int v,up,down,du,dd;
};

bool Prime[N+10];
vector<PRIME>p;
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
    //int count=0;
    for ( i = 3; i <47000; i += 2 ) {
        if ( Prime [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }

}
void precal()
{
    for(i=0;i<prime.size();i++)
    {

    }
}
bool is_prime(long long x)
{
    if(x<N)
    return Prime[x];
    long long i;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)
        return false;
    }
    return true;
}
long long next_prime(long long i,long long j)
{
    while(i<=j)
    {
        if(is_prime(i))
        return i;
        i++;
    }
    return 0;
}
int main()
{
    sieve();
    long long i,j,k,a,b,c,d,cp1,cp2,dp1,dp2,mx,mn;
    while(scanf("%lld %lld",&i,&j)==2)
    {
        if(i>j)
        {
            i^=j;
            j^=i;
            i^=j;
        }

        a=b=cp1=cp2=dp1=dp2=0;
        mx=0;
        mn=2147483647;

        a=next_prime(i,j);
        //printf("%d",a);
        if(a)
        {
            i=a;
            while(i<=j)
            {
                b=next_prime(i+1,j);
                //printf(" %d",b);
                if(b)
                {
                    //printf("%lld %lld %lld\n",a,b,b-a);
                    if((b-a)<mn)
                    {
                        //printf("->%lld %lld\n",b-a,mn);
                        cp1=a;
                        cp2=b;
                        mn=b-a;
                    }
                    if((b-a)>mx)
                    {
                        dp1=a;
                        dp2=b;
                        mx=b-a;
                    }
                    a=i=b;

                }
                else
                break;
            }
        }


        if(!cp1 || !cp2 || !dp1 || !dp2 )
        printf("There are no adjacent primes.\n");
        else
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",cp1,cp2,dp1,dp2);
    }
    return 0;
}

