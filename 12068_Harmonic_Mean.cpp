//Problem Type : GCD,LCM;
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
#define LL long long
#define N 65700000

bool mark [N+10];
vector <LL> prime;

void sieve ()
{
    LL i,j;
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
    for ( i = 3; i <= N; i += 2 ) {
        if ( mark [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d ",i);
            }
    }
    //printf("%d",prime.size());
}


LL GCD(LL a,LL b)
{
    if(!b)
    return a;
    return GCD(b,a%b);
}
LL LCM(LL a,LL b)
{
    LL c;
    if(a>b)
    {
        c=a;
        a=b;
        b=c;
    }
    return (a*b) /GCD (a,b);
}
int main()
{
    //sieve();
    LL n,p,q,a[15],x,i,tc,t=1;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        q=a[0];

        for(i=1;i<n;i++)
        {

            q=LCM(q,a[i]);
            //cout<<q<<endl;
        }

        p=0;
        for(i=0;i<n;i++)
            p+=q/a[i];
        q*=n;

        //cout<<p<<" "<<q<<endl;
    /*
        for(i=0;i<prime.size() && prime[i]*prime[i]<=p && prime[i]*prime[i]<=q;i++)
        {
            while(p%prime[i]==0 && q%prime[i]==0)
            {
                p/=prime[i];
                q/=prime[i];
            }
        }
        */
        while(1)
        {
            x=GCD(p,q);
            if(x==1)
            break;
            p/=x;
            q/=x;
        }

        printf("Case %lld: %lld/%lld\n",t++,q,p);


    }
    return 0;
}
//1 9 101 99 98 97 95 93 91 89 87
