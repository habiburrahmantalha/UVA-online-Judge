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

#define N 10000000
#define LL long long
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
LL lowest_div(LL x,LL y,LL z)
{
    if(x<0)
    return 0;
    LL i,j;
    vector<LL>div;

    for(i=0;prime[i]*prime[i]<=x;i++)
    {
        while(x%prime[i]==0)
        {
            div.push_back(prime[i]);
            x/=prime[i];
        }
    }
    if(x!=1)
    div.push_back(x);

    /*
    for(i=0;i<div.size();i++)
    cout<<div[i]<<" ";
    cout<<endl;
    */

    map<LL,int>T;
    sort(div.begin(),div.end());
    map<LL,int> ::reverse_iterator rit;
    map<LL,int> ::iterator it;
    T[1]=1;
    for(i=0;i<div.size();i++)
    {
        for(rit=T.rbegin();rit!=T.rend();rit++)
        {
            T[rit->first*div[i]]=1;
        }
    }
    /*
    for(it=T.begin();it!=T.end();it++)
    cout<<it->first<<" ";
    cout<<endl;
    */
    if(div.size())
    {

        for(it=T.begin();it!=T.end();it++)
        {
            if(it->first>=y && z%it->first==y)
                return it->first;
        }
    }

    return 0;
}
int main()
{
    sieve();
    LL tc,x,y,z,c,i;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&x,&y);
        z=x-(y-2);
        if((x%1)+2==y)
            printf("1\n");
        else if((x%(x+1))+2==y)
            printf("%lld\n",x+1);
        else
        {
            c=lowest_div(z,y-2,x);
            //cout<<c<<"*";
            if(c==0)
            printf("Impossible\n");
            else
            printf("%lld\n",c);
        }
    }
    return 0;
}
