#include<stdio.h>
#include<string.h>
#include<vector>

#define N 32000

using namespace std;

bool prime[N+10];
vector<int> Prime;

void sieve()
{
    int i,j;
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


int PHI(int x)
{

    int i,num,a=1,b=1;
    bool f=false;
    num=x;
    for(i=0;i<Prime.size();i++)
    {
        f=false;
        while(x%Prime[i]==0)
        {
            x/=Prime[i];
            f=true;
        }
        if(f==true)
        {
            //num*=(num/Prime[i])*(Prime[i]-1);
            //printf("%d ",Prime[i]);
            a*=(Prime[i]-1);
            b*=Prime[i];
        }

        if(x==1)
        return ((num/b)*a);

    }
    //num*=(num/Prime[i])*(Prime[i]-1);
    a*=x-1;
    b*=x;
    return ((num/b)*a);
}

int main()
{
    sieve();
    int x;
    while(scanf("%d",&x) && x)
    {
        printf("%d\n",PHI(x));
    }

    return 0;
}

