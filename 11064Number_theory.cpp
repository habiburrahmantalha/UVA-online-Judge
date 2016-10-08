#include<stdio.h>
#include<string.h>
#include<vector>

#define N 47000

using namespace std;

bool prime[N+10];
vector<long long> Prime;


void sieve()
{
    long long i,j;
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;

    for(i = 4; i < N; i+=2)
    prime[i] = false;
    for(i = 3; i * i < N; i++)
    {
        if(prime[i])
        for (j = i * i; j < N; j += 2 * i )
        prime[j]=false;

    }
    for(j = 1; j < N; j++)
    if(prime[j])
    Prime.push_back(j);

    //printf("%d",Prime.size());
}

long long NOD(long long x)
{
    long long p,i;
    long long nod=1;

    for(i=0;Prime[i]*Prime[i]<=x;i++)
    {
        p=1;
        while(x%Prime[i]==0)
        {
            p++;
            x/=Prime[i];
        }
        nod*=p;
        if(x==1)
        break;
    }
    if(x!=1)
    return nod*2;

    return nod;
}
long long PHI(long long x)
{

    bool f;
    long long Euler=x;
    long long i,a=1,b=1;

    for(i=0;Prime[i]*Prime[i]<=x;i++)
    {
        f=true;
        while(x%Prime[i]==0)
        {
            x/=Prime[i];
            if(f)
            {
                a*=(Prime[i]);
                b*=(Prime[i]-1);
                f=false;
            }
        }
        if(x==1)
        break;
    }
    if(x!=1)
    {
        a*=x;
        b*=x-1;
    }
    Euler=(Euler/a)*b;
    return Euler;
}

int main()
{
    sieve();
    long long x,res;
    while(scanf("%lld",&x)==1)
    {
        if(x==0)
        printf("0\n");
        else
        {
            res=x-PHI(x)-NOD(x)+1;
            printf("%lld\n",res);
        }
    }
    return 0;
}


