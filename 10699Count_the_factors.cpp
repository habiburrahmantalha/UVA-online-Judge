#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<set>

#define N 10000000

using namespace std;

bool mark [N+10];

vector <int> primeList;

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
    primeList.clear ();
    primeList.push_back (2);
    //int count=0;
    for ( i = 3; i < N; i += 2 )
    {
        if ( mark [i] )
            {
                primeList.push_back (i);
                //count++;
            }
    }
    //printf("%d",count);
}
int factorial(int n)
{
    int i;
    set<int>fact;
    for(i=0;primeList[i]*primeList[i]<=n;i++)
    {
        while(n%primeList[i]==0)
        {
            n=n/primeList[i];
            fact.insert(primeList[i]);
        }
    }
    if(n!=1 && mark[n])
    fact.insert(n);

    return fact.size();
}
int main()
{
    sieve();
    int n;

    while(scanf("%d",&n) && n)
    {
        if(n<0)
        printf("%d : 1\n",n);
        else
        printf("%d : %d\n",n,factorial(n));
    }

    return 0;
}
