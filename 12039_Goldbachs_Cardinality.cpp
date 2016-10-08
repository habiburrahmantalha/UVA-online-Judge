#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 1000000

using namespace std;

bool mark [N+10];
int G[N+10];
vector <long long> prime;

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
    printf("%d\n",prime.size());
    printf("%d\n",prime[prime.size()-1]);
}
void gold()
{
    memset(G,0,sizeof(G));
    for(int i=0;i<100;i++)
    {
        for(int j=i+1;j<prime.size();j++)
        {
            if(prime[i]+prime[j]>N)
            break;
            G[prime[i]+prime[j]]++;
        }
    }
    for(int i=2;i<105;i+=2)
        printf("%d %d\n",i,G[i]);
}
int main()
{
    sieve();
    gold();
    return 0;
}
