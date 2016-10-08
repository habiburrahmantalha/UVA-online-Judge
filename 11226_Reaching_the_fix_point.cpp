//Problem Type : primefactor
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
#define N 500010
bool mark [N+10];
int sopf[N+10];
vector <int> prime;

void sieve ()
{
    int i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for (i = 4; i < N; i += 2 )
        mark [i] = false;

    for (i = 3; i * i <= N; i++ )
        if ( mark [i] )
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = false;

    prime.clear ();
    prime.push_back (2);

    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
                prime.push_back (i);

    }

}

int SOPF(int n)
{
    int s,c=0,i,m;
    while(1)
    {
        s=0;
        m=n;
        for ( i = 0;prime[i]*prime[i]<= n; i ++ )
        {
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                s+=prime[i];
            }
        }
        if(n>1)
            s+=n;
        c++;
        if(sopf[s])
        {
            c+=sopf[s];
            break;
        }
        if(m==s || mark[s])
        break;
        n=s;
    }
    return c;
}


int main()
{
    sieve();
    memset(sopf,0,sizeof(sopf));
    for(int i=2;i<N;i++)
    sopf[i]=SOPF(i);
    int a,b,tc,t=1,mx,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        swap(a,b);
        mx=0;
        for(i=a;i<=b;i++)
        {
            //cout<<sopf[i]<<endl;
            if(sopf[i]>mx)
                mx=sopf[i];
        }
        printf("Case #%d:\n%d\n",t++,mx);

    }
    return 0;
}
