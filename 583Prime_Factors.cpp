#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 65000

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
    //int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            {
                primeList.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }
    //printf("%d",count);
}
void factorial(long long n)
{
    long long i;
    vector<long long>fact;
    for(i=0;primeList[i]*primeList[i]<=n;i++)
    {
        while(n%primeList[i]==0)
        {
            n=n/primeList[i];
            fact.push_back(primeList[i]);
        }
    }
    if(n!=1)
    fact.push_back(n);
    for(i=0;i<fact.size()-1;i++)
        printf("%lld x ",fact[i]);
    printf("%lld\n",fact[fact.size()-1]);

}
int main()
{
    sieve();
    long long n;

    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
        break;

        printf("%lld = ",n);
        if(n==1)
        printf("1\n");
        else if(n==-1)
        printf("-1 x 1\n");
        else if(n<0)
        {
            printf("-1 x ");
            n=-n;
            factorial(n);
        }
        else
        factorial(n);

    }

    return 0;
}
