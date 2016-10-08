#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 100000

using namespace std;

bool mark [N+10];

vector <long long> primeList;

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


    primeList.clear ();
    primeList.push_back (2);
    int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            {
                primeList.push_back (i);
                count++;
                printf("%d ",i);
            }
    }
    printf("%d",count);
}
long long sum_digit(long long n)
{
    long long sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
long long factorial(long long n)
{
    long long i,fact=0,p=n;

    for(i=0;primeList[i]*primeList[i]<=n;i++)
    {
        while(n%primeList[i]==0)
        {
            //printf("%lld ",primeList[i]);
            n=n/primeList[i];
            fact+=sum_digit(primeList[i]);
        }
    }
    if(n!=1)
    fact+=sum_digit(n);
    if(n==p)
    return 0;
    return fact;
}

int main()
{
    sieve();
    int tc;
    long long n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        //printf("%lld ",factorial(n));

        for(n=n+1;;n++)
        if(sum_digit(n)==factorial(n))
        {
            printf("%lld\n",n);
            break;
        }


    }

    return 0;
}
