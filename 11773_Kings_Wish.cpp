//Problem Type :
//Time :
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

#define N 10000001

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
struct tiles
{
    long long L,W,D,P;
};
bool cmp(tiles a,tiles b)
{
    if(a.D==b.D)
        return a.P>b.P;
    else
        return a.D>b.D;
}
map<long long,long long> res;
bool divs(long long x)
{

    long long y,z=x,i;
    res.clear();
    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)
        {
            y=1;
            while(x%prime[i]==0)
            {
                x/=prime[i];
                y*=prime[i];
            }
            res[prime[i]]=y;
        }
    }
    if(x!=1)
        res[x]=x;

    if(z!=x)
    return false;
    else
    return true;

}
tiles T[100100];
int main()
{
    sieve();
    int tc,t=1,i;
    map<long long,long long>::iterator it;
    long long x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld",&x);
        if(divs(x))
            printf("Case %d: Impossible\n",t++);
        else
        {
            /*
            for(it=res.begin();it!=res.end();it++)
            {
                if(it->first<it->second)
                {
                    T[i].W=x/it->first;
                    T[i].L=it->second;
                }
                else
                {
                    T[i].W=x/it->second;
                    T[i].L=it->first;

                }

                T[i].W=x/it->first;
                T[i].L=it->second;
                T[i].D=T[i].L-T[i].W;
                T[i].P=2*(T[i].L+T[i].W);
            }
            sort(T,T+i,cmp);
            printf("Case %d: %lld %lld\n",t++,T[0].L,T[0].W);
            //*/
            //sort(res.begin(),res.end());
            //printf("Case %d: %lld %lld\n",t++,x/res[0],res[0]);



        }
    }
    return 0;
}
