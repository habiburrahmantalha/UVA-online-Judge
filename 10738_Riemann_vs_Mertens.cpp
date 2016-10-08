#include<cstdio>
#include<vector>
#include<cstring>

#define N 1000001

using namespace std;

bool Prime[N+10];

vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (Prime, true, sizeof (Prime));
    Prime [0] = Prime [1] = false;

    for (i = 4; i < N; i += 2 )
        Prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( Prime [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                Prime [j] = false;
        }
    }

    prime.clear ();
    prime.push_back (2);
    //int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( Prime [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }

}
int mu[N],M[N];
void cal_mu(int x)
{
    if(Prime[x])
    {
        mu[x]=-1;
        return;

    }

    int i,c,y;
    y=x;
    c=0;
    for(i=0;prime[i]*prime[i]<=x;i++)
    {

        if(x%prime[i]==0)
        {

            c++;
            x/=prime[i];
            if(x%prime[i]==0)
            {
                mu[y]=0;
                return;
            }

        }

    }
    if(Prime[x])
    c++;
    if(c&1)
    mu[y]=-1;
    else
    mu[y]=1;
}
void precal()
{
    int i;
    sieve();
    mu[1]=M[1]=1;

    for(i=2;i<N;i++)
    {
        cal_mu(i);
        M[i]=M[i-1]+mu[i];
    }
}
int main()
{
    precal();
    int x;
    while(scanf("%d",&x)==1 && x)
    {
        printf("%8d%8d%8d\n",x,mu[x],M[x]);
    }
    return 0;
}
