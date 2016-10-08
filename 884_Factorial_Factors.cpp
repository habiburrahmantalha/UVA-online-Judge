#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 1000010

using namespace std;

int mark [N+10],F[N+10];

vector <int> prime;

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
int prime_factor(int x)
{
    int c=0,i;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        while(x%prime[i]==0)
        {
            x/=prime[i];
            c++;
        }
        if(F[x])
        return F[x]+c;
        if(mark[x])
        return c+1;
    }
    return c;
}
void precal()
{
    int i;
    for(i=0;i<N;i++)
    if(mark[i])
    F[i]=1;
    else
    F[i]=prime_factor(i);

    for(i=1;i<N;i++)
    F[i]+=F[i-1];

}
int main()
{
    sieve();
    precal();
    int x;
    while(scanf("%d",&x)==1)
    {
        printf("%d\n",F[x]);
    }
    return 0;
}
