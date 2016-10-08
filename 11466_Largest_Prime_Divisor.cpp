#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 10000001

using namespace std;

bool mark [N+10];

vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (mark, true, sizeof (mark));
    //mark [0] = mark [1] = false;

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

}
long long LPD(long long x)
{
    int i;
    long long c=0,l;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)
        {
            c++;
            l=prime[i];
            while(x%prime[i]==0)
                x/=prime[i];
        }
    }
    if(c>0 && x!=1)
        return x;
    else if(x!=1 || c==0)
    return 0;
    else if(c==1 && x==1)
    return 0;
    else
    return l;

}
int main()
{
    sieve();
    long long n,x;
    while(scanf("%lld",&n) && n)
    {
        if(n<0)
            n=-n;
        if(n<N && mark[n])
            printf("-1\n");
        else
        {
            x=LPD(n);
            if(x<=1)
                printf("-1\n");
            else
                printf("%lld\n",x);
        }
    }
    return 0;
}
