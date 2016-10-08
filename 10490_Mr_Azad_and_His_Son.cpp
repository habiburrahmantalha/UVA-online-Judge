#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
#define N 1000001
#define LL long long
using namespace std;

bool mark [N+10];
long long RP[35],P[35];
vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for (i = 4; i < N; i += 2 )
        mark [i] = false;

    for (i = 3; i * i <= N; i++ )
        if ( mark [i] )
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = false;

    prime.clear ();
    prime.push_back (2);

    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
                prime.push_back (i);

    }

}
void relative_perfect()
{
    long long i;
    for(i=1;i<=32;i++)
    {
        RP[i]=pow(2,i-1)*(pow(2,i)-1);
        //printf("%lld\n",RP[i]);
    }
    //RP[31]++;
}
LL SOD(LL n)
{
    if(n<N && mark[n])
    return n+1;
    LL sod=1,a=0;
    int i;
    for ( i = 0;prime[i]*prime[i]<= n; i ++ )
    {
        a=0;
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            a++;
        }
        sod*=(pow(prime[i],a+1)-1)/(prime[i]-1);
        //printf("%lld %d",sod,i);
        if(n==1)
        return sod/2;


    }
    if(n>1)
        sod*=(pow(n,2)-1)/(n-1);
    return sod/2;
}

void perfect_number()
{
    LL x;
    int i;
    for(i=1;i<=32;i++)
    {

        if(SOD(RP[i])==RP[i])
        P[i]=1;
        else
        P[i]=0;

    }
        //printf("%lld\n",SOD(RP[31]));
}
int main()
{
    sieve();
    relative_perfect();
    perfect_number();
    LL n;
    while(scanf("%lld",&n) && n)
    {
        if(P[n]==1)
            printf("Perfect: %lld!\n",RP[n]);
        else if(mark[n])
            printf("Given number is prime. But, NO perfect number is available.\n");
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
