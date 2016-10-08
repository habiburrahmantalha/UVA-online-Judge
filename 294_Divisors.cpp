#include<stdio.h>
#define N 1000001
#include<vector>
#include<string.h>
using namespace std;

bool mark [N+10];

vector <long long> prime;
long long L,U;
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

    prime.clear ();
    prime.push_back (2);
    //int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }
    //printf("%d",primeList.size());
}
long long NOD(long long x)
{
    long long p,i;
    long long nod=1;

    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        p=1;
        while(x%prime[i]==0)
        {
            p++;
            x/=prime[i];
        }
        nod*=p;
        if(x==1)
        break;
    }
    if(x!=1)
    return nod*2;

    return nod;
}

void heighest_NOD()
{
    long long i,d,max=0,num;
    for(i=L;i<=U;i++)
    {
        d=NOD(i);
        if(max<d)
        {
            max=d;
            num=i;
        }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,num,max);
}

int main()
{
    sieve();
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&L,&U);
        heighest_NOD();
    }
    return 0;
}
