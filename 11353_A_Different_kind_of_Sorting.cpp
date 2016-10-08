#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 2000000

using namespace std;

bool Prime[N+10];

vector <int> prime;
struct PF
{
    int n,f;
};
PF res[N+5];

void sieve ()
{
    int i,j;
    memset (Prime, true, sizeof (Prime));
    Prime [0] = Prime [1] = false;

    for (i = 4; i <= N; i += 2 )
        Prime [i] = false;

    for (i = 3; i * i <= N; i++ )
        if ( Prime [i] )
            for (j = i * i; j < N; j += 2 * i )
                Prime [j] = false;

    prime.clear ();
    prime.push_back (2);

    for ( i = 3; i <=N; i += 2 )
        if ( Prime [i] )
                prime.push_back (i);
}
int prime_factor(int x)
{
    if(Prime[x])
    return 1;
    int c=0,i;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        while(x%prime[i]==0)
        {
            c++;
            x/=prime[i];
            if(res[x].n)
            return res[x].f+c;
            if(Prime[x])
            return c+1;

        }
    }
    if(Prime[x])
    return c+1;
    else
    return c;
}

void factors()
{
    int i;
    res[1].n=1;
    res[1].f=0;
    for(i=2;i<=N;i++)
    {
        res[i].n=i;
        res[i].f=prime_factor(i);
    }
}
bool comp(PF a,PF b)
{
    if(a.f==b.f)
    return a.n<b.n;
    return a.f<b.f;
}
int main()
{
    sieve();
    factors();
    sort(res,res+N+1,comp);
    int n,t=1;
    while(scanf("%d",&n) && n)
    {
        printf("Case %d: %d\n",t++,res[n].n);
    }
    return 0;
}
