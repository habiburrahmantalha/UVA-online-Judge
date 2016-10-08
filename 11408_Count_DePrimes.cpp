#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 5000000

using namespace std;

bool mark [N+10];
int deprime[N+5];
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
    //printf("%d",prime.size());
}
int SOPF(int x)
{
    int i,sum=0;
    bool f;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        f=false;
        while(x%prime[i]==0)
        {
            x/=prime[i];
            f=true;
        }
        if(f)
            sum+=prime[i];
        if(x==1)
            return sum;
    }
    return sum+x;
}
void DePrime()
{
    int i;
    for(i=2;i<=N/2;i++)
    {

        if(mark[SOPF(i)])
        {
            deprime[i]=1;
            //printf("%3d ",i);
            //if(i%20==0)
                //printf("\n");
        }
    }
}

int main()
{
    sieve();
    DePrime();

    return 0;
}

